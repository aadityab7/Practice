//use map to store last position of card in deck - 335 ms
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = INT_MAX;
        //store last position
        unordered_map<int, int> mp;

        for(int i = 0; i < cards.size(); i++){
            if(mp.find(cards[i]) != mp.end()){
                ans = min(ans, i - mp[cards[i]] + 1);
            }
            
            mp[cards[i]] = i;
        }


        if(ans == INT_MAX) return -1;
        else return ans;
    }
};

//using a array instead of map - 292 ms
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = INT_MAX;
        vector<int> arr(1e6 + 1, -1);

        for(int i = 0; i < cards.size(); i++){
            if(arr[cards[i]] != -1) ans = min(ans, i - arr[cards[i]] + 1);
            arr[cards[i]] = i;
        }

        if(ans == INT_MAX) return -1;
        else return ans;
    }
};