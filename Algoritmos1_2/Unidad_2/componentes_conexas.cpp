/*
Codigo extraido de :
https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/?ref=gcse
el día 23 de Noviembre del 2022

Comentado y traducido por: 
Maria Yoselin Garcia Medina 338030

Programa para imprimir componentes concexos de un
grafo no dirigido 
*/
#include <bits/stdc++.h>
using namespace std;

//Clase grafo
//grafo no dirigido usando lista de adyacencia
class Grafo {
	int V; // Numero de vertices 

	// puntero a una matriz
	list<int>* adj;

	// Funcion utilizada por DFS
	void DFSUtil(int v, bool visited[]);

public:
	Grafo(int V); // Constructor
	~Grafo();
	void addEdge(int v, int w);
	void connectedComponents();
};

// Metodo para imprmir los componentes conexos
void Grafo::connectedComponents()
{
	// Marcando todos los vertices como no visitados
	bool* visited = new bool[V];
	for (int v = 0; v < V; v++)
		visited[v] = false;
		
	//recorro la matriz 
	for (int v = 0; v < V; v++) {
		if (visited[v] == false) {	//si no ha sido visitado
			// imprimiendo los vertices alcanzable por v
			DFSUtil(v, visited);

			cout << "\n";
		}
	}
	delete[] visited;
}

void Grafo::DFSUtil(int v, bool visited[])
{
	// Marca el nodo actual como visitado
	visited[v] = true;
	// Imprime el nodo visitado
	cout << v << " ";

	// Recursividad para vertices adyacentes a este
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

Grafo::~Grafo() { delete[] adj; }

// method to add an undirected edge
void Grafo::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

// El Main
int main()
{
	// Crea un gráfico dado en el diagrama anterior
	Grafo g(5); // 5 vértices numerados del 0 al 4
	g.addEdge(1, 0);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	//Imprimo los componetentes conexos 
	cout << " Los siguientes con componentes conexos: \n";
	g.connectedComponents();

	return 0;
}

