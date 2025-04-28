class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        for (int i = 0,group=0,prev=nums[0];i<n;i++){
            if (abs(nums[i]-prev)>maxDiff)
                group++;
            prev=nums[i];
            nums[i]=group;
        }
        vector<bool> res;
        for (auto& q:queries)
            res.push_back(nums[q[0]] == nums[q[1]]);
        return res;
    }
};