# 645. Set Mismatch

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        freq = {}

        for i in nums :
            freq[i] = freq.get(i,0)+1

        missing = -1 
        duplicate = -1 
        n = len(nums)

        for i in range(1,n+1):
            if i not in freq:
                missing = i 

            elif freq[i] != 1:
                duplicate = i

        return [duplicate,missing]
        
