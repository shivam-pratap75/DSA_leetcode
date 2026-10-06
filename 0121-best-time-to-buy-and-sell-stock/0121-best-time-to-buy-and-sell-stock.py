class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        answer=-1
        buy=prices[0]
        sell=prices[0]
        for i in range(len(prices)):
            sell=prices[i]

            answer=max(answer,sell-buy)
            buy=min(buy,prices[i])

        return answer    

        