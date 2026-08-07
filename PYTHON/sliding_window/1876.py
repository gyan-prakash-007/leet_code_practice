#1876. Substrings of Size Three with Distinct Characters

class Solution(object):
    def countGoodSubstrings(self, s):
        count = 0 # counter for number of good substrings
        left = 0 # first element of string 

        for right in range(2,len(s)):
          # it can be also seen as window left and left+1 is window element , right is the element entering window and left is leaving window 
            a=s[left] #first element 
            b=s[left+1] # second element
          
            c=s[right] # third element 

            if a!=b and b!=c and c!= a:
                count +=1

            left +=1

        return count 
