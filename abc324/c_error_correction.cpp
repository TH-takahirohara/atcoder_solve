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
  int N;
  cin >> N;
  string Td;
  cin >> Td;
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  vector<int> cnttd(30);
  rep(i,0,Td.size()) {
    char c = Td.at(i);
    int idx = int(c - 'a');
    cnttd.at(idx)++;
  }

  vector<int> ans;
  rep(i,0,N) {
    string s = S.at(i);
    // vector<int> cnts(30);
    // rep(j,0,s.size()) {
    //   char c = s.at(i);
    //   int idx = int(c - 'a');
    //   cnts.at(idx)++;
    // }
    // cout << "s: " << s << endl;

    // if (Td.size() - s.size() >= 2 || s.size() - Td.size() >= 2) continue;
    // cout << "i: " << i << endl;
    if (Td == s) {
      ans.push_back(i+1);
      continue;
    }

    if (Td.size() - s.size() == 1) {
      int idx = -1;
      rep(k,0,s.size()) {
        if (Td.at(k) != s.at(k)) {
          idx = k;
          break;
        }
      }
      if (idx == -1) {
        ans.push_back(i+1);
        continue;
      }
      string Tdc = Td;
      string Tdcn = Tdc.erase(idx,1);
      // cout << "Tdcn: " << Tdcn << endl;
      bool can = true;
      rep(k,0,s.size()) {
        if (Tdcn.at(k) != s.at(k)) {
          can = false;
        }
      }
      if (can) {
        ans.push_back(i+1);
        continue;
      }
    }

    if (s.size() - Td.size() == 1) {
      int idx = -1;
      rep(k,0,Td.size()) {
        if (Td.at(k) != s.at(k)) {
          idx = k;
          break;
        }
      }
      if (idx == -1) {
        ans.push_back(i+1);
        continue;
      }
      string sn = s;
      string snn = sn.erase(idx,1);
      bool can = true;
      rep(k,0,Td.size()) {
        if (Td.at(k) != snn.at(k)) {
          can = false;
          break;
        }
      }
      if (can) {
        ans.push_back(i+1);
        continue;
      }
    }

    if (Td.size() == s.size()) {
      int notcnt = 0;
      rep(k,0,s.size()) {
        if (Td.at(k) != s.at(k)) {
          notcnt++;
        }
      }
      if (notcnt == 1) {
        ans.push_back(i+1);
        continue;
      }
    }
  }

  cout << ans.size() << endl;
  rep(i,0,ans.size()) {
    cout << ans.at(i) << " ";
  }
  cout << endl;
}
