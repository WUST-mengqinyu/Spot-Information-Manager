#include "stdafx.h"
#include "UnOrderedGraph.h"

//
// Created by badcw on 2019/1/25.
//

#include "UnOrderedGraph.h"

UnOrderedGraph::UnOrderedGraph(int n, int m, std::vector<std::pair<int, int>> edges[MAXN], MessageNode node[MAXN]) :N(n), M(m) {
	clear();
	for (int i = 0; i < n; ++i) {
		Node[i] = node[i];
		Edges[i] = edges[i];
		for (int j = 0; j < n; ++j) {
			G[i][j] = INF;
		}
		G[i][i] = 0;
		for (auto j : Edges[i]) {
			G[i][j.first] = j.second;
		}
	}
}

UnOrderedGraph::UnOrderedGraph()
{
	clear();
	N = M = 0;
}

std::vector<std::pair<MessageNode, int> > UnOrderedGraph::neighbor(int u) {
	std::vector<std::pair<MessageNode, int>> res;
	for (auto i : Edges[u]) {
		res.emplace_back(Node[i.first], i.second);
	}
	return res;
}

int UnOrderedGraph::Find(int x) {
	return x == pre[x] ? x : pre[x] = Find(pre[x]);
}

void UnOrderedGraph::cal(int e) {
	res.push_back(ways);
}

void UnOrderedGraph::dfsNow(int u, int e, int pre) {
	if (u == e) {
		cal(e);
		return;
	}
	for (auto Next : Edges[u]) {
		int v = Next.first;
		if (v == pre || vis[v] || Node[v].idx == -1) continue;
		ways.push_back(v);
		vis[v] = true;
		dfsNow(v, e, u);
		ways.pop_back();
		vis[v] = false;
	}
}

std::vector<std::vector<int> > UnOrderedGraph::dfs(int s, int e) {
	for (int i = 0; i < N; ++i) vis[i] = 0;
	res.clear();
	ways.clear();
	vis[s] = true;
	ways.push_back(s);
	dfsNow(s, e);
	return res;
}

std::pair<std::vector<int>, int> UnOrderedGraph::distance(int s, int e) {
	std::pair<std::vector<int>, int> Result;
	int path[MAXN];
	for (int i = 0; i < N; ++i) {
		path[i] = -1;
		vis[i] = 0;
		dist[i] = INF;
	}
	dist[s] = 0;
	for (int i = 0; i < N; ++i) {
		int now = -1;
		for (int j = 0; j < N; ++j) {
			if (Node[j].idx == -1) continue;
			if (!vis[j] && (now == -1 || dist[j] < dist[now])) {
				now = j;
			}
		}
		if (now == -1) break;
		vis[now] = 1;
		for (auto j : Edges[now]) {
			if (!vis[j.first] && dist[now] + j.second < dist[j.first]) {
				dist[j.first] = dist[now] + j.second;
				path[j.first] = now;
			}
		}
		/*for (int j = 0; j < N; ++j) {
			if (Node[j].idx == -1) continue;
			if (!vis[j] && dist[now] + G[now][j] < dist[j]) {
				dist[j] = dist[now] + G[now][j];
				path[j] = now;
			}
		}*/
	}
	if (dist[e] >= INF) {
		Result.second = -1;
		return Result;
	}
	Result.second = dist[e];
	while (path[e] != -1) {
		Result.first.push_back(e);
		e = path[e];
	}
	Result.first.push_back(s);
	std::reverse(Result.first.begin(), Result.first.end());
	return Result;
}

std::pair<std::vector<IntEdge>, int> UnOrderedGraph::MST() {
	std::pair<std::vector<IntEdge>, int> Result;
	int dist[MAXN], closest[MAXN], now;
	int ans, root;
	for (int i = 0; i <= N; ++i) {
		if (Node[i].idx != -1) {
			root = i;
			break;
		}
	}
	for (int i = 0; i <= N; i++)
		vis[i] = 0, dist[i] = INF, closest[i] = -1;
	dist[root] = 0, closest[root] = root;
	for (int i = 0; i <= N; i++) {
		int tmp = INF;
		int k = -1;
		for (int j = 0; j <= N; j++) {
			if (!vis[j] && tmp > dist[j]) {
				tmp = dist[j];
				k = j;
			}
		}
		if (k == -1) break;
		vis[k] = 1;
		for (int j = 0; j <= N; j++) {
			if (!vis[j] && dist[j] > G[k][j])
				dist[j] = G[k][j], closest[j] = k; 
		}
	}

	std::vector<std::pair<int, int> > tmp;

	for (int i = 0; i <= N; ++i) {
		if (Node[i].idx == -1) continue;
		if (closest[i] == -1) {
			Result.first.clear();
			Result.second = -1;
			return Result;
		}
		if (i == root || std::find(tmp.begin(), tmp.end(), std::make_pair(min(i, closest[i]), max(i, closest[i]))) != tmp.end()) continue;
		Result.first.push_back(IntEdge(i, closest[i], G[i][closest[i]]));
		Result.second += G[i][closest[i]];
		tmp.push_back(std::make_pair(min(i, closest[i]), max(i, closest[i])));
	}
	memset(vis, 0, sizeof vis);
	return Result;
}

int UnOrderedGraph::insertNode(MessageNode x) {
	if (x.idx < 0 || x.idx >= MAXN || N == MAXN - 1)
		return 0;
	Node[x.idx] = x;
	N = max(N, x.idx + 1);
	for (int i = 0; i < N; ++i) {
		G[x.idx][i] = INF;
	}
	G[x.idx][x.idx] = 0;
	return 1;
}

int UnOrderedGraph::insertEdges(int u, int v, int w) {
	if (u < 0 || v < 0 || u >= MAXN || v >= MAXN || u == v || Node[u].idx == -1 || Node[v].idx == -1 || G[u][v] != INF)
		return 0;
	Edges[u].push_back(std::make_pair(v, w));
	Edges[v].push_back(std::make_pair(u, w));
	G[u][v] = w;
	G[v][u] = w;
	M++;
	return 1;
}

int UnOrderedGraph::deleteEdges(int u, int v) {
	if (u < 0 || v < 0 || u >= MAXN || v >= MAXN || u == v || Node[u].idx == -1 || Node[v].idx == -1 || G[u][v] == INF)
		return 0;
	G[u][v] = G[v][u] = INF;
	for (std::vector<std::pair<int, int> >::iterator j = Edges[u].begin(); j != Edges[u].end(); ++j) {
		if ((*j).first == v) {
			Edges[u].erase(j);
			break;
		}
	}
	for (std::vector<std::pair<int, int> >::iterator j = Edges[v].begin(); j != Edges[v].end(); ++j) {
		if ((*j).first == u) {
			Edges[v].erase(j);
			break;
		}
	}
	M--;
	return 1;
}

int UnOrderedGraph::deleteNode(int x) {
	if (x < 0 || x >= MAXN || Node[x].idx == -1)
		return 0;
	for (auto i : Edges[x]) {
		for (std::vector<std::pair<int, int> >::iterator j = Edges[i.first].begin(); j != Edges[i.first].end(); ++j) {
			if ((*j).first == x) {
				Edges[i.first].erase(j);
				break;
			}
		}
	}
	Edges[x].clear();
	Node[x] = MessageNode();
	for (int i = 0; i < N; ++i) {
		G[x][i] = G[i][x] = INF;
	}
	return 1;
}

int UnOrderedGraph::changeNode(MessageNode newNode) {
	int x = newNode.idx;
	if (x < 0 || x >= MAXN || Node[x].idx != -1)
		return 0;
	Node[x] = newNode;
	N = max(N, x + 1);
	return 1;
}

int UnOrderedGraph::changeEdges(int u, int v, int w) {
	if (u < 0 || v < 0 || u >= MAXN || v >= MAXN || u == v || Node[u].idx == -1 || Node[v].idx == -1)
		return 0;
	G[u][v] = G[v][u] = w;
	int flag = 0;
	for (int i = 0; i < Edges[u].size(); ++i) {
		if (Edges[u][i].first == v) {
			Edges[u][i].second = w;
			flag = 1;
			break;
		}
	}
	if (flag == 0) Edges[u].push_back(std::make_pair(v, w));
	flag = 0;
	for (int i = 0; i < Edges[v].size(); ++i) {
		if (Edges[v][i].first == u) {
			Edges[v][i].second = w;
			flag = 1;
			break;
		}
	}
	if (flag == 0) Edges[v].push_back(std::make_pair(u, w));
	return 1;
}

int UnOrderedGraph::getIdx(MessageNode x) {
	for (int i = 0; i <= N; ++i) {
		if (Node[i].name == x.name) return i;
	}
	return -1;
}

void UnOrderedGraph::clear()
{
	for (int i = 0; i < MAXN; ++i) {
		Edges[i].clear();
	}
	for (int i = 0; i < MAXN; ++i) {
		Node[i] = MessageNode();
	}

	for (int i = 0; i < MAXN; ++i) {
		for (int j = i + 1; j < MAXN; ++j) {
			G[i][j] = G[j][i] = INF;
		}
		G[i][i] = 0;
	}
	N = M = 0;
}

std::pair<CString, CString> UnOrderedGraph::toString()
{
	CString NodeRes, EdgeRes, tmp;
	for (int i = 0; i <= N; ++i) {
		if (Node[i].idx != -1) {
			tmp.Format("%d ", Node[i].idx);
			NodeRes += tmp;
			NodeRes += Node[i].name + TEXT(" ") + Node[i].desc + TEXT("\r\n");
			for (auto j : Edges[i]) {
				if (j.first < i) continue;
				tmp.Format(" %d\r\n", j.second);
				EdgeRes += Node[i].name + TEXT(" ") + Node[j.first].name + tmp;
			}
		}
	}
	return std::make_pair(NodeRes, EdgeRes);
}
