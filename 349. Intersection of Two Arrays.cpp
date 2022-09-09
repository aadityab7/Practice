//7ms
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int arr[1001] = {}, arr2[1001] = {};
        
        for(int i = 0; i < nums1.size(); i++){
            arr[nums1[i]] = 1;
        }
        
        for(int i = 0; i < nums2.size(); i++){
            arr2[nums2[i]] = 1;
        }
        
        vector<int> ans;
        for(int i = 0; i < 1001; i++){
            if(arr[i] && arr2[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};

/*
7ms
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a, b;
        
        
        for(int i = 0; i < nums1.size(); i++){
            a.insert(nums1[i]);
        }
        
        for(int i = 0; i < nums2.size(); i++){
            b.insert(nums2[i]);
        }
        
        vector<int> ans;
        
        
        
        for(auto itr = a.begin(); itr != a.end(); itr++){
            if(b.find(*itr) != b.end()){
                ans.push_back(*itr);
            }
        }
        
        return ans;
        
    }
};
*/

/*
20ms
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a, b;
        
        
        for(int i = 0; i < nums1.size(); i++){
            a.insert(nums1[i]);
        }
        
        for(int i = 0; i < nums2.size(); i++){
            b.insert(nums2[i]);
        }
        
        vector<int> ans;
        
        auto itr = a.begin();
        auto it = b.begin();
        
        while(itr != a.end() && it != b.end()){
            if(*itr == *it){
                ans.push_back(*itr);
                itr++;
                it++;
            }
            else if(*itr > *it){
                it++;
            }
            else{
                itr++;
            }
        }
        
        return ans;
        
    }
};
*/