class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int maxProfit = 0;

        while(sell < prices.size()){
            maxProfit = max(maxProfit, prices[sell] - prices[buy]);
            if(prices[buy] > prices[sell]){
                buy = sell;
            }
            sell++;
        }

        return maxProfit;
    }
};
