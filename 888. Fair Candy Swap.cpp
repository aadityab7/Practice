class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans(2,0);
        
        unordered_set<int> st(aliceSizes.begin(), aliceSizes.end());

        int alice = 0, bob = 0;
        for(int i = 0; i < aliceSizes.size(); i++){
            alice += aliceSizes[i];
        }
        
        for(int i = 0; i < bobSizes.size(); i++){
            bob += bobSizes[i];
        }
        
        //alice - a + b = bob - b + a
        
        //alice - bob = 2a - 2b
        //or 
        //bob - alice = 2b - 2a
        
        //when bob is bigger 
        //a = b - diff / 2
        
        //when alice is bigger
        //a = b + diff / 2;
        
        int diff = alice - bob;
        
        for(int i = 0; i < bobSizes.size(); i++){
            int x = bobSizes[i] + (diff / 2);
            if(st.find(x) != st.end()){
                ans[0] = x;
                ans[1] = bobSizes[i];
                break;
            }
        }
        
        return ans;
        
    }
};

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans(2);
        
        unordered_set<int> st;

        int alice = 0, bob = 0;
        for(int i = 0; i < aliceSizes.size(); i++){
            alice += aliceSizes[i];
            st.insert(aliceSizes[i]);
        }
        
        for(int i = 0; i < bobSizes.size(); i++){
            bob += bobSizes[i];
        }
        
        int diff = (alice - bob) / 2;
        for(int i = 0; i < bobSizes.size(); i++){
            if(st.find(bobSizes[i] + diff) != st.end()){
                ans[0] = bobSizes[i] + diff;
                ans[1] = bobSizes[i];
                break;
            }
        }
        
        
        return ans;
    }
};