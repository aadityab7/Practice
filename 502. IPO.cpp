class Solution {
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    }

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //sort the jobs by increasing capital 
        //and a max heap priority queue to store all the projects we can do right now (sort according to profit)
        
        vector<pair<int, int>> available;
        for(int i = 0; i < capital.size(); i++) available.push_back({capital[i], profits[i]});
        sort(available.begin(), available.end(), comp);
        
        priority_queue<int> feasible;
        int curr_capital = w;
        int ptr = 0; //pointer to the first job that we can't do right now;
         
        for(int i = 0; i < k; i++){
            
            //check how many jobs can we do 
            while(ptr < available.size() && available[ptr].first <= curr_capital){
                feasible.push(available[ptr].second);
                ptr++;
            }

            //now that we have all the jobs we can do select the job with max profit
            if(!feasible.empty()){
                curr_capital += feasible.top();
                feasible.pop();
            }
            else break;
        }

        return curr_capital;
    }
};