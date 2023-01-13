//HARD

//NOTE : 
//ADJECENT : neighbour nodes must NOT be the same
//but the path can have 2 nodes with the same label

class Solution {
    
    int dfs(int index, const string &s, const vector<vector<int>> &tree, int &res){
        int longest = 0, second_longest = 0, child_longest;

        for(int child : tree[index]){
            child_longest = dfs(child, s, tree, res);

            //check only if the char in child is different from curr node char
            if(s[child] != s[index]){
                if(child_longest > longest){
                    second_longest = longest;
                    longest = child_longest;
                }
                else if(child_longest > second_longest){
                    second_longest = child_longest;
                }
            }
        }

        //check if curr length of subtree > res
        res = max(res, longest + second_longest + 1);
        return longest + 1;
    }

public:
    int longestPath(vector<int>& parent, string s) {
        //create a tree from given parent array
        vector<vector<int>> tree(parent.size());
        for(int i = 1; i < parent.size(); i++) tree[parent[i]].push_back(i);
        
        int res = 0;
        
        dfs(0, s, tree, res);

        return res;
    }
};