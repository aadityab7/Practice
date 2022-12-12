class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int ans = 1, i = 0, n = nums.size();
        int x, max, mx, j, y;

        while(i < n){
            //for each extra stop we have to make ans++;
            x = nums[i];
            max = i + x;
            
            if(max < n - 1){
                
                mx = i + x;
                max = 0;

                for(j = 1; j <= x; j++){
                    y = i + j + nums[i + j];
                    if(y > max){
                        max = y;
                        mx = i + j;
                    }
                }

                i = mx;
                ans++;
            }
            else break;
        }

        return ans;
    }
};

/*

Greedy - select the max from the next x numbers

*/