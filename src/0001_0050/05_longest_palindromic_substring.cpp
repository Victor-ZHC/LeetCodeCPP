#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        long len = s.length();

        if (len == 0) {
            return "";
        }
        
        long max_palidrome_len = 1;
        long palidrome_begin = 0;

        for (long center = 0; center < len; center++) {
            for (long lenth = 1; (center - lenth >= 0) && (center + lenth < len) && (s[center - lenth] == s[center + lenth]); lenth++) {
                if (lenth * 2 + 1 > max_palidrome_len) {
                    max_palidrome_len = lenth * 2 + 1;
                    palidrome_begin = center - lenth;
                }
            }
        }

        for (long center = 0; center < len; center++) {
            for (long lenth = 1; (center - lenth + 1 >= 0) && (center + lenth < len) && (s[center - lenth + 1] == s[center + lenth]); lenth++) {
                if (lenth * 2 > max_palidrome_len) {
                    max_palidrome_len = lenth * 2;
                    palidrome_begin = center - lenth + 1;
                }
            }
        }

        return s.substr(palidrome_begin, max_palidrome_len);
    }
};


int main(int argc, char const *argv[]) {
    string s;
    string longest_palindrome;

    getline(cin, s);

    Solution S;
    longest_palindrome = S.longestPalindrome(s);

    cout << longest_palindrome << endl;

    return 0;
}
