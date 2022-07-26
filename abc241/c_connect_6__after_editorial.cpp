#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N;
vector<string> vec;

bool check(int i, int j) {
  bool can = false;
  for (int r=-1; r<=1; r++) {
    for (int c=-1; c<=1; c++) {
      if (r==0 && c==0) continue;
      int cnt = 0;
      int cnt_k = 0;
      
      rep(k,0,6) {
        int nowi = i + r*k;
        int nowj = j + c*k;
        if (nowi < 0 || nowj < 0 || nowi >= N || nowj >= N) break;
        if (vec.at(nowi).at(nowj) == '#') cnt_k++;
        cnt++;
      }
      
      if (cnt == 6 && cnt_k >= 4) can = true;
    }
  }
  return can;
}

int main() {
  cin >> N;
  vec.assign(N, "");
  rep(i,0,N) cin >> vec.at(i);
  
  string ans = "No";
  rep(i,0,N) {
    rep(j,0,N) {
      if (vec.at(i).at(j) == '.') continue;
      if (check(i,j)) ans = "Yes";
    }
  }
  cout << ans << endl;
}

