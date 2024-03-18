#include <vector>

using namespace std;

vector<int> subarraySort(vector<int> array) {
    int n = array.size();
    int i = 0, j = n - 1;
    int minimum, maximum;

    while (i < n - 1 && array[i] <= array[i + 1]) i++;
    while (j > 0 && array[j] >= array[j - 1] && j > i) j--;

    if (i >= j) return {-1, -1};

    minimum = array[i];
    maximum = array[i];
    int k = i;
    while (k <= j) {
        minimum = min(array[k], minimum);
        maximum = max(array[k], maximum);
        k++;
    }

    while (i > 0 && array[i - 1] > minimum) i--;
    while (j < n - 1 && array[j + 1] < maximum) j++;
    return {i, j};
}