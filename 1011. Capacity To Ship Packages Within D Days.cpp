class Solution {
    bool feasible(int cap, const vector<int> & weights, int days){
        //check in how many days will it take for us to ship all weights
        //with capacity cap of ship
        int curr_load = 0, curr_days = 1;

        for(int weight : weights){
            curr_load += weight;

            if(curr_load > cap){
                curr_load = weight;
                curr_days++;
            }
        }

        return curr_days <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        //Use Binary Search
        //l = max_weight, r = sum_of_all_weights
        
        int l = 0, r = 0;
        for(int &weight : weights){
            r += weight;
            l = max(l, weight);
        }

        int ans = r;

        while(l <= r){
            int mid = (l + r) / 2;

            if(feasible(mid, weights, days)){
                ans = mid;
                //check if any smaller capacity will work or not
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};