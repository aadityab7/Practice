class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //if they are in a straight line then area = 0
        //and ans = false;
        //else ans = true;
        
        //area = (x1 (y2 - y3) + x2(y3 - y1) + x3(y1 - y2));
        
        int a = (points[0][0] * (points[1][1] - points[2][1]));
        int b = (points[1][0] * (points[2][1] - points[0][1]));
        int c = (points[2][0] * (points[0][1] - points[1][1]));
        
        if(a + b + c == 0) return false;
        
        return true;
    }
};

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //if they are in a straight line then area = 0
        //and ans = false;
        //else ans = true;
        
        //area = (x1 (y2 - y3) + x2(y3 - y1) + x3(y1 - y2));
        
        int area = 
            (points[0][0] * (points[1][1] - points[2][1])) + 
            (points[1][0] * (points[2][1] - points[0][1])) +
            (points[2][0] * (points[0][1] - points[1][1]));
        
        if(area) return true;
        
        return false;
    }
};
