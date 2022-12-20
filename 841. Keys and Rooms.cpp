//using set
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> st;

        q.push(0);
        st.insert(0);

        while(!q.empty()){
            int curr = q.front();
            st.insert(curr);
            q.pop();

            for(int x : rooms[curr]){
                if(st.find(x) == st.end()) q.push(x);
            }
        }

        return st.size() == rooms.size();
    }
};
    
//using array
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int> visited(rooms.size(), 0);

        q.push(0);
        int curr;

        while(!q.empty()){
            curr = q.front();
            visited[curr] = 1;
            q.pop();

            for(int & x : rooms[curr])
                if(!visited[x]) q.push(x);
        }

        int total = 0;
        for(int i : visited) total += i;

        return total == rooms.size();
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int> visited(rooms.size(), 0);

        q.push(0);
        int curr;

        while(!q.empty()){
            curr = q.front();
            visited[curr] = 1;
            q.pop();

            for(int & x : rooms[curr])
                if(!visited[x]) q.push(x);
        }

        for(int &x : visited) if(!x) return false;

        return true;
    }
};