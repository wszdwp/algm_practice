#questions
##Full-time

1. 	Given a number (not necessarily of type int), find if it is 2^n. What is the complexity?
	O(logk)

2. 	Given a set of points represented by x and y coordinates, 
	find out the first k points that are closest to the origin. What is the complexity?

3. 	Given an array of integers, return the largest occurrence element times its array index. 	 Do it in place. 
   	What is the complexity?

4. 	Given a binary tree(not necessarily BST), return the sum of all kth level nodes. What is the complexity? 
	O(2^K)

5. 	What is the difference between a linked list and an array
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

	`def div(a, b):
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

    return c`

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

14.	An arrays of integers is there which has all elements present odd number of times, 
	only one element is present even number of times, find the number.

15.	Sorting in linear time 
	http://en.wikipedia.org/wiki/Pigeonhole_sort
	http://en.wikipedia.org/wiki/Radix_sort

16.	Given an int K and a list of 2-D (x,y) points, write a piece of code 
	that will return the K closest points to the origin (which is the point(0,0))

17.	 write a program to connect two people in a social network

18.	Implementing least-recently-used cache. Because I didn't have experience with cache techniques,
	so I got an awkward moment with the interviewee explaining the LRU cache.  

19.	Combinations of nodes in BST based on the sum. Like display all the nodes whose key values sum to 10 

20.	Design a database that fit specific criteria.

21.	Write a power function. All edge cases like overflow, different values of powers (+ve, -ve, zero) 
	need to be handled. Have to give most efficient solutions.

22.	 Write a function that, given an array and a number as input, 
	 finds all pairs in the array that add up to that number. 
	 Number can be +ve/-ve. Write most space (or) time efficient algorithm. 
	 How will it handle duplicate pairs.

23.	On-site interviews:

	1. Given a 2D array (which has initially all false values), fill it up with 'X' true values placed randomly in it (like minesweeper game). Most efficient alog expected with handling of ALL edge cases.

	2. Implement a simple contacts application in which one can search via First name. Most efficient alog expected with handling of ALL edge cases.

	3. Bar-raiser: Given a log file from a website which contains the user ID and the accessed URL, find the TOP "sequence" of 3 urls amongst ALL visitors of the website. The sequence of urls have to be in sequence as they are accessed.

	4. Experience related questions by Team manager over lunch.

	5. Implement classes for a website that can be used for building your own computer. Eg: If a user selects a motherboard, it should filter out all the incompatible CPUs etc. You have to implement various classes that can be used for implementing this functionality.
	Interview Question – Bar-raiser was difficult and unexpected (to me) as I'm from embedded application dev background and haven't dealt with such scenario's. 


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

1) Reverse a string
2) Print multiplication tables from 1 to 12
3)	Print a grid of the form
	1 2 3 4 5 6 7 8 9 10 11 12
	2 4 6 8 10 12 14 16 18 20 22 24
	3 6 9 12 15 18 21 27 27 30 33 36
	.
	.
	.
	.
	.
	.
	12

generate sample math problems(additions) for a 8th grade student and 
the results should be stored in such a way that they can be printed 
when required. Sample problem is 7+8=_____
printed when required. Sample problem is 7+8=_____
The constraints are:-
1) The numbers that are to be added should be <=9
2) The result should be <=17


Given two different strings, find the common characters between the two. 
For example if string A is "hello" and string B is "elbow" the common characters would be ['e', 'l', 'o']. 
Give a method that returns unique or duplicate entries.

Solu1: java
public class StringIntersection {
    String str1 = "hello";
    String str2 = "elbow";

    public Set findIntersection() {
        String[] arr1 = str1.split("");
        String[] arr2 = str2.split("");

        List<String> list = Arrays.asList(arr1);

        Set<String> set = new LinkedHashSet<String>(Arrays.asList(arr1));
        set.retainAll(Arrays.asList(arr2));

        set.remove("");

        return set; // returns [e, l, o]
    }
}

Solu2: python
def duplicateChars(s1, s2):
    s1set = set()
    s2set = set()
    for c in s1:
        s1set.add(c)
    for c in s2:
        s2set.add(c)

    return s1set.intersection(s2set)

print duplicateChars("string", "ring")

The last/hardest question I was asked was how to do an in order tree traversal

Write a function to remove all redundant characters in a given string. 

