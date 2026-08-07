# 28. Find the Index of the First Occurrence in a String
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)
        for i in range(n):
           if haystack[i:i+m] == needle : # using string slicking to match if the needle is present in the haystack or not it checks ith element to i+mth element if its equal t needle or not 
            return i


        return - 1
