#There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

#You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

 

class Solution(object):
    def largestAltitude(self, gain):
        current = 0 # starting from altitude o 
        max_alt = 0 

        for num in gain :
            current = current + num # summing the 2 consecutive altitude 
            if max_alt < current :
               max_alt = current # updating if max altitude is smaller than the current  

        return max_alt
