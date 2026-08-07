# 344 Reverse String 

# Write a function that reverses a string. The input string is given as an array of characters s.

# You must do this by modifying the input array in-place with O(1) extra memory.

class Solution(object):
    def reverseString(self, s):
        left = 0 # points to the first element
        right = len(s)-1 # points to the last element 

        while left < right :
            s[left],s[right] = s[right],s[left] # swap the first element to last element 
            left += 1 # increment left most element 1st -> 2nd
            right -= 1 # decrement right most element 4th -> 3rd
        return s 
