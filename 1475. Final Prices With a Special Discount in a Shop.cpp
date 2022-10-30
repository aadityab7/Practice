class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        int flag;
        
        for(int i = 0; i < prices.size(); i++){
            flag = 1;
            for(int j = i + 1; j < prices.size(); j++){
                if(prices[j] <= prices[i]){
                    ans[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        stack<int> st;
        
        for(int i = 0; i < prices.size(); i++){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                ans[st.top()] -= prices[i]; 
                st.pop();
            }
            
            st.push(i);
        }
        
        return ans;
    }
};