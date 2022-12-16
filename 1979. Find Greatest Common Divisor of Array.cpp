class Solution {

//using euclidean theoram
int gcd_(int a, int b){
    if(b == 0) return a;
    return gcd_(b, a % b);
}

public:
    int findGCD(vector<int>& nums) {
        int max = nums[0], min = nums[0];

        for(int i : nums){
            if(i > max) max = i;
            if(i < min) min = i;
        }

        return gcd_(max, min);
    }
};

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max = nums[0], min = nums[0];

        for(int i : nums){
            if(i > max) max = i;
            if(i < min) min = i;
        }

        return gcd(min, max);
    }
};