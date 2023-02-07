class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        
        int prev_element = fruits[0];
        int prev_element_count = 0;
        int curr = 0;
        int first = fruits[0], second = fruits[0];

        for(int fruit : fruits){
            if(fruit == prev_element){
                //fruit is same as before
                curr++;
                prev_element_count++;
            }
            else{
                if(fruit == first || fruit == second){
                    curr++;
                }
                else{
                    //remove one fruit basket 
                    if(prev_element == second){
                        first = prev_element;
                    }

                    second = fruit;

                    curr = prev_element_count + 1;
                }

                prev_element = fruit;
                prev_element_count = 1;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};