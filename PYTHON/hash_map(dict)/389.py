# 389. Find the Difference
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        freq = {}

        for i in s:
            freq[i] = freq.get(i,0)+1

        for j in t:
            if j not in freq :
                return j 

            freq[j] -= 1

            if freq[j] < 0 :
                return j
        
