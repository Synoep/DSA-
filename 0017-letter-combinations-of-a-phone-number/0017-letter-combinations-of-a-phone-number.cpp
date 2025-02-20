class Solution {
private:
    void help(int idx, string &ansString, vector<string> &result, const string &digits, const unordered_map<int, string> &mapping){
        if(ansString.size() == digits.size()){
            result.push_back(ansString);
            return;
        }

        int letter = digits[idx] - '0';
        int size = mapping.at(letter).size();

        for(int i = 0; i < size; ++i){
            ansString.push_back(mapping.at(letter)[i]);
            help(idx+1, ansString, result, digits, mapping);
            ansString.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<int, string> mapping = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        vector<string> result;
        string ansString = "";
        help(0, ansString, result, digits, mapping);

        return result;
    }
};