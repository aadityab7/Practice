//309ms
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> st;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        
        int i = 1;
        auto itr = st.begin();
        
        while(i <= nums.size()){
            if(itr != st.end() && i == *itr){
                itr++;
            }
            else{
                ans.push_back(i);
            }
            
            i++;
        }
        
        return ans;
    }
};

//49ms
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            //mark this index as negetive
            int x = abs(nums[i]);
            
            if(nums[x - 1] > 0){
                nums[x - 1] = 0 - nums[x - 1];
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};