# 1588. Sum of All Odd Length Subarrays
# took the help of chat gpt 

class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        total = 0 

        for i in range(n):
            total_subarray = (i+1)*(n-i) # this formula gives the total number of subarray that contain the ith element 
            odd_count = (total_subarray+1)//2 # total number of odd subarrays that contain ith element 
            total += arr[i]*odd_count

        return total 
