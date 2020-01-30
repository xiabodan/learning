import java.io.*;

class TestThrows{
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

    public static void main(String[] args){
        try {
        //     throw2();
            throw3(0);
        // } catch (IllegalAccessException e) {
        //     System.out.println("main catch . ");
        //     e.printStackTrace();
        } catch (FileNotFoundException e1) {
            System.out.println("main catch file . ");
            e1.printStackTrace();
        } catch (SecurityException e) {
            System.out.println("main catch secur . ");
            e.printStackTrace();
        }
        System.out.println("main end . ");
    }
}
