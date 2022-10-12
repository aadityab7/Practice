class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //use Priority Queue or Max heap to get the max elements quickly
        priority_queue<int> pq(stones.begin(), stones.end());
        int x, y;
        
        while(pq.size() > 1){
            y = pq.top();
            pq.pop();
            
            x = pq.top();
            pq.pop();
            
            if(x != y) pq.push(y - x);
        }
        
        if(pq.empty()) return 0;
        
        return pq.top();
    }
};

//1 3 
//diff btw max and min
//1 2 3 4 5 6 7 8
//1 2 3 4 5 6 0 1
//1 2 3 4 0 1 0 1 
//1 2 3 4 0 1 0 1 
//1 2 0 1 1 1
//1 1 1 1
//0