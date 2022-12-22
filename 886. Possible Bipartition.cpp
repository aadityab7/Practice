class Solution {
    queue<pair<int, int>> q;
    unordered_map<int, vector<int>> mp;

    void check(const vector<int> & visited, vector<int> & a){
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(!visited[itr -> first - 1]){
                q.push({itr -> first, 1});
                a[itr->first - 1] = 1;
                return;
            }
        }

    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        for(auto & d : dislikes){
            mp[d[0]].push_back(d[1]);
            mp[d[1]].push_back(d[0]);
        }

        //perform bfs

        vector<int> visited(n, 0), a(n, 0), b(n, 0);

        check(visited, a);
        
        while(!q.empty()){
            int x = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level % 2){
                for(auto & temp : mp[x]){
                    b[temp - 1] = 1;
                    if(visited[temp - 1] == 0) q.push({temp, level + 1});
                }
            }
            else{
                for(auto & temp : mp[x]){
                    a[temp - 1] = 1;
                    if(!visited[temp - 1]) q.push({temp, level + 1});
                }
            }

            visited[x - 1] = 1;     

            if(q.empty()) check(visited, a);       
        }

        for(int i = 0; i < n; i++){
            if(a[i] && b[i]) return false;
        }

        return true;

    }
};