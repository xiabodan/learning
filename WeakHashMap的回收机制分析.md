在Java中，一般人对于WeakHashMap的理解都是：当某个键不再被使用时，将自动移除回收其条目。

WeakHashMap真的是自动移除回收其条目的吗？

看了下WeakHashMap的实现源码，主要是通过expungeStaleEntries这个函数来实现回收的，基本上WeakHashMap中所有的public方法都调用了该函数，简言之就是只要访问WeakHashMap的内容就会调用该函数，从而达到清除其内部不再被引用的条目。
但是如果预先生成了WeakHashMap，而在gc以前又不曾访问该WeakHashMap，是不是就不能释放内存了呢？ 写个代码测试一下：

```
List<WeakHashMap<byte[][], byte[][]>> maps = new ArrayList<WeakHashMap<byte[][], byte[][]>>();
for (int i = 0; i < 1000; i++) {
 WeakHashMap<byte[][], byte[][]> d = new WeakHashMap<byte[][], byte[][]>();
 d.put(new byte[5000][5000], new byte[5000][5000]);
 maps.add(d);
 System.gc();
 System.err.println(i);
}
```

在不改变JDK内存参数的情况下，该测试循环不了几次就内存溢出了，果不其然，WeakHashMap在这时候并没有自动帮我们清理不用的条目而释放内存。
加个会对map进行访问的代码试试：

```

List<WeakHashMap<byte[][], byte[][]>> maps = new ArrayList<WeakHashMap<byte[][], byte[][]>>();
for (int i = 0; i < 1000; i++) {
 WeakHashMap<byte[][], byte[][]> d = new WeakHashMap<byte[][], byte[][]>();
 d.put(new byte[1000][1000], new byte[1000][1000]);
 maps.add(d);
 System.gc();
 System.err.println(i);
 //元素并不存在，只达到访问WeakHashMap方法目的
 System.out.println(maps.get(0));

}

```

这下就没有问题了，测试顺利通过。

可见，WeakHashMap并不是你啥也不干就能自动清理回收内部对象的，而是在你访问它内容的时候释放内部不用的对象（实则是通过访问调用了它的expungeStaleEntries函数），没理解这一点，在程序中就有可能引发灾难！

在WeakHashMap$Entry<K,V>的构造函数里面是这样写的：

```
Entry(K key, V value, ReferenceQueue<K> queue, int hash, Entry<K, V> next) {
 super(key, queue);
 this.value = value;
 this.hash = hash;
 this.next = next;

}

```

注意它构造父类的语句：super(key, queue)，传入的是key，因此key才是进行弱引用的，value是直接强引用关联在this.value之中，在System.gc()时，key被清除了，WeakHashMap本身根据ReferenceQueue中接收到的清除通知来清理value值，这个动作实现在expungeStaleEntries()方法之内，在getTable()之中对这个方法进行了调用，而WeakHashMap几乎在所有public的方法中都是要调用getTable()的。**所以效果是key在GC的时候被清除，value在key清除后访问WeakHashMap的时候被清除。**

WeakHashMap的说明之中也是说“An entry in a WeakHashMap will automatically be removed when its key is no longer in ordinary use”。所以WeakHashMap的实现并没有问题，只是人们大多想当然的理解为value会自动清除而已。
