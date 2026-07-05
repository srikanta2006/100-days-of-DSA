#include<vector>
#include<iostream>
using namespace std;
class DisjointSet{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DisjointSet(int V){ //constructor which create memory for rank and parent vectors
            rank.assign(V, 0);
            parent.resize(V);
            for(int i = 0; i < V; i++){
                parent[i] = i;
            }
        }
    
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i]);
    }

    bool unite(int u, int v){
        int u_parent = find(u);
        int v_parent = find(v);

        if(u_parent ==v_parent){ //already connencted
            return false;
        }

        int r_u_parent = rank[u_parent];
        int r_v_parent = rank[v_parent];

        //attach smaller tree under the root of the larger tree
        if(r_u_parent > r_v_parent){
            parent[v_parent]=u_parent;
        }
        else if(r_v_parent > r_u_parent){
            parent[u_parent]=v_parent;
        }
        else{
            parent[u_parent]=v_parent;
            rank[v_parent]++;
        }
        return true;
    }

    bool connected(int u, int v){
        int u_parent = find(u);
        int v_parent = find(v);

        if(u_parent == v_parent){
            return true;
        }
        else{
            return false;
        } 
    }
};
