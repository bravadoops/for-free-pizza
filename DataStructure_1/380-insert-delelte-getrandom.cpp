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
        // crucial point: remove element in vector by swaping it to back        // write your code here
        if (n == 1) {
            return 1;
        }
        priority_queue<double, vector<double>, greater<double>> q;
        unordered_set<double> s;
        vector<double> res;
        
        q.push(2); q.push(3); q.push(5);
        s.insert(2); s.insert(3); s.insert(5);
        
        while (res.size() < n+6) {
            double top = q.top(); q.pop();
            // save in result
            res.push_back(top);
            
            if (s.find(top * 2) == s.end()) {
                q.push(top * 2);
                s.insert(top * 2);
            }
            if (s.find(top * 3) == s.end()) {
                q.push(top * 3);
                s.insert(top * 3);
            }
            if (s.find(top *5) == s.end()) {
                q.push(top * 5);
                s.insert (top * 5);
            }
        }
        return res[n-2];
    }
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