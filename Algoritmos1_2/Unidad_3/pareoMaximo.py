#emparejamiento maximo
import networkx as nx
import matplotlib.pyplot as plt

G=nx.Graph()
G.add_nodes_from(["S","D","L","E","P","V","M","U"])
G.add_edge("S","D")
G.add_edge("S","E")
G.add_edge("S","V")
G.add_edge("L","D")
G.add_edge("L","U")
G.add_edge("P","E")
G.add_edge("P","U")
G.add_edge("M","V")

#Dibujo el grafo
def emparejamientoMaximo(G):
    #Obtenemos el emparejamiento maximo
    emparejamiento=nx.max_weight_matching(G)
    print("Emparejamiento maximo: ", emparejamiento)
    
    #Dibujamos el grafo
    nx.draw(G, with_labels=True)
    plt.show()

emparejamientoMaximo(G)

