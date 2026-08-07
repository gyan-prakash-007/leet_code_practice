# 724. Find Pivot Index
# simple question just have to subtract left sum and the element at present index 
class Solution(object):
    def pivotIndex(self, nums):
        totalsum= sum(nums) # calcculate the total sum of the array 
        leftsum =0 #initializing the left sum to zero 

        for i in range(len(nums)): 
            if leftsum == totalsum - leftsum - nums[i]: # checking if the sum of elements to the right of the index is equal to left sum 
                return i # return index if condition is true 
            leftsum +=nums[i] # if condition is not full filled then add the ith element in left sum
        return -1 #return - 1 as instructed in the question 

#peace 
        
