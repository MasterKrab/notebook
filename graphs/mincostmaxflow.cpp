template <class Flow, class Cost> struct MinCostMaxFlow {
  struct Edge {
    int from, to;
    Flow capacity;
    Cost cost;
    Flow flow = 0;
  };

  int n, source, sink;
  vector<vector<int>> graph;
  vector<Edge> edges;
  vector<ll> distance, potential;
  vector<int> parent;

  MinCostMaxFlow() {}
  MinCostMaxFlow(int n, int source, int sink)
      : n(n), source(source), sink(sink), graph(n) {}

  void addEdge(int from, int to, Flow capacity, Cost cost) {
    graph[from].push_back(edges.size());
    edges.push_back({from, to, capacity, cost});

    graph[to].push_back(edges.size());
    edges.push_back({to, from, 0, -cost});
  }

  void calculateDistances() {
    if (potential.empty()) {
      potential.assign(n, 0);

      for (int i = 0; i < n - 1; ++i)
        for (Edge &edge : edges) {
          if (edge.flow >= edge.capacity)
            continue;

          potential[edge.to] =
              min(potential[edge.to], potential[edge.from] + edge.cost);
        }
    }

    parent.assign(n, -1);
    distance.assign(n, numeric_limits<Cost>::max());

    distance[source] = 0;

    priority_queue<pair<Cost, int>> pq;

    pq.push({0, source});

    while (!pq.empty()) {
      auto [current, node] = pq.top();
      pq.pop();

      if (distance[node] < -current + potential[node])
        continue;

      for (int index : graph[node]) {
        Edge &edge = edges[index];

        Cost newDistance = distance[node] + edge.cost;

        if (edge.flow >= edge.capacity || newDistance >= distance[edge.to])
          continue;

        distance[edge.to] = newDistance;
        parent[edge.to] = index;
        pq.push({potential[edge.to] - newDistance, edge.to});
      }
    }

    potential = distance;
  }

  Flow calculateMaxFlow() {
    potential.clear();

    Flow total = 0;

    while (true) {
      calculateDistances();

      if (parent[sink] == -1)
        break;

      Flow pathFlow = numeric_limits<Flow>::max();

      for (int node = sink; parent[node] != -1; node = edges[parent[node]].from)
        pathFlow = min(pathFlow,
                       edges[parent[node]].capacity - edges[parent[node]].flow);

      for (int node = sink; parent[node] != -1;
           node = edges[parent[node]].from) {
        edges[parent[node]].flow += pathFlow;
        edges[parent[node] ^ 1].flow -= pathFlow;
      }

      total += pathFlow;
    }

    return total;
  }

  pair<Flow, vector<vector<int>>> searchMaxFlowPaths() {
    Flow maxFlow = calculateMaxFlow();
    vector<vector<int>> paths;

    while (true) {
      vector<int> path;
      int current = source;
      path.push_back(current);

      while (current != sink) {
        bool found = false;

        for (int index : graph[current]) {
          Edge &edge = edges[index];

          if (edge.flow == 0)
            continue;

          edge.flow -= 1;
          edges[index ^ 1].flow += 1;
          current = edge.to;
          path.push_back(current);
          found = true;
          break;
        }

        if (!found)
          break;
      }

      if (path.back() != sink)
        break;

      paths.push_back(path);
    }

    return {maxFlow, paths};
  }

  pair<Flow, vector<pii>> searchMinCutEdges() {
    Flow maxFlow = calculateMaxFlow();

    vector<bool> visited(n);

    function<void(int)> dfs = [&](int u) {
      visited[u] = true;

      for (int index : graph[u]) {
        Edge &edge = edges[index];

        if (visited[edge.to] || edge.flow == edge.capacity)
          continue;

        dfs(edge.to);
      }
    };

    dfs(source);

    vector<pii> minCutEdges;

    for (Edge &edge : edges) {
      if (edge.capacity == 0 || edge.flow != edge.capacity)
        continue;

      if (visited[edge.from] && !visited[edge.to])
        minCutEdges.emplace_back(edge.from, edge.to);
    }

    return {maxFlow, minCutEdges};
  };
};