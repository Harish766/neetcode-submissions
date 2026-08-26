class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold=-prices[0];
        int cash=0;
        for(int i=1;i<prices.size();i++){
            hold=max(hold,-prices[i]);
            cash=max(cash,hold+prices[i]);
        }
        return cash;
    }
};
