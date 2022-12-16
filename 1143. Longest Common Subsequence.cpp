//28 ms
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> arr((n+ 1), vector<int>((m + 1), 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //find the max from arr[i - 1][j] & arr[i][j - 1]
                
                if(text1[i] == text2[j]){
                    arr[i + 1][j + 1] = arr[i][j] + 1;
                }
                else{
                    arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]); 
                }
            }
        }


        return arr[text1.size()][text2.size()];
    }
};

//25ms - Uses Less Memory
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size(), i, j;

        vector<vector<int>> arr(2, vector<int>((m + 1), 0));

        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(text1[i] == text2[j]) arr[1][j + 1] = arr[0][j] + 1;
                else arr[1][j + 1] = max(arr[0][j + 1], arr[1][j]); 
            }
            arr[0] = arr[1];
        }

        return arr[1][m];
    }
};