class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i]){
                if(count > max){
                    max = count;
                }
                
                count =  0;
            }
            else{
                count++;
            }
        }
        
        if(count > max){
           max = count; 
        }
        
        return max;
    }
};


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0, last = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                mx = max(mx, i - last);
                last = i + 1;
            }
        }

        mx = max(mx, n - last);
        return mx;
    }
};