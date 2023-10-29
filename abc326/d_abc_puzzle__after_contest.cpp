#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<vector<int>> idxs5 = {{2,3,4}, {1,3,4}, {1,2,4}, {1,2,3}, {0,3,4}, {0,2,4}, {0,2,3}, {0,1,4}, {0,1,3}, {0,1,2}};
vector<vector<int>> idxs4 = {{0,1,2}, {0,1,3}, {0,2,3}, {1,2,3}};
vector<vector<int>> idxs3 = {{0,1,2}};

bool ok = false;
vector<string> ans;

string R, C;

vector<string> mojivec(char c) {
  if (c=='A') return {"ABC", "ACB"};
  else if (c=='B') return {"BAC", "BCA"};
  else return {"CAB", "CBA"};
}

void rec(int nokori, int n, vector<vector<int>> idxs, vector<string> vec) {
  if (nokori == 0) {
    bool can = true;
    for (int j=0; j<n; j++) {
      vector<int> kazus(3);
      rep(i,0,n) {
        if (vec.at(i).at(j) == '.') continue;
        kazus.at(int(vec.at(i).at(j) - 'A'))++;
      }
      rep(i,0,3) {
        if (kazus.at(i) != 1) can = false;
      }
    }

    for (int j=0; j<n; j++) {
      char c = C.at(j);
      rep(i,0,n) {
        if (vec.at(i).at(j) == '.') continue;
        if (vec.at(i).at(j) != c) {
          can = false;
          break;
        } else {
          break;
        }
      }
    }

    if (can) {
      ok = true;
      ans = vec;
    }
    return;
  }
  for (auto idx : idxs) {
    char c = R.at(n-nokori);
    vector<string> mojiv = mojivec(c);
    for (auto moji : mojiv) {
      vector<string> nvec = vec;
      string s = "";
      rep(i,0,n) s += ".";
      for (int i=0; i < 3; i++) {
        s.at(idx.at(i)) = moji.at(i);
      }
      nvec.push_back(s);
      rec(nokori-1, n, idxs, nvec);
    }
  }
}

int main() {
  int N;
  cin >> N;
  cin >> R >> C;

  vector<vector<int>> idxs;
  if (N == 5) idxs = idxs5;
  else if (N == 4) idxs = idxs4;
  else idxs = idxs3;

  rec(N,N,idxs,{});
  if (ok) {
    cout << "Yes" << endl;
    rep(i,0,N) {
      cout << ans.at(i) << endl;
    }
  } else {
    cout << "No" << endl;
  }
}
