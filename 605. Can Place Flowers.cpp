class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        if(n == 0) return true;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]==0)
            if(i == 0 || arr[i - 1] == 0){
                //then this place is available from the back 
                if(i == arr.size() - 1 || arr[i + 1] == 0){
                    //available from next
                    arr[i] = 1;
                    n--;
                }
            }
            
            if(!n) return true;
        }
        
        return false;
    }
};

/*
1 0 0 1
1 0 0 0 1
1 0 0 0 0 1
1 0 0 0 0 0 1

count the continuous 0's and planting space = 
*/