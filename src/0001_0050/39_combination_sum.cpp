#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        combination(candidates, temp, 0, 0, target);
        return result;
    }

    void combination(vector<int> &candidates, vector<int> temp, size_t index, int sum, int target)
    {
        for (size_t i = index; i < candidates.size(); i++)
        {
            int a = candidates[i];
            int next_sum = a + sum;
            temp.push_back(a);
            if (next_sum == target)
            {
                result.push_back(temp);
                return;
            }
            else if (next_sum > target)
            {
                return;
            }
            else
            {
                combination(candidates, temp, i, next_sum, target);
                temp.pop_back();
            }
        }
    }

private:
    vector<vector<int>> result;
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(5);
    vector<vector<int>> result = s.combinationSum(candidates, 8);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
