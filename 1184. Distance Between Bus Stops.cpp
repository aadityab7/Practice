class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        //go from start to end and from end to start
        int n = distance.size();
        int one = 0, two = 0;
        
        int i = start;
        while(i != destination){
            one += distance[i];
            i = (i + 1) % n;
        }
        
        
        i = destination;
        while(i != start){
            two += distance[i];
            i = (i + 1) % n;
        }
        
        //cout << one << ' ' << two << '\n';
        
//         if(one < two) return one;
//         return two;
        
        return min(one, two);
    }
};