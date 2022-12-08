#El problema a resolver es el siguiente:
#Determinar el camino mas rapido a recorrer
#tomando llas viajes del tren de las diferentes lineas
#tomando en cuenta que solo tienen un viaje de ida al dia
#iniciando en el nodo A y terminando en el nodo E

#El grafo es el siguiente:
grafo = {'A': [('B', 5), ('C', 3), ('D', 2)],
    'B': [('A', 5), ('C', 2), ('E', 1)],
    'C': [('A', 3), ('B', 2), ('D', 1), ('E', 1)],
    'D': [('A', 2), ('C', 1), ('E', 1)],
    'E': [('B', 1), ('C', 1), ('D', 1)]}

def recorrido(grafo, origen, destino):
    camino = []
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
    #si el destino esta en la lista de visitados
    #entonces hay camino
    if destino in visitados:
        for i in visitados:
            if i == destino:
                camino.append(destino)
                print("El camino es: ", camino)
                break
            else:
                camino.append(i)
    else:
        print("No hay camino")
            
recorrido(grafo, 'A', 'E')
