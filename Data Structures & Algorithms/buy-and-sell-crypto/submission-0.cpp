class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i+1; j < prices.size(); j++){
                int difference = (-1*prices[i])+prices[j];
                if(difference > profit){
                    profit = difference;
                }
            }
        }
        return profit;  
    }
};
