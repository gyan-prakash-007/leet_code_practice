#1991. Find the Middle Index in Array 
# same quesion as 724 
# copy paste 

class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        totalsum= sum(nums)
        leftsum =0 

        for i in range(len(nums)):
            if leftsum == totalsum - leftsum - nums[i]:
                return i
            leftsum +=nums[i]
        return -1
        
