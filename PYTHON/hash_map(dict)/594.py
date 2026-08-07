# 594. Longest Harmonious Subsequence
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        freq = {}

        for i in nums :
            freq[i] = freq.get(i,0)+1

        ans = 0

        for i in nums :
            if i+1 in freq: # checking the occurance of elements whose difference is 1 
                ans = max(ans , freq[i]+ freq[i+1]) # maximising the count of elements thats difference is one 

        return ans 
        
