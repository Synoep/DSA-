class Solution {
public:
    long countBadPairs(std::vector<int>& nums) {
        unordered_map<int, int> freq;
        long good = 0;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i] - i;
            good += freq[key];
            freq[key]++; 
        }
        long totalPairs = static_cast<long>(nums.size())*(nums.size()-1)/2; 
        return totalPairs - good; 
    }
};