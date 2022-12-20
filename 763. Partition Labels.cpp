class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        map<char, vector<int>> mp;

        for(int i = 0; i < s.size(); i++) mp[s[i]].push_back(i);

        int i = 0, j = 0;

        while(i < s.size()){
            j = mp[s[i]].back();
            
            int x = i;

            while(x <= j){
                if(mp[s[x]][0] >= i && mp[s[x]][0] <= j){
                    if(mp[s[x]].back() < i || mp[s[x]].back() > j){
                        //cout << s[x] << ' ';
                        j = mp[s[x]].back();
                    }
                }
                
                x++;
            }
            

            //partition is from i to j 
            ans.push_back(j - i + 1);
            i = j + 1;
        }

        return ans;
    }
};