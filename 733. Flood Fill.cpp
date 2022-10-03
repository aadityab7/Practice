class Solution {
private:
    int target;
    int col;
    
    void fill(int x, int y, vector<vector<int>> &img, vector<vector<int>> &v){
        
        //fill the curr 
        //return when out of range
        if(x < 0 || y < 0 || x >= img.size() || y >= img[0].size()) return;
        
        if(v[x][y]) return;
        v[x][y] = 1;
        
        if(img[x][y] == target) img[x][y] = col;
        else return;
        
        //top
        fill(x - 1, y, img, v);
        
        //down
        fill(x + 1, y, img, v);
        
        //left
        fill(x, y - 1, img, v);
        
        //right
        fill(x, y + 1, img, v);
        
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //start from (sr,sc) then go to up down left right
        //go top left right down
        target = image[sr][sc];
        col = color;
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> vis(n, vector(m,0));
        
        fill(sr, sc, image, vis);
        
        return image;
        
    }
};

class Solution {
private:
    int target;
    int col;
    int rows;
    int cols;
    
    void fill(int x, int y, vector<vector<int>> &img){
        
        //fill the curr if = target and continue search
        
        if(img[x][y] == target){
            img[x][y] = col;
            
            //go up
            if(x > 0) fill(x - 1, y, img);
            //go down
            if(x < (rows - 1)) fill(x + 1, y, img);
            
            //go left
            if(y > 0) fill(x, y - 1, img);
            //go right
            if(y < (cols - 1)) fill(x, y + 1, img);
        }
        else return;
        
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //start from (sr,sc) then go to up down left right
        //go top left right down
        target = image[sr][sc];
        col = color;
        
        rows = image.size();
        cols = image[0].size();
        
        if(target != col) fill(sr, sc, image);
        
        return image;
        
    }
};