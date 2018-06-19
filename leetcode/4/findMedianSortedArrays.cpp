#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = static_cast<int>(nums1.size()), size2 = static_cast<int>(nums2.size()); // NOLINT
    vector<int> tmp1(size1, 1); vector<int> tmp2(size2, 1);
    for (int i = 1; i < size1; ++i) tmp1[i] = tmp1[i] + tmp1[i-1];
    for (int i = 1; i < size2; ++i) tmp2[i] = tmp2[i] + tmp2[i-1];
    map<int, int> map1, map2;
    for (int i = 0; i < size1; ++i) map1.insert(pair<int,int>(nums1[i], tmp1[i]));
    for (int i = 0; i < size2; ++i) map2.insert(pair<int,int>(nums2[i], tmp2[i]));

    int cnt = 0;
    int mid = (size1 + size2) / 2;
    bool odd = (size1 + size2) % 2 == 1;
    auto it1 = map1.begin(), it2 = map2.begin();
    while (it1 != map1.end() && it2 != map2.begin()) {
        auto lower_bound = map2.lower_bound(it1->first);
        it1++;
        if (cnt + static_cast<>)
        cnt = cnt + static_cast<int>(distance(lower_bound, it2)) + 1;
        it2 = move(lower_bound);
    }

    if (it1 == map1.end()) {
        if (odd) return static_cast<double>(nums1[size1/2] + nums2[size1/2+1])/2;
        return static_cast<double>(nums1[size1/2])/2;
    }
    if (odd) {
        if (size2 % 2 == 1) return static_cast<double>(nums2[size2/2] + nums2[size2/2+1])/2;
        return static_cast<double>(nums2[size2/2])/2;
    }
}

int main() {
    int n, m;
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());
    cin >> n >> m;
    vector<int> nums1(n,0);
    vector<int> nums2(m,0);
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> nums2[j];
    }
    cout << findMedianSortedArrays(nums1, nums2);
}