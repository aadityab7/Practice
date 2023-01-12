
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        //create a ordered set of items
        set<string> st;
        for(auto order : orders) st.insert(order[2]);
        
        //associate a index to each item
        unordered_map<string, int> mp;
        int curr = 0;
        for(auto str : st) mp[str] = curr++;

        vector<int> t(st.size(), 0);
        map<int, vector<int>> table_order;

        //create the map with orders for each table
        for(auto order : orders){
            int num = stoi(order[1]);
            
            if(table_order.find(num) == table_order.end()) table_order[num] = t;
            
            table_order[num][mp[order[2]]]++;
        }

        //resulting vectors
        vector<vector<string>> ans;
        vector<string> temp;

        //Header
        temp.push_back("Table");
        for(auto str : st) temp.push_back(str);
        ans.push_back(temp);

        //Inserting data 
        for(auto [table, order] : table_order){
            temp.clear();

            temp.push_back(to_string(table));

            for(int x : order) temp.push_back(to_string(x));

            ans.push_back(temp);
        }

        return ans;
    }
};

//first I need to get a list of all the food items
//then create a map corresponding to each table 
//and then

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        //create a ordered set of items
        map<string, int> mp;
        map<int, int> mp_tb;
        for(auto &order : orders){
            mp[order[2]] = 0;
            mp_tb[stoi(order[1])] = 0;
        }
        
        int curr = 0;
        for(auto itr = mp.begin(); itr != mp.end(); itr++) itr -> second = curr++;

        curr = 0;
        for(auto itr = mp_tb.begin(); itr != mp_tb.end(); itr++) itr -> second = curr++;
       
        int total_tables = mp_tb.size(), total_items = mp.size() + 1;
        vector<vector<int>> arr(total_tables, vector<int>(total_items, 0));

        for(auto &order : orders){
            int table_no = mp_tb[stoi(order[1])];
            int item_pos = mp[order[2]];

            arr[table_no][0] = stoi(order[1]);
            arr[table_no][item_pos + 1]++;
        }

        //resulting vectors
        vector<vector<string>> ans;
        vector<string> temp;

        //Header
        temp.push_back("Table");
        for(auto [str, pos] : mp) temp.push_back(str);
        ans.push_back(temp);

        //Inserting data 
        for(auto &a : arr){
            temp.clear();
            for(int x : a){
                temp.push_back(to_string(x));
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
