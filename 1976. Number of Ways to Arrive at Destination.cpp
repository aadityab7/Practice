#define ll long long

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //Dijkstra's Algorithm
        ll MOD = 1000000007;

        vector<vector<pair<ll, ll>>> graph(n);

        for(auto r : roads){
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<ll> count_ways(n, 0);
        vector<ll> distance(n, LONG_MAX);

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> minheap;

        minheap.push({0, 0}); // minimum_distance from 0 and index
        count_ways[0] = 1;
        distance[0] = 0;

        while(!minheap.empty()){
            pair<ll, ll> temp = minheap.top(); minheap.pop();

            ll min_dist = temp.first;
            ll index = temp.second;

            //if(min_dist > distance[index]) continue; // not up to date

            for(auto g : graph[index]){
                //for all the connected nodes check if the 
                ll candidate = min_dist + g.second;

                if(candidate == distance[g.first]){
                    count_ways[g.first] = (count_ways[g.first] + count_ways[index]) % MOD;
                }
                else if(candidate < distance[g.first]){
                    distance[g.first] = candidate;
                    count_ways[g.first] = count_ways[index];
                    minheap.push({candidate, g.first});
                }
            }
        }

        return count_ways[n - 1] % MOD;
    }
};

#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //Dijkstra's Algorithm
        ll MOD = 1000000007;

        vector<vector<pll>> graph(n);

        for(auto r : roads){
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<ll> count_ways(n, 0);
        vector<ll> distance(n, LONG_MAX);

        priority_queue<pll, vector<pll>, greater<>> minheap;

        minheap.push({0, 0}); // minimum_distance from 0 and index
        count_ways[0] = 1;
        distance[0] = 0;

        while(!minheap.empty()){
            ll min_dist = minheap.top().first;
            ll index = minheap.top().second;
            minheap.pop();

            //if(min_dist > distance[index]) continue; // not up to date

            for(auto g : graph[index]){
                //for all the connected nodes check if the 
                ll candidate = min_dist + g.second;

                if(candidate == distance[g.first]){
                    count_ways[g.first] = (count_ways[g.first] + count_ways[index]) % MOD;
                }
                else if(candidate < distance[g.first]){
                    distance[g.first] = candidate;
                    count_ways[g.first] = count_ways[index];
                    minheap.push({candidate, g.first});
                }
            }
        }

        return count_ways[n - 1] % MOD;
    }
};


//Most Concise - Dijkstra's Algo - 97 ms
#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //Dijkstra's Algorithm
        ll MOD = 1000000007;

        vector<vector<pll>> graph(n);

        for(auto r : roads){
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<ll> count_ways(n, 0);
        vector<ll> distance(n, LONG_MAX);

        priority_queue<pll, vector<pll>, greater<>> minheap;

        minheap.push({0, 0}); // minimum_distance from 0 and index
        count_ways[0] = 1;
        distance[0] = 0;

        while(!minheap.empty()){
            ll min_dist = minheap.top().first;
            ll index = minheap.top().second;
            minheap.pop();

            // if(index == n - 1) return count_ways[index] % MOD;

            if(min_dist > distance[index]) continue; // not up to date node must be skipped

            for(auto g : graph[index]){
                //for all the connected nodes check if the 
                ll candidate = min_dist + g.second;

                if(candidate == distance[g.first]){
                    count_ways[g.first] = (count_ways[g.first] + count_ways[index]) % MOD;
                }
                else if(candidate < distance[g.first]){
                    distance[g.first] = candidate;
                    count_ways[g.first] = count_ways[index];
                    minheap.push({candidate, g.first});
                }
            }
        }

        return count_ways[n - 1] % MOD;
    }
};