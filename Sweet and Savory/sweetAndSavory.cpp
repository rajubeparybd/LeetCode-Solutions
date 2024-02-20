#include <iostream>
#include <vector>

using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target) {
    sort(dishes.begin(), dishes.end());

    int sweet = 0, savory = dishes.size() - 1, bestDiff = INT_MAX;
    vector<int> ans = {0, 0};

    if (dishes.size() < 2 || dishes[sweet] > 0 || dishes[savory] < 0)
        return ans;

    while (sweet < savory && dishes[sweet] * dishes[savory] < 0) {
        if (dishes[sweet] > 0 || dishes[savory] < 0) break;

        int flavor = dishes[sweet] + dishes[savory];
        if (flavor == target) return {dishes[sweet], dishes[savory]};

        if (flavor < target) {
            int currDiff = target - flavor;
            if (currDiff < bestDiff) {
                bestDiff = currDiff;
                ans[0] = dishes[sweet];
                ans[1] = dishes[savory];
            }
            sweet++;
        } else savory++;
    }
    return ans;
}
