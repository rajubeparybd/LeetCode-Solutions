#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> array) {
    int ans = array[0];
    int cnt = 0;
    for (int n: array) {
        if (cnt == 0) ans = n;
        (n == ans) ? cnt++ : cnt--;
    }
    return ans;
}
