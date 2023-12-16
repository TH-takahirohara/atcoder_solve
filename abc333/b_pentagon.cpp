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
  string SS, TT;
  cin >> SS >> TT;

  int slen = 0;
  int tlen = 0;
  
  slen = abs(int(SS.at(0) - 'A') - int(SS.at(1) - 'A'));
  tlen = abs(int(TT.at(0) - 'A') - int(TT.at(1) - 'A'));

  slen = min(slen, 5 - slen);
  tlen = min(tlen, 5 - tlen);

  if (slen == tlen) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
