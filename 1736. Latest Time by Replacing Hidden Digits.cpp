class Solution {
public:
    string maximumTime(string time) {
        //ans for hours is between 00 and 23
        char a = time[0];
        char b = time[1];

        char c = time[3];
        char d = time[4];

        //now we have to perform replacement 
        /*
        if d missing replace with 9
        if c missing replace with 5
        if a and b both missing 23
        else if a is missing replace with 2 if b < 4
        else a = 1
        if b is ? replace with 3 if a == 3
        else b = 9
        */

        if(d == '?') d = '9';
        if(c == '?') c = '5';

        if(a == '?' && b == '?'){
            a = '2';
            b = '3';
        }
        else{
            if(a == '?'){
                if(b - '0' < 4) a = '2';
                else a = '1';
            }
            else if (b == '?'){
                if(a - '0' == 2) b = '3';
                else b = '9'; 
            } 
        }

        string ans = "";
        
        ans += a;
        ans += b;
        ans += ":";
        ans += c; 
        ans += d;

        return ans;
    }
};

//in place
class Solution {
public:
    string maximumTime(string time) {

        char a = time[0], b = time[1];

        if(time[4] == '?') time[4] = '9';
        if(time[3] == '?') time[3] = '5';

        if(a == '?' && b == '?'){
            a = '2';
            b = '3';
        }
        else{
            if(a == '?'){
                if(b - '0' < 4) a = '2';
                else a = '1';
            }
            else if (b == '?'){
                if(a - '0' == 2) b = '3';
                else b = '9'; 
            } 
        }

        time[0] = a;
        time[1] = b;

        return time;
    }
};

        //ans for hours is between 00 and 23
        //now we have to perform replacement 
        /*
        if d missing replace with 9
        if c missing replace with 5
        if a and b both missing 23
        else if a is missing replace with 2 if b < 4
        else a = 1
        if b is ? replace with 3 if a == 3
        else b = 9
        char c = time[3];
        char d = time[4];
        */