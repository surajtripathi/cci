#include<iostream>
#include<vector>

using namespace std;
typedef vector< vector<int> > vv;
class Graph {
	vv adjacency_list;
	int size;
	public:
	Graph(int size)	{
		this->size = size;
		this->adjacency_list = vector< vector<int> >(size, vector<int>());
	}
	void add_edge(int u, int v);
	void print();
};

int main() {
	Graph graph(5);
	graph.add_edge(1, 2);
	graph.add_edge(2, 4);
	graph.add_edge(3, 1);
	graph.add_edge(4, 5);
	graph.add_edge(4, 3);
	graph.print();
	return 0;
}
void Graph::add_edge(int u, int v) {
	adjacency_list[u-1].push_back(v-1);
	adjacency_list[v-1].push_back(u-1);
}
void Graph::print() {
	vv::iterator i;
	vector<int>::iterator j;
	int  pos = 0;
	for(i = adjacency_list.begin() ; i != adjacency_list.end() ; i++, pos++) {
		for(j = i->begin() ; j != i->end() ; j++) {
			cout << (pos + 1) << " ----> " << ((*j) + 1) << endl;
		}
	}
}