from collections import defaultdict  #A defaultdict automatically creates a default value if a key does not exist.
class Solution(object):
    def groupAnagrams(self, strs):
       

        anagram_map = defaultdict(list) # created a dict with key as the sorted version of word and list of anagram 
        result = []

        for s in strs :
            sorted_s = tuple(sorted(s)) # sort the words in alphabetical order and convert it into a tuple as the mutable data type cannot be a key in dict 
            anagram_map[sorted_s].append(s) # append the anagram words with respect to the key         
        for value in anagram_map.values(): # traverse the values in the dictionary 
            result.append(value) # append the values in result array 

        return result
