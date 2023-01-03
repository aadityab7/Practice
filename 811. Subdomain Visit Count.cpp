class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        //seperate everything
        //extract the number
        vector<string> ans;

        unordered_map<string, int> mp;

        for(string s : cpdomains){
            string temp = "", count = "";
            int flag = 1, dom_flag = 0;
            int num;

            for(int i = 0; i < s.size(); i++){
                if(s[i] == ' '){
                    //everything after this is a domain
                    num = stoi(count);
                    dom_flag = 1;
                    flag = 0;
                }
                else if(flag){
                    count += s[i];
                }
                else if(s[i] == '.'){
                    dom_flag = 1;
                }
                else if(dom_flag){
                    //everything from this index to last is a domain
                    temp = s.substr(i, s.size() - i);
                    
                    if(mp.find(temp) == mp.end()) mp[temp] = num;
                    else mp[temp] += num;

                    dom_flag = 0;
                }
            }

        }

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
                //cout << itr -> second << ' ' << itr -> first << '\n';
                string temp = to_string(itr -> second) + " " + itr -> first;
                ans.push_back(temp);
            }

            return ans;
    }
};