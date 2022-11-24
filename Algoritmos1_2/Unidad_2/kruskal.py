class Graph:

 
 #se inicializa el grafo con un diccionario vacio
    def __init__(self, vertices):
      
        self.V = vertices  
        self.graph = []
      
 # agregar aristas
    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])

    # encontrar la raiz del nodo
    #parent es el arreglo de padres
    #i es el indice del nodo que estamos buscando
    def find(self, parent, i):

        if parent[i] != i: #aqui vemos si el padre del nodo no es el mismo nodo
            
            parent[i] = self.find(parent, parent[i]) #recursividad encontramos la raiz 
        return parent[i]

#esta funcion sirve para unir los nodos que no estan conectados 
#parent es el arreglo de padres
#rank es el numero de nodos que tiene cada nodo
#x es el primer nodo
#y es el nodo que se va a conectar con x
    def union(self, parent, rank, x, y):


        if rank[x] < rank[y]: #si el primer nodo es menos al que se va a conectar
            parent[x] = y #el padre del primer nodo pasa a se al que se va a conectar
        elif rank[x] > rank[y]: #si el primer nodo es mayor al que se va a conectar
            parent[y] = x #el padre del que se va a conectar pasa a ser el primer nodo
 
 
        else:
            parent[y] = x #el padre del que se va a conectar pasa a ser el primer nodo
            rank[x] += 1 #aumentamos el numero de nodos que tiene el primer nodo
 
#funcion que aplica el algoritmo de kruskal
    def KruskalMST(self):
       
 
        result = []   #arreglo que va a contener el arbol de expansion minimo
 
        i = 0 #indice i con valor 
 
        e = 0 #indice e con valor 0
 
        self.graph = sorted(self.graph, #mandamos a llamar la funcion sorted para ordenar el grafo
                            key=lambda item: item[2]) #le asignamos la primera funcion lambda para ordenar el grafo
                            #item es el elemento que estamos ordenando
 
        parent = []
        rank = []
 

        for node in range(self.V): #recorremos el numero de nodos
            parent.append(node) #agregamos el nodo al arreglo de padres
            rank.append(0) #agregamos el nodo al arreglo de rank
 
        while e < self.V - 1: #mientras e sea menor al numero de nodos -1
 

            u, v, w = self.graph[i] #asignamos a u,v,w los valores del grafo en la posicion i
            i = i + 1 #incrementa  i
            x = self.find(parent, u) #asignamos a x el valor de la funcion find con los parametros parent y u
            y = self.find(parent, v) 


            if x != y: #si x es diferente a y
                e = e + 1 #
                result.append([u, v, w]) #agregamos a result los valores de u,v,w
                self.union(parent, rank, x, y) #mandamos a llamar la funcion union con los parametros parent,rank,x,y
       
 
        minimumCost = 0 #inicializamos el costo minimo en 0
        print("caminos")
        for u, v, weight in result: #recorremos result
            minimumCost += weight #sumamos el costo minimo con el peso
            print("%d -- %d == %d" % (u, v, weight)) #imprimimos el camino
        print("camino más corto ", minimumCost)
 
 

if __name__ == '__main__':
    #la forma en que se crea el grafo es la siguiente
    #se crea un objeto de la clase Graph
    #los dos primeros numeros son la union de los nodos
    #el tercer numero es el peso de la union
    g = Graph(4)
    g.addEdge(0, 1, 10)
    g.addEdge(0, 2, 6)
    g.addEdge(0, 3, 5)
    g.addEdge(1, 3, 15)
    g.addEdge(2, 3, 4)


    g.KruskalMST()