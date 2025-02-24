class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freqMp;
        for (auto num : arr) {
            int numModK = ((num % k) + k) % k;
            freqMp[numModK]++;
        }
        for (auto& freqEntry : freqMp) {
            int numModK = freqEntry.first, numModKFreq = freqEntry.second;
            if (numModK == 0) {
                if (numModKFreq % 2 != 0) return false;
            } else {
                int compNumModK = k - numModK, compFreq = freqMp[compNumModK];
                if (numModKFreq != compFreq) return false;
            }
        }
        return true;
    }
};