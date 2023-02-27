/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* make_tree(int x, int y, int a, int b, const vector<vector<int>> &mtrx){

        //number of ones in the current box we are considering
        int curr = mtrx[a][b];
        if(y) curr -= mtrx[a][y - 1];
        if(x) curr -= mtrx[x - 1][b];
        if(x && y) curr += mtrx[x - 1][y - 1];

        int r = a - x + 1, c = b - y + 1;
        int size = r * c;
        
        //it is a leaf node
        if(curr == 0){
            return new Node(0, 1);
        }
        else if(curr == size){
            return new Node(1, 1);
        }

        //it is not a leaf node
        int h = r / 2;

        Node* nw = new Node(1, 0);

        nw -> topLeft = make_tree(x, y, (x + h - 1), (y + h - 1), mtrx);

        nw -> topRight = make_tree(x, (y + h), (x + h - 1), (y + h + h - 1), mtrx);

        nw -> bottomLeft = make_tree((x + h), y, (x + h + h - 1), (y + h - 1), mtrx);

        nw -> bottomRight = make_tree((a - h + 1), (b - h + 1), a, b, mtrx);
        
        return nw;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> mtrx = grid;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i) mtrx[i][j] += mtrx[i - 1][j];
                if(j) mtrx[i][j] += mtrx[i][j - 1];
                if(i && j) mtrx[i][j] -= mtrx[i - 1][j - 1];
            }
        }

        return make_tree(0, 0, n - 1, n - 1, mtrx);
    }
};