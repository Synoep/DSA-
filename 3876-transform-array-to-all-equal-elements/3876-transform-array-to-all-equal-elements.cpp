class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int> temp = nums;
        int cnt = 0,n(nums.size());
        for(int i=0;i<n-1;i++){
            if(nums[i] == -1){
                nums[i]*=-1;
                nums[i+1]*=-1;
                cnt++;
            }
            if(cnt > k) break;
        }
        if(cnt <= k && nums[n-1] == 1) return true;

        nums = temp;
        cnt = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i] == 1){
                nums[i]*=-1;
                nums[i+1]*=-1;
                cnt++;
            }
            if(cnt > k) break;
        }
        if(nums[n-1] == 1) return false;
        return cnt <= k;
    }
};