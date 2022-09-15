class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //for each nums1 element find that element in nums2 and then find the number greater than that
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums2.size() - 1; i++){
            for(int j = i + 1; j < nums2.size(); j++){
                if(nums2[j] > nums2[i]){
                    //if there exists an element greater than this then add it to the map
                    mp[nums2[i]] = nums2[j];
                    break;
                }
            }
        }//end for
        
        for(int i = 0; i < nums1.size(); i++){
            if(mp[nums1[i]]){
                ans.push_back(mp[nums1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //for each nums1 element find that element in nums2 and then find the number greater than that
        vector<int> ans;
        unordered_map<int, int> mp;
        stack<int> st;
        
        for(int i = 0; i < nums2.size(); i++){
            
            while(!st.empty() && nums2[i] > st.top()){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            
            st.push(nums2[i]);
            
        }
        
        for(int i = 0; i < nums1.size(); i++){
            if(mp[nums1[i]]){
                ans.push_back(mp[nums1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //for each nums1 element find that element in nums2 and then find the number greater than that
        vector<int> ans;
        unordered_map<int, int> mp;
        stack<int> st;
        int x;
        
        for(int i = 0; i < nums2.size(); i++){
            x = nums2[i];
            
            while(!st.empty() && x > st.top()){
                mp[st.top()] = x;
                st.pop();
            }
            
            st.push(x);
            
        }
        
        for(int i = 0; i < nums1.size(); i++){
            if(mp[nums1[i]]){
                ans.push_back(mp[nums1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};