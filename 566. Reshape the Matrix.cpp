class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int total = mat.size() * mat[0].size();
        int new_total = r * c;
        
        if(total != new_total){
            return mat;
        }
        
        vector<vector <int>> ans(r, vector<int> (c));
    
//traverse the original array and add the elements to the new array
        vector<int> empty_arr;
        // vector<int> temp;
        
        int r_count = 0;
        int count = 0;
        
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                // temp.push_back(mat[i][j]);
                ans[r_count][count] = mat[i][j];
                count++;
                
                if(count == c){
                    //ans.push_back(temp);
                    //temp = empty_arr;
                    r_count++;
                    count = 0;
                }
            }
        }
        
        return ans;
    }
};