class Solution {
    int find(int x, const vector<int> &groups){
        if(groups[x] == x) return x;
        else return find(groups[x], groups);
    }

    void combine(int &x, int &y, vector<int> &groups){
        int a = find(x, groups), b = find(y, groups);

        if(a < b) groups[b] = a;
        else groups[a] = b;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> groups(n);
        for(int i = 0; i < n; i++) groups[i] = i;

        for(auto &edge : edges){
            combine(edge[0], edge[1], groups);
        }

        vector<int> group_sets(n);
        long long ans = 0;

        for(int i = 0; i < n; i++){
            int curr = find(i, groups);
            group_sets[curr]++;

            ans += (i + 1 - group_sets[curr]);
        }

        return ans;
    }
};