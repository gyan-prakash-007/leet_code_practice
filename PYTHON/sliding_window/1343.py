# 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
# medium level question
# Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.



class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        window_sum = sum(arr[:k]) # storing the sum of first k elements of list arr in window_sum
        max_sum = window_sum # storing the value of window_sum 
        num_subarrays = 0 # variable to calculate number of sub arrays that full fill our conditions
        if window_sum//k >= threshold:# checking if the sum of fist k elements is greater than or equal to the threshold value  
            num_subarrays +=1 # incrementing if the conditions are satisfied 

        for i in range(k,len(arr)): # checking the elements after the kth element 
            window_sum += arr[i] # adding the k+1 element in window_sum as we sliding the wiondow one element at a time
            window_sum -= arr[i-k]# subtracting the k -i element from the window_sum as it is out of window now 
            avg = window_sum//k # calculating the average of k elemets in window 
            if avg >= threshold: # checking threshould condition
                num_subarrays += 1 # incrementing the value of num_subarray is threshold codition is satisfied 

        return num_subarrays 



        
