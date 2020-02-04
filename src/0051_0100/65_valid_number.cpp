//
// Created by victo on 2020/2/4.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool sign = false;
        bool point = false;
        bool index = false;
        bool is_number = false;

        // 判断空字符串并去除开头结尾空格
        if (s.length() == 0) {
            return false;
        }

        int start = s.find_first_not_of(' ');
        int end = s.find_last_not_of(' ');

        if (start < 0 || end < 0) {
            return false;
        }

        s = s.substr(start, end - start + 1);

        // 开始逐个字符判断
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    digit = true;
                    is_number = true;
                    break;
                case '+':
                case '-':
                    if (digit || point || sign) {
                        return false;
                    }
                    sign = true;
                    is_number = false;
                    break;
                case 'e':
                    if (!digit || index) {
                        return false;
                    }
                    index = true;
                    digit = false;
                    sign = false;
                    point = false;
                    is_number = false;
                    break;
                case '.':
                    if (point || index) {
                        return false;
                    }
                    point = true;
                    is_number = digit;
                    break;
                default:
                    return false;
            }
        }
        return is_number;
    }
};

int main() {
    Solution s;
    cout << (s.isNumber(".1") ? "true" : "false") << endl;
    return 0;
}