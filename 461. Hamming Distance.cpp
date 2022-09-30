class Solution {
public:
    int hammingDistance(int x, int y) {
        int a[32] = {}, b[32] = {};
        int i = 0;
        
        while(x > 0){
            if(x % 2) a[31 - i] = 1;
            else a[31 - i] = 0;
            x /= 2;
            i++;
        }
        
        i = 0;
        
        while(y > 0){
            if(y % 2) b[31 - i] = 1;
            else b[31 - i] = 0;
            y /= 2;
            i++;
        }
        
        int ans = 0;
        
        for(int i = 0; i < 32; i++){
            if(a[i] != b[i]){
                ans++;
            }
        }
        
        return ans;
    }
};

//1
//100
//