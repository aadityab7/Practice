//312 ms
class Solution {
unordered_map<int, vector<vector<int>>> mp;

public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    
        for(int i = 0; i < groupSizes.size(); i++){
            //check if x exists in map
            int x = groupSizes[i];

            if(mp.find(x) != mp.end()){
                //exists
                //get the last array 
                vector<vector<int>> a = mp[x];
                int size = a.size();
                vector<int> b = a[size - 1];
                if(b.size() == x){
                    vector<int> t;
                    t.push_back(i);
                    mp[x].push_back(t);
                } 
                else{
                    mp[x][size - 1].push_back(i);
                }
            }
            else{
                //does not exist
                vector<int> t;
                t.push_back(i);
                mp[x].push_back(t);
            }
        }


        vector<vector<int>> ans;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            vector<vector<int>> x = itr -> second;
            for(vector<int> y : x){
                ans.push_back(y);
            }
        }


        return ans;
    }
};


//CONDENSED VERSION - 30 ms
class Solution {
unordered_map<int, vector<vector<int>>> mp;

public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    
        for(int i = 0; i < groupSizes.size(); i++){
            int x = groupSizes[i];
            if(mp.find(x) != mp.end() && mp[x].back().size() < x) mp[x].back().push_back(i);
            else mp[x].push_back({i});
        }

        vector<vector<int>> ans;
        for(auto x : mp){
            for(auto y : x.second)
                ans.push_back(y);
        }
        return ans;
    }
};

//7 ms by sorting an array / creating a sorted map
class Solution {
    map<int, vector<int>> mp;

public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        for(int i = 0; i < groupSizes.size(); i++) mp[groupSizes[i]].push_back(i);

        vector<vector<int>> ans;

        vector<int> arr;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            vector<int> x = itr -> second;

            for(int i = 0, count = 1; i < x.size(); i++, count++){
                arr.push_back(x[i]);

                if(count == itr -> first){
                    ans.push_back(arr);
                    arr.clear();
                    count = 0;
                }
            }
        }

        return ans;
    }
};