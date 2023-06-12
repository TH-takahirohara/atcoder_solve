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

  int cnt = 0;
  rep(i,1,N+1) {
    int n10 = i;
    bool no10 = true;
    while (n10 > 0) {
      if (n10 % 10 == 7) no10 = false;
      n10 /= 10;
    }

    int n8 = i;
    bool no8 = true;
    while (n8 > 0) {
      if (n8 % 8 == 7) no8 = false;
      n8 /= 8;
    }

    if (no10 && no8) cnt++;
  }

  cout << cnt << endl;
}
