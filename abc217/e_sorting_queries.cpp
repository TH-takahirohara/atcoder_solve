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
  int Q;
  cin >> Q;
  priority_queue<int, vector<int>, greater<int>> pq;
  deque<int> deq;

  rep(i,0,Q) {
    int c; cin >> c;
    if (c == 1) {
      int x; cin >> x;
      deq.push_back(x);
    } else if (c == 2) {
      if (pq.empty()) {
        cout << deq.front() << endl;
        deq.pop_front();
      } else {
        cout << pq.top() << endl;
        pq.pop();
      }
    } else {
      int sz = deq.size();
      rep(i,0,sz) {
        pq.push(deq.front());
        deq.pop_front();
      }
    }
  }
}
