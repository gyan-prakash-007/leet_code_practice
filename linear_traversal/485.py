#2026's first question 
#485. Max Consecutive Ones
class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        current = 0 # setting the current sum to zero 
        max_count = 0 # maximum count of 1s
        for i in nums : # traversing through all elements of list  
            if i == 1: 
                current += 1 # incrementing the current counter if the element is 1 
                max_count = max(current,max_count)  # ggetting maximum of current sum and max sum and updating the max sum 

            else :
                current = 0 # current counter to zero if the element is 0 

        return max_count
            
            

        
