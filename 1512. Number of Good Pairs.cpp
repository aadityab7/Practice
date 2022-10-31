class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, vector<int>> mp;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]].push_back(i);
            }
            else{
                mp[nums[i]] = {i};
            }
        }
        
        int ans = 0;
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            //n * (n - 1) / 2
            int x = (itr -> second).size();
            int y = (x * (x - 1)) / 2;
            ans += y;
        }
        
        return ans;
    }
};