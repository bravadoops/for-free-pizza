class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        if (n == 1) {
            return 1;
        }
        // priority_queue with set
        priority_queue<double, vector<double>, greater<double>> q;
        unordered_set<double> s;
        vector<double> res;
        
        int t1 = 2, t2 = 3, t3 = 5;

        q.push(t1); q.push(t2); q.push(t3);
        s.insert(t1); s.insert(t2); s.insert(t3);
        
        while (res.size() < n+6) {
            double top = q.top(); q.pop();
            // save in result
            res.push_back(top);
            
            if (s.find(top * t1) == s.end()) {
                q.push(top * t1);
                s.insert(top * t1);
            }
            if (s.find(top * t2) == s.end()) {
                q.push(top * t2);
                s.insert(top * t2);
            }
            if (s.find(top * t3) == s.end()) {
                q.push(top * t3);
                s.insert (top * t3);
            }
        }
        return res[n-2];
    }
};