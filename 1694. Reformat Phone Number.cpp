class Solution {
public:
    string reformatNumber(string number) {
        string temp = "";
        string ans = "";
        
        for(int i = 0; i < number.size(); i++){
            if(number[i] >= '0' && number[i] <= '9') temp += number[i];
        }
        
        //we now have a string of numbers 
        int i = 0;
        int size = temp.size();
        
        while(i < size){
            if(size - i <= 4){
                //there are less than = 4 numbers remaining
                if(size - i == 4){
                    ans += temp.substr(i, 2);
                    ans += '-';
                    i += 2;
                }
                
                ans += temp.substr(i, (size - i));
                break;
            }
            else{
                //pair 3 numbers 
                ans += temp.substr(i, 3);
                i += 3;
                ans += '-';
            }
        }
        
        return ans;
    }
};