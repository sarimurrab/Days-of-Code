#include "bits/stdc++.h"
using namespace std;

// v = number of vertex
class graph
{
    int v;
    list<int> *l;

public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void add_edges(int s, int d)
    {
        l[s].push_back(d);
        l[d].push_back(s);
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "--> ";
            for (auto x : l[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void sssp_bfs(int src)
    {
        map<int, int> distances;
        for (int i = 0; i < v; i++)
        {
            distances[i] = INT_MAX;
        }

        queue<int> q;
        q.push(src);
        distances[src] = 0;

        while (!q.empty())
        {
            int save = q.front();
            q.pop();

            for (auto nbr : l[save])
            {
                if(distances[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    distances[nbr]=distances[save] +1;
                }
            }
        }



        // Printing the distances
        for(auto p:distances)
        {
            cout<<"From "<<src<<" to "<<p.first<<" SSSP distance is "<<p.second<<endl;
        }
    }
};

int main()
{

    graph g(6);
    g.add_edges(0, 1);
    g.add_edges(0, 3);
    g.add_edges(2, 3);
    g.add_edges(1, 2);
    g.add_edges(3, 4);
    g.add_edges(4, 5);

    g.sssp_bfs(0);
}
