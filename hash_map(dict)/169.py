# 169. Majority Element
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq = {}
        n =  len(nums)/2

        for i in nums:
            freq[i] = freq.get(i,0)+1

            if freq[i] >n:
                return i
        
