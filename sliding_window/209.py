# 209. Minimum Size Subarray Sum

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0 # setting the left pointer to zero 
        current_sum= 0 #current sum is zero  
        min_len = len(nums)+1 # setting the minimum lenght of array to the number of elements +1
        for right in range(len(nums)): # traversing the list from first elemet to last element 
            current_sum += nums[right] # adding the elements 

            while current_sum>= target: # checking if the current element is greater than or eual to the target 
                min_len = min(min_len,right-left+1) # if the condition is satisfied , setting the minimum lenght of sub array 
                current_sum -= nums[left] # subtracting the left most element of suarray 
                left+=1 #incrementing the left pointer 

        if min_len == len(nums) +1: # if the min lenght of subarray dudnt change 
            return 0 #return 0
        return min_len
            
