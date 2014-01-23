/**
*	Java Interview Questions
*	Source: http://www.geeksforgeeks.org/compare-two-arrays-java/	
*	Date: 2014-01-21
*/

//How to compare two arrays in Java?
public class Hello
{
	public static void main (String[] args) 
    {
        int arr1[] = {1, 2, 3};
        int arr2[] = {1, 2, 3};
        if (arr1 == arr2) // Same as arr1.equals(arr2)
            System.out.println("Same");
        else
            System.out.println("Not same");
    }
}