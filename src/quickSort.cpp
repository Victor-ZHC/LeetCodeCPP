//
// Created by victo on 2021/6/7.
//
#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int begin, int end)
{
    if (begin >= end) {
        return;
    }

    int left = begin;
    int right = end;
    bool numberAtLeft = true;

    while (left <= right) {
        if (numberAtLeft) {
            while (left <= right && nums[left] < nums[right]) {
                right--;
            }
        } else {
            while (left <= right && nums[right] > nums[left]) {
                left++;
            }
        }

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        numberAtLeft = !numberAtLeft;
    }

    quickSort(nums, begin, left - 1);
    quickSort(nums, left + 1, right);
}

int main() {
    vector<int> nums({3, 1, 2, 5, 4});
    quickSort(nums, 0, 4);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
}
