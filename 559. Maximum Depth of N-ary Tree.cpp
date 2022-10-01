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
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        
        queue<Node *> q;
        q.push(root);
        int level = 0;
        int breadth;
        
        while(!q.empty()){
            breadth = q.size();
            level++;
            //there are b elements on this level go to each one and add all 
            //it's children to q
            
            for(int i = 0; i < breadth; i++){
                Node * node = q.front();
                q.pop();
                
                //add all it's children to queue;
                vector<Node*> temp = node -> children;
                
                for(auto c : temp){
                    q.push(c);
                }//end for all children of node
                
            }//end for this level
            
        }
        
        return level;
    }
};