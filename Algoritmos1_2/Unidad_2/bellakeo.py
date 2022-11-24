#Si quiero ir al jardin san marcos, pero antes de eso debo de pasar por 
#todos mis amigos, todos en diferentes puntos de la ciudad, asi que tengo
#que buscar la manera de recorrer todas la casas y llegar ahi en el menor
#tiempo posible
#su big o es O(n!)
#Importamos la libreria de grafos
import networkx as nx
from networkx.algorithms import tree
import matplotlib.pyplot as plt
import numpy as np
from itertools import permutations
#Creamos el grafo
G=nx.Graph()

#Agregamos los nodos
G.add_nodes_from(["Dante","Luis","Santiago","Saul"])

#Agregamos las aristas, estas van a ser los tiempos que tardamos de casa a casa
G.add_edge("Dante","Luis",weight=27)
G.add_edge("Dante","Santiago",weight=13)
G.add_edge("Dante","Saul",weight=15)

G.add_edge("Luis","Santiago",weight=19)
G.add_edge("Luis","Saul",weight=27)

G.add_edge("Santiago","Saul",weight=11)

#creamos todsa las combinaciones y la suma de los pesos
def sumaPesos(G,lista):
    suma=0
    for i in range(len(lista)-1):
        suma+=G[lista[i]][lista[i+1]]['weight']
    return suma

lista=list(permutations(G.nodes()))
#Creamos una lista de las sumas de los pesos
listaPesos=[]
for i in lista:
    listaPesos.append(sumaPesos(G,i))
#Obtenemos el indice del camino mas corto
indice=listaPesos.index(min(listaPesos))
#Obtenemos el camino mas corto
caminoMasCorto=lista[indice]
#Imprimimos el camino mas corto
print("El camino mas corto es: ", caminoMasCorto)
print("El tiempo que tardamos en llegar es: ", min(listaPesos))

