class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        //first row
        ans.push_back({1});
        
        for(int i = 2; i <= numRows; i++){
            vector<int> temp(i);
            
            //we need elements = i
            //first element always 1
            temp[0] = 1;
            
            //need to loop for i - 2 times
            for(int j = 0; j < i - 2; j++){
                int number = ans[i - 2][j] + ans[i - 2][j + 1];
                temp[j + 1] = number;
            }
            
            //last element = 1
            temp[i - 1] = 1;
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};