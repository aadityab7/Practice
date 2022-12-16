class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        // for(int i = 0; i < patterns.size(); i++){
        //     if(word.find(patterns[i]) != string::npos){
        //         ans++;
        //     }
        // }

        for(string s : patterns) 
            if(word.find(s) != string::npos) ans++;

        return ans;
    }
};