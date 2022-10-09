class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        
        int inc = 1;
        int in = 0;
        //increasing and then decreasing
        
        for(int i = 1; i < arr.size(); i++){
            if(inc){
                if(arr[i] < arr[i - 1]){
                    inc = 0;
                }
                else if(arr[i] > arr[i - 1]) in = 1;
                else return false;
            }
            else{
                if(!in) return false;
                
                if(arr[i] >= arr[i - 1]) return false;
            }
        }
        
        return !inc;
    }
};

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        
        //increasing and then decreasing
        
        int i = 1;
        while(i < arr.size() && arr[i] > arr[i - 1]) i++;
            
        if(i == 1 || i == arr.size()) return false;

        while(i < arr.size() && arr[i] < arr[i - 1]) i++;

        if(i != arr.size()) return false;
        
        return true;
    }
};