class Solution {
    static bool comp(vector<int> &v1, vector<int> &v2){
        if(v1[0] == v2[0]) return v1[1] < v2[1];
        
        return v1[0] < v2[0];
    }

public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) tasks[i].push_back(i);    

        sort(tasks.begin(), tasks.end(), comp);

        vector<int> visited(tasks.size(), 0);

        long long curr = tasks[0][0];
        int ptr = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minheap;
        vector<int> temp;

        for(int i = 0; i < n; i++){
            //put all the processess with enque time less than equal to curr in pq (minheap)
            while(ptr < n && tasks[ptr][0] <= curr){
                minheap.push({tasks[ptr][1], tasks[ptr][2], tasks[ptr][0]});
                ptr++;
            }

            if(minheap.size() == 0){
                minheap.push({tasks[ptr][1], tasks[ptr][2], tasks[ptr][0]});
                ptr++;
            }

            //take out the top of the minheap and put index in ans
            //cout << minheap.top()[1] << ' ';
            temp = minheap.top();

            ans.push_back(temp[1]);
            
            curr += temp[0];
            if(temp[0] + temp[2] > curr) curr = temp[0] + temp[2];

            //cout << curr << ' ';

            minheap.pop();
        }

        return ans;
    }
};

class Solution {

public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) tasks[i].push_back(i);    

        sort(tasks.begin(), tasks.end());

        vector<int> visited(tasks.size(), 0);

        long long curr = tasks[0][0];
        int ptr = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minheap;
        vector<int> temp;

        for(int i = 0; i < n; i++){
            //put all the processess with enque time less than equal to curr in pq (minheap)
            while(ptr < n && tasks[ptr][0] <= curr){
                minheap.push({tasks[ptr][1], tasks[ptr][2], tasks[ptr][0]});
                ptr++;
            }

            if(minheap.size() == 0){
                minheap.push({tasks[ptr][1], tasks[ptr][2], tasks[ptr][0]});
                ptr++;
            }

            //take out the top of the minheap and put index in ans
            //cout << minheap.top()[1] << ' ';
            temp = minheap.top();

            ans.push_back(temp[1]);
            
            curr += temp[0];
            if(temp[0] + temp[2] > curr) curr = temp[0] + temp[2];

            //cout << curr << ' ';

            minheap.pop();
        }

        return ans;
    }
};