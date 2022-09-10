//30ms

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        
        auto itr = st.rbegin();
        
        if(st.size() > 2){
            itr++;
            itr++;
        }
        
        return *itr;
    }
};

//5ms

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long f, s, t;
        f = s = t = LONG_MIN;
        int x;
        
        for(int i = 0; i < nums.size(); i++){
            x = nums[i];
            
            if(f == x || s == x || t == x){
                continue;
            }
            
            if(x > f){
                t = s;
                s = f;
                f = x;
            }
            else if(x > s){
                t = s;
                s = x;
            }
            else if(x > t){
                t = x;
            }
            
        }
        
        if(t != LONG_MIN){
            return (int)t;
        }
        else{
            return (int)f;
        }
    
    }
};