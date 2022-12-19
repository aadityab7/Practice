//Recursive approach for DFS 
class Solution {
    unordered_map<int, vector<int>> mp;
    int dest;

    bool helper(int source, vector<int> &arr){
        arr[source] = 1;

        for(int x : mp[source])
            if(x == dest) 
                return true;
            else if(!arr[x] && helper(x, arr))
                return true;
        
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<int> arr(n, 0);
        dest = destination;

        for(vector<int> e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        } 

        return helper(source, arr);
    }
};

//Iterative DFS
class Solution {
    unordered_map<int, vector<int>> mp;

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<int> visited(n, 0);

        for(vector<int> e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        } 

        stack<int> s;
        s.push(source);

        while(!s.empty()){
            int tp = s.top();
            if(tp == destination) return true;
            visited[tp] = 1;
            s.pop();

            for(int x : mp[tp])
                if(!visited[x]) s.push(x);
        }

        return false;
    }
};


//Using Queue for BFS
class Solution {
    unordered_map<int, vector<int>> mp;

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<int> visited(n, 0);

        for(vector<int> e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        } 

        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int tp = q.front();
            if(tp == destination) return true;
            visited[tp] = 1;
            q.pop();

            for(int x : mp[tp])
                if(!visited[x]) q.push(x);
        }

        return false;
    }
};

//Disjoint Set Union - 794 ms
class Solution {
    //returns the parent 
    int find(int i, vector<int> &arr){
        if(i == arr[i]) return i;
        i = find(arr[i], arr);
        return i;
    }

    //used to perform union of two sets
    void uni(int i, int j, vector<int> &arr){
        int x = find(i, arr);
        int y = find(j, arr);

        if(x < y) arr[y] = x;
        else arr[x] = y;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> arr(n);

        for(int i = 0; i < n; i++) arr[i] = i;

        for(vector<int> e : edges) uni(e[0], e[1], arr);

        return find(source, arr) == find(destination, arr);
    }
};    