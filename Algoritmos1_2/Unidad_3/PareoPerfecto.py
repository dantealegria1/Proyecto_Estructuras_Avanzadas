#encontrar si un emparejamiento to
import networkx as nx
import matplotlib.pyplot as plt
import random
nodo1=["A","B","C","D"]
nodo2=["1","2","3","4"]
G=nx.Graph()
G.add_nodes_from(nodo1)
G.add_nodes_from(nodo2)
G.add_edge("A","1",weight=1)
G.add_edge("A","3",weight=1)
G.add_edge("A","4",weight=1)

G.add_edge("B","1",weight=1)
G.add_edge("B","3",weight=1)

G.add_edge("C","2",weight=1)

G.add_edge("D","2",weight=1)
G.add_edge("D","3",weight=1)
#dibujo el grafo

##cREAMOS LA LISTA DE PARES ELIMINADOS
eliminados=[]
#creamos una lista de los nodos que solamente tienen un vecino
nodosUnicos=[]
nodosUnicos2=[]
for nodo in nodo1:
    if len(G[nodo])==1:
        nodosUnicos.append(nodo)

for nodo in nodo2:
    if len(G[nodo])==1:
        nodosUnicos2.append(nodo)

def elegirDestino(G,origen):
    #tomamos como prioridad los nodos que tienen un solo vecino
    adyacentes=G[origen]
    for pene in nodosUnicos:
        if pene == origen:
            for destino in adyacentes:
                if destino not in eliminados:
                    eliminados.append(destino)
                    return destino
    for pene in nodosUnicos2:
        if pene == origen:
            for destino in adyacentes:
                if destino not in eliminados:
                    eliminados.append(destino)
                    return destino
    for destino in adyacentes:
        if destino not in eliminados:
            eliminados.append(destino)
            return destino
    #si no hay mas destinos disponibles
#aplicamos la funcion a cada nodo
for nodo1 in nodo1:
    print("El nodo",nodo1,"tiene como destino",elegirDestino(G,nodo1))



