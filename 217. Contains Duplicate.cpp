class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> st;
        
        for(int i = 0; i < nums.size(); i++){
            
            auto itr = st.find(nums[i]);
            
            if(itr != st.end()){
                return true;
            }
            
            st.insert(nums[i]);
        }
        
        return false;
    }
};

//ANOTHER ONE - BEST ONE
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }    
        
        return (st.size() != nums.size());
    }
};