#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target) {
    vector<int> sweet;
    vector<int> savory;

    for (int it: dishes) {
        if (it < 0) sweet.push_back(it);
        else savory.push_back(it);
    }

    sort(sweet.begin(), sweet.end(), [](int a, int b) { return abs(a) < abs(b); });
    sort(savory.begin(), savory.end());

    vector<int> bestPair = {0, 0};
    int i = 0, j = 0, bestDiff = INT_MAX;

    while (i < sweet.size() && j < savory.size()) {
        int curr = sweet[i] + savory[j];
        if (curr <= target) {
            int currDiff = target - curr;
            if (currDiff < bestDiff) {
                bestDiff = currDiff;
                bestPair[0] = sweet[i];
                bestPair[1] = savory[j];
            }
            j++;
        } else i++;
    }
    return bestPair;
}
