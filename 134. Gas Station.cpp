//My solution - 2963 ms
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0) return -1;
        if(gas.size() == 1 && gas[0] >= cost[0]) return 0;
        int ans = -1;
        int n = gas.size();
        int curr;

        for(int i = 0; i < n; i++) gas[i] -= cost[i];

        for(int i = 0; i < n; i++){
            if(gas[i] > 0){

                curr = gas[i];
                int flag = 1;

                for(int j = 1; j < n; j++){
                    curr +=  gas[(i + j) % n];
                    if(curr < 0){
                        flag = 0;
                        break;
                    }
                }

                if(flag) return i;
            }
        }

        return ans;
    }
};

//if total gas > total cost solution exists - 96 ms
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, n = gas.size(), start = 0, tank = 0;

        for(int i = 0; i < n; i++){
            total += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){
                tank = 0;
                start = i + 1;
            }
        }

        if(total < 0) return -1;
        else return start;
    }
};