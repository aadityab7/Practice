class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int r = image.size(), x, s = ceil(r / 2.0), i, j;
        
        for(i = 0; i < r; i++){
            for(j = 0; j < s; j++){
                x = image[i][j];
                image[i][j] = 1 - image[i][r - j - 1];
                image[i][r - j - 1] = 1 - x;
            }
        }
        
        return image;
    }
};

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int r = image.size(), x, s = ((r+1) / 2), i, j;
        
        for(i = 0; i < r; i++){
            for(j = 0; j < s; j++){
                x = 1 - image[i][j];
                image[i][j] = 1 - image[i][r - j - 1];
                image[i][r - j - 1] = x;
            }
        }
        
        return image;
    }
};