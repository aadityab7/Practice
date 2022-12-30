class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = nums[0];
        
        for(int n : nums) ans |= n;

        return ans;
    }
};

/*
here we can perform the operation nums[i] & (nums[i] ^ x)
the AND operator can never add a set bit but can remove a set bit 
so in the final XOR the bit places which have odd number are set and 
even are not set so using & we can make the bits at a position odd

so in the final solution we are taking all the bits that are set accross all the numbers using OR (|)
*/