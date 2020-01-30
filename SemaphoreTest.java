import java.util.*;
import java.util.concurrent.*;

public class SemaphoreTest {
    private static final int COUNT = 40;
    private static Executor executor = Executors.newFixedThreadPool(COUNT);
    private static Semaphore semaphore = new Semaphore(2); // 每次只允许两个线程同时执行 默认情况下是非公平的，即谁能拿到信号量不确定
    public static void main(String[] args) {
        for (int i=0; i< COUNT; i++) {
            MyThread t = new MyThread("Thread" + i, new Object());
            t.start();
        }
    }

    static class MyThread extends Thread {
        private String name;
        private Object co;

        public MyThread(String name, Object o) {
            this.name = name;
            this.co = o;
        }

        @Override
        public void run() {
            System.out.println(name + " is waiting.");
            try {
                semaphore.acquire();  // 没拿到信号量的只能阻塞等待
                Thread.sleep(1000);
                System.out.println(name + " has been excute.");
                semaphore.release();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
