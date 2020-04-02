import java.io.*;
import java.util.*;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

class SemaphoreTest {
    static void throw1() throws FileNotFoundException {
        // try {
        //     System.out.println("Inside throw1 . ");
        //     throw new IllegalAccessException("demo");
        // } catch (IllegalAccessException e) {
        //     System.out.println("throw1 catch . ");
        //     e.printStackTrace();
        // }
        FileInputStream is = new FileInputStream(new File("test222"));
    }

    static void throw2() throws FileNotFoundException {
        try {
            throw1();
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException();
        }
    }

    static String buildSecurityExceptionMsg(int op, int uid, String packageName) {
        return packageName + " from uid " + uid + " not allowed to perform ";
    }

    static void throw3(int i) throws FileNotFoundException {
        if (i == 0) {
            // throw new SecurityException(buildSecurityExceptionMsg(1, 1, "xiabo"));
            // throw new IllegalAccessException("demo");
            throw new NullPointerException("demo");
        }
    }

    public static class MyThread extends Thread {
        TEST test;
        public MyThread (TEST test) {
            this.test = test;
        }

        @Override
        public void run() {
            super.run();
            test.test();
        }
    }

    static class TEST {
        private final int MAX_WAIT_START_ASSISTANT_PROCESS_SECONDS = 5;  // 10s
        private final Semaphore mStartAssistantProcessLock = new Semaphore(2);

        public TEST() {
        }

        private void run() {
            try {
                Thread t = Thread.currentThread();
                System.out.println("run begin ... " + t.getId());
                Thread.sleep(10000);
                System.out.println("run end ... " + t.getId());
            } catch (Exception e) {
            }
        }

        private void test() {
            boolean acquired = false;
            try {
                if (mStartAssistantProcessLock.tryAcquire(MAX_WAIT_START_ASSISTANT_PROCESS_SECONDS, TimeUnit.SECONDS)) {
                    System.out.println("test tryAcquire count " + mStartAssistantProcessLock.availablePermits());
                    acquired = true;
                }
                run();
            } catch (Exception e) {
                System.out.println("Exception " + e);
                e.printStackTrace();
            } finally {
                if (acquired == true) {
                    mStartAssistantProcessLock.release();
                    System.out.println("finally count " + mStartAssistantProcessLock.availablePermits());
                }
            }
        }

        public void a() {
            try {
                test();
                test();
                test();
                test();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args){
        System.out.println("main start . ");
        TEST t = new SemaphoreTest.TEST();
        MyThread mythread = new MyThread(t);
        mythread.start();
        MyThread mythread1 = new MyThread(t);
        mythread1.start();
        MyThread mythread2 = new MyThread(t);
        mythread2.start();
        try {
            Thread.sleep(1000);
            // mythread1.interrupt();
        } catch (Exception e) {
            e.printStackTrace();
        }
        //     throw2();
        //     throw3(0);
        // } catch (IllegalAccessException e) {
        //     System.out.println("main catch . ");
        //     e.printStackTrace();
        // } catch (FileNotFoundException e1) {
        //     System.out.println("main catch file . ");
        //     e1.printStackTrace();
        // } catch (SecurityException e) {
        //     System.out.println("main catch secur . ");
        //     e.printStackTrace();
        // }

        // System.out.println("main end . ");
}
}
