import java.util.*;
import java.io.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

public final class PhoneNumber {
    private final short areaCode;
    private final short prefix;
    private final short lineNumber;
    public PhoneNumber(int areaCode, int prefix, int lineNumber) {
        rangeCheck(areaCode, 999, "prefix");
        rangeCheck(prefix, 999, "area code"); 
        rangeCheck(lineNumber, 9999, "line number");
        this.areaCode = (short) areaCode;
        this.prefix = (short) prefix;
        this.lineNumber = (short) lineNumber;
    }
    private static void rangeCheck(int arg, int max, String name) {
        if (arg < 0 || arg > max)
            throw new IllegalArgumentException(name + ": " + arg);
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof PhoneNumber))
            return false;
        PhoneNumber pn = (PhoneNumber)o;

        boolean r =  pn.lineNumber == lineNumber && pn.prefix == prefix && pn.areaCode == areaCode;
        System.out.println("equals " + r);
        return r;
    } // Broken - no hashCode method // ... Remainder omitted

    @Override
    public int hashCode() {
        return 42;   // Map由于hashcode都为42，所以退化成链表
    }

    public static void main(String[] args) {
        Map<PhoneNumber, String> m = new HashMap<PhoneNumber, String>();
        m.put(new PhoneNumber(707, 867, 5309), "Jenny");
        m.put(new PhoneNumber(707, 867, 5308), "Jenny");


        System.out.println("get " + m.get(new PhoneNumber(707, 867, 5309)));
        System.out.println("get " + m.get(new PhoneNumber(707, 867, 5308)));

        try {
            File file = new File("text.txt");

            System.out.println("file.exists " + file.exists());
            File tmp = new File("text1.txt");
            tmp.createNewFile();
            boolean r = tmp.renameTo(file);
            System.out.println("renameTo " + r);

            System.out.println("file.exists " + file.exists());
        } catch (Exception e) {
        }

        String str = "LLILII";
        System.out.println("hashcode " + str.hashCode());
    }
}
