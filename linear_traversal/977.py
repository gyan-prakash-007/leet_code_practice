#977. Squares of a Sorted Array
class Solution(object):
    def sortedSquares(self, nums):
        squares = []
        for number in nums:
            x = number*number # squaring the numbers 
            squares.append(x) # putting the number in wmoty list squares
        squares.sort() # sorted the already created list 
        return squares
