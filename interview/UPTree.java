import java.util.*;

public class UPTree
{
	private UPNode root;

	public static void main(String[] args)
	{
		/*
		*		 5
		*	  3      8
		*   2   4   7  9
		*  1       6
		*/
		UPNode root = new UPNode(5);
		UPNode nd1  = new UPNode(1);
		UPNode nd2  = new UPNode(2);
		UPNode nd3  = new UPNode(3);
		UPNode nd4  = new UPNode(4);
		UPNode nd6  = new UPNode(6);
		UPNode nd7  = new UPNode(7);
		UPNode nd8  = new UPNode(8);
		UPNode nd9  = new UPNode(9);

		nd1.parent = nd2;
		nd2.parent = nd3;
		nd4.parent = nd3;
		nd3.parent = root;
		nd6.parent = nd7;
		nd7.parent = nd8;
		nd9.parent = nd8;
		nd8.parent = root;

		UPNode node = firstCommonAncestor(nd1, nd6);
		System.out.println("node is " + node.val);

	}

	public static UPNode firstCommonAncestor(UPNode nd1, UPNode nd2)
	{
		Queue<UPNode> que1 = new LinkedList<UPNode>();
		Queue<UPNode> que2 = new LinkedList<UPNode>();
		int size1 = 0;
		int size2 = 0;
		while(nd1 != null)
		{
			que1.add(nd1);
			size1++;
			System.out.print(nd1.val + ", ");
			nd1 = nd1.parent;
		}
		System.out.println();
		while(nd2 != null)
		{
			que2.add(nd2);
			size2++;
			System.out.print(nd2.val + ", ");
			nd2 = nd2.parent;
		}
		System.out.println();

		int length = Math.min(size1, size2);
		UPNode n1, n2;
		while(length != 0)
		{
			n1 = que1.remove();
			n2 = que2.remove();
			if(n1.val == n2.val)
				return n1;
		}
		return null;
		

	}
}