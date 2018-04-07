class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> a;
    unordered_map<int, int> m;
    
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool contain = m.find(val) != m.end();
        if (contain) {
            return false;
        }
        // m[value] = index
        m[val] = a.size();
        a.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool contain = m.find(val) == m.end();
        if (contain) {
            return false;
        }
        // crucial point: remove element in vector by swaping it to back
        // vector
        int back = a.back();
        int index = m[val];
        a[index] = a.back();
        a.pop_back();
        // map
        m[back] = index;
        m.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = getIndex(a.size() - 1);
        return a[index];
    }
private:
    int getIndex(int e) {
        return rand() % (e + 1);
    }
    
};