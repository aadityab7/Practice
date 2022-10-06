class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0;
        for(int i = 0; i < bills.size(); i++){
            
            if(bills[i] == 10){
                
                //we need exactly 1 5note
                
                if(f) f--;
                else return false;
                
                t++;
                
            }
            else if(bills[i] == 20){
                
                //we need at least one f
                if(f) f--;
                else return false;
                
                //now we need 1 ten or 2 fives
                if(t) t--;
                else if(f > 1) f -= 2;
                else return false;
                
            }
            else f++;
            
        }
        
        return true;
    }
};