#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> array) {
    sort(array.begin(), array.end());
    int mid = array.size() - 1;
    mid /= 2;

    return array[mid];
}
