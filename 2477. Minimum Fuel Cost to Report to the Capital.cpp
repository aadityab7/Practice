class Solution {
    //{filled cars, people, cost}
    vector<long long> dfs(int index, int par, const vector<vector<int>> &graph, int seats){
        //calc cost for coming upto here 
        long long filled_cars = 0, people = 0, cost = 0;

        for(int neighbour : graph[index]){
            if(neighbour != par){
                auto res = dfs(neighbour, index, graph, seats);
                filled_cars += res[0];
                people += res[1];
                cost += res[2];
            }
        }

        if(index == 0){
            //destination
            return {0, 0, cost};
        }
        else{
            //1 more person will get on here
            people++;
            filled_cars += (people / seats);
            people %= seats;

            cost += filled_cars; // totally filled cars traveling
            if(people) cost++; // if there are people traveling in a non - filled car

            return {filled_cars, people, cost};
        }
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        //DFS
        vector<vector<int>> graph(roads.size() + 1);

        for(auto road : roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        } 

        auto res = dfs(0, 0, graph, seats);

        return res[2];
    }
};