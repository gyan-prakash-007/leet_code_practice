# Two Sum
class Solution(object):
    def twoSum(self, nums, target):
        mp = {}# initialising a dictionary / hashmap 

        for i , num in enumerate(nums):
            need = target - num # finding the other numbebr that we will need 

            if need in mp : # checking if the other number is already present in the hash map 
                return [ mp[need],i] # returning the index of both numbers 
            mp[num] = i # if the number doest not exist in hash map then put nums in dict with its index 
        
