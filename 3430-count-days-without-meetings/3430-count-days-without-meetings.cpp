class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> events;
        for (auto& meeting : meetings) {
            events.push_back({meeting[0], 1});
            events.push_back({meeting[1] + 1, -1});
        }
        sort(events.begin(), events.end());

        int availableDays = 0, activeMeetings = 0, prevDay = 1;

        for (auto& event : events) {
            int currDay = event.first, change = event.second;
            if (activeMeetings == 0) {
                availableDays += (currDay - prevDay);
            }
            activeMeetings += change;
            prevDay = currDay;
        }
        if (activeMeetings == 0) {
            availableDays += (days - prevDay + 1);
        }

        return availableDays;
    }
};