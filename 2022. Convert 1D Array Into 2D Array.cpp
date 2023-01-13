class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(original.size() != m * n) return ans;

        ans.resize(m, vector<int>(n));

        int curr = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = original[curr++];
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m * n) return {};
        
        vector<vector<int>> ans;

        //create a vector using elements of original and push it to ans
        for(int i = 0; i < m * n; i += n)
            ans.push_back(vector<int>(original.begin() + i, original.begin() + i + n));
            
        return ans;
    }
};