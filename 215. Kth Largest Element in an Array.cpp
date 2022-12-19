class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &n : nums){
            if(pq.size() < k) pq.push(n);
            else if(n > pq.top()){
                pq.pop();
                pq.push(n);
            }
        }

        return pq.top();
    }
};

//by sorting an array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};