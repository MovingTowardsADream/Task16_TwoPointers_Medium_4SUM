#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<int> small;
        std::vector<std::vector<int>> output;
        int l, r, n = nums.size();
        long sum;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < n - 3;i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1;j < n - 2;j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                l = j + 1;
                r = n - 1;
                while (l < r) {
                    sum = static_cast<long>(nums[i]) + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        small = { nums[i] ,nums[j],nums[l] ,nums[r] };
                        output.push_back(small);
                        l++;
                        while (l < r && nums[l] == nums[l - 1]) ++l;
                        r--;
                        while (l < r && nums[r] == nums[r + 1]) --r;
                    }
                    else if (sum > target) {
                        r--;
                    }
                    else {
                        l++;
                    }
                }
            }
        }
        return output;
    }
};

int main()
{
    std::vector<int> nums = { 1,0,-1,0,-2,2 };
    for (std::vector<int> i : Solution::fourSum(nums, 0)) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}