//My Approach - using Priority Queue - 43ms
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                pq.push(matrix[i][j]);
                if(pq.size() > k) pq.pop();
            }
        }

        return pq.top();
    }
};

//Utilising the fact that matrix has sorted rows
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minheap;

        for(int i = 0; i < n; i++) 
            minheap.push({matrix[i][0], i, 0});


        int ans = matrix[0][0];

        for(int i = 0; i < k; i++){
            //get the minimum element from heap - top()
            vector<int> min_ele = minheap.top(); minheap.pop();
            int r = min_ele[1], c = min_ele[2];
            ans = min_ele[0];
            if(c < n - 1) minheap.push({matrix[r][c + 1], r, c + 1}); 
        }

        return ans;

    }
};

//Binary Search - 23 ms
class Solution {
    int countEqualOrLess(int num, const vector<vector<int>> & matrix){
        int count = 0, n = matrix.size();
        int c = n - 1;

        for(int i = 0; i < n; i++){
            while(c >= 0 && matrix[i][c] > num) c--;

            count += (c + 1);
        }

        return count;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), ans = -1, mid;
        int l = matrix[0][0], r = matrix[n - 1][n - 1];

        while(l <= r){
            mid = (l + r) / 2;

            if(countEqualOrLess(mid, matrix) >= k){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};