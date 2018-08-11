/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1

Input [7,1,5,3,6,4]
Output 7
Explanation Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2

Input [1,2,3,4,5]
Output 4
Explanation Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3

Input [7,6,4,3,1]
Output 0
Explanation In this case, no transaction is done, i.e. max profit = 0.
*/



/*
    Basic strategy: buy in the beginning of ascending stock market (牛市) and sell at the beginning of desending stock market (熊市).
    Keep track of the trend of the array.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        bool stock_ascend = false;
        int len = prices.size();
        int recent_buy_day = 0;
        for (int i = 0; i < len - 1; i++) {
            if (stock_ascend) {  // stock price is ascending
                if (prices[i + 1] < prices[i]) {  // next day stock price will decend
                    stock_ascend = false;
                    max_profit += prices[i] - prices[recent_buy_day];
                }  // if (prices[i + 1] >= prices[i]), correspond with (stock_ascend == true), so just do nothing
            } else {  // stock price is decending
                if (prices[i + 1] >= prices[i]) {  // next day stock price will ascend
                    stock_ascend = true;
                    recent_buy_day = i;
                }  // if (prices[i + 1] < prices[i]), correspond with (stock_ascend == false), so just do nothing
            }
        }
        if (stock_ascend && len >= 2) {
            max_profit += prices[len - 1] - prices[recent_buy_day];
        }
        return max_profit;
    }
};