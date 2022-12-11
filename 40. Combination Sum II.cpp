//15 ms
class Solution {
vector<vector<int>> ans;
vector<int> curr;

void helper(const vector<int> &c, int target, int index){
    if(target == 0){
        ans.push_back(curr);
    }
    else if(target > 0){
        int i = index;
        while(i < c.size()){
            curr.push_back(c[i]);
            helper(c, target - c[i], i + 1);
            curr.pop_back();
            
            int num = c[i];
            i++;

            while(i < c.size() && c[i] == num) i++;
        }
    }
}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0);
        return ans;
    }
};

//4 ms
class Solution {
void helper(const vector<int> &c, int target, int index, vector<int> &curr, vector<vector<int>> &ans){
    if(target == 0) ans.push_back(curr);
    
    int i = index;
    while(i < c.size()){
        if(target - c[i] < 0) break; 
        
        curr.push_back(c[i]);
        helper(c, target - c[i], i + 1, curr, ans);
        curr.pop_back();
        
        int num = c[i];
        i++;

        while(i < c.size() && c[i] == num) i++;
    }
    
}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, curr, ans);
        return ans;
    }
};