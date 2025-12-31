# 11. Container With Most Water

class Solution(object):
    def maxArea(self, height):
        left = 0 
        right = len(height)- 1
        max_area = 0

        while left < right :
            lenght = min(height[left],height[right])
            width = right - left

            area = width*lenght
            if max_area < area:
                max_area = area
            if height[left]< height[right]:
                left +=1
            else:
                right -=1

        return max_area
        
