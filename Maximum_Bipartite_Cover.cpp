#include <iostream>
using namespace std;

bool bipartiteGraph[20][20];
int printbipartiteGraph[20][20];

bool bipMax(int u, bool visited[], int a[],int M,int N) {
    for (int v = 0; v < N; v++) {
    if (bipartiteGraph[u][v] && !visited[v]) {
        visited[v] = true;
        if (a[v] < 0 || bipMax(a[v], visited, a,M,N)) {
            a[v] = u;
            printbipartiteGraph[u][v]=1;
            return true;
            }
        }
    }
    return false;
}
int maxPair(int M,int N) {
    int a[N];
    for(int i = 0; i<N; i++)
        a[i] = -1;
    int Count = 0;
    for (int u = 0; u < M; u++) {
        bool visited[N];
        for(int i = 0; i<N; i++)
            visited[i] = false;
            if (bipMax(u, visited, a,M,N))
                Count++;
        }
    return Count;
}
int main() {
    int M,N;
    cout<<"Enter the number of elements in subset M and N"<<endl;
    cin>>M>>N;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<M;i++)
    {
        cout<<"Row "<<i+1<<" Elements :"<<endl; 
        for(int j=0;j<N;j++)
        {
            cin>>bipartiteGraph[i][j];
        }
    }
    cout << "Maximum Matching Bipartite Pair " << maxPair(M,N)<<endl;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<printbipartiteGraph[i][j]<<" ";
        }
    cout<<endl;
    }
    return 0;
}
