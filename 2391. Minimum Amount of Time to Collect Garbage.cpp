class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        int g = 0, p = 0, m = 0; // positions of trucks

        for(int i = 0; i < garbage.size(); i++){
            int glass = 0, paper = 0, metal = 0;

            //calculate the amount of 3 at this house
            for(char c : garbage[i]){
                if(c == 'G') glass++;
                else if(c == 'P') paper++;
                else metal++;
            }

            ans += glass + paper + metal; // time required to pick up 

            if(glass){
                ans += g;
                g = 0;
            }

            if(metal){
                ans += m;
                m = 0;
            }

            if(paper){
                ans += p;
                p = 0;
            }

            //move trucks to the next house 
            if(i != travel.size()){
                g += travel[i];
                p += travel[i];
                m += travel[i];
            }
        }


        return ans;
    }
};