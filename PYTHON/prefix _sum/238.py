# 238. Product of Array Except Self

class Solution(object):
    def productExceptSelf(self, nums):
        
        n = len(nums)

        suffix = [1]*n
        prefix = [1]*n
        answer = [1]*n

        for i in range(1,n):
            prefix[i] = prefix[i-1]*nums[i-1] # calculate the product of numbers ahead of index i 

        for i in range(n-2,-1,-1):
            suffix[i] = suffix[i+1]*nums[i+1] # calculate the product of numbers previous to index i 
        
        for i in range(n):
            answer[i] = prefix[i]*suffix[i]

        return answer
