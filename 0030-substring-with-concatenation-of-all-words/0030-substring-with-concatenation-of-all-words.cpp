class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map, freq;

        for (int i = 0; i < words.size(); i++) {
            map[words[i]]++;
        }

        int len = words[0].size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            int left = i, right = i;
            while (right < s.size()) {
                string str = s.substr(right, len);

                if (map.find(str) == map.end()) {
                    right += len;
                    left = right;
                    freq.clear();
                    continue;
                }

                freq[str]++;

                while (left < right && freq[str] > map[str]) {
                    string wrd = s.substr(left, len);
                    freq[wrd]--;
                    left += len;
                }

                if (map == freq) {
                    res.push_back(left);
                }

                right += len;
            }
            freq.clear();
        }

        return res;
    }
};