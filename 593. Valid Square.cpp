class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //find distances between all the points
        //p1 - p2, p1 - p3, p1 - p4
        //p2 - p3, p2 - p4
        //p3 - p4 

        vector<long long> arr(6);

        arr[0] = (long long) (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        arr[1] = (long long) (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
        arr[2] = (long long) (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);
        arr[3] = (long long) (p3[0] - p2[0]) * (p3[0] - p2[0]) + (p3[1] - p2[1]) * (p3[1] - p2[1]);
        arr[4] = (long long) (p4[0] - p2[0]) * (p4[0] - p2[0]) + (p4[1] - p2[1]) * (p4[1] - p2[1]);
        arr[5] = (long long) (p3[0] - p4[0]) * (p3[0] - p4[0]) + (p3[1] - p4[1]) * (p3[1] - p4[1]);

        //find min and max of arr
        long long min = arr[0], max = arr[0];

        for(auto &a : arr){
            if(a > max) max = a;
            if(a < min) min = a;
        }

        if(min == max) return false;
        
        for(auto a : arr) if(a != min && a != max) return false;

        return max == 2 * min; 
    }
};

//1 + 1 = 2 * 2
//distance = (x1 - x2) ** 2 + (y1 - y2) ** 2

//dist btw adj points ==
//sides must be same 
//dist btw opp points ==
//diagonals must be same