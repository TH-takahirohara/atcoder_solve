// サンプルケースだと通るが、テストにかけるとruntime errorが出る。
// 調べてみると、sがピースの四隅に一致する場合があり、
// それがきっかけで剰余計算時の右辺の値が0になることが原因であるとわかった。
// だが、それを直す方法が分からなかった。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  while (true) {
    int N,W,H;
    cin >> N >> W >> H;
    if (N==0 && W==0 && H==0) break;
    
    vector<pair<int,int> > vec;
    vec.push_back(make_pair(W, H));
    
    rep(i,0,N) {
      int p,s;
      cin >> p >> s;
      p--;
      
      pair<int,int> tar_p = vec.at(p);
      int wid = tar_p.first;
      int hei = tar_p.second;
      int dis = s % ((wid+hei)*2);
      
      int new_wid, new_hei;
      if (dis<wid) {
        new_wid = dis;
        new_hei = hei;
      } else if (wid<dis && dis < (wid+hei)) {
        new_wid = wid;
        new_hei = dis - wid;
      } else if ((wid+hei) < dis && dis < (wid*2+hei)) {
        new_wid = dis - wid - hei;
        new_hei = hei;
      } else if (dis > (wid*2+hei)) {
        new_wid = wid;
        new_hei = dis - wid*2 - hei;
      }
      
      // 配列の修正、新規追加
      if (new_wid == wid) {
        if (new_hei < hei - new_hei) {
          vec.at(p) = make_pair(new_wid, new_hei);
          vec.push_back(make_pair(new_wid, hei - new_hei));
        } else {
          vec.at(p) = make_pair(new_wid, hei - new_hei);
          vec.push_back(make_pair(new_wid, new_hei));
        }
      } else {
        if (new_wid < wid - new_wid) {
          vec.at(p) = make_pair(new_wid, new_hei);
          vec.push_back(make_pair(wid - new_wid, new_hei));
        } else {
          vec.at(p) = make_pair(wid - new_wid, new_hei);
          vec.push_back(make_pair(new_wid, new_hei));
          
        }
      }
      
    }
    
    // 面積を格納する配列を作成
    vector<int> mensekis;
    rep(i,0,N+1) {
      int wid = vec.at(i).first;
      int hei = vec.at(i).second;
      mensekis.push_back(wid*hei);
    }
    
    // 出力
    sort(mensekis.begin(), mensekis.end());
    rep(i,0,N+1) {
      if (i!=N) cout << mensekis.at(i) << " ";
      else cout << mensekis.at(i) << endl;
    }
  }
}
