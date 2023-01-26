class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Create a adj list of graph
        vector<vector<pair<int, int>>> graph(n); //(next_node, price)
        for(auto fl : flights){
            graph[fl[0]].push_back({fl[1], fl[2]});
        }

        //stops - the min number of stops that we require to get to this node
        vector<int> stops(n, INT_MAX);

        //we travel to the node at least distance first using pq;
        //{price_from_src, node, number_of_steps_from_src}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int price = temp[0], node = temp[1], steps = temp[2];

            //if we already have a path of reaching here in less steps and less cost
            //(pq traverse the cheapest path first) - so if we have been here that must be cheaper
            //or if the number of steps exceed the limit

            if(steps > stops[node] || steps > k + 1){
                continue;
            }

            stops[node] = steps;

            if(node == dst) return price;

            for(auto [neighbour, price_next] : graph[node]){
                pq.push({price + price_next, neighbour, steps + 1});
            }
        }

        return -1;
    }
};