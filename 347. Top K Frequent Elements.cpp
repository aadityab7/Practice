class Solution {
    static bool comp(pair<int,int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }

        //create a vector of pairs and sort by frequency
        vector<pair<int, int>> arr;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            arr.push_back({itr -> first, itr -> second});
        }

        sort(arr.begin(), arr.end(), comp);

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};



//using priority queue (heap)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        
        for(int num : nums)
            mp[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(pair<int, int> p : mp){
            pq.push({p.second, p.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;

        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};