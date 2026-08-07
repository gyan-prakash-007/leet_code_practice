# 557. Reverse Words in a String III
class Solution(object):
    def reverseWords(self, s):
        words = s.split() # split the string into a list of words 
        result = []

        for word in words:
            result.append(word[::-1]) # appending the reverse of each words in the empty list result 

        return " ".join(result) # converts a list of strings into a single sentence by joining each element with a space in between.

        
