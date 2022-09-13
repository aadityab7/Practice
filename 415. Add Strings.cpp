class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans, temp = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0, res, x, y;
    
        while(i >= 0 && j >= 0){
            //add the numbers and store the carry 
            //x = stoi(num1[i]);
            x = num1[i] - '0';
            y = num2[j] - '0';
            //y = stoi(num2[j]);
            
            res = x + y + carry;
            
            //temp += to_string(res % 10);
            temp += (res % 10) + '0';
            carry = res / 10;
            
            i--;
            j--;
        }
        
        while(i >= 0){
            //x = stoi(num1[i]);
            x = num1[i] - '0';
            res = x + carry;
            
            // temp += to_string(res % 10);
            temp += (res % 10) + '0';
            carry = res / 10;
            
            i--;
        }
        
        while(j >= 0){
            // y = stoi(num2[j]);
            y = num2[j] - '0';
            res = y + carry;
            
            // temp += to_string(res % 10);
            temp += (res % 10) + '0';
            carry = res / 10;
            
            j--;
        }
        
        if(carry){
            temp += to_string(carry);
        }
        
        ans = "";
        
        for(int i = temp.size() - 1; i >= 0; i--){
            ans += temp[i];
        }
        return ans;
        
    }
};