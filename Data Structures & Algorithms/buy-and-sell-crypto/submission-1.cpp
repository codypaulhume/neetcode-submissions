class Solution {
public:
    // Brute force - O(n^2)
    // int maxProfit(vector<int>& prices) {
    //     int profit = 0;
    //     for(int i = 0; i < prices.size(); i++){
    //         for(int j = i+1; j < prices.size(); j++){
    //             int difference = (-1*prices[i])+prices[j];
    //             if(difference > profit){
    //                 profit = difference;
    //             }
    //         }
    //     }
    //     return profit;  
    // }

    // O(n) method. Use pointers (left and right). Left is always pointing at the smallest number by 
    // comparing its value to the right. If it is less, then calculate profit and update maxProfit if
    // it is the max. If the right value is smaller, update left to be right.
    // Finally, iterate to next right value.
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;

        while(right < prices.size()){
            if(prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            }else{
                left = right;
            }
            right++;
        }
        return maxProfit;
    }
};
