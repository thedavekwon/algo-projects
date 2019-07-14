#include <iostream>
#include <fstream>
#include <stack>
#include <cmath>

using namespace std;

const long long limit = pow(2, 32);

void check(long long x) {
    if (x >= limit) {
        cout << "OVERFLOW!!!" << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    ifstream in("./B.input");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    long long x = 0;
    string tmp;
    stack<long long> values;
    values.push(1);
    
    while (tc--) {
        cin >> tmp;
        if (tmp == "for") {
            long long tt = 0;
            cin >> tt;
            values.push(min(limit, values.top()*tt));
        } else if (tmp == "end") {
            values.pop();
        } else {
            x = x + values.top();
        }        
    }

    check(x);
}