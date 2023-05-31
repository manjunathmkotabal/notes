#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    //each node a parent value and a rank
    int parent;
    int rank;
}node;

//gives the absolute patent nodes(root)
int find(int v,vector<node> &nodes){
    if(nodes[v].parent==-1){
        return v;
    }
    else{
        return nodes[v].parent=find(nodes[v].parent,nodes);
    }
}

//performing union of both nodes 
void unionbyrank(int fromp,int top,vector<node> &nodes){
    if(fromp>top){
            nodes[top].parent = fromp;
        }
        else if(top>fromp){
            nodes[fromp].parent = top; 
        }

        //rank of new parent will increase
        else{
            //from will point to if same(convenience)
            nodes[fromp].parent = top;
            nodes[top].rank++;
        }
}

bool iscyclic(vector<pair<int,int>> &edgelist,vector<node> &nodes){
    for(pair<int,int> e : edgelist){

        //get the abs parent of both nodes
        int fromp = find(e.first,nodes);
        int top = find(e.second,nodes);

        //there exists a cycle if both have same parent
        if(fromp==top){
            return true;
        }
        else{
            //unify them
            unionbyrank(fromp,top,nodes);
        }
    }
    return false;
}



int main(){
    // we need a vector of nodes
    // and a vector of edges
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

