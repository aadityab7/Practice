class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans = 0, max = 0, x;
        
        for(int i = 0; i < rectangles.size(); i++){
            x = rectangles[i][0];
            if(x > rectangles[i][1]) x = rectangles[i][1];
            
            
            if(x == max) ans++;
            else if(x > max){
                ans = 1;
                max = x;
            }
        }
        
        return ans;
    }
};