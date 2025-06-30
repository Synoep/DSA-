class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxi;
        for(int num:nums) maxi.push(num);
        for(int i=1;i<k;i++) maxi.pop();
        return maxi.top();
    }
};