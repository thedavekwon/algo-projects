#include <vector>

using namespace std;

typedef int var;

vector<var> partialSum(const vector<var> &nums) {
    vector<var> ret(nums.size());
    ret[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        ret[i] = ret[i-1] + nums[i];
    }
    return ret;
}

vector<var> squarePartialSum(const vector<var> &nums) {
    vector<var> ret(nums.size());
    ret[0] = nums[0]*nums[0];
    for (int i = 1; i < nums.size(); i++) {
        ret[i] = ret[i-1] + nums[i]*nums[i];
    }
    return ret;
}

var rangeSum(const vector<var> &psum, int a, int b) {
    if (a==0) return psum[b];
    return psum[b] - psum[a-1];
}

double variance(const vector<var>& sqpsum,const vector<var> &psum, int a, int b)  {
    double mean = rangeSum(psum, a, b) / double(b-a+1);
    double ret = rangeSum(sqpsum, a, b) - 2*mean*rangeSum(psum, a, b) + 
                 (b-a+1)*mean*mean;
    return ret / (b-a+1);
}