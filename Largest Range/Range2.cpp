#include <vector>
#include <unordered_set>

using namespace std;

vector<int> largestRange(vector<int> array) {
    int longestLength = 0;
    unordered_set<int> nums;
    vector<int> range(2);

    for (int &num: array) nums.insert(num);

    for (int &num: array) {
        if (nums.find(num - 1) == nums.end()) {
            int i = num;
            while (nums.find(i) != nums.end()) i++;

            int currLen = i - num;
            if (currLen > longestLength) {
                longestLength = currLen;
                range = {num, i - 1};
            }
        }
    }

    return range;
}


