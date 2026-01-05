# 4. Median of Two Sorted Arrays
# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

# The overall run time complexity should be O(log (m+n)).

# very easy question idk why it was in hard level 

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        nums3 = nums1+nums2 # merging two given array 
        nums3.sort()# sorting the new array 
        n = len(nums3) 
        if n % 2 == 0: # if number of elements in the new array is even 
            return (nums3[n//2-1]+nums3[n//2])/2.0 # return the average of 2 middle elements 
        else: # if the number of elements is odd in the new array is odd 
            return float(nums3[n//2]) # return the middle elemet
