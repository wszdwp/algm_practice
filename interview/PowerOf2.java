public class PowerOf2
{
	public static void main(String[] args) 
	{
		int test = 8;
		System.out.println(test + " Expected(true) " + checkPowerOf2(test));
	}

	public static boolean checkPowerOf2(int n) 
	{
		return ((n &(n - 1))==0);
	}
}