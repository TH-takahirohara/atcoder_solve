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
  int N,K;
  cin >> N >> K;
  queue<int> que;
  vector<int> A(N);
  // rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) {
    int tmp; cin >> tmp;
    que.push(tmp);
  }

  rep(i,0,K) {
    que.pop();
    que.push(0);
  }

  while (!que.empty()) {
    cout << que.front() << " ";
    que.pop();
  }
}
