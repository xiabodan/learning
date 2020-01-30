import java.util.*;
import java.util.concurrent.*;

public class IteratorTest {
    private static CopyOnWriteArrayList<String> list = new CopyOnWriteArrayList<>();

    public static void main(String[] args) {

        list.add("1");
        list.add("2");
        list.add("3");

        Iterator<String> iter = list.iterator();
        ExecutorService service = Executors.newFixedThreadPool(10);

        for (int i = 0; i < 10; i++) {
            service.execute(new Runnable() {
                @Override
                public void run() {
                    while (iter.hasNext()) {
                        System.err.println(iter.next());
                    }
                }
            });
        }

        for (int i = 0; i < 10; i++) {
            service.execute(new Runnable() {
                @Override
                public void run() {
                    list.add("121");
                }
            });
        }
        System.err.println(Arrays.toString(list.toArray()));
    }
}
