int K;

struct Node {
  array<long long, 5> cnt;  // pre[x] = numbers of prefixes whose product % k == x
  int prod;  // prod = product % k
  Node() : prod(1) {
      for (int i = 0; i < 5; i++) cnt[i] = 0;
  }
  Node(long long v) {
      for (int i = 0; i < 5; i++) cnt[i] = 0;
      prod = v % K;
      cnt[prod] = 1;
  }
  friend Node merge(Node l, Node r) {
      Node res;
      res.prod = l.prod * r.prod % K;
      for (int x = 0; x < K; x++) {
          res.cnt[x] += l.cnt[x];
          res.cnt[x * l.prod % K] += r.cnt[x];
      }
      return res;
  }
  void update(long long v) { *this = Node(v); }
};

struct SegmentTree {
  int n;
  vector<Node> seg;
  SegmentTree(int _n) : n(_n), seg(2 * _n) {}
  template <typename Type>
  SegmentTree(vector<Type> a) {
    n = int(a.size());
    seg.resize(2 * n);
    for (int i = 0; i < n; i++) seg[i + n] = Node(a[i]);
    for (int i = n - 1; i > 0; i--)
      seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
  }
  void update(int i, long long v) {
    for (seg[i += n].update(v); i >>= 1;)
      seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
  }
  Node query(int l, int r) {
    Node resl, resr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = merge(resl, seg[l++]);
      if (r & 1) resr = merge(seg[--r], resr);
    }
    return merge(resl, resr);
  }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        K = k;
        vector<int> ans;
        SegmentTree sg(nums);
        
        for (auto q : queries) {
            int index = q[0], value = q[1], start = q[2], rem = q[3];
            sg.update(index, value);
            auto res = sg.query(start, n - 1).cnt[rem];
            ans.push_back(res);
        }
        return ans;
    }
};