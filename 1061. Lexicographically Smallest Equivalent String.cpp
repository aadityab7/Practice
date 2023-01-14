//union the elements that belong together
class Solution {
    int arr[26] = {};

    int find(int num){
        if(arr[num] == num) return num;
        else return find(arr[num]);
    }

    void set(int i, int j){
        int x = find(i), y = find(j);
        int mn = min(x, y);
        arr[x] = mn;
        arr[y] = mn;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        for(int i = 0; i < 26; i++) arr[i] = i;

        for(int i = 0; i < n; i++) set(s1[i] - 'a', s2[i] - 'a');

        string ans;
        for(int i = 0; i < baseStr.size(); i++) ans += find(baseStr[i] - 'a') + 'a';

        return ans;
    }
};