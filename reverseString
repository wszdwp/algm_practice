public class StrAlg
{
    private static String[] tests = {"abcdefg", "a", "", "123", "abc123", "!@#", "!@ #"};
    
    //version 1 - recursive way
   /*  
    public static String reverse(String str)
    {
        if ((null == str) || (str.length()  <= 1)) {
               return str;
           }
           return reverse(str.substring(1)) + str.charAt(0);
    }
    */
    
    //version 2 - StringBuffer
    /*
    public static String reverse(String str) {
            if ((null == str) || (str.length()  <= 1 )) {
                return str;
            }
            StringBuffer result = new StringBuffer(str);
            for (int i = 0; i < (str.length() / 2); i++) {
                int swapIndex = str.length() - 1 - i;
                char swap = result.charAt(swapIndex);
                result.setCharAt(swapIndex, result.charAt(i));
                result.setCharAt(i, swap);
            }
            return result.toString();
        }
    */
    
    //version 3 - Array method
    /*
    public static String reverse(String str) {
          if ((null == str) || (str.length() <= 1)) {
              return str;
          }
          char[] chars = str.toCharArray();
          int right = chars.length - 1;
          for (int left = 0; left < right; left++) {
              char swap = chars[left];
              chars[left] = chars[right];
              chars[right--] = swap;
          }
          return new String(chars);
      }
    */
    
    //version 4(recommended)- StringBuffer appended way 
   
    public static String reverse(String str) {
          if ((null == str) || (str.length() <= 1)) {
              return str;
          }
          StringBuffer reverse = new StringBuffer(str.length());
          for (int i = str.length() - 1; i >= 0; i--) {
            reverse.append(str.charAt(i));
          }
          return reverse.toString();
      }
   
    
    //version 5 -XOR -- http://weblogs.sqlteam.com/mladenp/archive/2006/03/19/9350.aspx
    /*
    public static String reverse(String str){
        // convert the string to char array
        char[] charArray = str.toCharArray();
        int len = str.length() - 1;
        //now this for is a bit unconventional at first glance because there
        // are 2 variables that we're changing values of: i++ and len--.
        //the order of them is irrelevant. so basicaly we're going with i from 
        //start to end of the array. with len we're shortening the array by one
        //each time. this is probably understandable.
         
        for (int i = 0; i < len; i++, len--){
            //now this is the tricky part people that should know about it don't.
            //look at the table below to see what's going on exactly here.
             
            charArray[i] ^= charArray[len];
            charArray[len] ^= charArray[i];
            charArray[i] ^= charArray[len];
        }
        return new String(charArray);
    }
    */
    
    //Version 6 - C style --modified based on http://weblogs.sqlteam.com/mladenp/archive/2006/03/19/9350.aspx
    /* 
    public static String reverse(String str){
        char[] charArray = new char[str.length()];
        int len = str.length() - 1;
        for (int i = 0; i <= len; i++)
            charArray[i] = str.charAt(len-i);
        return new String(charArray);
    }
    */
     
    
    //print out the result
    public static void main(String[] args)
    {
        for( String test : tests ) {
            System.out.println(reverse(test));
        }
    }
}
