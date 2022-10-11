
bool comp(pair<int, vector<int>> &a, pair<int, vector<int>> &b){
        return a.first < b.first;
}

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        //store coordinates and thier dist from r and c
        //sort by dist and then return the coordinates
        
        //create a 2d vector and sort by the first value in
        //each row will have 3 columns dist, x, y
        
        vector< pair< int, vector<int> > > arr;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                //we have coordinates
                int dist = abs(i - rCenter) + abs(j - cCenter);
                
                arr.push_back({dist, {i,j}});
            }
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        vector<vector<int>> ans(arr.size());
        
        for(int i = 0; i < arr.size(); i++){
            ans[i] = arr[i].second;
        }
        
        return ans;
        
    }
};