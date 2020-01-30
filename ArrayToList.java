import java.util.*;

public class ArrayToList
{
    public static void main(String[] args)
    {
        // This gives us nothing good
        System.out.println(args);

        // Convert args to a List of String
        List<String> argList = Arrays.asList(args);
        // argList.add("dddd"); // error!!!

        // Print them out
        System.out.println(argList);
    }
}
