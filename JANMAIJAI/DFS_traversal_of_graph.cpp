#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
int V;
list <int> *l;
};

Graph* creategraph(int x){
  Graph* g = new Graph;
  g->V = x;
  g->l = new list<int>[g->V];
  return g;
}

void addEdge(Graph*g,int src,int dest){
  g->l[src].push_back(dest);
}

void DFStrav(Graph* g,int st,bool visited[]){
  list<int>::iterator it;

  visited[st] = true;
  cout<<st<<" ";
  for(it = g->l[st].begin();it!=g->l[st].end();++it){
    if(!visited[*it]){
      DFStrav(g,*it,visited);
    }   
  }
}

void DFS(Graph* g,int st){
  
  bool *visited = new bool[g->V];
  for(int i=0;i<g->V;i++){
    visited[i] = false;
  }
  
  DFStrav(g,st,visited);
}


int main(){
  int V=4;
  Graph* g = creategraph(V);
  addEdge(g,0, 1); 
  addEdge(g,0, 2); 
  addEdge(g,1, 2); 
  addEdge(g,2, 0); 
  addEdge(g,2, 3);
  int st;
  cin>>st; 
  DFS(g,st);
}
