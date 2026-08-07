# 771. Jewels and Stones
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        mp = {} # created a dictionary 
        count = 0  # initializing count to 0 

        for j in jewels : # looping each elemets of strig jewels 
            mp[j] = True # storing the elements of jewels as key with value true 

        for s in stones: # looping through elements of stones 
            if s in mp : # if s is present in hashmap mp 
                count += 1 # count + 1
        return count 
            
        
