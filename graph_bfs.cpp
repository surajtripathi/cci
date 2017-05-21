#include<iostream>
#include<vector>
#include<list>

using namespace std;

typedef vector<vector<int> > vv;

class Graph {
	int size;
	vv graph;
	public:
	Graph(int size) {
		this->size = size;
		this->graph = vv(size, vector<int>());
	}
	int get_size() { return this->size; }
	void add_edge(int u, int v) {
		graph[u - 1].push_back(v - 1);
		return;
	}

	void bfs_traversal(int start) {
		list<int> queue;
		vector<bool> visited(get_size(), false);
		visited[start - 1] = true;
		queue.push_back(start - 1);
		int front;
		vector<int>::iterator it;
		while(!queue.empty()) {
			front = queue.front();
			queue.pop_front();
			cout << (front + 1) << " ";
			it = graph[front].begin();
			while(it != graph[front].end()) {
				if(!visited[*it]) {
					visited[*it] = true;
					queue.push_back(*it);
				}
				it++;
			}
		}
		cout << "\n";
	}

	void dfs_traversal(int start) {
		vector<bool> visited(get_size(), false);
		visited[start - 1] = true;
		dfs(start - 1, visited);
		cout << "\n";
	}
	void dfs(int vertex, vector<bool> &visited) {
		if(!graph[vertex].empty()) {
			cout << (vertex + 1) << " ";
			vector<int>::iterator it = graph[vertex].begin();
			while(it != graph[vertex].end()) {
				if(!visited[*it]) {
					visited[*it] = true;
					dfs(*it, visited);
				}
				it++;
			}
		}
	}
};
int main() {
	Graph graph(5);
	graph.add_edge(1, 2);
	graph.add_edge(1, 3);
	graph.add_edge(3, 1);
	graph.add_edge(3, 4);
	graph.add_edge(2, 3);
	graph.add_edge(4, 4);

	graph.bfs_traversal(3);
	graph.dfs_traversal(3);
	return 0;
}