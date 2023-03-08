class Solution {
    int hours_taken(const vector<int> & piles, int speed){
        int time = 0;
        for(int pile : piles){ 
            time += pile / speed;
            if(pile % speed != 0) time++;
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        for(int &pile : piles) right = max(right, pile);
        
        while(left < right){
            int mid = left + (right - left) / 2;

            if(hours_taken(piles, mid) > h){
                //need to eat faster
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }

        return left;
    }
};