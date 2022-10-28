class Solution {
    map<string, int> mo= {
        {"Jan",1},
        {"Feb",2},
        {"Mar",3},
        {"Apr",4},
        {"May",5},
        {"Jun",6},
        {"Jul",7},
        {"Aug",8},
        {"Sep",9},
        {"Oct",10},
        {"Nov",11},
        {"Dec",12}
    };
    
public:
    string reformatDate(string date) {
        string d = "", m = "", y = "";
        int i = 0;
        
        //get date 
        while(date[i] >= '0' && date[i] <= '9'){
            d += date[i++];
        }
        
        while(date[i] != ' ') i++;
        
        i++;
        
        //cout << d << ' ';
        
        
        while(date[i] != ' '){
            m += date[i++];
        }
        
        i++;
        
        //cout << m << ' ';
        
        for(; i < date.size(); i++){
            y += date[i];
        }
        
        //cout << y << '\n';
        
        string ans = y;
        ans += '-';
        
        int mm = mo[m];
        if(mm < 10) ans += '0';
        ans += to_string(mm);
        ans += '-';
        
        if(d.size() == 1) ans += '0';
        ans += d;
        
        return ans;
    }
};