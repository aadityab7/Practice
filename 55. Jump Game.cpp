class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        
        //keep record of the max index you can reach and keep traversing the array till you reach the limit or end
        //update the limit if you find a greater index

        for(int limit = 0; i <= limit && i < nums.size(); i++){
            limit = max(limit, i + nums[i]);
        }

        return i == nums.size();
    }
};