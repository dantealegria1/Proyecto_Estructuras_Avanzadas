#Emparejamiento estable
#Dante Alejandro Alegria Romero
#Andrea Margarita Balandran Felix

import networkx as nx
import matplotlib.pyplot as plt

#Definimos los gustos de cada quien
Paises=["COLOMBIA", "MEXICO", "PERU", "CHILE", "ARGENTINA"]
Personas=["Ana", "Beto", "Carlos", "Andrea", "Eduardo"]

#Creamos el grafo
G=nx.Graph()

#Agregamos los nodos
G.add_nodes_from(Paises)
G.add_nodes_from(Personas)

#Agregamos las aristas
G.add_edge("Ana", "CHILE", weight=1)
G.add_edge("Ana", "MEXICO", weight=2)

G.add_edge("Beto", "PERU", weight=1)
G.add_edge("Beto", "CHILE", weight=2)

G.add_edge("Carlos", "PERU", weight=1)
G.add_edge("Carlos", "MEXICO", weight=2)

G.add_edge("Andrea", "COLOMBIA", weight=1)
G.add_edge("Andrea", "ARGENTINA", weight=2)

G.add_edge("Eduardo", "CHILE", weight=1)
G.add_edge("Eduardo", "ARGENTINA", weight=2)

#Creamos la lista de paises eliminados
PaisesEliminados=[]

#Verificamos si es un grafo bipartito
if nx.is_bipartite(G):
    print("Es un grafo bipartito")
else:
    print("No es un grafo bipartito")
    exit()

def elegirDestino(G, origen):
    #Obtenemos los nodos adyacentes
    adyacentes=G[origen]
    #Obtenemos el nodo con el peso mas bajo
    destino=min(adyacentes, key=lambda x: adyacentes[x]['weight'])
    if destino not in PaisesEliminados:
    #Lo agregamos a la lista de nodos ya visitados
        PaisesEliminados.append(destino)
        return destino
    else:
        return None

def segundaOpcion(G, origen):
    #Obtenemos los nodos adyacentes
    adyacentes=G[origen]
    #Obtenemos el nodo con el peso mas bajo
    destino=max(adyacentes, key=lambda x: adyacentes[x]['weight'])
    return destino        

for persona in Personas:
    destino=elegirDestino(G, persona)
    if destino!=None:
        print(persona, "se va a", destino, "(opcion 1)")
    else:
        destino=segundaOpcion(G, persona)
        print(persona, "se va a", destino, "(opcion 2)")

#Dibujamos el grafo
nx.draw(G,with_labels=True)
plt.show()

