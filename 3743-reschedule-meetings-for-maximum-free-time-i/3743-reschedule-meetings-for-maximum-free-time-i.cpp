class Solution {
public:
    int maxFreeTime(int eventTime, int k,vector<int>& startTime,vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gaps(n+1,0);
        gaps[0] =startTime[0];  
        for (int i=1;i<n;i++) {
            gaps[i]=startTime[i]-endTime[i-1];
        }
        gaps[n] = eventTime-endTime[n - 1];  
        int maxi=0;
        int cur=0;
        for (int i=0;i<=k&&i<gaps.size();i++) {
            cur+= gaps[i];
        }
        maxi=cur;
        for (int i=k+1; i<gaps.size();i++) {
            cur+=gaps[i]-gaps[i-(k+1)];
            maxi=max(maxi, cur);
        }
        return maxi;
    }
};
