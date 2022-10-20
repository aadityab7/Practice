class Solution {
    
    vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k){
        vector<vector<int>> res;
        
        if(start == nums.size()) return res;
        
        long long average_val = target / k;
        
        if(nums[start] > average_val || average_val > nums.back()) return res;
        
        if(k == 2) return twoSum(nums, target, start);
        
        for(int i = start; i < nums.size(); i++){
            
            //check for duplicate
            if(i == start || nums[i - 1] != nums[i]){
                vector<vector<int>> temp = kSum(nums, target-nums[i], i + 1, k - 1);
                
                for(int j = 0; j < temp.size(); j++){
                    res.push_back({nums[i]});
                    vector<int> x = temp[j];
                    
                    for(int l = 0; l < x.size(); l++){
                        res.back().push_back(x[l]);
                    }
                }
            }
            
        }
        
        return res;
        
    }
    
    //two sum return the possible pair for given target
    vector<vector<int>> twoSum(vector<int> &nums, long long target, int start){
        //we have to start searching the array from start pos
        unordered_set<long long> st;
        vector<vector<int>> res;
        
        for(int i = start; i < nums.size(); i++){
            if(res.empty() || res.back()[1] != nums[i]){
                if(st.count(target - nums[i])){
                    res.push_back({int(target - nums[i]), nums[i]});
                }
            }
            
            st.insert(nums[i]);
        }
        
        return res;
    }
    
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //solve using recursion 
        //with end condition being two sum function
        
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
        
    }
};



//SOME SMALL CHANGES
class Solution {
    
    vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k){
        vector<vector<int>> res;
        
        if(start == nums.size()) return res;
        
        long long average_val = target / k;
        
        if(nums[start] > average_val || average_val > nums.back()) return res;
        
        if(k == 2) return twoSum(nums, target, start);
        
        for(int i = start; i < nums.size(); i++){
            
            //check for duplicate
            if(i == start || nums[i - 1] != nums[i]){
//                 vector<vector<int>> temp = kSum(nums, target-nums[i], i + 1, k - 1);
                
                for(vector<int>& sub : kSum(nums, target - nums[i], i + 1, k - 1)){
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(sub), end(sub));
                }
//                 for(int j = 0; j < temp.size(); j++){
//                     res.push_back({nums[i]});
//                     vector<int> x = temp[j];
                    
//                     for(int l = 0; l < x.size(); l++){
//                         res.back().push_back(x[l]);
//                     }
//                 }
            }
            
        }
        
        return res;
        
    }
    
    //two sum return the possible pair for given target
    vector<vector<int>> twoSum(vector<int> &nums, long long target, int start){
        //we have to start searching the array from start pos
        unordered_set<long long> st;
        vector<vector<int>> res;
        
        for(int i = start; i < nums.size(); i++){
            if(res.empty() || res.back()[1] != nums[i]){
                if(st.count(target - nums[i])){
                    res.push_back({int(target - nums[i]), nums[i]});
                }
            }
            
            st.insert(nums[i]);
        }
        
        return res;
    }
    
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //solve using recursion 
        //with end condition being two sum function
        
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
        
    }
};