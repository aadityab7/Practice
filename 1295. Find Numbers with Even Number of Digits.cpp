class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int count = 0;
            
            while(x > 0){
                count++;
                x/=10;    
            }
            
            if(count % 2 == 0) ans++;
        }
        
        return ans;
    }
};

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
           string x = to_string(nums[i]);
            if(!(x.size() % 2)) ans++;
        }
        
        return ans;
    }
};