class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        //use binary search to find the min time required to complete trips
        long long l = 1, r = 1e14, mid, trips;

        while(l < r){
            mid = l + (r - l) / 2;
            
            trips = 0;
            for(int &t : time)
                trips += mid / t;

            if(trips >= totalTrips) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};