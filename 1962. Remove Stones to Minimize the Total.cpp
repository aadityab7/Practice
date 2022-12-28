class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < piles.size(); i++){
            pq.push(piles[i]);
        }

        for(int i = 0; i < k; i++){
            //get the max value
            int x = pq.top();
            pq.pop();
            pq.push(ceil(x / 2.0));
        }

        int ans = 0;

        while(pq.size()){
            //cout << pq.top() << ' ';
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int arr[10001] = {};

        for(int p : piles) arr[p]++;

        int i = 10000;

        while(k > 0 && i >= 0){
            while(i >= 0 && arr[i] == 0) i--;

            //divide the number by 2
            arr[i]--;

            int x = ceil(i / 2.0);
            arr[x]++;

            k--;
        }

        int ans = 0;
        
        for(int i = 0; i <= 10000; i++){
            ans += i * arr[i];
        }

        return ans;
    }
};