#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,int> split(const string &s) {
    unordered_map<string,int> ret;
    int idx=0;
    for (int i=0;i<s.size();i++) {
        if (s[i] == ' ') {
            string t;
            for(int j=idx;j<i;j++) {
                t = t + s[j];
            }
            ret.insert({t,1});
            idx = i+1;
        }
    }
    string t;
    for(int j=idx;j<s.size();j++) {
        t = t + s[j];
    }
    ret.insert({t,1});
    return ret;
}

int count(unordered_map<string,int> &lang, unordered_map<string,int> &tmp) {
        
}

int main() {
    string tmp;
    getline(cin,tmp);
    int tc = tmp[0] - '0';
    while(tc--) {
        getline(cin,tmp);
        int N = tmp[0] - '0';
        string f,e,t;
        getline(cin,e);
        getline(cin,f);
        unordered_map<string,int> english = split(e);
        unordered_map<string,int> french = split(f);
        for(int i=0; i<N-2; i++) {
            getline(cin,t);
            unordered_map<string,int> tmp = split(t);
        }
    }
}
