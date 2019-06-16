/**
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 1
 * 11
 * 21
 * 1211
 * 111221
 * 312211
 * 13112221
 * ...
 */
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
private:
    string count(string in, int level, int n) {
        if (level == n)
            return in;

        string out;
        size_t i = 0, j = 0;

        while (i < in.length())
        {
            if (in[i] != in[j])
            {
                out.append(1, '0' + i - j);
                out.append(1, in[j]);
                j = i;
            }
            i++;
        }

        out.append(1, '0' + i - j);
        out.append(1, in[j]);
        
        return count(out, ++level, n);
    }
public:
    string countAndSay(int n) {
        return count("1", 1, n);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;
    cout << s.countAndSay(n) << endl;
    return 0;
}
