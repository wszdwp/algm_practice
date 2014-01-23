/**
*	2) In Java, methods declared as private can never be overridden, 
*		they are in-fact bounded during compile time. 
*		this behavior is different from C++. In C++, we can have virtual private methods 
*		(See this : http://ideone.com/6645Uz)
*/

class OverRidden
{
	public static void main(String[] args) 
	{
      Base obj = new Derived();
      obj.fun();
 	}  

	static class Derived extends Base 
	{
	  private void fun() {
	     System.out.println("Derived fun");  
	  }

	  public void fun1() {
	     System.out.println("Derived fun");  
	  } 
	}

	static class Base
	{
	  private void fun() {
	     System.out.println("Base fun");     
	  }

	  public void fun1() {
	     System.out.println("Base fun");     
	  }
	}
}