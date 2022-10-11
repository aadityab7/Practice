class Solution {
public:
    int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    int dayOfYear(string date) {
        string year = date.substr(0,4);
        int y = stoi(year);
        
        string month = date.substr(5,2);
        int m = stoi(month);
        
        string day = date.substr(8,2);
        int d = stoi(day);
        
        //cout << d << ' ' << m << ' ' <<  y << '\n';
        
        int ans = d;
        
        for(int i = 0; i < m; i++){
            ans += mon[i];
        }
        
        //check for leap year
        if(m > 2){
            if(y % 100 == 0){
                if(y % 400 == 0)ans++;
            }
            else{
                if(y % 4 == 0) ans++;
            }
        }
        
        return ans;
    }
};

//9 + 0 + 31
//40

class Solution {
public:
    int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    int dayOfYear(string date) {
        int y = stoi(date.substr(0,4)), m = stoi(date.substr(5,2)), d = stoi(date.substr(8,2));
        
        int ans = d, i;
        
        for(i = 0; i < m; i++) ans += mon[i];
        
        if(m > 2){
            if(y % 100 == 0){
                if(y % 400 == 0)ans++;
            }
            else{
                if(y % 4 == 0) ans++;
            }
        }
        
        return ans;
    }
};

//9 + 0 + 31
//40