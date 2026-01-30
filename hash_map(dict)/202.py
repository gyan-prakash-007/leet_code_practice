# 202. Happy Number
# Input: n = 19
# Output: true
# Explanation:
# 12 + 92 = 82
# 82 + 22 = 68
# 62 + 82 = 100
# 12 + 02 + 02 = 1
class Solution(object):
    def isHappy(self, n):
        seen = {}

        while n != 1 :
            if n in seen :
                return False 
            seen[n] = 1

            total = 0

            while n > 0 :
                digit = n % 10 
                total += digit * digit 
                n //= 10 

            n = total

        return True  

                
            
            

        
