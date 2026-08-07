# 1984. Minimum Difference Between Highest and Lowest of K Scores

class Solution(object):
    def minimumDifference(self, nums, k):
        if k == 1 :
            return 0 # return 0 if there is only one elemet is present in the list 

        nums.sort() # sort all the elemets of the list 
        answer = nums[k-1]-nums[0] # calculate the difference of first and last element of list 

        for i in range(1,len(nums)-k+1): # checking the elemets except first and last
            answer = min(answer,nums[i+k-1]-nums[i])# checking the rest elements

        return answer
