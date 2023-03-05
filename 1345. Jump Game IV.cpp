class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> pos;
        
        for(int i = 0; i < n; i++){
            pos[arr[i]].push_back(i);
        } 
        
        vector<bool> visited(n);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        int steps = 0;

        while(!q.empty()){
            //currently the queue holds a list of all the indices that we can reach in "steps" steps.
            int size = q.size();

            for(int i = 0; i < size; i++){

                int curr_index = q.front();
                q.pop();

                if(curr_index == n - 1) return steps; // reached the last index;
                //return curr_steps because we can reach all the curr_indices in that many steps 

                //the indices we can visit with 1 step more than curr step from curr_index;
                vector<int> &next_indices = pos[arr[curr_index]];
                next_indices.push_back(curr_index + 1);
                next_indices.push_back(curr_index - 1);

                for(int &index : next_indices){
                    if(index >= 0 && index < n && visited[index] == false){
                        q.push(index);
                        visited[index] = true;
                    }
                }

                next_indices.clear();
            }

            //the next indices will take an extra step
            steps++;
        }

        return 0;
    }
};