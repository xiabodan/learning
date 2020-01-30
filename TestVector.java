import java.util.ArrayList;
import java.util.Vector;
import java.util.concurrent.CountDownLatch;

public class TestVector {
	// public static ArrayList<Object> arrayList = new ArrayList<Object>(); // 线程不安全
	public static Vector<Object> arrayList = new Vector<Object>();  // 线程安全 结果为1000
	public static CountDownLatch countDownLatch = new CountDownLatch(10);
	public static int x = 0;
	public static void main(String[] args0) throws InterruptedException{
		Threads []threads = new Threads[10];
		for(int i=0;i<10;i++){
			threads[i] = new Threads();
			threads[i].start();
		}
		countDownLatch.await();
		for(int i=0;i<arrayList.size();i++){
			if(i==(arrayList.size()-1))
				System.out.println(arrayList.size());
			System.out.println(arrayList.get(i));
		}
	}
	static class Threads extends Thread{
		public void run(){
			for(int i=0;i<100;i++){
				arrayList.add(Thread.currentThread().getName()+"Thread"+x++);
			}
			countDownLatch.countDown();
		}
	}
}
