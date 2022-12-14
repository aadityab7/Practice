//6 ms
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int arr[26] = {};

        for(int i = 0; i < s.size(); i++){
            arr[s[i] - 'a']++;
        }

        int curr = -1;

        for(int i = 0; i < 26; i++){
            if(arr[i]){
                if(curr != -1){
                    if(arr[i] != curr){
                        return false;
                    }
                }
                else{
                    curr = arr[i];
                }
            }
        }

        return true;
    }
};

//4 ms
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++) mp[s[i]]++;

        int curr = mp[s[0]];

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second != curr) return false;
        }

        return true;
    }
};