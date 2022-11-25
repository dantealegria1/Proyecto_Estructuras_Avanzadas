#encontrar si un emparejamiento tonto?
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
##cREAMOS LA LISTA DE PARES ELIMINADOS
eliminados=[]

def elegirDestino(G,origen):
    adyacentes=G[origen]
    for destino in adyacentes:
        if destino not in eliminados:
            eliminados.append(destino)
            return destino
    #si no hay mas destinos disponibles
    if len(eliminados)==len(G.nodes()):
        return "No hay mas destinos disponibles"

#aplicamos la funcion a cada nodo
for nodo1 in nodo1:
    print("El nodo",nodo1,"tiene como destino",elegirDestino(G,nodo1))



