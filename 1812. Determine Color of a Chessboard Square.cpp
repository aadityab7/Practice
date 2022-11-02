class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a' + 1;
        int y = coordinates[1] - '0';
        
        if((x + y) % 2) return true;
        
        return false;
    }
};