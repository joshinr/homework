#include <iostream>
#include <vector>
#include <list>

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

        std::list<int> queue;
        queue.push_back(vertex);

        while(!queue.empty())
        {
            int tmp = queue.front();
            queue.pop_front();

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

    void DFS_Traverse(int vertex, std::vector<bool> &visited)
    {
        std::cout<<vertex<<", ";

        visited[vertex] = true;
        for(auto &it : list_[vertex])
        {
            if (visited[it] == false)
            {
                DFS_Traverse(it, visited);
            }
        }
    }

    void DFS(int vertex)
    {
        std::vector<bool> visited;
        for (int i=0; i < v_; ++i)
        {
            visited.push_back(false);
        }

        DFS_Traverse(vertex, visited); 
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

    std::cout << std::endl << "BFS" << std::endl;
    g.BFS(2);
    std::cout << std::endl << "DFS" << std::endl;
    g.DFS(2);
    std::cout << std::endl; 
    return 0;
}
