# 125. Valid Palindrome
# A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

# Given a string s, return true if it is a palindrome, or false otherwise.

class Solution(object):
    def isPalindrome(self, s):
        left = 0 # points to the left most element 
        right = len(s)-1 #points to right most element 

        while left< right: # checing if left index is smaller than right 
            while left<right and not s[left].isalnum(): # checing if element at left most index is alphabet or numeric 
                left +=1 # if not alphabet or numeric we move to the next element 
            while left<right and not s[right].isalnum(): # checking if the elemrnt at right most element is alphabet or numeric 
                right -=1 # if not alphabet or numeric we move to the previous element 

            if s[left].lower()!= s[right].lower():# checking if left most elemet is equal to right most element 
                return False

            left +=1 # incrementing after left = right element 
            right -=1 # decrement after right = left element
        return True


# .isalnum() is used to check if the element is alphabet i.e a to b  or A to B or 0 to 9 .
# .lower() is used t convert upper case to lower case as a != A
