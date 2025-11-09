#include <bits/stdc++.h>
using namespace std;

constexpr long double EPS = 1e-9;

struct point {
  long double x, y;
  bool operator<(const point &rhs) const {
    if (abs(this->x - rhs.x) > EPS)
      return this->x < rhs.x;
    if (abs(this->y - rhs.y) > EPS)
      return this->y < rhs.y;
    return false;
  }
  bool operator==(const point &rhs) const {
    return (abs(this->x - rhs.x) < EPS) && (abs(this->y - rhs.y) < EPS);
  }
  friend istream &operator>>(istream &in, point &pt) {
    in >> pt.x >> pt.y;
    return in;
  }
};

struct triangle {
  array<point, 3> points;
  friend istream &operator>>(istream &in, triangle &tr) {
    for (int i = 0; i < 3; i++)
      in >> tr.points[i];
    return in;
  };
};

long double dist_sq(const point &p1, const point &p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

long double cross_product(const point &p0, const point &p1, const point &p2) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

bool on_segment(const point &p, const point &p1, const point &p2) {
  if (abs(cross_product(p1, p2, p)) > EPS)
    return false;

  return p.x >= min(p1.x, p2.x) - EPS && p.x <= max(p1.x, p2.x) + EPS &&
         p.y >= min(p1.y, p2.y) - EPS && p.y <= max(p1.y, p2.y) + EPS;
}

bool segment_intersection(const point &a, const point &b, const point &c,
                          const point &d, point &result) {
  long double a1 = cross_product(a, b, c);
  long double a2 = cross_product(a, b, d);

  if (a == c || a == d || b == c || b == d)
    return false;

  if ((a1 * a2 < -EPS)) {
    long double a3 = cross_product(c, d, a);
    long double a4 = cross_product(c, d, b);

    if (a3 * a4 < -EPS) {
      long double det = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);

      long double t =
          ((c.x - a.x) * (d.y - c.y) - (c.y - a.y) * (d.x - c.x)) / det;

      result.x = a.x + t * (b.x - a.x);
      result.y = a.y + t * (b.y - a.y);

      return t > EPS && t < 1.0L - EPS;
    }
  }
  return false;
}

struct dsu {
  vector<int> v;
  dsu(int n) : v(n, -1) {}
  int find(int a) { return (v[a] < 0 ? a : v[a] = find(v[a])); }
  void unify(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return;
    if (v[a] > v[b])
      swap(a, b);
    v[a] += v[b];
    v[b] = a;
  }
  int cnt() {
    int ret = 0;
    for (auto &x : v)
      if (x < 0)
        ret++;
    return ret;
  }
};

map<point, int> point_to_id;
vector<point> id_to_point;
int next_id = 0;

int get_id(const point &p) {
  if (point_to_id.count(p)) {
    return point_to_id[p];
  }
  int id = next_id++;
  point_to_id[p] = id;
  id_to_point.push_back(p);
  return id;
}

bool segment_intersect2(const point &a, const point &b, const point &c,
                        const point &d) {
  long double cp1 = cross_product(a, b, c);
  long double cp2 = cross_product(a, b, d);
  long double cp3 = cross_product(c, d, a);
  long double cp4 = cross_product(c, d, b);

  if ((cp1 * cp2 < -EPS) && (cp3 * cp4 < -EPS))
    return true;

  if (abs(cp1) < EPS && on_segment(c, a, b))
    return true;
  if (abs(cp2) < EPS && on_segment(d, a, b))
    return true;
  if (abs(cp3) < EPS && on_segment(a, c, d))
    return true;
  if (abs(cp4) < EPS && on_segment(b, c, d))
    return true;

  return false;
}

bool triangles_intersect(const triangle &t1, const triangle &t2) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (segment_intersect2(t1.points[i], t1.points[(i + 1) % 3], t2.points[j],
                             t2.points[(j + 1) % 3]))
        return true;
    }
  return false;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<triangle> a(n);
  for (auto &x : a)
    cin >> x;

  dsu d(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (triangles_intersect(a[i], a[j])) {
        d.unify(i, j);
      }
    }
  }

  vector<pair<point, point>> segments;

  for (const auto &tr : a) {
    for (int i = 0; i < 3; ++i) {
      point p1 = tr.points[i];
      point p2 = tr.points[(i + 1) % 3];

      get_id(p1);

      if (p2 < p1)
        swap(p1, p2);
      segments.push_back({p1, p2});
    }
  }

  set<point> intersection_points;
  int num_segments = segments.size();

  for (int i = 0; i < num_segments; ++i) {
    for (int j = i + 1; j < num_segments; ++j) {
      point intersection;
      if (segment_intersection(segments[i].first, segments[i].second,
                               segments[j].first, segments[j].second,
                               intersection)) {
        intersection_points.insert(intersection);
      }
    }
  }

  sort(segments.begin(), segments.end());

  for (const auto &p : intersection_points) {
    get_id(p);
  }

  long long total_vertices = next_id;
  long long total_edges = 0;

  for (const auto &seg : segments) {
    const point &p_start = seg.first;
    const point &p_end = seg.second;

    vector<int> segment_vertex_ids;

    for (int id = 0; id < next_id; ++id) {
      const point &p = id_to_point[id];

      if (on_segment(p, p_start, p_end)) {
        segment_vertex_ids.push_back(id);
      }
    }

    sort(segment_vertex_ids.begin(), segment_vertex_ids.end(),
         [&](int id1, int id2) {
           const point &p1 = id_to_point[id1];
           const point &p2 = id_to_point[id2];
           return dist_sq(p_start, p1) < dist_sq(p_start, p2);
         });

    segment_vertex_ids.erase(
        unique(segment_vertex_ids.begin(), segment_vertex_ids.end()),
        segment_vertex_ids.end());

    total_edges += (segment_vertex_ids.size() - 1);
  }
  cout << total_edges - total_vertices + d.cnt() << '\n';
}
