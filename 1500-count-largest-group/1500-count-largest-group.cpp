class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groups;

        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            groups[sum]++;
        }

        int maxSize = 0;
        for (auto& [key, count] : groups)
            maxSize = max(maxSize, count);

        int res = 0;
        for (auto& [key, count] : groups)
            if (count == maxSize) res++;

        return res;
    }
};