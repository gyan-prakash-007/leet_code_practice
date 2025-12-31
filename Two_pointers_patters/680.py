#680 Valid Palindrome II
# Given a string s, return true if the s can be palindrome after deleting at most one character from it.
# re do 
class Solution(object):
    def validPalindrome(self, s):
        left = 0
        right = len(s) - 1

        while left < right:
            if s[left] != s[right]:

                
                l1, r1 = left + 1, right
                while l1 < r1 and s[l1] == s[r1]:
                    l1 += 1
                    r1 -= 1

               
                l2, r2 = left, right - 1
                while l2 < r2 and s[l2] == s[r2]:
                    l2 += 1
                    r2 -= 1

                return l1 >= r1 or l2 >= r2

            left += 1
            right -= 1

        return True
