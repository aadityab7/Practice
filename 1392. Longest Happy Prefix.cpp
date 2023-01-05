//HARD - 71 ms
//KMP Search - suffix is also prefix 
class Solution {
public:
    string longestPrefix(string s) {
        int j = 0, n = s.size();
        vector<int> kmp_arr(n, 0);

        for(int i = 1; i < n; i++)
            if(s[i] == s[j]) kmp_arr[i] = ++j; // or j + 1 and then j++
            else if(j){
                j = kmp_arr[j - 1];
                i--;
            }

        return s.substr(0, j);
    }
};