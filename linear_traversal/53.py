# my first medium level question 
# 53. Maximum Subarray

# sloved using Kadane’s Logic :Is it better to extend the previous subarray or start fresh from this element?

class Solution(object):
    def maxSubArray(self, nums):
        current_sum = nums[0] # keep track of sum for every iteration 
        global_maximum = nums[0] # track the best seen so far 
        
        for i in range(1,len(nums)) : # loop start from index  prevent double counting 
            if current_sum + nums[i] > nums[i]:
                current_sum = current_sum + nums[i] # extend the sub array if the sum of sub array is greater than current element
            else:
                current_sum = nums[i] # if current element is greater than sum then start fresh form the current element 
            if global_maximum < current_sum:
                global_maximum = current_sum # updating the global max for each element 

        return global_maximum
