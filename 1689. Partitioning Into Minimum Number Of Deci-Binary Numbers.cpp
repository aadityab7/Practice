class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;

        for(int i = 0; i < n.size(); i++){
            int x = n[i] - '0';

            if(x > ans) ans = x;
        }

        return ans;
    }
};

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;

        for(char c : n)
            ans = max(ans, c - '0');

        return ans;
    }
};