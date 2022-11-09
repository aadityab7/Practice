class StockSpanner {
    vector<int> arr;
    int x;
public:
    StockSpanner() {
        x = -1;
    }
    
    int next(int price) {
        arr.push_back(price);
        x++;
        
        int ans = 0;
        int i = x;
        
        while(i >= 0 && arr[i] <= price){
            ans++;
            i--;
        }
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner {
    stack<pair<int, int>> st;
public:
    
    int next(int price) {
        int ans = 1;
        
        while(!st.empty() && st.top().first <= price){
            ans += st.top().second;
            st.pop();
        }
        
        st.push({price, ans});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner {
public:
    int ans;
    stack<pair<int, int>> st;
    int next(int price) {
        ans = 1;
        
        while(!st.empty() && st.top().first <= price){
            ans += st.top().second;
            st.pop();
        }
        
        st.push({price, ans});
        
        return ans;
    }
};