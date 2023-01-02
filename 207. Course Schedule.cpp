//36 ms 
class Solution {
    vector<set<int>> arr;
    set<int> visited;

    bool helper(int index){
        if(visited.find(index) != visited.end()) return false;

        visited.insert(index);

        for(auto itr = arr[index].begin(); itr != arr[index].end(); itr++){
            if(helper(*itr)) arr[index].erase(itr);
            else return false;
        }

        visited.erase(index);

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        arr.resize(numCourses);

        for(auto &p : prerequisites) arr[p[0]].insert(p[1]);

        for(int i = 0; i < numCourses; i++) if(!helper(i)) return false;
        
        return true;
    }
};


/*
  0 1
0 0 1
1 1 0 
*/

//using vector to store visited nodes instead of sets - 27 ms
class Solution {
    bool helper(vector<set<int>> &arr, vector<int> &visited, int index){
        if(visited[index]) return false;

        visited[index] = 1;

        for(auto itr = arr[index].begin(); itr != arr[index].end(); itr++){
            if(helper(arr, visited,*itr)) arr[index].erase(itr);
            else return false;
        }

        visited[index] = 0;

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> visited(numCourses, 0);

        vector<set<int>> arr(numCourses);

        for(auto &p : prerequisites) arr[p[0]].insert(p[1]);

        for(int i = 0; i < numCourses; i++) if(!helper(arr, visited, i)) return false;
        
        return true;
    }
};