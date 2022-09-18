class Solution {
public:
    map <int, vector<string>> hours = {
        {0, {"0"}},
        {1, {"1", "2", "4", "8"}},
        {2, {"3", "5", "9", "6", "10"}},
        {3, {"7", "11"}}
    };
    
    map <int, vector<string>> mins = {
        {0, {"00"}},
        {1, {"01", "02", "04", "08", "16", "32"}},
        {2, {
            "03", "05", "09", "17", "33", "06", "10", "18", "34", 
            "12", "20", "36", "24", "40", "48"
        }},
        {3, {"07", "11", "19", "35", "14", "22", "38", "28", "44", "49",
            "50", "52", "56", "41", "42", "37", "13", "21", "25", "26"    
        }},
        {4, {"15", "23", "27", "29", "30", "39", "43", "45", "46", "57",
            "58", "53", "54", "51"
        }},
        {5, {"31", "47", "55", "59"}}
    };
    
  
    
    
    vector<string> readBinaryWatch(int n) {
        //at most 3 in h
        //at most 5 in m
        
        //at most 8 in total
        vector<string> ans;
        if(n > 8) return ans;
        
        //first find out posible hours 0, 1, 2, 3
        //eliminate where n - 5 = i or i = 0
        int i = 0;
        
        if(n > 5){
            i = n - 5;
        }
        
        int limit = min(n, 3);
        
        //for each hour find the posible mins n - i
        //0 and 1
        for(; i <= limit; i++){
            //now we have n - i leds for mins
            vector<string> temp;
            
            vector<string> t = hours[i];
            
            for(int j = 0; j < t.size(); j++){
                temp.push_back(t[j] + ":");
            }
            
            vector<string> m = mins[n - i];
            for(int j = 0; j < m.size(); j++){
                //take all the times in temp and 
                for(int k = 0; k < temp.size(); k++){
                    ans.push_back(temp[k] + m[j]);
                }
            }
            
        }
        
        return ans;
        
        
    }
    
};

/*
0 = {0}
1 = {1, 2, 4, 8}
2 = {3, 5, 9, 6, 10}
3 = {7, 11}


*/