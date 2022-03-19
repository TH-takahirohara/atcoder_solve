// 文字列サイズよりR,Cがそれぞれ1だけ大きいdp行列を使うのがポイントと思われる。
// こうすると、i,jの文字が一致している場合、i-1, j-1 の座標の値から1加算した値と比較し、
// そうでない場合、i-1, j-1の座標の値と比較する、という形を統一的に扱える。
// こうしないと、例えば下記の丸印付きの座標の緩和を行いづらくなる。
//     b d c a b a
//   0 0 0 0 0 0 0
// a 0 0 0 0 1 1 ①
// b 0 1 1 1 1 2 2
// c 0 1 1 2 2 2 2
// b 0 1 1 2 2 3 3
// d 0 1 2 2 2 3 3
// a 0 1 2 2 3 3 4
// b 0 1 2 2 3 4 4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  rep(loop,0,N) {
    string str1, str2;
    cin >> str1 >> str2;
    
    vector<vector<int> > dp(str1.size()+1, vector<int>(str2.size()+1, 0));
    
    rep(i,1,str1.size()+1) {
      rep(j,1,str2.size()+1) {
        dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j));
        dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i).at(j-1));
        if (str1.at(i-1) == str2.at(j-1)) dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j-1)+1);
        else dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j-1));
      }
    }
    
    cout << dp.at(str1.size()).at(str2.size()) << endl;
  }
}
