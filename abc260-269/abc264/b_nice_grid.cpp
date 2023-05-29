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
  int R, C;
  cin >> R >> C;
  R--; C--;
  vector<vector<bool>> vec(15, vector<bool>(15));

  pair<int,int> lu = make_pair(7,7), ld = make_pair(7,7), ru = make_pair(7,7), rd = make_pair(7,7);
  bool is_black = false;
  for (int i=0; i < 8; i++) {
    for (int c = lu.second; c <= ru.second; c++) {
      vec.at(lu.first).at(c) = is_black;
      vec.at(ld.first).at(c) = is_black;
    }
    for (int r = ru.first; r <= rd.first; r++) {
      vec.at(r).at(ru.second) = is_black;
      vec.at(r).at(lu.second) = is_black;
    }
    is_black = !is_black;
    lu = make_pair(lu.first - 1, lu.second - 1);
    ld = make_pair(ld.first + 1, ld.second - 1);
    ru = make_pair(ru.first - 1, ru.second + 1);
    rd = make_pair(rd.first + 1, rd.second + 1);
  }

  if (vec.at(R).at(C)) cout << "black" << endl;
  else cout << "white" << endl;
}
