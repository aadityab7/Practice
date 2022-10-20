class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        //move everything at 1 or 2
        //if we choose 2 -> cost = odd coins
        //else cost = even coins
        
        int odd = 0, even = 0;
        for(int i = 0; i < position.size(); i++){
            if(position[i] % 2) odd++;
            else even++;
        }
        
        if(odd < even) return odd;
        
        return even;
    }
};