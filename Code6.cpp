//WAP to find minimum cost spanning tree by using prim's Algorithm.

#include <iostream>
using namespace std;

int main(){
    int n,e;
    cout<<"Enter number of vertices:";
    cin>>n;

    cout<<"Enter number of edges:";
    cin>>e;

    int u[20], v[20], w[20];

    cout<<"Enter the edges (i.e., u v w ):\n"; // u is the starting vertex , v is the ending vertex , w is th weight of the edge
    for(int i=0;i<e;i++){
        cin>>u[i]>>v[i]>>w[i];
    }

    int visited[10]={0};
    visited[0]=1; //Make the starting index = 0 by visiting it...

    int total = 0; //Stores the final minimum cost.

    //cout<<"Minimum Spanning tree:\n";
    for(int k=0 ; k<n-1 ; k++){ //Go to each vertex ,i.e., if n=4 , k will be 0,1,2 
        int min = 999;
        int pos = -1; //Stores the index of the minimum cost

        for(int i=0;i<e;i++){

            // One vertex visited and other not visited
            if(visited[u[i]]==1 && visited[v[i]]==0 || visited[u[i]]==0 && visited[v[i]]==1){
                if(w[i]<min){
                    min = w[i];
                    pos = i;
                }
            }

        } 

        if(pos!=-1){
            // cout<<"Edge selected:-";
            // cout<<u[pos]<<"-"<<v[pos]<<"="<<w[pos]<<endl;
            total += w[pos];
            visited[u[pos]]=1;
            visited[v[pos]]=1;
        }

    }

    cout << "Minimum Cost = " << total << endl;

    return 0;
}