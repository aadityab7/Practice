class Solution {
public:
    string reverseStr(string s, int k) {
        //"abcdefg" s = 7 / 4 => 2
        //2
        //start = 0 and end = 7 - 0 or 4 => 4
        //abcd n = 2 0
        //start = 2 * 2 * 1 = 4 end = 7 - 4  = 3 or 4 
        
        int start, end;
        int size = s.size();
        int count;
        
        int times = ceil((float) size / (2.0 * k));
        
        string ans = "";
        
        for(int i = 0; i < times; i++){
            //each time take 2 * k elements and then reverse the first k elements
            start = (2 * k * i);
            
            int x = size - start;
            int y = 2 * k;
            
            count = x;
            
            if(y < x){
                count = y;
            }
            
            //cout << count << '\n';
            
            string temp = s.substr(start, count);
            
            //if less then k elements remain reverse them all 
            int n = temp.size();
            
            if(n > k){
                n = k;
            }
           
            for(int j = 0; j < n / 2; j++){
                //swap i and n - 1 - i 
                char t = temp[j];
                temp[j] = temp[n - j - 1];
                temp[n - j - 1] = t;
            }
            
            ans += temp;
        }
        
        return ans;
    }
};