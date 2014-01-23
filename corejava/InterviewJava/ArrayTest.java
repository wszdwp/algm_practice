/**
*	Geeksforgeeks.org
*	http://www.geeksforgeeks.org/compare-two-arrays-java/
*	2014-01-21
*
*/

//How to compare two arrays in Java?
//Predict the output of following Java program.
import java.util.Arrays;

class ArrayTest
{
    public static void main (String[] args) 
    {
    	ArrayTest testResult = new ArrayTest();
        int arr1[] = {1, 2, 3};
        int arr2[] = {1, 2, 3};
        //not works
        System.out.print("Expected(Not Same): ");
        testResult.compareArray0(arr1, arr2);

        System.out.print("Expected(Same): ");
        testResult.compareArray1(arr1, arr2);

        System.out.print("Expected(Not Same): ");
        testResult.compareArray2(arr1, arr2);

        System.out.print("Expected(Same): ");
        testResult.compareArray3(arr1, arr2);

        System.out.print("Expected(Same): ");
        testResult.compareArray4(arr1, arr2);
    }

    public void compareArray0(int[] arr1, int[] arr2)
    {
    	if(arr1 == arr2)
    		System.out.println("Same");
        else
            System.out.println("Not same");
    }

    public void compareArray1(int[] arr1, int[] arr2)
    {
    	if(Arrays.equals(arr1, arr2))
    		System.out.println("Same");
        else
            System.out.println("Not same");
    }

    public void compareArray2(int[] arr1, int[] arr2)
    {
    	Object[] cappedArr1 = {arr1};
    	Object[] cappedArr2 = {arr2};
    	if(Arrays.equals(cappedArr1, cappedArr2))
    		System.out.println("Same");
        else
            System.out.println("Not same");
    }

    public void compareArray3(int[] arr1, int[] arr2)
    {
    	Object[] cappedArr1 = {arr1};
    	Object[] cappedArr2 = {arr2};
    	if(Arrays.deepEquals(cappedArr1, cappedArr2))
    		System.out.println("Same");
        else
            System.out.println("Not same");
    }

    public void compareArray4(int[] arr1, int[] arr2)
    {
    	Object[] midArr1 = {arr1};
    	Object[] midArr2 = {arr2};
    	Object[] outarr1 = {midArr1}; // outarr1 contains only one element
      	Object[] outarr2 = {midArr2}; // outarr2 also contains only one element 
    	if(Arrays.deepEquals(outarr1, outarr2))
    		System.out.println("Same");
        else
            System.out.println("Not same");
    }

}