//MY SOLUTION
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         set<int> numbers;
        
//         int n = nums.size();
//         int a;
        
//         for(int i = 0; i < n; i++){
//             a = nums[i];
        
//             if(numbers.find(a) == numbers.end()){
//                 numbers.insert(a);
//             }
//             else{
//                 numbers.erase(a);
//             }
//         }
        
//         //the remaining element is ans
//         auto itr = numbers.begin();
        
//         int ans = *itr;
        
//         return ans;
        
//     }
// };

//Solution using Bitwise XOR (because a ^ a = 0 and a ^ a ^ b = b) all elements occuring twice will be canceled 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            ans = ans ^ nums[i];       
        }
    
        return ans;
        
    }
};