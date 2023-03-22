class Solution {
    int find(int x, const vector<int> & groups){
        if(groups[x] == x) return x;
        return find(groups[x], groups);
    }

    void combine(int &x, int &y, int &dist, vector<int> &groups, vector<int> &mins){
        int a = find(x, groups), b = find(y, groups);

        if(a < b){
            mins[a] = min(mins[a], min(mins[b], dist));
            groups[b] = a;
        }
        else{
            mins[b] = min(mins[a], min(mins[b], dist));
            groups[a] = b;
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> groups(n + 1), mins(n + 1, INT_MAX);
        for(int i = 0; i <= n; i++) groups[i] = i;

        for(auto road : roads){
            combine(road[0], road[1], road[2], groups, mins);
        }

        //after combinining mins[1] should contain the road with min distance
        return mins[1];
    }
};