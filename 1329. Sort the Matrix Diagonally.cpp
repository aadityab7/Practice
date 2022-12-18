// 7 ms
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        int x, y, i, j;
        vector<int> arr;

        for(i = 0; i < c - 1; i++){
            arr.clear();
            x = 0; y = i;

            while(x < r && y < c) arr.push_back(mat[x++][y++]);
            
            sort(arr.begin(), arr.end());

            x = 0; y = i;

            j = 0;
            while(x < r && y < c) mat[x++][y++] = arr[j++];
        }

        for(i = 1; i < r - 1; i++){
            arr.clear();
            x = i; y = 0;

            while(x < r && y < c) arr.push_back(mat[x++][y++]);

            sort(arr.begin(), arr.end());

            x = i; y = 0;

            j = 0;
            while(x < r && y < c) mat[x++][y++] = arr[j++];
        }

        return mat;
    }
};


//using the same array 
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size(), i, k, bound;
        int a[min(r,c)];

        //for first row
        for(i = 0; i < c - 1; i++){
            bound = min(r, c - i);

            for(k = 0; k < bound; k++) a[k] = mat[k][i + k];
            
            sort(a, a + bound);

            for(k = 0; k < bound; k++) mat[k][i + k] = a[k];
        }

        //for first column
        for(i = 1; i < r - 1; i++){
            bound = min(r - i, c);

            for(k = 0; k < bound; k++) a[k] = mat[i + k][k];

            sort(a, a + bound);

            for(k = 0; k < bound; k++) mat[i + k][k] = a[k];
        }

        return mat;
    }
};