// 大まかな方向性はあっていたが、Nが奇数のケースへの対応ができなかった。
// Nが奇数のケースでは、いずれかのseenを最初にtrueにするとうまく対処できることに
// 解説を見て気づき、その後修正してAC
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N;
vector<vector<ll>> D;
ll ans = 0;

void rec(ll sum, vector<bool> seen) {
  int zan = 0;
  rep(i,0,N) if (!seen.at(i)) zan++;
  if (zan == 0) {
    ans = max(ans, sum);
    return;
  }

  int idx = -1;
  rep(i,0,N) {
    if (!seen.at(i)) {
      idx = i;
      break;
    }
  }
  seen.at(idx) = true;

  rep(i,0,N) {
    if (seen.at(i)) continue;

    seen.at(i) = true;
    rec(sum + D.at(idx).at(i), seen);
    seen.at(i) = false;
  }
}

int main() {
  cin >> N;
  D.assign(N, vector<ll>(N));
  rep(i,0,N-1) {
    rep(j,0,N-1-i) {
      ll tmp;
      cin >> tmp;
      D.at(i).at(j+i+1) = D.at(j+i+1).at(i) = tmp;
    }
  }

  if (N % 2 == 0) {
    vector<bool> iseen(N, false);
    rec(0, iseen);
  } else {
    vector<bool> iseen(N, false);
    rep(i,0,N) {
      iseen.at(i) = true;
      rec(0, iseen);
      iseen.at(i) = false;
    }
  }
  cout << ans << endl;
}
