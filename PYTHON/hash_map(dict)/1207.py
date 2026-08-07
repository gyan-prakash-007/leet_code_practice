class Solution(object):
    def uniqueOccurrences(self, arr):
        freq = {}

        for i in arr :
            freq[i] = freq.get(i,0)+1

        freq_count = {}

        for j in freq.values():
            freq_count[j] = freq_count.get(j,0)+1
            if freq_count[j]>1:
                return False



        return True
