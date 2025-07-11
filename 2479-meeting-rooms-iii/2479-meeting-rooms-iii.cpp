class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> roomCount(n, 0);
        priority_queue<int, vector<int>, greater<int>> ar;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> br;
        for (int i=0;i<n;i++) {
            ar.push(i);
        }
        for (auto& meeting:meetings) {
            long long start=meeting[0];
            long long duration=meeting[1] - meeting[0];
            
            while (!br.empty() && br.top().first <= start) {
                ar.push(br.top().second);
                br.pop();
            }
            if (!ar.empty()) {
                int room=ar.top();
                ar.pop();
                br.push({start + duration, room});
                roomCount[room]++;
            } else {
                auto [endTime, room]=br.top();
                br.pop();
                br.push({endTime+duration,room});
                roomCount[room]++;
            }
        }
        
        int maxMeetings =0;
        int result =0;
        for (int i=0;i<n;i++) {
            if (roomCount[i]>maxMeetings) {
                maxMeetings=roomCount[i];
                result=i;
            }
        }
        
        return result;
    }
};