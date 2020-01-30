import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

public class SYNTest {
    static public class ObjectService {
        public void serviceMethodA(){
            try {
                synchronized (this) {
                    System.out.println("A begin time="+System.currentTimeMillis());
                    Thread.sleep(2000);
                    System.out.println("A end   time="+System.currentTimeMillis());
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        public void serviceMethodB(){
            synchronized (this) {
                System.out.println("B begin time="+System.currentTimeMillis());
                System.out.println("B end   time="+System.currentTimeMillis());
            }
        }
    }

    static public class ThreadA extends Thread {
        private ObjectService objectService;
        public ThreadA(ObjectService objectService){
            super();
            this.objectService=objectService;
        }
        @Override
        public void run() {
            super.run();
            objectService.serviceMethodA();
        }
    }

    static public class ThreadB extends Thread {
        private ObjectService objectService;
        public ThreadB(ObjectService objectService){
            super();
            this.objectService=objectService;
        }
        @Override
        public void run() {
            super.run();
            objectService.serviceMethodB();
        }
    }


    public static void main(String[] args) {
        ObjectService service = new ObjectService();
        ThreadA a = new ThreadA(service);
        a.setName("a");
        a.start();
        ThreadB b = new ThreadB(service);
        b.setName("b");
        b.start();
    }
}
