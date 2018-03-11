
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<int> *adjList;
        
public:
    Graph(int n)
    {
        vertices = n;
        adjList = new vector<int>[vertices];
    }
   
    ~Graph()
    {
        delete []adjList;
        adjList = nullptr;
	} 

    int addEdge(int vertex, int edge)
    {
        if (vertex < vertices)
        {
            adjList[vertex].push_back(edge);
            return 0;
        }
        return -1;
    }
    
    void BreadthFirstSearch(int vertex)
    {
        std::vector<bool> visited(vertices, false);
        
        std::queue<int> queue;
        queue.push(vertex);
        
        while(!queue.empty())
        {
            int tmp = queue.front();
            queue.pop();
            
            visited[tmp] = true;
            std::cout<<tmp<<" ";
            
            const vector<int> &lst = adjList[tmp];
            for(auto &it : lst)
            {
                if (visited[it] == false)
                {
                    queue.push(it);
                }
            }
        }
    }
    
    void DepthFirstTraversal(int vertex)
    {
        std::vector<bool> visited(vertices, false);
        dfs(vertex, visited);
    }
    
    void dfs(int vertex, std::vector<bool> &visited)
    {
        std::cout<<vertex<<" ";
        visited[vertex] = true;
        
        const vector<int> &lst = adjList[vertex];
        for(auto &it : adjList[vertex])
        {
            if (visited[it] == false)
            {
                dfs(it, visited);
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
    
    g.BreadthFirstSearch(2);
    cout<<endl;
    g.DepthFirstTraversal(2);
	return 0;
}
