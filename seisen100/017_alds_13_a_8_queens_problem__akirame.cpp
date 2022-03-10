// 考え方としては、入力のマス以外のマス目について、row, colごとに順列全探索する。
// 下記コードでは、変数canがtrueになるケースが1つだけのはずだが無数に出てしまう状態になり、原因が分からず諦めた。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int K;
vector<int> ex_row, ex_col;
vector<int> row, col;
set<int> t_row, t_col;
int dr[] = {-1, 1, 1, -1};
int dc[] = {-1, -1, 1, 1};
vector<vector<bool>> tmp;

int main() {
  cin >> K;
  
  rep(i, 0, K) {
    int trow, tcol;
    cin >> trow >> tcol;
    ex_row.push_back(trow);
    t_row.insert(trow);
    ex_col.push_back(tcol);
    t_col.insert(tcol);
  }
  
  rep(i, 0, 8) {
    if (!t_row.count(i)) row.push_back(i);
    if (!t_col.count(i)) col.push_back(i);
  }
  
  do {
    do {
      // クイーンのある位置をマッピングする二重配列
      tmp = vector<vector<bool>>(8, vector<bool>(8, false));
      vector<int> tmp_r = {};
      vector<int> tmp_c = {};
      rep(i, 0, K) {
        tmp[ex_row[i]][ex_col[i]] = true;
        tmp_r.push_back(ex_row[i]);
        tmp_c.push_back(ex_col[i]);
      }
      rep(i, 0, (8-K)) {
        tmp[row[i]][col[i]] = true;
        tmp_r.push_back(row[i]);
        tmp_c.push_back(col[i]);
      }
      
      bool can = true;
      rep(i, 0, 8) {
        rep(j, 0, 8) {
          int r_now = tmp_r[i] + dr[j];
          int c_now = tmp_c[i] + dc[j];
          while (r_now >= 0 && r_now < 8 && c_now >= 0 && c_now < 8) {
            if (tmp[r_now][c_now]) {
              can = false;
              break;
            }
            r_now += dr[j];
            c_now += dc[j];
          }
        }
      }
      
      if (can) cout << "ok" << endl;
      
    } while(next_permutation(col.begin(), col.end()));
  } while(next_permutation(row.begin(), row.end()));
}
