public class BinaryTree
{
	private Node root;

	public void BinaryTree()
	{
		root = null;
	} 

	private class Node 	// ?? private static class Node
	{
		int data;
		Node left;
		Node right;
		Node(int aData)
		{
			left = null;
			right = null;
			data = aData;
		} 
	}

	public boolean lookup(int data)
	{
		return (lookup(root, data));
	}

	private boolean lookup(Node node, int data)
	{
		if(node == null)
			return(false);
		if(data == node.data)
		{
			return(true);
		}
		else if(data < node.data)
		{
			return(lookup(node.left, data));
		}
		else
		{
			return(lookup(node.right, data));	
		}
	}

	public void insert(int data)
	{
		root = insert(root, data);
	}

	private Node insert(Node node, int data)
	{
		if(node == null)
			node = new Node(data);
		else{
			if(data <= node.data)
			{
				node.left = insert(node.left, data);
			}
			else
			{
				node.right = insert(node.right, data);
			}
		}
		return node;
	}

	public void printTree()
	{	
		printTree(root);
		System.out.println();
	}

	private void printTree(Node node)
	{
		if(node == null)	return;
		printTree(node.left);
		System.out.print(node.data + " ");
		printTree(node.right);
	}

	public void build123()
	{
		root = null;
		root = insert(root, 2);
		root = insert(root, 1);
		root = insert(root, 3);
	}

	public int size()
	{
		return size(root);
	}

	private int size(Node node)
	{
		if(node == null)	return 0;
		else 
		{
			return (1 +size(node.left) + size(node.right));
		}
	}

	public int maxDepth()
	{
		return maxDepth(root);
	}

	private int maxDepth(Node node)
	{
		if(node == null)	return 0;
		else
		{
			int lDepth = maxDepth(node.left);
			int rDepth = maxDepth(node.right);
			return (1 + Math.max(lDepth, rDepth));
		}
	}

	public int minValue()
	{
		return minValue(root);
	}

	private int minValue(Node node)
	{
		Node current = node;
		while(current.left != null)
			current = current.left;
		return current.data;
	}

	public int maxValue()
	{
		return maxValue(root);
	}

	private int maxValue(Node node)
	{
		Node current = node;
		while(current.right != null)
			current = current.left;
		return current.data;
	}

	public boolean hasPath(int sum)
	{
		return hasPath(root, sum);
	}

	private boolean hasPath(Node node, int sum)
	{
		if(node == null)	
			return (sum == 0);
		else
		{
			int subSum = sum - node.data;
			return hasPath(node.left, subSum) || hasPath(node.right, subSum);		
		}
	}

	public void printPaths()
	{
		int[] path = new int[100];
		printPaths(root, path, 0);
	}

	private void printPaths(Node node, int[] path, int pathLen)
	{
		if(node == null)	return;
		path[pathLen] = node.data;
		pathLen++;
		//System.out.println("pathLen= " + pathLen);
		if(node.left == null && node.right == null)
			printArray(path, pathLen);
		else
		{
			//System.out.println("pathLen= " + pathLen);
			printPaths(node.left, path, pathLen);
			//System.out.println("pathLen= " + pathLen);
			printPaths(node.right, path, pathLen);
		}
	}

	private void printArray(int[] ints, int len)
	{
		int i;
		for(i = 0; i < len; i++)
			System.out.print(ints[i] + " ");
		System.out.println();
	}

	public void mirror()
	{
		mirror(root);
	}

	private void mirror(Node node)
	{
		if(node != null)
		{
			mirror(node.left);
			mirror(node.right);
			Node tmp = node.left;
			node.left = node.right;
			node.right = tmp;
		}
	}

	public void doubleTree()
	{
		doubleTree(root);
	}

	private void doubleTree(Node node)
	{
		Node oldLeft;
		if(node == null)	return;
		doubleTree(node.left);
		doubleTree(node.right);
		oldLeft = node.left;
		node.left = new Node(node.data);
		node.left.left = oldLeft;
	}

	public boolean sameTree(BinaryTree other)
	{
		return (sameTree(root, other.root));
	}

	private boolean sameTree(Node a, Node b)
	{
		if(a == null && b == null)	return true;
		else if (a != null && b != null)
		{
			return( 
					a.data == b.data &&
					sameTree(a.left, b.left) &&
					sameTree(a.right, b.right)
				  );
		}
		else
			return false;
	}

	public int countTrees(int numKeys)
	{
		if(numKeys <= 1)
			return 1;
		else
		{
			int sum = 0;
			int left, right, root;
			for(root = 1; root <= numKeys; root++)
			{
				left = countTrees(root - 1);
				right = countTrees(numKeys - root);
				sum += left*right;
			}
			return sum;
		}
	}

	public boolean isBST1()
	{
		return isBST1(root);
	}

	private boolean isBST1(Node node)
	{
		if(node == null)	return true;
		if(node.left != null && maxValue(node.left) > node.data)
			return false;
		if(node.right != null && minValue(node.right) <= node.data)
			return false;
		return isBST1(node.left) && isBST1(node.right);
	}

	public boolean isBST2()
	{
		//return isBST2(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
		return isBST2(root, minValue(), maxValue());
	}

	private boolean isBST2(Node node, int min, int max)
	{
		if(node == null)
			return true;
		else
		{
			boolean leftOk = isBST2(node.left, min, node.data);
			if(!leftOk)
				return false;
			boolean rightOk = isBST2(node.right, node.data + 1, max);
			return rightOk;
		}
	}
}