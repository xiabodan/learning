# java-learning
java/c/c++基础知识学习

编译liba.so
    gcc -shared a.c c.c -o liba.so -fPIC
结合liba.so编译b
    gcc -la -L.  b.c -o b

__attribute__ ((visibility ("hidden"))) 修饰的symbol对当前所有文件可见,对外不可见
