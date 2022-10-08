// 1つだけWAとなった。
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  map<int,int> mp;
  rep(i,0,N) mp[A.at(i)]++;

  int amari = 0;
  for (auto &p : mp) {
    int v = p.second;
    amari += max(v-1, 0);
  }

  int plus = amari / 2;
  amari = amari % 2;
  int idx = 1;
  rep(i,0,1000000) {
    if (mp.count(idx) && mp.at(idx) > 0) {
      idx++;
    } else {
      if (plus > 0) {
        plus--;
        mp[idx] = 1;
        idx++;
      } else {
        break;
      }
    }
  }

  if (idx == 1) {
    cout << 0 << endl;
    return 0;
  }

  auto r = --mp.end();
  rep(i,1,300005) {
    if (i >= (*r).first) break;
    if (mp.count(i) && mp.at(i) > 0) continue;
    while (i < (*r).first && amari < 2) {
      amari++;
      (*r).second = 0;
      r = (--r);
    }
    if (amari < 2) break;
    amari = 0;
    mp[i] = 1;
  }

  rep(i,1,300005) {
    if (mp.count(i) && mp.at(i) > 0) continue;
    cout << i-1 << endl;
    return 0;
  }
}
