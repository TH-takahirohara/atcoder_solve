#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  rep(i,0,N) cin >> v.at(i);

  vector<int> cnt_o(100001), cnt_e(100001);
  rep(i,0,N/2) {
    cnt_o.at(v.at(2*i))++;
  }
  rep(i,0,N/2) {
    cnt_e.at(v.at(2*i+1))++;
  }

  int idx_o = -1, idx_e = -1;
  int max_o = 0, max_e = 0;
  int idx_o_2 = -1, idx_e_2 = -1;
  int max_o_2 = 0, max_e_2 = 0;

  // 奇数番目に登場する数のうち、最多の登場回数とそのindex
  rep(i,0,100001) {
    if (cnt_o.at(i) > max_o) {
      max_o = cnt_o.at(i);
      idx_o = i;
    }
  }
  // 2番目に多い登場回数とそのindex
  rep(i,0,100001) {
    if (i == idx_o) continue;
    if (cnt_o.at(i) > max_o_2) {
      max_o_2 = cnt_o.at(i);
      idx_o_2 = i;
    }
  }
  // 偶数番目に登場する数のうち、最多の登場回数とそのindex
  rep(i,0,100001) {
    if (cnt_e.at(i) > max_e) {
      max_e = cnt_e.at(i);
      idx_e = i;
    }
  }
  // 2番目に多い登場回数とそのindex
  rep(i,0,100001) {
    if (i == idx_e) continue;
    if (cnt_e.at(i) > max_e_2) {
      max_e_2 = cnt_e.at(i);
      idx_e_2 = i;
    }
  }

  if (idx_o == idx_e) {
    if (max_o_2 < max_e_2) {
      max_e = max_e_2;
    } else {
      max_o = max_o_2;
    }
  }

  cout << N - max_o - max_e << endl;
}
