class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxheap;
        
        for(int &num : nums) maxheap.push(num);
        
        long long ans = 0;
        
        for(int i = 0; i < k; i++){
            long long temp = maxheap.top(); maxheap.pop();
            
            ans += temp;
            
            maxheap.push(ceil(temp / 3.0));
        }
        
        return ans;
    }
};