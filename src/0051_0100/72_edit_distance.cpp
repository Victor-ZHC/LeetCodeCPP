//
// Created by victo on 2020/2/4.
//

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int Matrix[10000][10000];

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_len = word1.length();
        int word2_len = word2.length();

        for (int i = 0; i <= word1_len; ++i) {
            Matrix[0][i] = i;
        }
        for (int i = 1; i <= word2_len; ++i) {
            Matrix[i][0] = i;
        }

        for (int i = 1; i <= word2_len; ++i) {
            for (int j = 1; j <= word1_len; ++j) {
                if (word2[i - 1] == word1[j - 1]) {
                    Matrix[i][j] = Matrix[i - 1][j - 1];
                } else {
                    Matrix[i][j] = min(Matrix[i - 1][j - 1], min(Matrix[i - 1][j], Matrix[i][j - 1])) + 1;
                }
            }
        }

        return Matrix[word2_len][word1_len];
    }
};

int main() {
    Solution s;
    cout << s.minDistance("horse", "ros");
    return 0;
}
