//42 ms
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         //using map
//         map<long, int> mp;
//         int n = nums.size();
        
//         long ans = nums[0];
        
//         for(int i = 0; i < n; i++){
//             auto itr = mp.find(nums[i]);
            
//             if(itr != mp.end()){
//                 mp[nums[i]]++;
//             }
//             else{
//                 mp[nums[i]] = 1;
//             }
            
//             if(mp[nums[i]] > (n / 2)){
//                 ans = nums[i];
//                 break;
//             }
//         }
        
//         return ans;
        
//     }
// };


//38 ms
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         //using map
//         map<long, int> mp;
//         int n = nums.size();
        
//         long ans = nums[0];
        
//         for(int i = 0; i < n; i++){
//             auto itr = mp.find(nums[i]);
            
//             if(itr != mp.end()){
//                 mp[nums[i]]++;
//             }
//             else{
//                 mp[nums[i]] = 1;
//             }
//         }
        
//         // if(mp[nums[i]] > (n / 2)){
//         //     ans = nums[i];
//         //     break;
//         // }
        
//         for(auto itr = mp.begin(); itr != mp.end(); itr++){
//             if(itr->second > (n / 2)){
//                 ans = itr->first;
//                 break;
//             }
//         }
        
//         return ans;
        
//     }
// };


//31 ms
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         //using map
//         map<long, int> mp;
//         int n = nums.size();
        
//         long ans = nums[0];
        
//         for(int i = 0; i < n; i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto itr = mp.begin(); itr != mp.end(); itr++){
//             if(itr->second > (n / 2)){
//                 ans = itr->first;
//                 break;
//             }
//         }
        
//         return ans;
        
//     }
// };

//25ms
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using map
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        long ans = nums[0];
        int curr = 1;
        
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                curr++;
            }
            else{
                curr = 1;
            }
            
            if(curr > n / 2){
                ans = nums[i];
                break;
            }
        }
    
        return ans;
        
    }
};