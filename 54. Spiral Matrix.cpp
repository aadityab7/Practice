class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int maxy = matrix.size() - 1;
        int maxx = matrix[0].size() - 1;
        int minx = 0;
        int miny = 1;

        int i = 0, j = 0;

        int dir = 0;

        vector<pair<int, int>> d;
        d.push_back({0,1});
        d.push_back({1,0});
        d.push_back({0,-1});
        d.push_back({-1,0});

        int num = 0;
        int max = matrix.size() * matrix[0].size();

        //cout << maxx << ' ' << maxy << ' ' << minx << ' ' << miny << '\n';

        while(num < max){
            ans.push_back(matrix[i][j]);

            //whenever you hit a wall change dir
            
            if(dir == 0 && j == maxx){
                dir = 1;
                maxx--;
            }
            else if(dir == 1 && i == maxy){
                dir = 2;
                maxy--;
            }
            else if(dir == 2 && j == minx){ 
                dir = 3;
                minx++;
            }
            else if(dir == 3 && i == miny){
                dir = 0;
                miny++;
            }

            

            i += d[dir].first;
            j += d[dir].second;

            //cout << d[dir].first << ' ' << i << '\n';
            //cout << d[dir].second << ' ' << j << '\n';
            num++;    
        }
        
    
        return ans;
    }
};