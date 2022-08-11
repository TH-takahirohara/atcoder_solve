// 最初、コンテスト後に追加されたテストケース以外は通っていた。
// それが通らず、テストケースを見た。
// 条件3で2回動くケースについての考慮が漏れていたので、それに対応する処理（27-29行）を追加しAC。
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

string S;
bool can = false;

void rec(vector<int> vec, int cnt, string s) {
  if (cnt == 0) {
    if (stoi(s) % 8 == 0) can = true;
    return;
  } else if (S.size() == 1 && cnt == 2) {
    if (stoi(s) % 8 == 0) can = true;
    return;
  } else if (S.size() == 2 && cnt == 1) {
    if (stoi(s) % 8 == 0) can = true;
    return;
  }
  
  rep(i,1,10) {
    if (vec.at(i) > 0) {
      vec.at(i) -= 1;
      rec(vec, cnt-1, s + to_string(i));
      vec.at(i) += 1;
    }
  }
}

int main() {
  cin >> S;

  vector<int> vec(10);
  rep(i,0,S.size()) {
    vec.at((int)(S.at(i) - '0')) += 1;
  }
  
  rec(vec, 3, "");
  
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
