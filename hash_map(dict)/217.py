
217. Contains Duplicate
# first answer not optimised 
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        freq = {}
        for i in nums :
            freq[i] = freq.get(i,0)+1
        
        for i in nums:
            if freq[i] >= 2 :
                return True 

        return False

# second attemp 
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        freq = {}
        for i in nums :
            if freq.get(i,0) >= 1 :
                return True 
            freq[i] = 1

        return False

        
      
        
