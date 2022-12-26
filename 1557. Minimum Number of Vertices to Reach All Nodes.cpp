class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> arr(n, 0), ans;
        int i;

        for(auto & e : edges) arr[e[1]] = 1;
        
        // for(i = 0; i < edges.size(); i++)
        //     arr[edges[i][1]] = 1;

        for(i = 0; i < n; i++)
            if(!arr[i]) ans.push_back(i);
        
        return ans;
    }
};