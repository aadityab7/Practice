class Solution {
    //vector to be used for union find
    vector<int> arr;
    
    int find(int num){
        if(arr[num] == num) return num;
        else return find(arr[num]);
    }

    void union_set(int node1, int node2){
        int head1 = find(node1), head2 = find(node2);
        int mn = min(head1, head2);

        arr[head1] = mn;
        arr[head2] = mn;
    }

public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans = 0;
        int n = vals.size();
        
        //the set in which each node belongs to 
        //initially every node belongs in its own set
        arr.resize(n);
        for(int i = 0; i < n; i++) arr[i] = i;

        //map for nodes having the same values
        //ordered from smallest to largest
        //so subtree can be formed in increasing order
        map<int, vector<int>> valuesToNodes;
        for(int i = 0; i < n; i++) valuesToNodes[vals[i]].push_back(i);

        //create adj list for tree
        vector<vector<int>> tree(n);
        for(auto e : edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        
        //traverse the nodes with same values
        for(auto [node_val, nodes] : valuesToNodes){
            
            //nodes with same values
            for(int node : nodes){  
                for(int neighbour : tree[node]){
                    if(vals[neighbour] <= vals[node]){
                        //this will update the set in which the node belongs to
                        union_set(node, neighbour);
                    }
                }
            }

            //visit all the nodes to find out how many different sets they belong to 
            //and how many elements in each set 

            unordered_map<int, int> groups;

            for(int node : nodes){
                groups[find(node)]++;
            }

            //traverse the groups map;
            for(auto [x, count] : groups){
                ans += ((count * (count + 1)) / 2);
            }
        }

        return ans;
    }
};