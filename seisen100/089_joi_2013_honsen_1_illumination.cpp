// 交互列で圧縮する。例えば pair (1, 3) というのは、1(点灯)を先頭とした交互列(1,0,1)に対応する。
// 上記のpairを配列に格納していく。
// 格納できたら、先頭の要素から、各要素について、下記を実施する。tmp_ansの値の最大値が答え。
// (1) その要素の交互列の数(second)をtmp_ansに足す。
// (2) その要素のすべての交互列を反転させた場合の先頭の値が、その要素の１つ前の交互列の最後の値と異なっていたら、
//     1つ前の要素と当該要素とで新たな交互列が作れることになるので、1つ前の要素の交互列の数をtmp_ansに足す。
// (3) その要素のすべての交互列を反転させた場合の最後の値が、その要素の1つ後の交互列の最初の値と異なっていたら、
//     1つ後の要素と当該要素とで新たな交互列が作れることになるので、1つ後の要素の交互列の数をtmp_ansに足す。
// -> こんな面倒なことをしないでも、解説を見ると、交互列を長さの数字に変換し、最大3つ連続する場所の最大値が答え。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  vector<pair<int,int>> vec;
  
  int prev_v;
  
  rep(i,0,N) {
    int v;
    cin >> v;
    
    if (i==0) {
      vec.push_back(make_pair(v, 1));
      prev_v = v;
      continue;
    }
    
    if (prev_v != v) {
      vec.at(vec.size()-1).second += 1;
      prev_v = v;
    } else {
      vec.push_back(make_pair(v, 1));
      prev_v = v;
    }
  }
  
  int ans = 0;
  rep(i,0,vec.size()) {
    int tmp_ans = 0;
    
    tmp_ans += vec.at(i).second;
    
    int now_first = vec.at(i).first;
    int now_last;
    if (vec.at(i).second % 2 == 0) now_last = 1-now_first;
    else now_last = now_first;
    
    int chd_first = 1-now_first;
    int chd_last = 1-now_last;
    
    if (i-1 >= 0) {
      int prev_first = vec.at(i-1).first;
      int prev_last;
      if (vec.at(i-1).second % 2 == 0) prev_last = 1-prev_first;
      else prev_last = prev_first;
      
      if (prev_last != chd_first) tmp_ans += vec.at(i-1).second;
    }
    
    if (i+1 <= vec.size()-1) {
      int nx_first = vec.at(i+1).first;
      if (nx_first != chd_last) tmp_ans += vec.at(i+1).second;
    }
    
    ans = max(ans, tmp_ans);
  }
  
  cout << ans << endl;
}
