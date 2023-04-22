#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  
  int ng = 0;
  int ok = N + 1;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    cout << "? ";
    cout << mid << endl;
    int s;
    cin >> s;
    if (s == 0) ng = mid;
    else ok = mid;
  }

  cout << "! ";
  cout << ng << endl;
}
