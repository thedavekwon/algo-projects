#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int l, int r, int val) {
    if (r >= l) {
        int m = (l+r) /2;
        if (arr[m] == val) {
            return m;
        }
        if (arr[m] > val) {
            return binarySearch(arr, 1, m-1, val);
        }
        return binarySearch(arr, m+1, r, val);
    }
    return -1;
}

int binarySearch(vector<int> &arr, int l, int r, int val) {
    if (r >= l) {
        int m = (l+r) /2;
        if (arr[m] >= val && arr[m-1] <= val) {
            return m;
        }
        if (arr[m] > val) {
            return binarySearch(arr, 1, m-1, val);
        }
        return binarySearch(arr, m+1, r, val);
    }
    return -1;
}