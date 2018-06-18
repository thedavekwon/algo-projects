//
// Created by dodo on 18. 6. 17.
//

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int max_N = 100;

int sums[max_N];
int numbers[max_N];
int squaredSums[max_N];
int avgCache[max_N][max_N];

int mean_avg(int start, int end) {
    if (avgCache[start][end] != -1) return avgCache[start][end];
    int temp_squared_sum = (start==0) ? squaredSums[end-1] : squaredSums[end-1] - squaredSums[start-1];
    int temp_sum = (start == 0) ? sums[end-1] : sums[end-1] - sums[start-1];
    auto mid = static_cast<int>(round(static_cast<double>(temp_sum) / (end - start)));
    int sum = temp_squared_sum - 2*mid*temp_sum + (mid*mid)*(end-start);
    avgCache[start][end] = sum;
    return avgCache[start][end];
}

int main() {
    for (int i = 0; i < 5; ++i) numbers[i] = i+1;
    sums[0] = numbers[0];
    squaredSums[0] = numbers[0] * numbers[0];
    for (int i = 1; i < 5; ++i) {
        sums[i] = sums[i-1] + numbers[i];
        squaredSums[i] = squaredSums[i-1] + (numbers[i] * numbers[i]);
    }
    memset(avgCache, -1, sizeof(avgCache));
    cout << mean_avg(0, 5) << endl;
}
