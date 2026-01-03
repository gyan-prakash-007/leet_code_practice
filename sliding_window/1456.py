# 1456. Maximum Number of Vowels in a Substring of Given Length
# mwdium level question 
# Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

# Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

class Solution(object):
    def maxVowels(self, s, k):
        vowel = "aeiouAEIOU" # a string containig all vowels for comparision 
        window_vowel = 0 # sum of all number vowels in k elements 

        for i in range(k):# for loop to calculate number of vowels in first k elements of list s
            if s[i] in vowel: # comparing all k elements in list s if they are vowel or not 
                window_vowel +=1 # if vowel increment the window to 1 
        max_vowel = window_vowel  # storing the number of vowels in first k elements of list s in max_vowel for comparision 

        for i in range(k,len(s)): # sliding window concept start from here
            if s[i] in vowel: # checking the k+1 element of s if it is vowel or not 
                window_vowel += 1 # if vowel then increment 
            if s[i-k] in vowel : # chceking the i-k element if its vowel // this element is outside of window 
                window_vowel -= 1# if it is vowel then we decrement the value by 1 

            max_vowel = max(max_vowel,window_vowel) # checking if the current window_vowel is greater than max_vowle if its greater than update the value if not then keep it 
          

         return max_vowel # return the value of max_vowel 
