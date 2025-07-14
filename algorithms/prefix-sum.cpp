template <typename T> struct PrefixSum {
  static_assert(is_arithmetic<T>::value);

  vector<T> prefix;

  PrefixSum(vector<T> &values) {
    int n = values.size();
    prefix.resize(n);

    prefix[0] = values[0];

    for (int i = 1; i < n; i++)
      prefix[i] = prefix[i - 1] + values[i];
  }

  T query(int left, int right) // [left, right]
  {
    return prefix[right] - (left > 0 ? prefix[left - 1] : 0);
  }
};