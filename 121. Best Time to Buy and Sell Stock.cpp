class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = prices[0];
        int max_profit = 0;
        int curr_profit = 0;
        
        int n = prices.size();
        
        int curr;
        
        for(int i = 0; i < n; i++){
            curr = prices[i];
            
            if(curr > max){
                max = curr;
                curr_profit = max - min;
                
                if(curr_profit > max_profit){
                   max_profit = curr_profit;
                }
            }
            else if(curr < min){
                min = max = curr;
            }  
        }
        
        return max_profit;
        
    }
};