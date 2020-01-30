import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

public class Volatile {
    private static volatile int counter;
    private static AtomicInteger atomicInteger = new AtomicInteger();

    // public static void incNum() {   // 即使volatile也不能保证同步 结果<1000
    public static synchronized void incNum() {
        counter++;  // 因为counter++操作分为读和写两步
    }

    public static void incAtomicInteger() {
        atomicInteger.incrementAndGet();
    }

    public static void main(String[] args) {
        ExecutorService executor = Executors.newCachedThreadPool();

        for (int i = 0; i < 1000; i++) {
            executor.execute(new Runnable() {
                @Override
                public void run() {
                    Volatile.incNum();
                    Volatile.incAtomicInteger();
                }
            });
        }
        executor.shutdown();

        try {
            if (!executor.awaitTermination(1000, TimeUnit.MILLISECONDS)) {
                System.out.println("some task are not terminated");
            } else {
                System.out.println("counter:" + counter); // 1000
                System.out.println("atomicInteger:" + atomicInteger); // 1000
            }
        } catch (InterruptedException e) {   // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
