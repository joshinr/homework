#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    private:
        int v_;
        std::vector<int> *list_;
        
    public:
    Graph(int vertices)
    {
        v_ = vertices;
	list_ = new std::vector<int>[v_];
    }
   
    ~Graph()
    {
	if (list_)
	{
		delete []list_;
	}
    } 

    int addEdge(int vertex, int edge)
    {
        if (vertex < v_)
        {
            list_[vertex].push_back(edge);
            return 0;
        }
        return -1;
    }
    
    void BFS(int vertex)
    {
        std::vector<bool> visited;
        for ( int i=0; i< v_; ++i )
        {
            visited.push_back(false);
        }
        
        std::vector<int> queue;
        queue.push_back(vertex);
        
        while(!queue.empty())
        {
            int tmp = queue.back();
            queue.pop_back();
            
            visited[tmp] = true;
            std::cout<<tmp<<",";
            
            for(auto &it : list_[tmp])
            {
                if (visited[it] == false)
                {
                    queue.push_back(it);
                }
            }
        }
    }
};

int main() {
	//code
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.BFS(2);
	return 0;
}
