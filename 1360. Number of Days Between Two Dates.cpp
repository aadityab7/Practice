class Solution {
private:
bool leap(int n){
    if(n % 100 != 0 && n % 4 == 0) return true; 
    else if(n % 400 == 0) return true;
    
    return false;
}
    
int mm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};     

int dayofyear(int y, int m, int d){
    int res = 0;
    
    for(int i = 1; i < m; i++){
        res += mm[i];
    }
    
    if(leap(y) && m > 2){
        res++;
    }
    
    res += d;
    
    return res;
}
    
public:
    int daysBetweenDates(string date1, string date2) {
        int y1 = stoi(date1.substr(0, 4));
        int m1 = stoi(date1.substr(5, 2));
        int d1 = stoi(date1.substr(8, 2));
        
        int y2 = stoi(date2.substr(0, 4));
        int m2 = stoi(date2.substr(5, 2));
        int d2 = stoi(date2.substr(8, 2));
        
        int ans = 0;
        
        if(y1 > y2){
            
            for(int i = y2 + 1; i < y1; i++){
                if(leap(i)) ans += 366;
                else ans += 365;
            }
            
            //days passed in this year
            ans += dayofyear(y1, m1, d1);
            
            //days remaining in that year
            ans += 365 - dayofyear(y2, m2, d2);
            
            if(leap(y2)) ans++;
            
        }
        else if(y2 > y1){
            
            for(int i = y1 + 1; i < y2; i++){
                if(leap(i)) ans += 366;
                else ans += 365;
            }
            
            //days passed in this year
            ans += dayofyear(y2, m2, d2);
            //29+6
            //days remaining in that year
            ans += 365 - dayofyear(y1, m1, d1);
            
            if(leap(y1)) ans++;
            
        }
        else{
            
            int x = dayofyear(y2, m2, d2);
            int y = dayofyear(y1, m1, d1);
            
            if(x > y) ans = x - y;
            else ans = y - x;
        }
        
        return ans;
    }
};