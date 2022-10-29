class Solution {
    static bool comp(pair<int,int> &a, pair<int,int> &b){
        return a.second > b.second;
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int size = growTime.size();
        int ans = 0;

        //plant time and grow time
        vector<pair<int, int>> v(size);
        
        for(int i = 0; i < size; i++){
            v.push_back({plantTime[i], growTime[i]});
        }
        
        //sort according to grow time in desc
        sort(v.begin(), v.end(), comp);
        
        //start planting pots and then 
        int grow = 0;
        
        for(int i = 0; i < size; i++){
            
            ans += v[i].first;
            
            if(grow){
                grow = max(0, grow - v[i].first);
            }
            
            grow = grow + max(0, v[i].second - grow);
            
        }
        
        ans += grow;
        
        return ans;
    }
};

//at least sum of planting days 
//1 + 2 = 3
//2 + 1 = 3
//3 + 2 = 3
//2 + 1 = 3
//8 + 6
//plant with least bloom days at last

/*
1 - - *
  1 1 1 1 - - - *
1 1 1 1 - - - * 
        1 - - *
          1 1 1 - *  
*/

class Solution {
    static bool comp(pair<int,int> &a, pair<int,int> &b){
        return a.second > b.second;
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int size = growTime.size();
        int ans = 0;

        //plant time and grow time
        vector<pair<int, int>> v(size);
        
        for(int i = 0; i < size; i++){
            v.push_back({plantTime[i], growTime[i]});
        }
        
        //sort according to grow time in desc
        sort(v.begin(), v.end(), comp);
        
        //start planting pots and then 
        
        int curr = 0, bloom;
        
        for(int i = 0; i < size; i++){
            
            //at what time this plant will bloom
            //bloom = currTime + growing time
            //if bloom is > max then max = bloom
            
            curr += v[i].first;
            bloom = curr + v[i].second;
            if(bloom > ans) ans = bloom;
            
        }
        
        return ans;
    }
};