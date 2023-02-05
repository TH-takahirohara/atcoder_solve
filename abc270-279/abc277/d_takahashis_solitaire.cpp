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
  int N; ll M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  sort(A.begin(), A.end());

  ll sum = 0;
  rep(i,0,N) sum += A.at(i);

  ll ans = sum;
  if (A.at(0) == 0) {
    ll stz = 0;
    int idx = 0;
    ll tar = 0;
    while (idx < N) {
      if (A.at(idx) == tar) {
        stz += A.at(idx);
        idx++;
      } else if (A.at(idx) == tar + 1) {
        tar++;
        stz += A.at(idx);
        idx++;
      } else {
        break;
      }
    }
    // cout << stz << endl;

    if (idx >= N-1) {
      cout << sum - stz << endl;
      return 0;
    }

    ll tmpans = 1e18;
    ll tmp = 0;
    ll v = A.at(idx);
    while (idx < N) {
      // cout << "v: " << v << endl;
      if (A.at(idx) == v) {
        tmp += A.at(idx);
        tmpans = min(tmpans, sum - tmp);
        if (idx == N-1 && A.at(idx) == M-1) {
          tmpans = min(tmpans, sum - tmp - stz);
        }
        idx++;
      } else if (A.at(idx) == v+1) {
        v++;
        tmp += A.at(idx);
        tmpans = min(tmpans, sum - tmp);
        if (idx == N-1 && A.at(idx) == M-1) {
          tmpans = min(tmpans, sum - tmp - stz);
        }
        idx++;
      } else {
        v = A.at(idx);
        tmp = A.at(idx);
        idx++;
        tmpans = min(tmpans, sum - tmp);
      }
    }
    cout << tmpans << endl;
  } else {
    int idx = 0;
    ll tmpans = 1e18;
    ll tmp = 0;
    ll v = A.at(idx);
    while (idx < N) {
      if (A.at(idx) == v) {
        tmp += A.at(idx);
        tmpans = min(tmpans, sum - tmp);
        idx++;
      } else if (A.at(idx) == v+1) {
        v++;
        tmp += A.at(idx);
        tmpans = min(tmpans, sum - tmp);
        idx++;
      } else {
        v = A.at(idx);
        // tmpを初期化
        tmp = A.at(idx);
        idx++;
        tmpans = min(tmpans, sum - tmp);
      }
    }
    cout << tmpans << endl;
  }
}
