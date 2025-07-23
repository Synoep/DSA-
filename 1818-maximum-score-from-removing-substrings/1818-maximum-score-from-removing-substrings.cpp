class Solution {
public:
int re(string& s, char first, char second, int points) {
    string result = "";
    int score=0;
    for (char ch:s) {
        if (!result.empty() && result.back()==first&&ch==second) {
            result.pop_back(); 
            score +=points;
        } else {
            result +=ch; 
        }
    }
    s=result; 
    return score;
}
int maximumGain(string s, int x, int y) {
    int total=0;
    if (x>=y) {
        total +=re(s,'a','b',x); 
        total +=re(s,'b','a',y); 
    } else {
        total += re(s,'b','a',y); 
        total += re(s,'a','b',x); 
    }
    return total;
    }
};