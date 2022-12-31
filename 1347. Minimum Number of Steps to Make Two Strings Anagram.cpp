class Solution {
public:
    int minSteps(string s, string t) {
        int arr_s[26] = {}, arr_t[26] = {};

        for(char c : s) arr_s[c - 'a']++;
        for(char c : t) arr_t[c - 'a']++;

        int ans = 0;

        for(int i = 0; i < 26; i++){
            ans += abs(arr_s[i] - arr_t[i]);
        }

        return ans / 2;
    }
};