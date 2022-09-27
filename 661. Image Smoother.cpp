class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size();
        int c = img[0].size();
        
        vector<vector<int>> ans(r, vector<int>(c));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                //for each block calculate the sum of 
                //(i-1, j-1) (i-1, j) (i -1, j + 1) 
                //(i, j - 1) (i,j) (i. j + 1)
                //(i + 1, j - 1) (i + 1, j) (i + 1, j + 1)
                int sum = img[i][j];
                int count = 1;
                
                //top
                if(i){
                    //i - 1 is present
                    sum += img[i - 1][j];
                    count++;
                    
                    if(j){
                        sum += img[i - 1][j - 1];
                        count++;
                    }
                    
                    if(j < (c - 1)){
                        sum += img[i - 1][j + 1];
                        count++;
                    }
                }
                
                //left right
                if(j){
                    sum += img[i][j - 1];
                    count++;
                }

                if(j < (c - 1)){
                    sum += img[i][j + 1];
                    count++;
                }
                
                //bottom
                if(i < (r - 1)){
                    sum += img[i + 1][j];
                    count++;
                    
                    if(j){
                        sum += img[i + 1][j - 1];
                        count++;
                    }
                    
                    if(j < (c - 1)){
                        sum += img[i + 1][j + 1];
                        count++;
                    }  
                }
                
                ans[i][j] = sum / count;                
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size();
        int c = img[0].size();
        int count;
        
        vector<vector<int>> ans(r, vector<int>(c));
        
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                //for each block calculate the sum of 
                //(i-1, j-1) (i-1, j) (i -1, j + 1) 
                //(i, j - 1) (i,j) (i. j + 1)
                //(i + 1, j - 1) (i + 1, j) (i + 1, j + 1)
                ans[i][j] = img[i][j];
                count = 1;
                
                //top
                if(i){
                    //i - 1 is present
                    ans[i][j] += img[i - 1][j];
                    count++;
                    
                    if(j){
                        ans[i][j] += img[i - 1][j - 1];
                        count++;
                    }
                    
                    if(j < (c - 1)){
                        ans[i][j] += img[i - 1][j + 1];
                        count++;
                    }
                }
                
                //left right
                if(j){
                    ans[i][j] += img[i][j - 1];
                    count++;
                }

                if(j < (c - 1)){
                    ans[i][j] += img[i][j + 1];
                    count++;
                }
                
                //bottom
                if(i < (r - 1)){
                    ans[i][j] += img[i + 1][j];
                    count++;
                    
                    if(j){
                        ans[i][j] += img[i + 1][j - 1];
                        count++;
                    }
                    
                    if(j < (c - 1)){
                        ans[i][j] += img[i + 1][j + 1];
                        count++;
                    }  
                }
                
                ans[i][j] /= count;                
            }
        }
        
        return ans;
    }
};