#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N,L;
int nums[21][21];
int dp[21][20][20][20][20];

bool in_bound(int y, int x) {
    return y>0 && y<=N && x>0 && x<=N; 
}

bool reachable(int l, int y1, int x1, int y2, int x2) {
    return abs(y2-y1) + abs(x2-x1) == (l-1);
}

int solve_r(int l, int y1, int x1, int y2, int x2) {
    //cout<<l<<" "<<y1<<","<<x1<<"("<<nums[y1][x1]<<")"<<" "<<y2<<","<<x2<<"("<<nums[y2][x2]<<")"<<endl;
    vector<pair<pair<int,int>,pair<int,int>>> numbers;
    cout<<l<<" "<<y1<<","<<x1<<" "<<y2<<","<<x2<<endl;
    if(l==1) return 1;
    if(l==2) {
        if(in_bound(y1,x1)&&in_bound(y2,x2)) {
            if(y2>=y1-1 && y2<=y1+1 && x2>=x1-1 && x2<=x1+1) {
                if(nums[y1][x1] == nums[y2][x2]) {
                    return 1;
                }
            }
        }
        return 0;
    }
    int &ret = dp[l][y1][x1][y2][x2];
    if(ret != -1) return ret;
    ret = 0;
    for(int y3=y1-1;y3<=y1+1;y3++) {
        for(int x3=x1-1;x3<=x1+1;x3++) {
            for(int y4=y2-1;y4<=y2+1;y4++) {
                for(int x4=x2-1;x4<=x2+1;x4++) {
                    if(!(x3==x1&&y3==y1)&&!(x4==x2&&y4==y2)) {
                        if(in_bound(y3,x3)&&in_bound(y4,x4)) {
                            if(nums[y3][x3]==nums[y4][x4]) {
                                numbers.emplace_back(make_pair(y3,x3),make_pair(y4,x4));
                                ret = ret + solve_r(l-2,y3,x3,y4,x4);
                            }
                        }
                    }   
                }
            }    
        }
    }
    for(auto p : numbers) {
        cout<< nums[p.first.first][p.first.second]<<nums[y1][x1]
        <<nums[p.second.first][p.second.second]<<endl;
    }
    cout<<"ret: "<<ret<<endl;
    return ret;
}

int main() {
    scanf("%d%d",&N,&L);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            scanf("%d",&nums[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int y1=1;y1<=N;y1++) {
        for(int x1=1;x1<=N;x1++) {
            for(int y2=1;y2<=N;y2++) {
                for(int x2=1;x2<=N;x2++) {
                    if(nums[y1][x1] == nums[y2][x2]) {
                        ans = ans + solve_r(L,y1,x1,y2,x2);                            
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}