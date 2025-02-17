class Solution {
   void backtrack(unordered_map<char, int>& freq, int& count, int n) {
    for (auto& [ch,f]:freq) {
        if (f>0) {
            count++; 
            freq[ch]--;  
            backtrack(freq,count,n);
            freq[ch]++;  
        }
    }
}
public:
    int numTilePossibilities(string tiles) {
    unordered_map<char, int> freq;
    for (char ch:tiles) {
        freq[ch]++;
    }
    int count = 0;
    backtrack(freq, count,tiles.size());
    return count;  
    }
};