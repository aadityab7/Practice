class Solution {
    void dfs(int index, unordered_map<int, vector<int>> &mp, vector<bool> & visited, int &ans){
        visited[index] = true;

        for(int neighbour : mp[index]){
            if(neighbour >= 0){
                if(visited[neighbour] == false){
                    ans++;
                    dfs(neighbour, mp, visited, ans);
                }
            }
            else{
                if(visited[-neighbour] == false){
                    dfs(-neighbour, mp, visited, ans);
                }
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> mp;
        for(auto con : connections){
            //all the directed away edges are to be converted
            mp[con[0]].push_back(con[1]);
            mp[con[1]].push_back(-con[0]);
        }

        int ans = 0;
        vector<bool> visited(n);

        dfs(0, mp, visited, ans);

        return ans;
    }
};

//using vector instead of map 
class Solution {
    void dfs(int index, const vector<vector<int>> &mp, vector<bool> & visited, int &ans){
        visited[index] = true;

        for(int neighbour : mp[index]){
            if(visited[abs(neighbour)] == false){
                if(neighbour >= 0) ans++;
                dfs(abs(neighbour), mp, visited, ans);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> mp(n);
        for(auto con : connections){
            //all the directed away edges are to be converted
            mp[con[0]].push_back(con[1]);
            mp[con[1]].push_back(-con[0]);
        }

        int ans = 0;
        vector<bool> visited(n);

        dfs(0, mp, visited, ans);

        return ans;
    }
};