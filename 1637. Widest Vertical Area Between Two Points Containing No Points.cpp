//USING SET - 380 ms
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> st;

        for(vector<int> x : points) st.insert(x[0]);

        int ans = 0;
        
        auto itr = st.begin();
        int prev = *itr;
        itr++;

        for(; itr != st.end(); itr++){
            if(*itr - prev > ans) ans = *itr - prev;
            prev = *itr; 
        }

        return ans;
    }
};

//using vector and sorting - 235 ms
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = 0;
        vector<int> x(points.size());
        for(int i = 0; i < points.size(); i++) x[i] = points[i][0];

        sort(x.begin(), x.end());

        for(int i = 1; i < x.size(); i++)
            ans = max(ans , x[i] - x[i - 1]);

        return ans;
    }
};