class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;
        int x;

        for(int num : nums){
            st.insert(num);
            x = 0;

            while(num){
                x *= 10;
                x += num % 10; 
                num /= 10; 
            }

            st.insert(x);
        }

        return st.size();
    }
};