#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N, R, C;

bool hantei(vector<pair<int,int>> &tairu_arr) {
  vector<vector<int>> masu(R, vector<int>(C));
  int idx = 0;
  rep(r,0,R) {
    rep(c,0,C) {
      if (idx >= tairu_arr.size()) {
        break;
      }
      if (masu.at(r).at(c) == 0) {
        auto p = tairu_arr.at(idx);
        int tate = p.first;
        int yoko = p.second;
        if (r + tate > R || c + yoko > C) { // はみ出るケース
          return false;
        }
        rep(i,0,tate) {
          rep(j,0,yoko) {
            masu.at(r+i).at(c+j) += 1;
          }
        }
        idx++;
      }
    }
  }

  rep(i,0,R) {
    rep(j,0,C) {
      if (masu.at(i).at(j) == 0 || masu.at(i).at(j) > 1) {
        return false;
      }
    }
  }
  return true;
}

int main() {  
  cin >> N >> R >> C;
  vector<pair<int,int>> tairu(N);
  rep(i,0,N) {
    int a, b;
    cin >> a >> b;
    tairu.at(i) = make_pair(a,b);
  }

  for (int i=1; i < (1<<N); i++) {
    vector<int> idxs;
    for (int j=0; j < N; j++) {
      if (i & (1 << j)) {
        idxs.push_back(j);
      }
    }

    int sz = idxs.size();
    do {
      for (int k=0; k < (1 << sz); k++) {
        vector<pair<int,int>> new_tairu_arr;
        for (int l=0; l < sz; l++) {
          auto pa = tairu.at(idxs.at(l));
          if (k & (1 << l)) {
            new_tairu_arr.push_back(make_pair(pa.second, pa.first));
          } else {
            new_tairu_arr.push_back(pa);
          }
        }

        if (hantei(new_tairu_arr)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    } while (next_permutation(idxs.begin(), idxs.end()));
  }
  cout << "No" << endl;
}
