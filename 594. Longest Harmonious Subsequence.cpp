class Solution {
public:
    int findLHS(vector<int>& nums) {
        //map of elements 
        map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int ans = 0;
        auto curr = mp.begin();
        auto prev = mp.begin();
        
        curr++;
        
        for(;curr != mp.end(); curr++){
            
            if(curr -> first == prev -> first + 1){
                if(curr -> second + prev -> second > ans){
                    ans = curr -> second + prev -> second;
                }
            }
            
            prev++;
        }
       
        return ans;
        
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        //map of elements 
        unordered_map<int, int> mp;
        int ans = 0;
        // int num;
        
        
        for(int i = 0; i < nums.size(); i++){
            // num = nums[i];
            
            mp[nums[i]]++;
        
            if(mp.find(nums[i] + 1) != mp.end()){
                ans = max(ans, mp[nums[i]] + mp[nums[i] + 1]);
            }
            
//             if(mp[num + 1]){
//                 // ans = max(ans, mp[num] + mp[num + 1]);
//                 if(mp[num] + mp[num + 1] > ans){
//                     ans = mp[num] + mp[num + 1];
//                 }
//             }
            
            if(mp.find(nums[i] - 1) != mp.end()){
                ans = max(ans, mp[nums[i]] + mp[nums[i] - 1]);
            }
            
            // if(mp[num - 1]){
            //     // ans = max(ans, mp[num] + mp[num - 1]);
            //     if(mp[num] + mp[num - 1] > ans){
            //         ans = mp[num] + mp[num - 1];
            //     }
            // }
        }
        
        return ans;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){    
            mp[nums[i]]++;
            if(mp.find(nums[i] + 1) != mp.end()){
                ans = max(ans, mp[nums[i]] + mp[nums[i] + 1]);
            }
            if(mp.find(nums[i] - 1) != mp.end()){
                ans = max(ans, mp[nums[i]] + mp[nums[i] - 1]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto num : nums){
            mp[num]++;
        }
        
        for(auto element : mp){
            auto found = mp.find(element.first + 1);
            
            if(found != mp.end()){
                if(found -> second + element.second > ans){
                    ans = element.second + found -> second;
                }
            }
        }
        return ans;
    }
};