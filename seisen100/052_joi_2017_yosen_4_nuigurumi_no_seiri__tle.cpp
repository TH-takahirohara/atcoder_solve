// テストケース5問中4問正解で80点。最後のテストケースがTLEとなる。
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
int INF = 1000000000;

int rec(int bit, int v) {
  if (bit==(1<<v)) {
    int cnt_t = 0;
    rep(i,N-cnts.at(v),N) if (vec.at(i) != v) cnt_t++;
    return cnt_t;
  }
  
  if (dp.at(bit).at(v) != -1) return dp.at(bit).at(v);
  
  // ずらす量
  int zurasu = 0;
  rep(j,0,M) {
    if (~bit & (1<<j)) zurasu += cnts.at(j);
  }
  
  int cnt = 0;
  rep(k,zurasu,zurasu+cnts.at(v)) {
    if (vec.at(k) != v) cnt++;
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
  
  dp.assign((1<<M), vector<int>(20, -1));
  
  int res = INF;
  rep(i,0,M) {
    res = min(res, rec((1<<M)-1, i));
  }
  
  cout << res << endl;
}
