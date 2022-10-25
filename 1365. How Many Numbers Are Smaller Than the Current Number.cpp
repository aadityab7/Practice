class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        
        int i = 0, temp;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            temp = itr -> second;
            itr -> second = i;
            i += temp;
        }
        
        for(i = 0; i < nums.size(); i++) nums[i] = mp[nums[i]];
        
        return nums;
        
    }
};