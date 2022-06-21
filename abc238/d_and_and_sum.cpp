// まず、s>=2aでないといけない。この時、aを2進数で表した場合に0となる桁をi1などとした時、
// s-2a = 2^i1 + 2^i2 + 2^i3 ...
// のような形式になっていれば良いと考えて解いてACした。
// 解説を見るとこんなことはしなくてももっと簡単な方法がある模様。
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
  int T;
  cin >> T;
  
  vector<ull> rui2(60);
  rep(i,0,60) {
    ull tmp = 1;
    rep(j,0,i) {
      tmp *= 2;
    }
    rui2.at(i) = tmp;
  }
  
  rep(ite,0,T) {
    ull a,s;
    cin >> a >> s;
    
    if (s < 2*a) {
      cout << "No" << endl;
      continue;
    }
    
    ull tmp = s - 2*a;
    
    vector<ull> keta(60);
    ull cnt = 0;
    while (a > 0) {
      if (a % 2 != 0) keta.at(cnt) = 1;
      a /= 2;
      cnt++;
    }
    
    for (int i=59; i>=0; i--) {
      if (keta.at(i) == 0 && tmp > 0 && tmp >= rui2.at(i)) {
        tmp -= rui2.at(i);
      }
    }
    if (tmp == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

