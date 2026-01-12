# 190. Reverse Bits
# in this question we have to convert the integer n into binary representation and reverse the binary and ND RETURN the new integer that is formed
class Solution(object):
    def reverseBits(self, n):
        x = bin(n)[2:]# convert the integer n into binary [2:] removes 0b from the representation 

        x = x.zfill(32) # .zfill pads the integer with zero from starting till there are 32 bits used

        y = x[::-1] # reverse the string 

        z = int(y,2) # convert the binary into integer 

        return z
        
