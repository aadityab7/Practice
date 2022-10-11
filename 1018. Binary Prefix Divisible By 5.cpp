class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum *= 2;
            if(nums[i]) sum++;
            
            sum %= 10;
            
            if(sum == 0 || sum == 5) ans[i] = true;
        }
        
        return ans;
    }
};

/*
0 - 0
5 - 101
10 - 1010
15 - 1111
20 - 10100
25 - 11001

//when is a number divisible by 5 when last digit is 5 or 0
msb to lsb
prevsum *= 2
prevsum += 1

0 = 0
1 = 1
10 = 2
11 = 3
100 = 4
101 = 5
110 = 6
111 = 7
1000 = 8
1001 = 9
1010 = 10 % 10 = 0
1011 = 11 % 10 = 1

*/