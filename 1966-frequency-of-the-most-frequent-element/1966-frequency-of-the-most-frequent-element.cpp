class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  
        long long windowSum = 0;
        int left = 0, maxFreq = 0;
        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];
            long long requiredSum = 1LL * nums[right] * (right - left + 1);
            long long cost = requiredSum - windowSum;

            while (cost > k) {
                windowSum -= nums[left];
                left++;
                requiredSum = 1LL * nums[right] * (right - left + 1);
                cost = requiredSum - windowSum;
            }
            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};
