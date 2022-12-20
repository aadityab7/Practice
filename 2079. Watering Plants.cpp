class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cap = capacity;
        int ans = plants.size();

        for(int i = 0; i < plants.size(); i++){
            if(cap < plants[i]){
                //walk back to the river to refill;
                ans += 2 * i;
                cap = capacity;
            }

            cap -= plants[i];
        }

        return ans;
    }
};