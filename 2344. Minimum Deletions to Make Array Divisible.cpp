//find gcd and smallest number that divides it - 180 ms
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        //find gcd of numsDivide
        int req = numsDivide[0];
        for(int x : numsDivide) req = gcd(req, x);

        // sort(nums.begin(), nums.end());

        // int ans = 0;

        // for(int &x : nums){
        //     if(req % x == 0) return ans;
        //     else ans++;
        // }

        map<int, int> mp;

        for(int x : nums) mp[x]++;

        int ans = 0;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(req % itr -> first == 0) return ans;
            else ans += itr -> second; 
        }

        return -1;
    }
};