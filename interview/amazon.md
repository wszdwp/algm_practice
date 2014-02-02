#questions
##Full-time

1. 	Given a number (not necessarily of type int), find if it is 2^n. What is the complexity?

2. 	Given a set of points represented by x and y coordinates, 
	find out the first k points that are closest to the origin. What is the complexity?

3. 	Given an array of integers, return the largest occurrence element times its array index. Do it in place. 
   	What is the complexity?

4. 	Given a binary tree(not necessarily BST), return the sum of all kth level nodes. What is the complexity? 

5. 
	What is the difference between a linked list and an array
	- Describe mergesort and its runtime
	- What is a hash table, hash function, runtimes, collision, etc.
	- What is a Binary Search Tree, runtimes... pros/cons vs hash table
	- Lowest Common Ancestor (See below)
	Interview Question – Imagine a data structure similar to a Binary Tree except, 
	rather than each node pointing to is lchild and rchild, it only points to its parent. 
	Write a function that, given two nodes into such a structure, returns their Lowest Common Ancestor 
	- the lowest node in the tree which where both subtrees meet.

6. 	Traverse a binary search tree, verify whether a given tree is a binary search tree or not. 
	Not the most difficult question, but make sure to know the details.  

7. 	Copying a tree

8.  Divide without the / operator
	Python solution:

	def div(a, b):
    """
    To divide a by b without / operator,
    assuming a >= 0 and b > 0.
    Result floored to the nearest integer.
    """

    c = 0
    d = b
    while True:
        if d > a:
            break
        else:
            c = c + 1
            d = d + b

    return c

9.	Emulate inorder BST tree traversal without using recursion

10.	phone interview, 2 parts, each part cost 50 minutes.
	first talk about my projects, and:
	Suppose there is array contains 100 unsorted elements ...say a[1] to a[100].
	find out the minimum and maximum value in the range of a[25] to a[75].
	second:
	You have got 2 strings(S1, S2) and 1 character(c1). All inputs to be taken from user. You need to check for the character c1 in String S1, and wherever you find the character, you need to replace it with the string S2.
	Next Write all possible test cases to test the program.
	It can be possible that the character c1 is appearing more than once in the String s1.
	Clause - You are not allowed to use any Java Library methods in it. Not even charAt() method.

11.	Given the following list of integers, how would you sort it the most efficiently 
	and weed out duplicates at the same time?

12. Find total number of nodes at level K.

13.	Asked two questions mainly on graph trees and algorithms and complexities





##internship
First question was tell me what you know about recursion. 
Then he asked me to code a function that returned the max integer in an array (no joke). 
Then a couple questions on sorting algorithms and how I would keep track of duplicates in an array, 
and how I would keep track of the indeces of duplicates in an array (hashset, hashmap).

given a node in a binary search tree, find the next highest value (in-order successor) 
assuming that the nodes have a parent link   
Answer Question
given the root of a binary search tree, return an array of the values in order   Answer Question
write a function to determine if a number is a palindrome  