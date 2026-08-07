# The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

# Given two integers x and y, return the Hamming distance between them.
class Solution(object):
    def hammingDistance(self, x, y):
        xor = x^y# return 1 if bits are different 
        count = 0 
# count the number of 1s in the bunary number 
        while xor > 0 :
            count += xor &1
            xor = xor >> 1
        return count 
