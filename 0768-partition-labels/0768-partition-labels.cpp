class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence;
        for (int index = 0; index < s.length(); index++) {
            lastOccurrence[s[index]] = index;
        }

        vector<int> partitionSizes;
        int partitionStart = 0, partitionEnd = 0;
        for (int index = 0; index < s.length(); index++) {
            partitionEnd = max(partitionEnd, lastOccurrence[s[index]]);
            if (index == partitionEnd) {
                partitionSizes.push_back(partitionEnd - partitionStart + 1);
                partitionStart = index + 1;
            }
        }
        return partitionSizes;
    }
};