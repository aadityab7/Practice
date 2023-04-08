/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node *, Node *> map;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(map.count(node)) return map[node];

        Node * newNode = new Node(node -> val);
        map[node] = newNode;

        for(Node * n : node -> neighbors){
            newNode -> neighbors.push_back(cloneGraph(n));
        }

        return map[node];
    }
};