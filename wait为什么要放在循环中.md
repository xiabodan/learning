在多线程的编程实践中，wait()的使用方法如下：

```
synchronized (monitor) {
    //  判断条件谓词是否得到满足
    while(!locked) {
        //  等待唤醒
        monitor.wait();
    }
    //  处理其他的业务逻辑
}
```

那为什么非要while判断，而不采用if判断呢？如下：

```
synchronized (monitor) {
    //  判断条件谓词是否得到满足
    if(!locked) {
        //  等待唤醒
        monitor.wait();
    }
    //  处理其他的业务逻辑
}
```

这是因为，如果采用if判断，当线程从wait中唤醒时，**那么将直接执行处理其他业务逻辑的代码，但这时候可能出现另外一种可能，条件谓词已经不满足处理业务逻辑的条件了(即locked = false)，这时应该继续循环检测locked，从而再次调用wait，而不是继续向下执行，** 于是有必要进行再一次判断，如下：

```
synchronized (monitor) {
    //  判断条件谓词是否得到满足
    if(!locked) {
        //  等待唤醒
        monitor.wait();
        if(locked) {
            //  处理其他的业务逻辑
        } else {
            //  跳转到monitor.wait(); 
        }
    }
}
```

而循环则是对上述写法的简化，唤醒后再次进入while条件判断，避免条件谓词发生改变而继续处理业务逻辑的错误。
