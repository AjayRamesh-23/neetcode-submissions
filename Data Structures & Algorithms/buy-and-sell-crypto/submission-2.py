class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        profit = 0
        l = 0
        r = 1
        while(l < r and r < len(prices)):
            profit = prices[r] - prices[l]
            if profit >= 0:
                max_profit = max(profit, max_profit)
                r = r + 1
            elif profit < 0:
                l = r
                r = l + 1
        return max_profit
            



            






