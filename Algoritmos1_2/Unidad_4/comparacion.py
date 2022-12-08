import networkx as nx
import matplotlib.pyplot as plt

grafo = {'a': [('p',4), ('j',15), ('b',1)],
       	'b': [('a',1), ('d',2), ('e',2), ('c',3)],
	'j': [('a',15)],
	'p': [('a', 4)],
	'd': [('b',2), ('g',3)],
	'e': [('b',2), ('g',4), ('f',5), ('c',2)],
	'c': [('b',3), ('e',2), ('f',5), ('i',20)],
	'g': [('d',3), ('e',4), ('f',10), ('h',1)],
	'f': [('g',10), ('e',5), ('c',5)],
	'i': [('c',20)],
	'h': [('g',1)] 
	}

def dibujar_grafo(grafo):
    G = nx.DiGraph()
    for key, lista in grafo.items():
        for key2, lista2 in lista:
            G.add_edge(key, key2)
    nx.draw(G, with_labels=True, font_weight='bold')
    plt.show()

def dfs(grafo, origen):
    visitados = []
    pila = []
    pila.append(origen)
    while pila:
        actual = pila.pop()
        if actual not in visitados:
            visitados.append(actual)
        for key, lista in grafo[actual]:
            if key not in visitados:
                pila.append(key)
    return visitados

def bfs(grafo, origen):
    visitados = []
    cola = []
    cola.append(origen)
    while cola:
        actual = cola.pop(0)
        if actual not in visitados:
            visitados.append(actual)
        for key, lista in grafo[actual]:
            if key not in visitados:
                cola.append(key)
    return visitados

def main():
    origen = input("Ingresa un nodo: ")
    print("\nLista de recorrido en profundidad\n")
    print(dfs(grafo, origen))
    print("\nLista de recorrido en anchura\n")
    print(bfs(grafo, origen))
    dibujar_grafo(grafo)

if __name__ == "__main__":
    main()
