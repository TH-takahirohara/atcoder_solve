// 解けなかった。N進数の問題だが、解けるようにするまでに工夫が必要。
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
  ll N;
  cin >> N;
  ll newN = N;
  
  int keta;
  ll cnt = 0;
  rep(i,1,15) {
    ll tmp = 1;
    rep(j,0,i) tmp *= 26;
    cnt += tmp;
    if (N <= cnt) {
      keta = i;
      break;
    }
    newN -= tmp;
  }
  
  newN--;
  vector<ll> vec;
  rep(i,0,keta) {
    vec.push_back(newN % 26);
    newN /= 26;
  }
  
  string S = "";
  rep(i,0,keta) {
    S = (char)(vec.at(i) + 'a') + S;
  }
  cout << S << endl;
}

