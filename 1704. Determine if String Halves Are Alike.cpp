class Solution {
public:
    bool halvesAreAlike(string s) {
        int arr[26] = {};
        int a[26] = {};
        int size = s.size();
        
        for(int i = 0; i < (size / 2); i++){
            if(s[i] >= 'a' && s[i] <= 'z') arr[s[i] - 'a']++;
            else arr[s[i] - 'A']++;
            
            if(s[size - i - 1] >= 'a' && s[size - i - 1] <= 'z') a[s[size - i - 1] - 'a']++;
            else a[s[size - i - 1] - 'A']++;
        }
        
        string str = "aeiou";
        int count = 0, co = 0;
        
        for(char c : str){
            count += arr[c - 'a'];
            co += a[c - 'a'];
        }
        
        if(count == co) return true;
        
        
        
        return false;
    }
};