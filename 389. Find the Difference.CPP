//4ms
class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26] = {};
        
        for(int i = 0; i < s.size(); i++){
            arr[s[i] - 'a']++;
        }
        
        for(int i = 0; i < t.size(); i++){
            arr[t[i] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++){
            if(arr[i]){
                return (i + 'a');
            }
        }
        
        return 'z';
    }
};

//3ms
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        
        for(int i = 0; i < t.size(); i++){
            sum += t[i];
        }
        
        for(int i = 0; i < s.size(); i++){
            sum -= s[i];
        }
        
        return sum;
    }
};