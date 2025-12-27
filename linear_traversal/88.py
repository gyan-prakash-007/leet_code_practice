# 88. Merge Sorted Array

class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i = m - 1 # index of last non zero element in nums1
        j = n - 1 # index of last element of nums2
        k = m + n -1 # index of last element of nums1 

        while j >= 0 :
            if i >=0 and nums1[i]>nums2[j]: # comparing the last element of nums1 to nums2
                nums1[k] = nums1[i] # if the element of last element of nums1 is greater than nums 2 append nums1[i] at nums[k]
                i -= 1 # decrement i

            else: 
                nums1[k]= nums2[j] # if the last element of nums2 is greater than nums1 then append the value of nums2[k] in nums1[k]
                j -= 1 #decrement j

            k -= 1
        return nums1
