#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> nums;
    for(int n : nums) {
        cout<<n<<endl;
    }
    nums.resize(3);
    for(int n : nums) {
        cout<<n<<endl;
    }
    fill(nums.begin(),nums.end(),1);
    for(int n : nums) {
        cout<<n<<endl;
    }
    nums.clear();
    for(int n : nums) {
        cout<<n<<endl;
    }
    nums.resize(3);
    for(int n : nums) {
        cout<<n<<endl;
    }
}