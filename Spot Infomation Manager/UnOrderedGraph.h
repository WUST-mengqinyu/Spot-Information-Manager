#pragma once
//
// Created by badcw on 2019/1/25.
//

#ifndef DATASTRUCTUREGUI_UNORDEREDGRAPH_H
#define DATASTRUCTUREGUI_UNORDEREDGRAPH_H

#include <vector>
#include <tuple>
#include <algorithm>
#include "MessageNode.h"
#include "IntEdge.h"
#define MAXN 100
#define INF 0x3f3f3f3f

class UnOrderedGraph {
private:
	int pre[MAXN];
	int Find(int x);
public:
	// N Messages
	MessageNode Node[MAXN];

	// M edges by adjacency list
	std::vector<std::pair<int, int> > Edges[MAXN];
	// M edges by adjacency matrix
	int G[MAXN][MAXN];
	bool vis[MAXN];
	// dijkstra
	int dist[MAXN];
	std::vector<std::vector<int> > res;
	std::vector<int> ways;

	void cal(int e);
	void cal2();
	void dfsNow(int u, int e, int pre = -1);
	void dfsNow2(int u, int hasgone = 1, int pre = -1);
	// N is ths node's number, m is the edge's number
	int N, M;
	UnOrderedGraph(int n, int m, std::vector<std::pair<int, int> > edges[MAXN], MessageNode node[MAXN]);
	UnOrderedGraph();
	// first is the place info and second is the path's length
	std::vector<std::pair<MessageNode, int> > neighbor(int u);
	std::vector<std::vector<int> > dfs(int s, int e);
	std::vector<std::vector<int> > dfs2(int s);
	// first is the path, second is the min distance
	std::pair<std::vector<int>, int> distance(int s, int e);
	// first is the path, second is the min distance
	std::pair<std::vector<IntEdge>, int> MST();
	// int to tell whether it's correct: 1 means success, 0 means not
	int insertNode(MessageNode x);
	int insertEdges(int u, int v, int w);
	int deleteEdges(int u, int v);
	int deleteNode(int x);
	int changeNode(MessageNode newNode);
	int changeEdges(int u, int v, int w);
	// get index of a message, -1 means fail
	int getIdx(MessageNode x);
	void clear();
	// to String
	std::pair<CString, CString> toString();
};


#endif //DATASTRUCTUREGUI_UNORDEREDGRAPH_H
