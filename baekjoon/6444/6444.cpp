#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        cin>>N>>M;
        unordered_map<pair<int,int>,vector<string>> eqs;
        vector<vector<int>> spreadsheet(N,vector<int>(M));
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                string in;
                cin>>in;
                if(in[0] != '=') {
                    spreadsheet[i][j] = atoi(in.c_str());
                } else {
                    vector<string> vars;
                    int idx = 1;
                    for(int i=1;i<in.size();i++) {
                        if(in[i] == '+') {
                            vars.push_back(in.substr(idx,i-idx));
                            idx = i;
                        }
                    }
                    vars.push_back(in.substr(idx,in.size()-idx));
                    eqs.insert(make_pair<pair<int,int>,vector<int>(make_pair(i,j),vars));
                }
            }
        }
    }
}