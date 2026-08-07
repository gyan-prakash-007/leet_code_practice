# Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
# its easy quetion just need to take an array of integers from 0 to n and count the number of 1s in the binary representation of each number  
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans=[] # initialise an empty array 
        for i in range(n+1): # traversing the array from 0 th index to nth index
            ans.append(bin(i).count('1')) # appending the number of 1s for each element in ans

        return ans
