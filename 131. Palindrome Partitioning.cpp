//My TLE Solution
class Solution {
    unordered_map<string, vector<vector<string>>> mp;

    bool isPal(string s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }

public:
    vector<vector<string>> partition(string s) {
        if(mp.find(s) != mp.end()) return mp[s];

        set<vector<string>> res;
        int n = s.size();

        vector<string> temp;

        if(n == 1 || isPal(s)){
            temp.push_back(s);
            res.insert(temp);
        } 

        for(int i = 0; i < n - 1; i++){
            string x = s.substr(0, i + 1);
            string z = s.substr(i + 1, n - i - 1);

            for(vector<string> aa : partition(x)){
                for(vector<string> bb : partition(z)){
                    temp = aa;
                    for(string bs : bb) temp.push_back(bs);

                    res.insert(temp);
                }
            }
        }

        vector<vector<string>> ans;
        for(auto element : res) ans.push_back(element);

        mp[s] = ans;

        return ans;
    }
};

//Using Reccursion and BackTracking - 149 ms
class Solution {
    vector<vector<string>> ans;
    vector<string> curr;

    bool isPal(string s){
        int n = s.size();

        for(int i = 0; i < n / 2; i++){
            if(s[i] != s[n - i - 1]) return false;
        }

        return true;
    }

    void helper(string s){
        int n = s.size();

        if(n == 0){
            ans.push_back(curr);
            return;
        }

        string x, y;
        
        for(int i = 1; i <= n; i++){
            x = s.substr(0, i);
            y = s.substr(i, n - i);
            
            if(isPal(x)){
                curr.push_back(x);
                helper(y);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        helper(s);
        return ans;
    }
};