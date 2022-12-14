//3 ms
class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            int x = s[i] - 'a' + 1;
            temp += to_string(x);
        }

        while(k--){
            //cout << temp << '\n';
            ans = 0;

            for(int i = 0; i < temp.size(); i++){
                ans += temp[i] - '0';
            }

            int n = ans;
            temp = "";
            while(n){
                temp += (n % 10) + '0';
                n /= 10;
            }
        }

        return ans;
    }
};

//0 ms
class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        int ans = 0, n;

        for(char c : s) temp += to_string(c - 'a' + 1);

        while(k--){
            ans = 0;
            for(char c : temp) ans += c - '0';

            n = ans;
            temp = "";
            while(n){
                temp += (n % 10) + '0';
                n /= 10;
            }
        }

        return ans;
    }
};