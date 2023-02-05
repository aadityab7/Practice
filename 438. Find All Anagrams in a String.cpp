class Solution {
    bool comp(int a[], int b[]){
        for(int i = 0; i < 26; i++) if(a[i] != b[i]) return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int arr1[26] = {}, arr2[26] = {};
        for(char c : p) arr1[c - 'a']++;
        
        int n = p.size() - 1;
        vector<int> ans;

        for(int i = 0; i < s.size(); i++){
            arr2[s[i] - 'a']++;

            if(i >= n){
                if(comp(arr1, arr2)) ans.push_back(i - n);

                arr2[s[i - n] - 'a']--;
            }
        }

        return ans;
    }
};