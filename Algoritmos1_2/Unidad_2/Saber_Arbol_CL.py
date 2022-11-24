import matplotlib.pyplot as plt
#Su big o es de o(n+m)
#llamamos la libreria
import networkx as nx
Grafo = nx.Graph()
#Creamos el grafo e inicializamos los nodos y aristas
Grafo.add_nodes_from([1,2,3,4])
Grafo.add_edges_from([(1,3),(3,4),(4,1)])
#llamamos nuestra funcion
print(nx.is_tree(Grafo))

#dibujamos el grafo
G = Grafo
subax1 = plt.subplot(121)
nx.draw(G, with_labels=True, font_weight='bold')
subax2 = plt.subplot(122)
nx.draw_shell(G, nlist=[range(5, 10), range(5)], with_labels=True, font_weight='bold')
plt.show()
