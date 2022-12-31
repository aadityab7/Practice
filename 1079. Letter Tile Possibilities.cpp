class Solution {
    unordered_set<string> ans;
    unordered_map<char, int> mp;
    string curr = "";

    void helper(){
        ans.insert(curr);
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second > 0){
                itr -> second--;
                curr += itr -> first;
                helper();
                curr = curr.substr(0, curr.size() - 1);
                itr -> second++;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        for(char c : tiles) mp[c]++;

        helper();

        return ans.size() - 1;
    }
};