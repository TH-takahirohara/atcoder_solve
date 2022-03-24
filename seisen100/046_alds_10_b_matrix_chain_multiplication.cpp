// 単純なケース(AB)(C)と(A)(BC)でどのように計算すれば良いか考えて、それを一般化する。
// (A)(BC) -> [0][0]+[1][2]+mr[0]*mc[0]*mc[2] -> [1][2]は、[1][1]+[2][2]+mr[0]*mc[1]*mc[2]=0+0+mr[0]*mc[1]*mc[2] となり、A*Bのスカラー積の個数に対応する。
// (AB)(C) -> [0][1]+[2][2]+mr[0]*mc[1]*mc[2]
// 
// sample inputだと、dp行列は下記のように緩和される。
// 0 15750 7875 9375 11875 15125 
// 1000000000 0 2625 4375 7125 10500 
// 1000000000 1000000000 0 750 2500 5375 
// 1000000000 1000000000 1000000000 0 1000 3500 
// 1000000000 1000000000 1000000000 1000000000 0 5000 
// 1000000000 1000000000 1000000000 1000000000 1000000000 0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<int> mr, mc;
vector<vector<int> > dp;
int INF = 1000000000;

int rec(int l, int r) {
  if (dp.at(l).at(r) != INF) return dp.at(l).at(r);
  if (l==r) {
    dp.at(l).at(r) = 0;
    return 0;
  }
  
  for (int mid = l; mid+1<=r; mid++) {
    dp.at(l).at(r) = min(dp.at(l).at(r), rec(l,mid) + rec(mid+1,r) + mr.at(l)*mc.at(mid)*mc.at(r));
  }
  return dp.at(l).at(r);
}

int main() {
  int N;
  cin >> N;
  
  mr.assign(N, 0);
  mc.assign(N, 0);
  rep(i,0,N) {
    cin >> mr.at(i) >> mc.at(i);
  }
  
  dp.assign(N, vector<int>(N,INF));
  
  rec(0, N-1);
  
  cout << dp.at(0).at(N-1) << endl;
}
