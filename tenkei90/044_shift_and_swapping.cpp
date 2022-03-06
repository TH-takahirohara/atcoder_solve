#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, Q;
  cin >> N >> Q;
  deque<int> deq;

  rep(i, N) {
    int tmp;
    cin >> tmp;
    deq.push_back(tmp);
  }
  
  rep(i, Q) {
    int ti;
    cin >> ti;
    if (ti == 1) {
      int x, y, tmp;
      cin >> x >> y;
      x--; y--;
      
      tmp = deq.at(x);
      deq.at(x) = deq.at(y);
      deq.at(y) = tmp;
    } else if (ti == 2) {
      int dm1, dm2;
      cin >> dm1 >> dm2;
      
      int last = deq.back();
      deq.pop_back();
      deq.push_front(last);
    } else {
      int x, dm;
      cin >> x >> dm;
      x--;
      
      cout << deq.at(x) << endl;
    }
  }
}

