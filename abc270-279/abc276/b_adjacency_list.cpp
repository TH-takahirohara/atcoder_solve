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
  int N, M;
  cin >> N >> M;
  vector<priority_queue<int, vector<int>, greater<int>>> G(N+1);

  rep(i,0,M) {
    int a, b;
    cin >> a >> b;
    G.at(a).push(b);
    G.at(b).push(a);
  }

  rep(i,1,N+1) {
    int sz = G.at(i).size();
    auto pq = G.at(i);
    cout << sz << " ";
    while (!pq.empty()) {
      cout << pq.top() << " ";
      pq.pop();
    }
    cout << endl;
  }
}
