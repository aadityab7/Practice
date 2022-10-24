class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        
        vector<char> arr;
        arr.push_back(s[0]);
        
        int j = 0;
        
        for(int i = 1; i < s.size(); i++){
            
            if(j == -1 || abs(s[i] - arr[j]) != 32){
                arr.push_back(s[i]);
                j++;
            }
            else{
                arr.pop_back();
                j--;
            }
        }
        
        for(int i = 0; i < arr.size(); i++) ans += arr[i];
        
        return ans;
    }
};