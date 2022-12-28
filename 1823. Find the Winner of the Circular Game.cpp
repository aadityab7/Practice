class Solution {
public:
    int helper(int n,int k){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k) + 1;   
        //+1 is for conterting 0-based indexing to 1-based indexing
    }
};

/*
n = 5
k = 2

1 to 5

0 + 2 % 1 = 0
0 + 2 % 2 = 0
0 + 2 % 3 = 2
2 + 2 % 4 = 0
0 + 2 % 5 = 2

*/