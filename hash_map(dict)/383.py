# 383. Ransom Note

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        freq = {}

        for i in magazine :
            freq[i] = freq.get(i,0)+1 # frequency counter for elements of magazine as we are trying to recreate ransomeNote from it 

        for j in ransomNote:
            if j not in freq:# if element i from RansomeNote is not in freq the return false 
                return False

            freq[j] -= 1 # if the element is in frequeny then we decrease its value by one  and it will help us check if the element is appearing more than ones 
            if freq[j] < 0 : # if the value of frequency becomes less than zero return false 
                return False

        return True 
