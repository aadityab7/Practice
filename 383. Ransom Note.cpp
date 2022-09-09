//21ms
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {};
        
        for(int i = 0; i < ransomNote.size(); i++){
            arr[ransomNote[i] - 'a']--;
        }
        
        for(int i = 0; i < magazine.size(); i++){
            arr[magazine[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(arr[i] < 0){
                return false;
            }
        }
        
        return true;
    }
};

/*
40ms
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        
        for(int i = 0; i < ransomNote.size(); i++){
            mp[ransomNote[i]]--;
        }
        
        for(int i = 0; i < magazine.size(); i++){
            mp[magazine[i]]++;
        }
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second < 0){
                return false;
            }
        }
        
        return true;
    }
};
*/