//Using 2 dfs - 890 ms
class Solution {
    vector<vector<int>> adj_list;
    vector<int> parent, distance;

    //calculate the distance from 0 to node: 
    void dfs(int index, int par, int dist){
        distance[index] = dist;
        parent[index] = par;

        for(int neighbour : adj_list[index]){
            if(neighbour == par) continue;
            dfs(neighbour, index, dist + 1);
        }
    }

    int max_sum_dfs(int index, int par, vector<int> &amt){
        int res = amt[index], sub_sum = -INT_MAX;

        for(int &neighbour : adj_list[index]){
            if(neighbour == par) continue;
            
            sub_sum = max(sub_sum, max_sum_dfs(neighbour, index, amt));
        }

        if(sub_sum == -INT_MAX) return res; // leaf node

        return res + sub_sum;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        //adjecency list
        int n = amount.size();
        adj_list.resize(n);

        for(auto &e : edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }    

        parent.resize(n);
        distance.resize(n);
        dfs(0, 0, 0); //calculate the distance from 0 to node;

        //update the amount according to who will reach the node first bob or alice
        int curr = bob, dist_bob = 0;

        while(curr){
            if(distance[curr] == dist_bob){
                amount[curr] = amount[curr] / 2;
            }
            else if(distance[curr] > dist_bob){
                amount[curr] = 0;
            }

            curr = parent[curr];
            dist_bob++;
        }    

        return max_sum_dfs(0, 0, amount);
    }
};



//Using 1 DFS - 450 ms
class Solution {
    vector<vector<int>> adj;
    vector<int> dist_bob;
    int bobNode;

    int dfs(int index, int par, int depth, const vector<int> & amount){
        int res = 0;
        int sub_sum = -INT_MAX;

        if(index == bobNode) dist_bob[index] = 0;
        else dist_bob[index] = amount.size();

        for(int neighbour : adj[index]){
            if(neighbour == par) continue;

            sub_sum = max(sub_sum, dfs(neighbour, index, depth + 1, amount));
            dist_bob[index] = min(dist_bob[index], dist_bob[neighbour] + 1);
        }

        if(dist_bob[index] == depth) res += amount[index] / 2;
        else if(dist_bob[index] > depth) res += amount[index];

        if(sub_sum == -INT_MAX) return res;
        
        return res + sub_sum;
    }


public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        bobNode = bob;
        dist_bob.resize(n);

        return dfs(0, 0, 0, amount);    
    }
};