class Solution {
public:
    string countAndSay(int n) {
        //take n and return the string 
        string ans = "1";

        for(int i = 2; i <= n; i++){
            string temp = ans;
            string x = "";

            //go through temp ltr
            int count = 1;
            char num = temp[0];

            for(int j = 1; j < temp.size(); j++){
                if(temp[j] != num){
                    x += to_string(count);
                    x += num;
                    num = temp[j];
                    count = 1;
                }
                else{
                    count++;
                }
            }

            x += to_string(count);
            x += num;

            ans = x;
        }

        return ans;

    }
};

class Solution {
public:
    string countAndSay(int n) {
        //take n and return the string 
        string ans = "1";
        int i, j, count;
        char num;

        for(i = 2; i <= n; i++){
            string x = "";

            count = 1;
            num = ans[0];

            for(j = 1; j < ans.size(); j++){
                if(ans[j] != num){
                    x += to_string(count);
                    x += num;
                    num = ans[j];
                    count = 1;
                }
                else{
                    count++;
                }
            }

            x += to_string(count);
            x += num;

            ans = x;
        }

        return ans;

    }
};