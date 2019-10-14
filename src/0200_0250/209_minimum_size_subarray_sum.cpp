#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0;
        int len = nums.size();
        long sum = 0;
        int min_len = len;

        while (j < len) {
            sum += nums[j];

            while (sum >= s) {
                min_len = j - i < min_len ? j - i : min_len;
                sum -= nums[i];
                i++;
            }
            
            j++;
        }

        return min_len == len ? 0 : min_len + 1;
    }
};


int main(int argc, char const *argv[]) {
    int s;
    vector<int> v;
    int in;

    cin >> s;
    cin >> in;
    while (in > 0) {
        v.push_back(in);
        cin >> in;
    } 
    Solution S;
    cout << S.minSubArrayLen(s, v) << endl;

    return 0;
}
