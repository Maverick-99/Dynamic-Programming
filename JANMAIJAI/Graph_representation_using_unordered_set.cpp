#include <bits/stdc++.h>
#include <set>
#include<iterator>
using namespace std;

class Graph{
  public:
  int V;
  unordered_set <int>*adj;
};

Graph* creategraph(int x){
  Graph* g = new Graph;
  g->V = x;
  g->adj = new unordered_set<int>[x];
  return g;
}

void addEdge(Graph* g,int x,int y){
  g->adj[x].insert(y);
  g->adj[y].insert(x);
}

void printgraph(Graph* g,int x){
  unordered_set<int>::iterator it;
  for(int i=0;i<x;i++){
    cout<<i;
    for(it = g->adj[i].begin();it!=g->adj[i].end();++it){
      cout<<"-> "<<*it;
    }
    cout<<endl;
  }
}

void searchedge(Graph* g,int src,int des){
  auto ge = g->adj[src].find(des);
  if(ge == g->adj[src].end()){
    cout<<"not found"<<endl;
  }else{
    cout<<"found"<<endl;
  }
}

int main(){
  int V = 5;
  Graph* gra = creategraph(V); 
  addEdge(gra, 0, 1); 
  addEdge(gra, 0, 4); 
  addEdge(gra, 1, 2); 
  addEdge(gra, 1, 3); 
  addEdge(gra, 1, 4); 
  addEdge(gra, 2, 3); 
  addEdge(gra, 3, 4); 
  printgraph(gra,V);
  searchedge(gra,1,3);
  searchedge(gra,2,3);
  searchedge(gra,2,5);
}
