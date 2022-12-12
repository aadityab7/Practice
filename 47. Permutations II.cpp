class Solution {
vector<vector<int>> ans;
vector<int> curr;
unordered_map<int, int> mp;
int n;

//function for BACKTRACKING
void helper(){
    if(curr.size() == n) ans.push_back(curr);
    else{
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second){
                curr.push_back(itr -> first);
                itr -> second--;
                helper();
                curr.pop_back();
                itr -> second++;
            }
        }
    }
}

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        
        //create a map
        for(int i = 0; i < n; i++) mp[nums[i]]++;
        
        helper();

        return ans;        
    }
};