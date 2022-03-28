// 数値が出てくる個数について累積和の考え方で対処することで、TLEを回避できるようになりACとなった。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int N,M;
vector<int> vec;
vector<int> cnts;
vector<vector<int>> dp;
vector<vector<int>> rui_cnts;
int INF = 1000000000;

int rec(int bit, int v) {
  if (bit==(1<<v)) {
    int cnt_tmp = 0;
    if (N-cnts.at(v)==0) {
      cnt_tmp = cnts.at(v) - (rui_cnts.at(v).at(N-1));
    } else {
      cnt_tmp = cnts.at(v) - (rui_cnts.at(v).at(N-1) - rui_cnts.at(v).at(N-cnts.at(v)-1));
    }
    return cnt_tmp;
  }
  
  if (dp.at(bit).at(v) != -1) return dp.at(bit).at(v);
  
  // ずらす量
  int zurasu = 0;
  rep(j,0,M) {
    if (~bit & (1<<j)) zurasu += cnts.at(j);
  }
  
  int cnt = 0;
  if (zurasu==0) {
    cnt = cnts.at(v) - (rui_cnts.at(v).at(zurasu+cnts.at(v)-1));
  } else {
    cnt = cnts.at(v) - (rui_cnts.at(v).at(zurasu+cnts.at(v)-1) - rui_cnts.at(v).at(zurasu-1));
  }
  
  int prev_bit = bit & ~(1<<v);
  
  int res = INF;
  rep(i,0,M) {
    if (!(prev_bit & (1<<i))) continue;
    
    res = min(res, rec(prev_bit, i) + cnt);
  }
  
  return dp.at(bit).at(v) = res;
}

int main() {
  cin >> N >> M;
  
  vec.assign(N,0);
  rep(i,0,N) {
    int tmp;
    cin >> tmp;
    tmp--;
    vec.at(i) = tmp;
  }
  
  cnts.assign(M,0);
  rep(i,0,N) {
    cnts.at(vec.at(i))++;
  }
  
  rui_cnts.assign(M, vector<int>(N,0));
  rep(i,0,M) {
    int now = 0;
    rep(j,0,N) {
      if (vec.at(j) == i) now++;
      rui_cnts.at(i).at(j) = now;
    }
  }
  
  dp.assign((1<<M), vector<int>(20, -1));
  
  int res = INF;
  rep(i,0,M) {
    res = min(res, rec((1<<M)-1, i));
  }
  
  cout << res << endl;
}
