# 686. Repeated String Match
class Solution(object):
    def repeatedStringMatch(self, a, b):
        rep = a
        count = 1 

        while len(rep) < len(b):
            rep += a 
            count += 1 

        if b in rep :
            return count

        rep +=a 
        count +=1

        if b in rep:
            return count 

        return -1
        
        
