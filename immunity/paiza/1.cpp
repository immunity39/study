#include <bits/stdc++.h>

//{ START
using namespace std;
#define int int64_t
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define reps(i, a, n) for (int i = (n - 1); i > (a - 1); --i)
#define arep(i, x) for (auto &&i : (x))
#define irep(i, x) for (auto i = (x).begin(); i != (x).end(); ++i)
#define rirep(i, x) for (auto i = (x).rbegin(); i != (x).rend(); ++i)
// 降順はgreater<T>()
#define all(x) (x).begin(), (x).end()
#define rv(s) reverse((s).begin(), (s).end())
// gcd lcmはそのままok
#define gcd(a, b) __gcd(a, b)
#define bits(n) (1LL << (n))
#define pcnt(x) __builtin_popcntll(x)
// 配列内等要素削除
#define Unique(x) (x).erase(unique((x).begin(), (x).end()), (x).end())
#define Fixed(n) fixed << setprecision(n)
// 総和
#define sowa(n) (((n) * ((n) + 1)) / 2)
#define updiv(a, b) ((a + b - 1) / b)
#define cauto const auto &
using P = pair<int, int>;
using Graph = vector<vector<P>>;
template <class T>  // 昇順
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>  // 降順
using max_heap = priority_queue<T>;
template <class A, class B>
using umap = unordered_map<A, B>;
template <class A>
using uset = unordered_set<A>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {  // 多次元初期化
  std::fill((T *)array, (T *)(array + N), val);
}
template <class A, class B>
bool chmax(A &a, const B &b) {  // 最大値更新 返り値はbool
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class A, class B>
bool chmin(A &a, const B &b) {  // 最小値更新 返り値はbool
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, 1, -1, -1};
constexpr int INF = 0x3f3f3f3f;
constexpr int LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9 + 7;
constexpr int mod2 = 998244353;
//} END

signed main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;

  vector<string> str(h);
  rep(i, 0, h) cin >> str[i];

  vector<int> vec(w, 0);
  int ans = 0;

  rep(i, 0, h) {
    rep(j, 0, w) {
      if (str[i][j] == '#') {
        vec[j] = 0;
      } else {
        vec[j]++;
      }
    }

    stack<int> st;
    rep(j, 0, w + 1) {
      while (!st.empty() && (j == w || vec[st.top()] >= vec[j])) {
        int now_h = st.top();
        st.pop();

        int now_w;
        if (st.empty())
          now_w = -1;
        else
          now_w = st.top();

        int siz = (j - now_w - 1) * vec[now_h];
        chmax(ans, siz);
      }
      st.push(j);
    }
  }

  cout << ans << '\n';
  return 0;
}