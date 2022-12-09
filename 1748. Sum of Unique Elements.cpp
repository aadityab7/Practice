class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int ans = 0;
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second == 1) ans += itr -> first;
        }
        
        return ans;
    }
};


class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int arr[101] = {};
        
        for(int i = 0; i < nums.size(); i++) arr[nums[i]]++;
        
        int ans = 0;
        
        for(int i = 1; i < 101; i++) if(arr[i] == 1) ans += i;
        
        return ans;
    }
};

//0 ms
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int arr[101] = {};
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(arr[nums[i]] == 0) {
                ans += nums[i];
            }
            else if(arr[nums[i]] == 1){
                ans -= nums[i];
            }
            
            arr[nums[i]]++;
        }
        
        
        return ans;
    }
};