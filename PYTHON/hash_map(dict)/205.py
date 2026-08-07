# 205. Isomorphic Strings
# have to prove that it is bijective 
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        freq_s = {}
        freq_t = {}

        if len(s) != len(t):
            return Flase

        for i in range(len(s)):
            c1 = s[i]
            c2 = t[i]

            if c1 in freq_s and freq_s[c1] != c2:
                return False
            if c2 in freq_t and freq_t[c2] != c1:
                return False

            freq_s[c1] = c2
            freq_t[c2] = c1

        return True 

