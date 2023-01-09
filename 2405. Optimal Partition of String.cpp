class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        vector<int> arr(26, 0), temp(26, 0);

        for(char c : s){
            if(arr[c - 'a']){
                ans++;
                arr = temp;
            }

            arr[c - 'a'] = 1;
        }

        return ans;
    }
};