#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>

using namespace std;

struct vertex {
	string name;
	vector< pair<int, vertex *> > adj;
	vertex(string s) : name(s) {}
};

class Graph {
	map<string, vertex *> graph;
	public:
		bool is_vertex(const string &v) { return (graph.find(v) != graph.end()); }
		void add_vertex(const string &v);
		void add_edge(const string &u, const string &v, int weight);
		void bfs(const string &start);
		string longest_path(const string &);
		int longest_path(const string &name, map<string, bool> &visited, vector<string> &path, int index, map<string, int> &dis);
};

void Graph::add_vertex(const string &v) {
	if(!is_vertex(v)) {
		graph[v] = new vertex(v);
	} else {
		cout << "vertex already exists\n";
	}
	return;
}

void Graph::add_edge(const string &u, const string &v, int weight) {
	vertex *from = graph.find(u)->second;
	vertex *to = graph.find(v)->second;
	from->adj.push_back(make_pair(weight, to));
}

void Graph::bfs(const string &start) {
	list<string> queue;
	map<string, bool> visited;
	queue.push_back(start);
	visited[start] = true;

	string front;
	vector<pair<int, vertex *> >::iterator it;
	while(!queue.empty()) {
		front = queue.front();
		it = (graph[front]->adj).begin();
		queue.pop_front();
		cout << front << " ";
		while(it != (graph[front]->adj).end()) {
			if(visited.find((it)->second->name) == visited.end()) {
				//cout << ((it)->second->name) << " ";
				queue.push_back((it)->second->name);
				visited[(it)->second->name] = true;
			}
			it++;
		}
	}
	cout << endl;
}

string Graph::longest_path(const string &start) {
	map<string, bool> visited;
	vector<string> path(10);
	map<string, int> des;
	int index = 0;
	int length = 0;
	//string name = start;
	path[index] = start;
	//cout << start << " ";
	cout << "length " << longest_path(start, visited, path, index, des) << endl;
	for(int i = 0; i < 10 ; i++ ) {
		cout << path[i] << " ";
	}
	cout << endl;
	return string("");
}

int Graph::longest_path(const string &name, map<string, bool> &visited, vector<string> &path, int index, map<string, int> &des) {
	vector<pair<int, vertex *> >::iterator it_adj = graph[name]->adj.begin();
	string temp_name;
	visited[name] = true;
	while(it_adj != graph[name]->adj.end()) {
		if(visited.find(it_adj->second->name) == visited.end() || visited[it_adj->second->name] == false) {
			int current_length = it_adj->first + longest_path(it_adj->second->name, visited, path, index + 1, des);
			if(des.find(it_adj->second->name) == des.end() || current_length > des[it_adj->second->name]) {
				des[it_adj->second->name] = current_length;
				//max_length = current_length;
				//cout << it_adj->first << " "  << current_length << " " << it_adj->second->name << " index " << (index + 1) << endl;
				path[index + 1] = it_adj->second->name;
			}
		}
		it_adj++;
	}
	visited[name] = false;
	//cout << temp_name << " ";
	return des[path[index + 1]];
}

int main() {
	Graph graph;
	graph.add_vertex("A");
	graph.add_vertex("B");
	graph.add_vertex("C");
	graph.add_vertex("D");
	graph.add_vertex("E");
	graph.add_vertex("F");
	graph.add_vertex("G");
	graph.add_vertex("H");

	graph.add_edge("A", "B", 2);
	graph.add_edge("A", "C", 5);
	graph.add_edge("A", "D", 7);
	graph.add_edge("B", "D", 4);
	graph.add_edge("C", "D", 6);
	graph.add_edge("D", "E", 10);
	graph.add_edge("E", "F", 10);
	graph.add_edge("F", "G", 10);
	graph.add_edge("F", "H", 10);

	graph.bfs("A");

	graph.longest_path("A");

	return 0;
}