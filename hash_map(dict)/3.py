class Solution(object):
    def lengthOfLongestSubstring(self, s):
        freq = {}
        left = 0 
        max_len = 0 

        for right in range(len(s)):
            if s[right] in freq and freq[s[right]] >= left :
                left = freq[s[right]]+1

            freq[s[right]] = right 
            max_len = max(max_len,right - left +1)

        return max_len
