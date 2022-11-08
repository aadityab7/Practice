class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c = 0, s = 0;
        int n = students.size();
        
        for(int i = 0; i < n; i++){
            if(students[i] == 0) c++;
            else s++;
        }
        
        
        for(int i = 0; i < n; i++){
            if(sandwiches[i] == 0 && c) c--;
            else if(sandwiches[i] == 1 && s) s--;
            else{
                //there is no one to take the top sandwich
                return c + s;
            }
        }
        
        return 0;
    }
};