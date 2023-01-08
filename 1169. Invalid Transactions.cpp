class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        int n = transactions.size();
        if(n == 0) return ans;

        vector<string> names(n), city(n);
        vector<int> time(n), invalid(n, 0);

        for(int i = 0; i < n; i++){
            string s = transactions[i];
            string na = "", ti = "", am = "", ci = "";

            int j = 0;
            while(s[j] != ',') na += s[j++];
            j++;
            while(s[j] != ',') ti += s[j++];
            j++;
            while(s[j] != ',') am += s[j++];
            j++;
            while(j < s.size()) ci += s[j++];

            time[i] = stoi(ti);
            names[i] = na;
            city[i] = ci;

            int amount = stoi(am);

            if(amount > 1000) invalid[i] = 1;

            //cout << names[i] << ' ' << time[i] << ' ' << city[i] << '\n';
        }

        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n; j++){
                if(names[i] == names[j]){
                    if(abs(time[i] - time[j]) < 61 && city[i] != city[j]){
                        invalid[i] = 1;
                        invalid[j] = 1;
                    }
                }
            }

        

        for(int i = 0; i < n; i++)
            if(invalid[i]) ans.push_back(transactions[i]);

        return ans;
    }
};