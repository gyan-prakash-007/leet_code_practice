# Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight
# number of 1s in the binary representation of a number 

   count = 0 
        while n > 0 : # iterate throught all the bits of the number 
            count += n &1 # count + 1 if the bit is 1 
            n = n >> 1      # right shift 
        return count # return count 

# alternate method 
return bin(n).count('1')
# bin converts integer into binary n 
# .count('1') counts number of 1s in the number 
