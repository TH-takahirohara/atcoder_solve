#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N, M;
string S;

bool hantei(int L) {
  int muji = M;
  int logo = L;

  rep(i,0,N) {
    if (S.at(i) == '0') {
      muji = M;
      logo = L;
    } else if (S.at(i) == '1') {
      if (muji > 0) {
        muji--;
      } else if (logo > 0) {
        logo--;
      } else {
        return false;
      }
    } else { // 2: kyopro event
      if (logo > 0) {
        logo--;
      } else {
        return false;
      }
    }
  }
  return true;
}

int main() {  
  cin >> N >> M;
  cin >> S;

  ll ng = -1;
  ll ok = N+1;
  while (ok - ng > 1) {
    ll mid = (ng + ok) / 2;

    if (hantei(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
}
