/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> ans;
    void post(Node * node){
        if(!node) return;
    
        for(auto c : node -> children){
            post(c);
        }
        
        ans.push_back(node -> val);
    }
public:
    vector<int> postorder(Node* root) {
        post(root);
        return ans;
    }
};