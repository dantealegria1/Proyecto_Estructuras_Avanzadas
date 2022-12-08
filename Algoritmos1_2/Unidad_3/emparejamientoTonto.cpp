#include <iostream>
#include <vector>
using namespace std;

/**
 * Algoritmo de emparejamiento de vertices de un grafo
 * @param matriz Matriz de adyacencia del grafo bipartito
*/

#define nodos 8 

int main() {

  int matriz[nodos][nodos] = {
    {0, 1, 1, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1, 1, 0},
  };

  vector<int> visitados(nodos, 0);

  vector<int> emparejamiento(nodos, -1);

  for (int i = 0; i < nodos; i++) {
    if (visitados[i] == 0) {
      for (int j = 0; j < nodos; j++) {
        if (matriz[i][j] == 1 && visitados[j] == 0) {
          emparejamiento[i] = j;
          emparejamiento[j] = i;
          visitados[i] = 1;
          visitados[j] = 1;
          break;
        }
      }
    }
  }

  for (int i = 0; i < nodos; i++) {
    if (emparejamiento[i] != -1) {
      cout << i << " - " << emparejamiento[i] << endl;
    }
  }

  return 0;
}