# 121. Best Time to Buy and Sell Stock

class Solution(object):
    def maxProfit(self, prices):
        buy_price = prices[0] # price at first index / day 1
        max_profit = 0 # initialising the profit to 0 

        for price in prices : # iterating through all prices from first index 
            if price < buy_price: # checing if the current price is lower than previous price 
                buy_price = price# update the current price if the current price is lower than the previous price  
            else: # current price is higher than previous price 
                max_profit = max(max_profit,price-buy_price) # calculaing profit and comparing it to previous profit 
        return max_profit # returing the profit / 0 if no profit 
