"""
Given two different strings, find the common characters between the two. 
For example if string A is "hello" and string B is "elbow" the common characters would be ['e', 'l', 'o']. 
Give a method that returns unique or duplicate entries.

"""

def findDupChars(s1, s2):
    s1set = set()
    s2set = set()
    [s1set.add(c) for c in s1]
    [s2set.add(c) for c in s2]  
    return s1set.intersection(s2set)

print findDupChars("string", "ring")