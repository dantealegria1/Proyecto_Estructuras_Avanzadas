#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void addEdge(int u,int v,vector<int>* V) //funcion para econtrar aristas 
{
	V[u].push_back(v);
}
void DFS(int s,vector<int>* adj,int n)
{
	
    int visited[n+1]={0};
    //creamos el stack  
    stack<int> stack; 
   
    stack.push(s); 
  	
  	vector<int>::iterator i;//declarar 
    while (!stack.empty()) 
    { 
        s = stack.top(); 
        stack.pop(); 
   
        if (!visited[s]) 
        { 
            cout << s << " "; 
            visited[s] = true; 
        } 
 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
            if (!visited[*i]) 
                stack.push(*i); 
    }  
}
int main()
{
	int n,e,u,v;
	cout<<"Ingresa el numero de vertices: "<<endl;
	cin>>n;
	cout<<"ingresa cuantas uniones tiene: "<<endl;
	cin>>e;
	int copy=n;
	vector<int> V[n+1];
	for(int i=0;i<e;i++)
	{
		cout<<"elige tu grafo: "<<i+1<<endl;
		cin>>u;
		cout<<"este tiene union con:"<<endl;
		cin>>v;
		addEdge(u,v,V);
	}
	cout<<"REPPRESENTACION GRAFICA "<<endl;
	vector<int>::iterator it;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<"->";
		for(it=V[i].begin();it!=V[i].end();it++)
		{
			cout<<*it<<" ";
		}	
		cout<<endl;
	}
	cout<<"su grafo con profundidad es: ";
	DFS(1,V,n);
	return 0;
}
