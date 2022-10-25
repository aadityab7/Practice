class Solution {
//     int search(vector<int>&arr, int target){
//         int l = 0;
//         int r = arr.size() - 1;
//         int mid;
        
//         while(l < r){
//             mid = (l + r) / 2;
//             if(arr[mid] == target) return mid;
//             else if(arr[mid] < target) l = mid + 1;
//             else r = mid;
//         }
        
//         return mid;
        
//         //2 3 5 6    
//     }
    
    
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //sort 1 array
        //iterate through other
        //find that element and check if a element 
        sort(arr2.begin(), arr2.end());
        
        int ans = 0;
        
        
        for(int i = 0; i < arr1.size(); i++){
            
            //check for the closest elements of arr2 
            int x = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            //cout << x << '\n';
            //now we have the lower bound the element equal to or bigger than num
            
            int flag = 1, num;
            
            //it is not the greatest element
            if(x != arr2.size()){
                num = arr2[x];
                if(abs(num - arr1[i]) <= d) flag = 0;
            }
            
            
            //it is not the smallest 
            if(x){
                //x is not 0
                num = arr2[x - 1];
                if(abs(num - arr1[i]) <= d) flag = 0;
            }
            
            if(flag) ans++;
        }
        
        return ans;
        
    }
};