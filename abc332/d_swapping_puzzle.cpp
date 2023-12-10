#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int R, C;
vector<vector<int>> A, B;

bool hantei(vector<int> &tate, vector<int> &yoko) {
  rep(i,0,R) {
    rep(j,0,C) {
      if (A.at(tate.at(i)).at(yoko.at(j)) != B.at(i).at(j)) {
        return false;
      }
    }
  }
  return true;
}

int bubble_num(vector<int> _arr) {
  vector<int> arr = _arr;
  int sz = _arr.size();
  int cnt = 0;
  for (int i=0; i < sz; i++) {
    for (int j=i+1; j < sz; j++) {
      if (arr.at(i) > arr.at(j)) {
        cnt++;
        int tmp = arr.at(i);
        arr.at(i) = arr.at(j);
        arr.at(j) = tmp;
      }
    }
  }
  return cnt;
}

int main() {
  cin >> R >> C;
  A.assign(R, vector<int>(C));
  B.assign(R, vector<int>(C));
  rep(i,0,R) {
    rep(j,0,C) {
      cin >> A.at(i).at(j);
    }
  }
  rep(i,0,R) {
    rep(j,0,C) {
      cin >> B.at(i).at(j);
    }
  }

  vector<int> tate(R), yoko(C);
  rep(i,0,R) {
    tate.at(i) = i;
  }
  rep(i,0,C) {
    yoko.at(i) = i;
  }

  int ans = 1e9;
  do {
    do {
      if (hantei(tate, yoko)) {
        int tate_num = bubble_num(tate);
        int yoko_num = bubble_num(yoko);
        ans = min(ans, tate_num + yoko_num);
      }
    } while (next_permutation(tate.begin(), tate.end()));
  } while (next_permutation(yoko.begin(), yoko.end()));

  if (ans >= 5e8) cout << -1 << endl;
  else cout << ans << endl;
}
