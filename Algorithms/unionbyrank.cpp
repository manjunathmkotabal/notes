#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int parent;
    int rank;
}node;

int find(int v,vector<node> &nodes){
    if(nodes[v].parent==-1){
        return v;
    }
    else{
        return nodes[v].parent=find(nodes[v].parent,nodes);
    }
}

void unionbyrank(int fromp,int top,vector<node> &nodes){
    if(fromp>top){
            nodes[top].parent = fromp;
        }
        else if(top>fromp){
            nodes[fromp].parent = top; 
        }
        else{
            nodes[fromp].parent = top;
            nodes[top].rank++;
        }
}

bool iscyclic(vector<pair<int,int>> &edgelist,vector<node> &nodes){
    for(pair<int,int> e : edgelist){
        int fromp = find(e.first,nodes);
        int top = find(e.second,nodes);

        if(fromp==top){
            return true;
        }
        else{
            unionbyrank(fromp,top,nodes);
        }
    }
    return false;
}



int main(){
    vector<node> nodes;
    vector<pair<int,int>> edgelist;

    int V,E;
    cin>>V>>E;

    for (int i = 0; i < V; i++) {
        nodes.push_back({-1, 0});  // Push back new nodes
    }

    for(int i=0;i<E;i++){
        int from,to;
        cin>>from>>to;
        edgelist.push_back({from,to});
    }

    if(iscyclic(edgelist,nodes)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

}

