import random

def findMaxRepeat(s, k):
	for i in range(0, len(s)):
		s[s[i]%k] += k;
	return s.index(max(s))


s = []
for i in range(0, 10):
	s.append(random.randint(0, 10))	

print(s)
k = max(s)
print(findMaxRepeat(s, k))

