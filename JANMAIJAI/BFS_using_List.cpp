#include <bits/stdc++.h>
using namespace std;

class Graph{
  public:
  int V;
  list<int>*lis;
};

Graph* creategraph(int x){
  Graph* gr = new Graph;
  gr->V = x;
  gr->lis = new list<int>[x];
  return gr;
}

void addEdge(Graph* g,int src,int dest){
  g->lis[src].push_back(dest);
}

void BFS(Graph* g,int st){
  list <int> q;

  bool *visited = new bool[g->V];
  for(int i=0;i<(g->V);i++){
    visited[i] = false;
  }
  
  q.push_back(st);
  visited[st] = true;
  list<int>::iterator it;
  while(!q.empty()){    
    int a = q.front();
    cout<<a<<" ";
    q.pop_front();    
    for(it = g->lis[a].begin();it!=g->lis[a].end();++it){
      
      if(visited[*it] == false){
        visited[*it] = true;
        q.push_back(*it);
      }
    }   
  }

}

int main(){
  int V=5;
  Graph* g = creategraph(V);
  addEdge(g,0, 1); 
  addEdge(g,0, 2); 
  addEdge(g,1, 2); 
  addEdge(g,2, 0); 
  addEdge(g,2, 3); 
  addEdge(g,3, 3);
  int st;
  cin>>st;
  BFS(g,st);


}
