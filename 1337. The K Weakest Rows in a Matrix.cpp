bool comp(pair<int, int>&a, pair<int,int> &b){
    if(a.second == b.second) return a.first < b.first;
    
    return a.second < b.second;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> arr(mat.size());
        vector<int> ans;
        
        for(int i = 0; i < mat.size(); i++){
            int count = 0;
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1) count++;
                else break;
            }
            
            arr[i] = {i, count};
        }
        
        //sort the arr according to count
        sort(arr.begin(), arr.end(), comp);
        
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i].first);
        }
        
        return ans;
    }
};