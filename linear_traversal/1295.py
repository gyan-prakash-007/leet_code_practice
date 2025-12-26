# Even Number of digits 
class Solution(object):
    def findNumbers(self, nums):
        i = 0                     
        for number in nums:
            s = str(number)
            if len(s) % 2 == 0:
                i += 1
        return i
