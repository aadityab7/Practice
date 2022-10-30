class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //calc the total size of both the arrays 
        //if odd we need size / 2 element only -> 5 -> 2
        //else 2 elements 
        
        double ans = 0, prev = 0;
        
        int n = nums1.size(), m = nums2.size();
        int size = n + m;
        
        int i = 0, j = 0;
        int x = size / 2;
        
        while(x >= 0){
            //cout << x << '\n';
            prev = ans;
            
            if(i == nums1.size()){
                ans = nums2[j++];
            }
            else if(j == nums2.size()){
                ans = nums1[i++];
            }
            else if(nums1[i] < nums2[j]){
                ans = nums1[i++];
            }
            else{
                ans = nums2[j++];
            }
            
            x--;
        }
        
        
        if(size % 2 == 0){
            //if even we need 1 more element
            //1 2 3 4
            ans += prev;
            ans /= 2.0;
        }
        
        return ans;
        
    }
};