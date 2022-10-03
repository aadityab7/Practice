class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //start from the begining zero = true
        bool ans = false;
        for(int i = 0; i < bits.size(); i++){
            if(bits[i]){
                i++;
                ans = false;
            }
            else ans = true;
        }
        return ans;
    }
};

//OPTIMAL SOLUTION
//check from the last;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        
        if(n == 1) return true;
        if(bits[n - 1] == 0 && bits[n - 2] == 0) return true;
        
        //if the last second bit is 1
        //then if there are even number of continues prev 1's it is true;
        //else false;
        
        int ones = 0;
        for(int i = n - 2; i >= 0; i--){
            if(bits[i]) ones++;
            else break;
        }
        
        if(ones % 2) return false;
        
        return true;
    }
};