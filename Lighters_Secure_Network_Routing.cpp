#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 100005;
struct Edge {
  int to;
  ll weight;
};
vector<Edge> adj[MAXN];
int disc[MAXN], low[MAXN], timer;
vector<tuple<int, int, ll>> bridges;
int bcc_id[MAXN];
int bcc_cnt = 0;
vector<int> bcc_nd[MAXN];
struct bcc {
  int id = -1;
  int endpoint_in = -1;
  int endpoint_out = -1;
  ll bridge_weight_out = 0;
};
vector<bcc> bcc_chn;
ll dist_ep[MAXN][2];
vector<ll> cumuldist;
int N, M, Q;
void dfs_bridge(int u, int p) {
  disc[u] = low[u] = ++timer;
  for (const auto &edge : adj[u]) {
    int v = edge.to;
    if (v == p)
      continue;
    if (disc[v]) {
      low[u] = min(low[u], disc[v]);
    } else {
      dfs_bridge(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > disc[u]) {
        bridges.emplace_back(u, v, edge.weight);
      }
    }
  }
}
void dfs_group_bcc(int u, int cur_bcc) {
  bcc_id[u] = cur_bcc;
  bcc_nd[cur_bcc].push_back(u);
  for (const auto &edge : adj[u]) {
    int v = edge.to;
    bool is_b = false;
    for (const auto &bridge : bridges) {
      int b1 = get<0>(bridge);
      int b2 = get<1>(bridge);
      if ((u == b1 && v == b2) || (u == b2 && v == b1)) {
        is_b = true;
        break;
      }
    }
    if (!is_b && bcc_id[v] == 0) {
      dfs_group_bcc(v, cur_bcc);
    }
  }
}
void group_bccs() {
  timer = 0;
  for (int i = 1; i <= N; ++i) {
    if (disc[i] == 0) {
      dfs_bridge(i, 0);
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (bcc_id[i] == 0) {
      bcc_cnt++;
      dfs_group_bcc(i, bcc_cnt);
    }
  }
}
map<int, ll> dijkstra_bcc(int start_node, int bcc_id_k) {
  map<int, ll> curdist;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;

  for (int node : bcc_nd[bcc_id_k]) {
    curdist[node] = INF;
  }

  curdist[start_node] = 0;
  pq.push({0, start_node});

  while (!pq.empty()) {
    ll d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (d > curdist[u])
      continue;
    for (const auto &edge : adj[u]) {
      int v = edge.to;
      if (bcc_id[v] == bcc_id_k) {
        ll new_d = d + edge.weight;
        if (new_d < curdist[v]) {
          curdist[v] = new_d;
          pq.push({new_d, v});
        }
      }
    }
  }
  return curdist;
}
void f() {
  map<int, vector<pair<int, ll>>> bcc_adj;

  for (const auto &bridge : bridges) {
    int u = get<0>(bridge);
    int v = get<1>(bridge);
    ll w = get<2>(bridge);

    int id_u = bcc_id[u];
    int id_v = bcc_id[v];

    if (id_u != id_v) {
      bcc_adj[id_u].push_back({id_v, w});
      bcc_adj[id_v].push_back({id_u, w});
    }
  }
  int start_bcc_id = -1;
  for (int i = 1; i <= bcc_cnt; ++i) {
    if (bcc_adj[i].size() <= 1) {
      start_bcc_id = i;
      break;
    }
  }
  if (start_bcc_id == -1 && bcc_cnt > 0)
    start_bcc_id = 1;
  int cur_bcc = start_bcc_id;
  int prev_bcc = -1;
  for (int i = 0; i < bcc_cnt && cur_bcc != -1; ++i) {
    bcc new_bcc;
    new_bcc.id = cur_bcc;
    int next_bcc = -1;
    for (const auto &conn : bcc_adj[cur_bcc]) {
      int neighbor_bcc = conn.first;
      ll bridge_w = conn.second;
      int u_node = -1, v_node = -1;
      for (const auto &bridge : bridges) {
        int bu = get<0>(bridge);
        int bv = get<1>(bridge);
        if ((bcc_id[bu] == cur_bcc && bcc_id[bv] == neighbor_bcc) ||
            (bcc_id[bv] == cur_bcc && bcc_id[bu] == neighbor_bcc)) {
          u_node = bu;
          v_node = bv;
          break;
        }
      }
      if (neighbor_bcc != prev_bcc) {
        new_bcc.bridge_weight_out = bridge_w;
        new_bcc.endpoint_out = (bcc_id[u_node] == cur_bcc) ? u_node : v_node;
        next_bcc = neighbor_bcc;
      } else {
        new_bcc.endpoint_in = (bcc_id[u_node] == cur_bcc) ? u_node : v_node;
      }
    }
    bcc_chn.push_back(new_bcc);
    prev_bcc = cur_bcc;
    cur_bcc = next_bcc;
  }
  for (size_t i = 0; i < bcc_chn.size(); ++i) {
    const auto &current_c = bcc_chn[i];
    int bcc_k_id = current_c.id;
    if (current_c.endpoint_in != -1) {
      map<int, ll> d_in = dijkstra_bcc(current_c.endpoint_in, bcc_k_id);
      for (int node : bcc_nd[bcc_k_id]) {
        dist_ep[node][0] = d_in[node];
      }
    } else {
      for (int node : bcc_nd[bcc_k_id])
        dist_ep[node][0] = INF;
    }

    if (current_c.endpoint_out != -1) {
      map<int, ll> d_out = dijkstra_bcc(current_c.endpoint_out, bcc_k_id);
      for (int node : bcc_nd[bcc_k_id]) {
        dist_ep[node][1] = d_out[node];
      }
    } else {
      for (int node : bcc_nd[bcc_k_id])
        dist_ep[node][1] = INF;
    }
  }
  cumuldist.assign(bcc_chn.size() + 1, 0);
  for (size_t i = 0; i < bcc_chn.size(); ++i) {
    int k = i + 1;
    if (i < bcc_chn.size() - 1) {
      const auto &current_c = bcc_chn[i];
      const auto &next_c = bcc_chn[i + 1];
      int ent_next_bcc = next_c.endpoint_in;
      ll dist_nxt_bcc = 0;
      if (next_c.endpoint_out != -1) {
        dist_nxt_bcc = dist_ep[ent_next_bcc][1];
      }
      ll segment_dist = current_c.bridge_weight_out + dist_nxt_bcc;
      cumuldist[k + 1] = cumuldist[k] + segment_dist;
    }
  }
}
ll solve_query(int a, int b) {
  int id_a = bcc_id[a];
  int id_b = bcc_id[b];
  int idx_a = -1, idx_b = -1;
  for (size_t i = 0; i < bcc_chn.size(); ++i) {
    if (bcc_chn[i].id == id_a)
      idx_a = i + 1;
    if (bcc_chn[i].id == id_b)
      idx_b = i + 1;
  }
  if (idx_a > idx_b) {
    swap(a, b);
    swap(idx_a, idx_b);
  }
  ll disttoex = dist_ep[a][1];
  ll dist_inter = cumuldist[idx_b - 1] - cumuldist[idx_a];
  ll br_out = 0;
  if (idx_b >= 2) {
    const auto &c_prev = bcc_chn[idx_b - 2];
    br_out = c_prev.bridge_weight_out;
  }
  ll disttoent = dist_ep[b][0];
  return disttoex + dist_inter + br_out + disttoent;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u, v;
    ll w;
    if (!(cin >> u >> v >> w))
      return 0;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  group_bccs();
  f();
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int u, v;
    if (!(cin >> u >> v))
      return 0;
    ll result = solve_query(u, v);
    cout << result << "\n";
  }
}
