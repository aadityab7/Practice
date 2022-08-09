class Solution {
public:
//MY SOLUTION:
//     vector<int> getRow(int rowIndex) {
//         vector<int> ans;
        
//         for(int i = 0; i <= rowIndex; i++){
//             vector<int> temp(i + 1, 1);
            
//             for(int j = 1; j < i; j++){
//                 temp[j] = ans[j - 1] + ans[j];
//             }
            
//             ans = temp;
//         }
        
//         return ans;
//     }
    
//More Optimal solution
        vector<int> getRow(int rowIndex){
            vector<int> ans(rowIndex + 1);
        
            ans[0] = ans[rowIndex] = 1;
        
            long temp = 1;
            
            int up = rowIndex;
            int low = 1;
            
            for(int i = 1; i < rowIndex; i++){
                temp = temp * up / low;
                ans[i] = temp;
                
                up--;
                low++;
            }
            
            return ans;
        }

};