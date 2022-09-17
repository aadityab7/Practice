class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4){
            return true;
        }
        
        return false;
        
    }
};

/*
1 w
2 w
3 w
4 l
5 w
6 w
7 w
8 l
9 

*/