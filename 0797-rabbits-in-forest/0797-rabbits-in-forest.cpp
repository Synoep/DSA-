class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (int a:answers) {
            mp[a]++;
        }
        int total =0;
        for (auto [x,cnt]:mp) {
            int g=x+1;
            int gs = (cnt + g-1) /g; 
            total+=gs*g;
        }
        return total;
    }
};
