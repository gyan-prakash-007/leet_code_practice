# 2085. Count Common Words With One Occurrence

class Solution(object):
    def countWords(self, words1, words2):
        freq1 = {}
        freq2 = {}

        for i in words1 :
            freq1[i] = freq1.get(i,0)+1

        for j in words2 :
            freq2[j] = freq2.get(j,0)+1
        count = 0
        for i in freq1:
            if freq1[i] == 1 and freq2.get(i,0) == 1: # chcecking the occurence of element i in freq1 and freq2 if its one then we increment counter by one 
                count +=1

        return count 
        
