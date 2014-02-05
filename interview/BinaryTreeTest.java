public class BinaryTreeTest
{
	public static void main(String[] args)
	{
		BinaryTree tr1 = new BinaryTree();
		tr1.insert(5);
		tr1.insert(3);
		tr1.insert(7);
		tr1.insert(6);
		tr1.insert(9);
		tr1.insert(8);
		tr1.insert(10);
		tr1.insert(2);
		tr1.insert(1);
		tr1.insert(4);
		System.out.println("-------tree1-------");
		tr1.printTree();
		System.out.println("size of tr1 = " + tr1.size());
		System.out.println("maxDepth of tr1 = " + tr1.maxDepth());
		System.out.println("minValue in tr1 = " + tr1.minValue());
		System.out.println("tr1 has a path whose sum is 10(expected: true): " + tr1.hasPath(10));
		System.out.println("tr1 has a path whose sum is 100(expected: false): " + tr1.hasPath(100));
		System.out.println("print all the paths of tr1 : ");
		tr1.printPaths();
		System.out.println("mirror of the tr1 is :");
		tr1.mirror();
		tr1.printTree();
		tr1.mirror();
		System.out.println("check if tr1 is a BST(expected: true): " + tr1.isBST1());
		System.out.println("check if tr1 is a BST(expected: true): " + tr1.isBST2());

		BinaryTree tr2 = new BinaryTree();
		tr2.build123();
		System.out.println("-------tree2-------");
		tr2.printTree();
		System.out.println("maxDepth of tr2 = " + tr2.maxDepth());
		System.out.println("minValue in tr2 = " + tr2.minValue());
		System.out.println("tr2 has a path whose sum is 4(expected: false): " + tr2.hasPath(4));
		System.out.println("tr2 has a path whose sum is 5(expected: true): " + tr2.hasPath(5));
		System.out.println("print all the paths of tr2 : ");
		tr2.printPaths();
		
		System.out.println("tr1 & tr2 is the same tree(false): " + tr1.sameTree(tr2));
		System.out.println("tr1 & tr1 is the same tree(true): " + tr1.sameTree(tr1));
		System.out.println("tr2 & tr2 is the same tree(true): " + tr2.sameTree(tr2));		

	}	
}