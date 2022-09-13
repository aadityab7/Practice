class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //using 3 pointers i will iterate from 0 to n - 2
        //then j and k will find the best possible values for this i 
        //-4 -1 1 2
        //
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        
        for(int i = 0; i < n - 2; i++){
            
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int temp = nums[i] + nums[j] + nums[k];
                
                if(abs(target - temp) < abs(target - ans)){
                    ans = temp;
                }
                
                if(temp > target){
                    k--;
                }
                else if(temp < target){
                    j++;
                }
                else{
                    return target;
                }
            }
            
        }
        
        return ans;
        
        
        
//         int min_diff = INT_MAX;
//         int flag = 0;
        
//         for(int i = 0; i < nums.size() - 2; i++){
//             for(int j = i + 1; nums.size() - 1; j++){
//                 for(int k = j + 1; k < nums.size(); k++){
//                     if(abs(target - (nums[i] + nums[j] + nums[k])) < min_diff){
//                         min_diff = abs(target - (nums[i] + nums[j] + nums[k]));
//                         if(target < nums[i] + nums[j] + nums[k]){
//                             flag = 1;
//                         }
//                     }
//                 }
//             }
//         }
        
//         if(flag){
//             return target + min_diff;
//         }
//         else{  
//             return target - min_diff;
//         }
    }
};