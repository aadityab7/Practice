class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = area, w = 1;
        vector<int> ans(2);
        
        while(l >= w){
            if(area == (l * w)){
                ans[0] = l;
                ans[1] = w;
            }
            
            w++;
            l = area / w;
        }
        
        
        return ans;
    }
};

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        
        while(area % w != 0) w--;
        
        return {area / w, w};
    }
};