class MyHashSet {
private:
	int prime;
	vector<vector<int>> table;

	int hash(int key) {
		return key % prime;
	}

	vector<int>::iterator search(int key) {
		int h = hash(key);
		//returns an iterator of given search type
		return find(table[h].begin(), table[h].end(), key);
        
//         vector<int>::iterator itr = table[h].begin();
//         for(; itr != table[h].end(); itr++)
//         {
//             if(*itr == key) break;
//         }
        
//         return itr;
	}

public:
	MyHashSet() {
        prime = 10007;
        table.resize(prime);
    }
       
	void add(int key) {
		int h = hash(key);
		if (!contains(key))
			table[h].push_back(key);
	}
	
	void remove(int key) {
		int h = hash(key);
		auto it = search(key);
		if (it != table[h].end())
			table[h].erase(it);
	}
	
	bool contains(int key) {
		int h = hash(key);
		return search(key) != table[h].end();
	}
};