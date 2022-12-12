class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //we have to run our sequence n / 2 times
        int x = n / 2;

        for(int i = 0; i < x; i++){
            for(int j = i; j < n - i - 1; j++){
                int a = matrix[i][j];
                // int b = matrix[j][n - i - 1];
                // int c = matrix[n - i - 1][n - j - 1];
                // int d = matrix[n - j - 1][i];

                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = a;
            }
        }

    }
};

/*
1

1 2 
3 4 
x = 1

i = 1, j = 0
j n - i - 1

0 1 - 1 2 



0 0 - 0 3 
*0 1 - 1 3 
0 2 - 2 3
0 3 - 3 3

1 0 - 0 2
1 1 - 1 2
1 2 - 2 2
*1 3 - 3 2

*2 0 - 0 1
2 1 - 1 1
2 2 - 2 1
2 3 - 3 1

3 0 - 0 0
3 1 - 1 0
*3 2 - 2 0
3 3 - 3 0
*/