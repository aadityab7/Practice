class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int, int> mp;
        int max = -1;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = 0;
            if(nums[i] > max) max = nums[i];
        }
        
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i] % space;
            
            for(auto itr = mp.begin(); itr != mp.end(); itr++){
                int y = itr -> first;
                if((y - x) % space == 0){
                    itr -> second++;
                    break;
                }
            }
        }
        
        int m = -1;
        int ans;
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second > m){
                m = itr -> second;
                ans = itr -> first;
            }
        }
        
        return ans;
    }
};