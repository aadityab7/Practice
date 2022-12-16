class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int, int> mp;

        for(int i = 0; i < ranges.size(); i++){
            if(mp.find(ranges[i][0]) != mp.end()){
                if(ranges[i][1] > mp[ranges[i][0]]) mp[ranges[i][0]] = ranges[i][1];
            }
            else mp[ranges[i][0]] = ranges[i][1];
        }

        int curr = left;

        while(curr <= right){
            int x = curr;

            for(auto itr = mp.begin(); itr != mp.end(); itr++){
                if(itr -> first <= curr && curr <= itr -> second){
                    curr = itr -> second + 1;
                }
            }

            if(curr == x) return false;
        }

        return true;
    }
};

//0 ms
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int curr = left, x;

        while(curr <= right){
            x = curr;

            for(int i = 0; i < ranges.size(); i++)
                if(curr >= ranges[i][0] && curr <= ranges[i][1]) 
                    curr = ranges[i][1]+1;
            

            if(curr == x) return false;
        }

        return true;
    }
};