# 1704. Determine if String Halves Are Alike
# done in one go 
class Solution(object):
    def halvesAreAlike(self, s):
        n = len(s)
        vowel = "aeiou"
        count_a = 0
        count_b = 0
        for i in range(n//2):
            if s[i].upper() in vowel.upper():
                count_a += 1

        for i in range(n//2,n):
            if s[i].upper() in vowel.upper():
                count_b += 1

        if count_a == count_b:
            return True 

        return False 




        
