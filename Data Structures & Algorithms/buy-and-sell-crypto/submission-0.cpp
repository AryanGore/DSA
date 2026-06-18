class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0 , sell = 0 , maxp = INT_MIN;

        while(sell < prices.size()){
            if((prices[sell] - prices[buy]) < 0){
                buy++;
            }else{
                maxp = max(maxp , prices[sell] - prices[buy]);
                sell++;
            }
        }

        return maxp;
    }
};
