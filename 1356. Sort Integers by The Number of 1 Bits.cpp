class Solution {
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second) return a.first < b.first;
        
        return a.second < b.second;
    }
    
public:
    vector<int> sortByBits(vector<int>& arr) {
        int size = arr.size();
        vector<pair<int, int>> v(size);
        int count;
        
        for(int i = 0; i < size; i++){
            count = 0;
            int x = arr[i];
            while(x){
                if(x % 2) count++;
                x /= 2;
            }
            v[i] = {arr[i], count};
        }
        
        sort(v.begin(), v.end(), comp);
        
        for(int i = 0; i < size; i++){
            arr[i] = v[i].first;
        }
        
        return arr;
    }
};