import java.util.*;


public class BST
{	
	//the 1st level is 1
	public static int bfsAndLevelSum(Node root, int level) 
	{
		Queue<Node> que = new LinkedList<Node>();
		int levelCount = 0;
		for(int i = 1; i < level; i++){
			levelCount += Math.pow(2, i-1);
		}
		//System.out.println("levelCount = " + levelCount);
		int count = (int)Math.pow(2, level-1);
		//System.out.println("count = " + count);
		int sum = 0;
		que.add(root);

		while(!que.isEmpty())
		{
			Node nd = que.remove();
			if(levelCount<=0 && count>0){
				sum += nd.val;
				count--;
			}
			System.out.println(nd.val);
			if(nd.lchild != null)
				que.add(nd.lchild);
			if(nd.rchild != null)
				que.add(nd.rchild);
			levelCount--;
		}
		return sum;
	}

	public static void main(String[] args)
	{
		/*
		*	  5
		*	3	6
		* 8	   1
		*/

		Node tr1 = new Node(5);		
		Node nd3 = new Node(3);		
		Node nd6 = new Node(6);
		Node nd1 = new Node(1);
		Node nd8 = new Node(8);
		tr1.lchild = nd3;
		tr1.rchild = nd6;
		nd6.lchild = nd1;
		nd3.lchild = nd8;

		System.out.println("Depth First Search Pre-Order: ");
		dfsPre(tr1);

		System.out.println("Depth First Search In-Order: ");
		dfsIn(tr1);

		System.out.println("Depth First Search Post-Order: ");
		dfsPost(tr1);

		System.out.println("Breadth First Search: ");
		int levelSum = bfsAndLevelSum(tr1, 3);
		System.out.println("levelSum = " + levelSum);
	}

	public static void dfsPre(Node root)
	{
		if(root == null)	return;
		else {
			System.out.println(root.val);
			dfsPre(root.lchild);
			dfsPre(root.rchild);
		}
	}

	public static void dfsIn(Node root)
	{
		if(root == null)	return;
		else {
			dfsIn(root.lchild);
			System.out.println(root.val);
			dfsIn(root.rchild);
		}
	}

	public static void dfsPost(Node root)
	{
		if(root == null)	return;
		else {
			dfsPost(root.lchild);
			dfsPost(root.rchild);
			System.out.println(root.val);
		}
	}


}

