class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;

        vector<int> ltr(n), rtl(n);

        ltr[0] = arr[0];
        rtl[n - 1] = arr[n - 1];

        for(int i = 1; i < n; i++){
            ltr[i] = arr[i] ^ ltr[i - 1];
            rtl[n - i - 1] = arr[n - i - 1] ^ rtl[n - i]; 
        }

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j; k < n; k++){
                    int x = rtl[i] ^ rtl[j];
                    int y = ltr[k] ^ ltr[j - 1];

                    if(x == y) ans++;
                }
            }
        }

        return ans;
    }
};

/*
2 = 10
3 ^ 1 = 11 ^ 01 = 10

01
01

000
111
111

110
111
001

001
110
111

000
111
*/