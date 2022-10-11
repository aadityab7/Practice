class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int bx = rec1[0], by = rec1[1], tx = rec1[2], ty = rec1[3];
        
        if(rec2[0] > bx) bx = rec2[0];
        if(rec2[1] > by) by = rec2[1];
        if(rec2[2] < tx) tx = rec2[2];
        if(rec2[3] < ty) ty = rec2[3];
        
        //find the area of intersecting rectangle
        
        int x = tx - bx, y = ty - by;
        
        if(x > 0 && y > 0) return true;
        
        return false;
    }
};

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        
        return (
            (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]))
            && 
            (min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]))
        );
        
    }
};