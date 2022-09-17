class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i = 0; i <= n; i++){
            //for each number count the number of ones;
            int temp = i;
            int count = 0;
            while(temp > 0){
                if(temp % 2){
                    count++;
                }
                
                temp /= 2;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    } 
};

//0ms 
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        
        for(int i = 1; i <= n; i++){
            ans.push_back(ans[i / 2] + (i % 2));
        }
        return ans;
    } 
};

/*
0  0    = 0
1  1    = 1
2  10   = 1
3  11   = 2
4  100  = 1
5  101  = 2
6  110  = 2
7  111  = 3
8  1000 = 1
9  1001 = 2
10 1010 = 2
11 1011 = 3
12 1100 = 2
13 1101 = 3
14 1110 = 3
15 1111 = 4

10000
*/