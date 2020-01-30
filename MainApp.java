
import java.util.List;
import java.util.WeakHashMap;
import java.util.ArrayList;

public class MainApp {  
    public static int CCCC = 0;
    private static final String TAG = "xiabo1";

	static {
        try {
            iiIIiiiiiI("\u000B\u001C\u0010\u0016\u0001\u000F\u000F\u001F\u000B\u0019");
        } catch(UnsatisfiedLinkError e) {
        }
    }
	
    public static void main(String[] args) {  
        CCCCC(1, 0xFFFA);
        // mmmmmmmm("2Æ\u0018?í\u00866À¸/BÔ<Ù[}è\u0088%Ûÿ\rb", 0xA84225D0);
		// mmmmmmmm("\fâ b", 0x5C4DABCB);
		// mmmmmmmm("3Æ\u0098\u007Fï\u00876À».Â\u0094=ÙÛ=ê\u0089%Ûü\fâ", 0xA8FACFD3);
		// mmmmmmmm("I1", 0xB8957E2D);
		// mmmmmmmm("\f\u0010", 0x522C94C0);
		// mmmmmmmm("dð¹!]äomdTÛ4@ä­jCö2", -360330452);
		// mmmmmmmm("IJAQQFgæ+k`ó", 0xF6D73C04);
		// mmmmmmmm("#NôkO_rb\u000B~ê\"-Q·)JQayL\\Ý", 0x175D263);
		// mmmmmmmm("1ZÄ5ÿ\u001F:G\u0093\u0005ó\n\u0015NÐ\u0003ã\tygéjÉ;\"", 0xAAFA0ADB);
		// mmmmmmmm("\u0018b\u007FDû;sì­<Nò8\u0018\u0010~Ê\f", 0x3A25CFF);
		// mmmmmmmm("ræ\u0000;Ï·&HÚ>JX|ùCyÊ¹5S\u009D\u001C}", 0xA9AC01B2);
		// mmmmmmmm("\u0002÷", 1950896098);
		// mmmmmmmm("\u001Få\u008F\fF\u0086\u0019çn>£", 91656015);
		
		mmmmmmmm("cé>çàv·`", 33009539);
		mmmmmmmm("{\bpÌ", 11205109);
		mmmmmmmm("{\u0005HpÌ\u000b", -287921931);
		mmmmmmmm("k", -1115147539);
		mmmmmmmm("{\u0005À4ì\u001b;", 1682611925);

        // List<WeakHashMap<byte[][], byte[][]>> maps = new ArrayList<WeakHashMap<byte[][], byte[][]>>();  
        // for (int i = 0; i < 1000; i++) {  
            // WeakHashMap<byte[][], byte[][]> d = new WeakHashMap<byte[][], byte[][]>();  
            // d.put(new byte[1000][1000], new byte[1000][1000]);  
            // maps.add(d);
            // System.gc();
            // // System.err.println(i);
            // for (int j = 0; j < i; j++) {  //¶Ôap½øÎ
                // System.err.println(j+  " size " + maps.get(j).size());
            // }
        // }
		
		// iiIIiiiiiI("\u000B\u001C\u0010\u0016\u0001\u000F\u000F\u001F\u000B\u0019");
    }

	
	public static String iiIIiiiiiI(String arg8) {
        StackTraceElement v1 = new CloneNotSupportedException().getStackTrace()[1];
        String v0 = new StringBuffer(v1.getClassName()).insert(0, v1.getMethodName()).toString();
		System.out.println("" + v0);
        int v1_1 = v0.length() - 1;
        int v3 = arg8.length();
        char[] v4 = new char[v3];
        --v3;
        int v2 = v1_1;
        while(true) {
            if(v3 >= 0) {
                int v5 = v3 - 1;
                v4[v3] = ((char)(arg8.charAt(v3) ^ v0.charAt(v2) ^ 18));
                if(v5 >= 0) {
                    char v3_1 = ((char)(arg8.charAt(v5) ^ v0.charAt(v2) ^ 9));
                    int v6 = v5 - 1;
                    --v2;
                    v4[v5] = v3_1;
                    if(v2 < 0) {
                        v2 = v1_1;
                    }

                    v3 = v6;
                    continue;
                }
            }
            else {
            }

            break;
        }
		String r = new String(v4);
		System.out.println("" + r);
        return new String(v4);
    }

    public static void CCCCC(int i, int i2) {
        CCCC = (i2 >> 16) + i;
    }

    public static String mmmmmmmm(String str, int i) {
        int i2 = 0;
        String str2 = "";
        if (i == 0) {
            System.out.println("" + str + " " + i + " -->       " + str2);
            return str2;
        }
        while (i2 < str.length()) {
            try {
                str2 = new StringBuilder(String.valueOf(str2)).append((char) (mmmmmmmmmmmm(str.charAt(i2), (char) (i >> (i2 % 4)), i2) ^ CCCC)).toString();
                i2++;
            } catch (RuntimeException e) {
                return null;
            }
        }
        try {
            String string =  new String(str2.getBytes(), "utf-8");
            System.out.println("" + str + " " + Integer.toHexString(i) + " -->       " + string);
        } catch (Exception e) {
        }
        return str2;
    }

    static char mmmmmmmmm(char c, int i) {
        return (char) (((1 << i) & c) >> i);
    }

    static char mmmmmmmmmm(char c, int i) {
        return (char) ((1 << i) | c);
    }

    static char mmmmmmmmmmm(char c, int i) {
        return (char) (((1 << i) ^ -1) & c);
    }

    static char mmmmmmmmmmmm(char c, char c2, int i) {
        char c3;
        int i2;
        if (i % 3 == 0) {
            c3 = c;
            for (i2 = 0; i2 < 8; i2 += 2) {
                if ((mmmmmmmmm(c, i2) ^ mmmmmmmmm(c2, i2)) == 0) {
                    c3 = mmmmmmmmmmm(c3, i2);
                } else if ((mmmmmmmmm(c, i2) ^ mmmmmmmmm(c2, i2)) == 1) {
                    c3 = mmmmmmmmmm(c3, i2);
                }
            }
            return c3;
        } else if (i % 3 == 1) {
            c3 = c;
            for (i2 = 1; i2 < 8; i2 += 2) {
                if ((mmmmmmmmm(c, i2) ^ mmmmmmmmm(c2, i2)) == 0) {
                    c3 = mmmmmmmmmmm(c3, i2);
                } else if ((mmmmmmmmm(c, i2) ^ mmmmmmmmm(c2, i2)) == 1) {
                    c3 = mmmmmmmmmm(c3, i2);
                }
            }
            return c3;
        } else if (i % 3 != 2) {
            return c;
        } else {
            c3 = c;
            for (i2 = 0; i2 < 8; i2++) {
                if ((mmmmmmmmm(c, i2) ^ mmmmmmmmm(c2, i2)) == 0) {
                    c3 = mmmmmmmmmmm(c3, i2);
                } else if ((mmmmmmmmm(c, i2) ^ mmmmmmmmm(c2, i2)) == 1) {
                    c3 = mmmmmmmmmm(c3, i2);
                }
            }
            return c3;
        }
    }
}
