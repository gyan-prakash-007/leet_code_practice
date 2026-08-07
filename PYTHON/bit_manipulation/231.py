# Given an integer n, return true if it is a power of two. Otherwise, return false.

# An integer n is a power of two, if there exists an integer x such that n == 2x.

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n > 0 and n & (n-1) == 0: # check if number is non negative and not 0 and n & (n-1) == 0
            return True 
        return False

# n & (n-1) for a power of 2 there is only one 1 present in the binary representation 
# 2 = 10
# 4 = 100
# 8 = 1000

# n - 1 = 4 - 1 = 3 = 011 

# so n & (n-1) always gives 0s in binary representation 
