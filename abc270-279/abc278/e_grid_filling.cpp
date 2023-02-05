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
  int H, W, N, h, w;
  cin >> H >> W >> N >> h >> w;
  set<int> st;
  map<int,int> mp;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i,0,H) {
    rep(j,0,W) {
      int tmp;
      cin >> tmp;
      A.at(i).at(j) = tmp;
      st.insert(tmp);
      mp[tmp]++;
    }
  }



  rep(i1,0,H-h+1) {
    set<int> stt = st;
    map<int,int> mpt = mp;
    rep(i,i1,h+i1) {
      rep(j,0,w) {
        int tar = A.at(i).at(j);
        mpt[tar]--;
        if (mpt[tar] == 0) stt.erase(tar);
      }
    }

    rep(j1,0,W-w+1) {
      // cout << i1 << " " << j1 << endl;
      if (j1 == 0) {
        cout << stt.size() << " ";
        continue;
      }

      // 縦方向の左端を追加、右端を削除
      rep(i2,i1,h+i1) {
        int tar1 = A.at(i2).at(j1-1);
        mpt[tar1]++;
        if (mpt[tar1] == 1) stt.insert(tar1);
        int tar2 = A.at(i2).at(j1+w-1);
        mpt[tar2]--;
        if (mpt[tar2] == 0) stt.erase(tar2);
      }
      cout << stt.size() << " ";
    }
    cout << endl;
  }
}
