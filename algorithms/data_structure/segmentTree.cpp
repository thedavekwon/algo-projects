#include <vector>

using namespace std;

typedef long long ll;
//a: numbers
//tree: segment tree
//node: node number in segment tree
//start~end: range of sum responsible for node
ll build(vector<ll> &a, vector<ll> &tree, int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = a[start];
    }
    else
    
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) +
                            init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
    }
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
    if (index < start || index > end)
        return;
    tree[node] = tree[node] + diff;
    if (start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

//NlgN solution for updating range
void update_range(vector<ll> &tree, int node, int start, int end, int left, int right, ll diff)
{
    if (left > end || right < end)
        return;
    if (start == end)
    {
        tree[node] = tree[node] + diff;
        return;
    }
    update_range(tree, node * 2, start, (start + end) / 2, left, right, diff);
    update_range(tree, node * 2 + 1, start, (start + end) / 2 + 1, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

//start~end: range of sum responsible for node
//left+right: range of sum to find
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    return sum(tree, node * 2, start, (start + end) / 2, left, right) +
           sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

//need to change init function to use find_min function
ll find_min(vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return INF;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    return min(find_min(tree, node * 2, start, (start + end) / 2, left, right),
               find_min(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

// from cp-algorithms
const MAXN;
int n, t[4 * MAXN];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] == a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(v * 2, tl, tm, pos, new_val);
        }
        else
        {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

// counting the number of zeros, searching for the k-th zero
// t stores the number of zeros in each segment in t[]
int find_kth(int v, int tl, int tr, int k)
{
    if (k > t[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (t[v * 2] >= k)
        return find_kth(v * 2, tl, tm, k);
    else
        return find_kth(v * 2 + 1, tm + 1, tr, k - t[v * 2]);
}

// finding the maximum and the number of times it appears

const MAXN;
pair<int, int> t[4 * MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = make_pair(a[tl], 1);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v * 2, tl, tm, l, min(r, tm)),
                   get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = make_pair(new_val, 1);
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(v * 2, tl, tm, pos, new_val);
        }
        else
        {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

// get_max
// v start with 1 not zero
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.size() == 0)
        return vector<int>();
    vector<int> ret;
    t.resize(4 * nums.size());
    build(nums, t, 1, 0, nums.size() - 1);
    for (int i = 0; i <= nums.size() - k; i++)
    {
        int tmp = get_max(t, 1, i, i + k - 1, 0, nums.size() - 1);
        ret.push_back(tmp);
    }
    return ret;
}

void build(vector<int> &nums, vector<int> &t, int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = nums[tl];
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(nums, t, v * 2, tl, tm);
        build(nums, t, v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int get_max(vector<int> &t, int v, int tl, int tr, int l, int r)
{
    if (tl > r || tr < l)
        return -987654321;
    if (l >= tl && r <= tr)
        return t[v];
    int m = (l + r) >> 1;
    return max(get_max(t, v * 2, tl, tr, l, m), get_max(t, v * 2 + 1, tl, tr, m + 1, r));
}

// find the smallest number greater or equal to a specified number
// (l, r, x) find the minimal number in the segment a[l...r] which is greater than or equal to x
// Merger Sort Tree

const MAXN;
vector<int> t[4 * MAXN];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = vector<int>(1, a[tl]);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        merge(t[v * 2].begin(), t[v * 2].end(),
              t[v * 2 + 1].begin(), t[v * 2 + 1].end(),
              back_inserter(t[v]));
    }
}

int query(int v, int tl, int tr, int l, int r, int x)
{
    if (l > r)
    {
        return INF;
    }
    if (l == tl && r == tr)
    {
        vector<int>::iterator pos = lower_bound(t[v].begin(), t[v].end(), x);
        if (pos != t[v].end())
            return *pos;
        return INF;
    }
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(r, tm), x),
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x));
}

// Simple 2D Segment Tree
void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
{
    if (ly == ry)
    {
        if (lx == rx)
        {
            t[vx][vy] = a[lx][ly];
        }
        else
        {
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
        }
    }
    else
    {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
    }
}

void build_x(int vx, int lx, int rx)
{
    if (lx != rx)
    {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx);
        build_x(vx * 2 + 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m - 1);
}

int sum_y(int vx, int vy, int tly, int try, int ly, int ry)
{
    if (ly > ry)
        return 0;
    if (ly == tly && try == ry)
        return t[vx][vy];
    int tmy = (tly + try) / 2;
    return sum_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)) +
           sum_y(vx, vy * 2 + 1, tmy + 1, try, max(ly, tmy + 1), ry);
}

int sum_x(int vx, int vy, int tlx, int trx, int lx, int rx)
{
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return t[vx][vy];
    int tmx = (tlx + trx) / 2;
    return sum_x(vx * 2, vy, tlx, tmx, lx, min(rx, tmx)) +
           sum_x(vx * 2 + 1, vy, tmx + 1, trx, max(lx, tmx + 1), rx);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val)
{
    if (ly == ry)
    {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
    }
    else
    {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy * 2, ly, my, x, y, my_val);
        else
            update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy * 2] + t[vx * 2 + 1][vy];
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val)
{
    int mx = (lx + rx) / 2;
    if (lx != rx)
    {
        if (x <= mx)
            update_x(vx * 2, lx, mx, x, y, new_val);
        else
            update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, mx - 1, x, y, new_val);
}