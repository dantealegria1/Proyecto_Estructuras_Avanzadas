#include <iostream>
#include <queue>
using namespace std;

/**
 * @brief Comprueba si un grafo es bipartito
 * @param matriz Matriz de adyacencia del grafo (no dirigido)
 * @return true si el grafo es bipartito, false en caso contrario
 * 
 * autor Diego Emilio Moreno Sánchez @YeyoM
 * @date 25 de octubre de 2022
 * 
 * Procedimiento basado en: Matemática Discreta - Grafo Bipartido. 
 * Ej.2 - Jesús Soto (https://www.youtube.com/watch?v=0Kb4r1oLMbY)
 * 
 * En teoría de grafos, un grafo bipartito es un grafo G=(N,E) cuyos 
 * vértices se pueden separar en dos conjuntos disjuntos U y V.
 * De manera que las aristas sólo pueden conectar vértices
 * de un conjunto con vértices del otro.
 * 
 * La idea para verificar si un grafo es bipartito es "colorear"
 * cada vertice ya sea de color 1 o 2. Si un vertice tiene color 1
 * entonces todos sus vecinos deben tener color 2 y viceversa.
 * 
 * De forma que para verificar, cada nodo guardará la información
 * del color que tiene. Si un nodo no tiene color, entonces se le
 * asigna el color 1 y se le asigna el color 2 a todos sus vecinos.
 * 
 * Este algoritmo se repite hasta que hayamos visitado todos los nodos.
 * 
*/

// #define NODOS 6  
#define NODOS 8  
struct Nodo {
  int color;
  int id;
};

int main() {

  int colorActual = 0; 

  // Matriz de adyacencia del grafo

  // Grafo Bipartito
  // int matriz[NODOS][NODOS] = {
  //   {0, 0, 1, 1, 0, 1},
  //   {0, 0, 0, 0, 1, 1},
  //   {1, 0, 0, 0, 0, 0},
  //   {1, 0, 0, 0, 0, 0},
  //   {0, 1, 0, 0, 0, 0},
  //   {1, 1, 0, 0, 0, 0}
  // };

  // Grafo No Bipartito
  // int matriz[NODOS][NODOS] = {
  //   {0, 0, 1, 1, 0, 1},
  //   {0, 0, 0, 0, 1, 1},
  //   {1, 0, 0, 0, 0, 0},
  //   {1, 0, 0, 0, 0, 0},
  //   {0, 1, 0, 0, 0, 1},
  //   {1, 1, 0, 0, 1, 0}
  // };

  // Grafo Bipartito 
  // (https://www.youtube.com/watch?v=0Kb4r1oLMbY)
  int matriz[NODOS][NODOS] = {
    {0, 1, 1, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1, 1, 0},
  };

  int visitados[NODOS];
  queue<int> cola;

  // Arreglo de nodos
  Nodo nodos[NODOS];
  for (int i = 0; i < NODOS; i++) {
    nodos[i].id = i;
    nodos[i].color = 0;
    visitados[i] = 0;
  }

  // Colorear el primer nodo
  nodos[0].color = 1;

  // Recorrer el grafo 
  cola.push(0);
  visitados[0] = 1;

  while(!cola.empty()) {
    int indiceNodo = cola.front();
    cola.pop();

    // Colorear los vecinos
    for (int i = 0; i < NODOS; i++) {
      if (matriz[indiceNodo][i] == 1) {
        if (nodos[i].color == 0) {
          nodos[i].color = nodos[indiceNodo].color == 1 ? 2 : 1;
          cola.push(i);
          visitados[i] = 1;
        } else if (nodos[i].color == nodos[indiceNodo].color) {
          cout << "El grafo no es bipartito" << endl;
          return 0;
        }
      }
    }
  }

  cout << "El grafo es bipartito" << endl;

  // color de los nodos
  for (int i = 0; i < NODOS; i++) {
    cout << "Nodo " << nodos[i].id << " tiene color " << nodos[i].color << endl;
  }

  return 0;
}