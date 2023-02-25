class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap;
        
        int mx_val = 1;

        for(int &num : nums){
            int original = num;
            while(num % 2 == 0) num /= 2;

            mx_val = max(mx_val, num);
            minheap.push({num, original});
        }
        
        int ans = INT_MAX;

        while(minheap.size() == nums.size()){
            int val = minheap.top().first, original_val = minheap.top().second;
            minheap.pop();
            
            ans = min(ans, mx_val - val);

            if((val % 2 == 1) || (val < original_val)){    
                mx_val = max(mx_val, val * 2);
                minheap.push({val * 2, original_val});
            }
        }

        return ans;
    }
};