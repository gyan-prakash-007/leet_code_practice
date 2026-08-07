# 2379. Minimum Recolors to Get K Consecutive Black Blocks
# easy question brain did it on auto piolet 


class Solution(object):
    def minimumRecolors(self, blocks, k):
        window_colour = blocks[:k]
        colour_black = 0
        
        for i in range(k):
            if blocks[i] == "W":
        
                
                colour_black += 1
        max_colour = colour_black
           
        for i in range(k,len(blocks)):
            window_colour = blocks[i-k:i]
            if blocks[i] == "W":
                
                colour_black += 1
            if blocks[i-k] == "W":
                
                colour_black -= 1
            max_colour = min(max_colour,colour_black)

        return max_colour  
