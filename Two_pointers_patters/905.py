# 905. Sort Array By Parity

# Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

# Return any array that satisfies this condition.

# even number goes left odd number goes right 
class Solution(object):
    def sortArrayByParity(self, nums):
        left = 0 
        right = len(nums)-1
        nums2 = [0]*len(nums)

        for num in nums: # iterate through every elements from left to right 
            if num %2 == 0: # chceck if the left mmost element is even or not
                nums2[left] = num # if even assign to the output array 
                left +=1 #increment the left pointer 
            else :
                nums2[right]= num # if not even assign the number to the right most element of output array 
                right -=1 # decrement the right pointer 
        return nums2

_________________________________________________________________________________________________________________________________________
  # another way to do this 
class Solution(object):
    def sortArrayByParity(self, nums):
        left = 0 
        right = len(nums)-1

        while left < right : # terminates when left is greater than right 

            if nums[left] %2== 1 and nums[right] %2 ==0: # swap the position of left element and right element if left is odd and right is even
                nums[left], nums[right] = nums[right] , nums[left]

            if nums[left]%2==0:# increment left if left element is even after swapping 
                left += 1
            if nums[right]%2==1:# decrement right if right element is odd
                right -= 1

        return nums

                
