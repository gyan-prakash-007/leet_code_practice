# 1657. Determine if Two Strings Are Close
class Solution(object):
    def closeStrings(self, word1, word2):
        if len(word1) != len(word2): # check if the string lengths are equal or not 
            return False 
        
        freq1 = {}
        freq2 = {}

        for i in word1:
            freq1[i] = freq1.get(i,0)+1
        for j in word2 : 
            freq2[j] = freq2.get(j,0)+1

        for i in word1 : # checking ig the elements of string one is present in the string 2
            if i not in freq2 :
                return False 

        for j in word2: # checking if the elements of string 3 is presetn in string one 
            if j not in freq1:
                return False 

        if sorted(freq1.values()) != sorted(freq2.values()): # frequencies of elements are equal or not regardless of the elements 
            return False

        return True 
        
