class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq_s = {} # frequency of s 
        freq_t = {} # frequency of t 

        for i in s :
            freq_s[i] = freq_s.get(i,0)+1
        for j in t :
            freq_t[j] = freq_t.get(j,0)+1
        
        if freq_s == freq_t:
            return True 

        return False 
