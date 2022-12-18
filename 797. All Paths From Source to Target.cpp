class Solution {
vector<vector<int>> ans;

void helper(const vector<vector<int>> &graph, vector<int> &curr, int index){
    
    if(index == graph.size() - 1){
        ans.push_back(curr);
        return;
    }

    for(int i = 0; i < graph[index].size(); i++){
        curr.push_back(graph[index][i]);
        helper(graph, curr, graph[index][i]);
        curr.pop_back();
    }
}

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> c;
        c.push_back(0);

        helper(graph, c, 0);

        return ans;
    }
};
