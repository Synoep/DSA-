class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end()); 
        priority_queue<int,vector<int>, greater<int>> pq; 
        int day=1,i=0,n=events.size(),res=0;
        while (i<n|| !pq.empty()) {
            while (i<n&&events[i][0]==day)
                pq.push(events[i++][1]);
            while (!pq.empty() && pq.top()<day) pq.pop();
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
            day++;
        }
        return res;
    }
};