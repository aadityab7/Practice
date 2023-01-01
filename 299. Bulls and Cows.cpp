class Solution {
public:
    string getHint(string secret, string guess) {
        int arr1[10] = {}, arr2[10] = {};
        int a = 0, b = 0, n = secret.size();

        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) a++;
            else{
                arr1[secret[i] - '0']++;
                arr2[guess[i] - '0']++;
            }
        }

        for(int i = 0; i < 10; i++){
            b += min(arr1[i], arr2[i]);
        }

        string ans = to_string(a) + "A";
        ans += to_string(b) + "B";

        return ans;
    }
};