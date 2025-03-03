#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result;
        if (numerator < 0 ^ denominator < 0) result += "-";

        long long n = llabs(numerator), d = llabs(denominator), r;
        
        result += to_string(n / d);
        r = n % d;
        if (r == 0) return result;

        result += ".";
        unordered_map<long long, int> remainders;
        
        while (r != 0) {
            if (remainders.find(r) != remainders.end()) {
                result.insert(remainders[r], "(");
                result += ")";
                break;
            }
            remainders[r] = result.size();

            r *= 10;
            result += to_string(r / d);
            r %= d;
        }

        return result;
    }
};