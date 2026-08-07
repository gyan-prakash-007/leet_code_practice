# 2485. Find the Pivot Integer
# same question as 724 
class Solution:
    def pivotInteger(self, n: int) -> int:
        left_sum = 0
        total_sum = n*(n+1)//2

        for i in range(1,n+1):
            if left_sum == total_sum - left_sum -i:
                return i

            left_sum += i

        

        return - 1
        
