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
    
    void pre(Node * node){
        //root, left to right
        if(!node) return;
        
        ans.push_back(node -> val);
        // vector<Node *> temp = node -> children;
        
        for(auto t : node -> children){
            pre(t);
        }
        
        // for(int i = 0; i < temp.size(); i++){
        //     pre(temp[i]);
        // }
    }
public:
    vector<int> preorder(Node* root) {
        pre(root);
        return ans;
    }
};