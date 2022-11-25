# Una clase para representar un objeto graph
class Graph:
    # Constructor
    def __init__(self, edges=None, n=0):
 
        # Número total de nodos en el graph
        self.n = n
 
        # Una lista de listas para representar una lista de adyacencia
        self.adjList = [[] for _ in range(n)]
 
        # agrega bordes al graph no dirigido
        for (src, dest) in edges:
            self.adjList[src].append(dest)
            self.adjList[dest].append(src)
 
 
# Realizar DFS en el graph a partir del vértice `v`
def DFS(graph, v, discovered, color):
 
    # do para cada arista (v, u)
    for u in graph.adjList[v]:
 
        # si se explora el vértice `u` por primera vez
        if not discovered[u]:
 
            # marca el nodo actual como descubierto
            discovered[u] = True
 
            # El nodo actual # tiene el color opuesto al de su padre
            color[u] = not color[v]
 
            # si DFS en cualquier subárbol enraizado en `v` devuelve falso
            if not DFS(graph, u, discovered, color):
                return False
 
        # si ya se ha descubierto el vértice y el color de
        # vértice `u` y `v` son iguales, entonces el grafo no es bipartito
        elif color[v] == color[u]:
            return False
 
    return True
 
 
# Función # para verificar si un graph es bipartito usando DFS
def isBipartite(graph):
 
    # para realizar un seguimiento de si se descubre un vértice o no
    discovered = [False] * graph.n
 
    # realiza un seguimiento del color asignado (0 o 1) a cada vértice en DFS
    color = [False] * graph.n
 
    # comienza desde cualquier nodo ya que el graph está conectado y no dirigido
    src = 0
 
    # marca el vértice de origen como descubierto y establece su color en 0 (Falso)
    discovered[src] = True
    color[src] = False
 
    # Procedimiento DFS de llamada
    return DFS(graph, src, discovered, color)
 
 
if __name__ == '__main__':
 
    # Lista de bordes de graph
    edges = [
        (0, 1), (1, 2), (1, 7), (2, 3), (3, 5), (4, 6), (4, 8), (7, 8), (1, 3)
        # si eliminamos el borde (1, 3), el grafo se vuelve bipartito
    ]
 
    # número total de nodos en el graph (0 a 8)
    n = 9
 
    # construye un graph a partir de los bordes dados
    graph = Graph(edges, n)
 
    if isBipartite(graph):
        print('Es bipartito')
    else:
        print('No es bipartito')