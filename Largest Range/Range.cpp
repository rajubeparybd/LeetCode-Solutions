#include <vector>
#include <unordered_map>

using namespace std;

vector<int> largestRange(vector<int> array) {
    int longestLength = 0;
    unordered_map<int, bool> nums = {};
    vector<int> range(2);
    for (int &it: array) nums[it] = true;

    for (int &it: array) {
        if (!nums[it]) continue;
        nums[it] = false;
        int currLen = 1;
        int left = it - 1;
        int right = it + 1;

        while (nums.find(left) != nums.end()) {
            nums[left] = false;
            currLen++;
            left--;
        }
        while (nums.find(right) != nums.end()) {
            nums[right] = false;
            currLen++;
            right++;
        }
        if (longestLength < currLen) {
            longestLength = currLen;
            range = {left + 1, right - 1};
        }
    }

    return range;
}


