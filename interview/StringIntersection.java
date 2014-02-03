import java.util.*;

public class StringIntersection {
    static String str1 = "hello";
    static String str2 = "elbow";

    public static Set findIntersection() {
        String[] arr1 = str1.split("");
        String[] arr2 = str2.split("");
        for(String s : arr1)
            System.out.println(s);
        List<String> list = Arrays.asList(arr1);

        Set<String> set = new LinkedHashSet<String>(Arrays.asList(arr1));
        set.retainAll(Arrays.asList(arr2));

        set.remove("");

        return set; // returns [e, l, o]
    }

    public static void main(String[] args) {
        System.out.println(findIntersection());
    }
}
