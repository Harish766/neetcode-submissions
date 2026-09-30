class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit=0;
        int min_price=prices[0];
        for(int i=1;i<prices.size();i++){
            min_price=min(min_price,prices[i]);
            int curr = prices[i]-min_price;
            maxProfit=max(maxProfit,curr);
        }
        return maxProfit;
    }
};
