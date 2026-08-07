# 350. Intersection of Two Arrays II
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        freq_1 = {}
       
        intersection = []

        for i in  nums1 :
            freq_1[i] = freq_1.get(i,0)+1

        for i in nums2:
            if i in freq_1 and freq_1[i] > 0:
                intersection.append(i)
                freq_1[i] -=1 

        return intersection 
