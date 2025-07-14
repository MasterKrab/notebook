#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;

template <typename T> void erase(ordered_multiset<T> &values, T value) {
  int rank = values.order_of_key(value);
  auto it = values.find_by_order(rank);
  values.erase(it);
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define gcd __gcd

#if defined(__LP64__) || defined(_WIN64)
using int128 = __int128;
using uint128 = __uint128_t;
#else
using int128 = ll;
using uint128 = ull;
#endif

template <typename T>
typename enable_if<is_same<T, int128>::value || is_same<T, uint128>::value,
                   istream &>::type
operator>>(istream &is, T &value) {
  string input;
  is >> input;

  value = 0;

  for (char character : input)
    if (isdigit(character))
      value = 10 * value + character - '0';

  if (input[0] == '-')
    value *= -1;

  return is;
}

template <typename T>
typename enable_if<is_same<T, int128>::value || is_same<T, uint128>::value,
                   ostream &>::type
operator<<(ostream &os, T value) {
  string output;

  bool isNegative = value < 0;

  if (isNegative) {
    value *= -1;
    output += '-';
  }

  do {
    output += value % 10 + '0';
    value /= 10;
  } while (value > 0);

  reverse(output.begin() + isNegative, output.end());

  return os << output;
}

template <typename T>
typename enable_if<is_integral<T>::value, T>::type lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

const ll MOD = 1e9 + 7;
const ll FFT_MOD = 119 << 23 | 1;
const ld PI = acos(-1);

void solve() {}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);

  int t = 1;
  //   cin >> t;

  while (t--)
    solve();
}
