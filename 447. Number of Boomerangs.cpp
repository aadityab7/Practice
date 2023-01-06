class Solution {
    int dist(vector<int> &a, vector<int> &b){
        int dx = a[0] - b[0], dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }

public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)     
                mp[dist(points[i], points[j])]++;
            
            for(auto [x, y] : mp)
                ans += y * (y - 1);

            mp.clear();
        }    

        return ans;
    }
};

/*
ab 
ba

2 => 2

abc

ab
ba
ac
ca
bc
cb

3 => 6

abcd
4 => 12

ab
ba
ac
ca
ad
da
bc
cb
bd
db
cd
dc

n * (n - 1);
*/