class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mapping;
        stack<int> stk;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && nums2[i] >= stk.top())
                stk.pop();
            if (!stk.empty())
                mapping[nums2[i]] = stk.top();
            else
                mapping[nums2[i]] = -1;

            stk.push(nums2[i]);
        }
        vector<int> answer;
        for (int i = 0; i < nums1.size(); i++)
            answer.push_back(mapping[nums1[i]]);

        return answer;
    }
};