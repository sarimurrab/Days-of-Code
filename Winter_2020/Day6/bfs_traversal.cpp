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


    void bfs()
    {
        map<int,bool> visited;
        queue<int> q;

        q.push(0);
        visited.insert({0,true});

        while(!q.empty())
        {
            int save = q.front();
            cout<<save<<" ";
            q.pop();

            for (auto nbr : l[save])
            {
                if(visited[nbr]==false)
                {
                    q.push(nbr);
                    visited[nbr]= true;
                }
            }
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

    g.bfs();
}
