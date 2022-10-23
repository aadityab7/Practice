class Solution {
public:
    vector<int> sumZero(int n) {
        //if odd start from n / 2 and go to 0 
        vector<int> ans;
        
        int x = n / 2;
        
        for(int i = x; i > 0; i--){
            ans.push_back(-i);
        }
        
        if(n % 2) ans.push_back(0);
        
        for(int i = 1; i <= x; i++){
            ans.push_back(i);
        }
        
        return ans;
        
    }
};

/*
odd
0
-1 0 1
-2 -1 0 1 2

even
skip 0

*/