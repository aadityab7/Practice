//7ms
class Solution {
vector<vector<int>> ans;
int t;

void helper(const vector<int> &c, vector<int>& curr, int sum, int index){
    if(sum == t) ans.push_back(curr);
    else if(t > sum){
        for(int i = index; i < c.size(); i++){
            curr.push_back(c[i]);
            sum += c[i];
            helper(c, curr, sum, i);
            curr.pop_back();
            sum -= c[i];
        }   
    }
}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        t = target;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        helper(candidates, curr, 0, 0);
        return ans;        
    }
};

//faster - 4ms
class Solution {
vector<vector<int>> ans;
vector<int> curr;

void helper(const vector<int> &c, int target, int index){
    if(target == 0){
        ans.push_back(curr);
    }else if(target > 0){
        for(int i = index; i < c.size(); i++){
            curr.push_back(c[i]);
            helper(c, target - c[i], i);
            curr.pop_back();
        }
    }
}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0);
        return ans;        
    }
};