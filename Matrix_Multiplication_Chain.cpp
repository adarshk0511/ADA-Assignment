#include<iostream>
#include<limits.h>
 
using namespace std;

 
void MatrixChainMultiplication(int p[], int n)
{
    int m[n][n],Kval[n][n];
    int i, j, k, L, q;
 
    for (i=0; i<n; i++){
        for(int j=0;j<n;j++)
    
        m[i][j] = 0;   
    }
     for (i=0; i<n; i++){
        for(int j=0;j<n;j++)
    
        Kval[i][j] = 0;   
    }
    
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    Kval[i][j]=k;
                }
            }
        }
    }
    cout<<"Main Matrix\n";
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n\n";
    cout<<"k Table\n";
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            cout<<Kval[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Mininum number of multiplication is : "<<m[1][n-1];  
 
}
 
int main()
{
    int n,i;
    cout<<"Enter number of matrices\n";
    cin>>n;
 
    n++;
 
    int arr[n];
 
    cout<<"Enter dimensions \n";
 
    for(i=0;i<n;i++)
    {
        cout<<"Enter d"<<i<<" :: ";
        cin>>arr[i];
    }
 
    int size = sizeof(arr)/sizeof(arr[0]);
 
    MatrixChainMultiplication(arr, size);
 
    return 0;
}
