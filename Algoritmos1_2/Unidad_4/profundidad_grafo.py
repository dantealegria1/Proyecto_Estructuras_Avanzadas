#Recorrido por profundidad de un grafo o DFS


import os

#definimos el grafo, y sus adyacentes, otra aplicacion de 
#las diferentes maneras de mostrar un gr<fo dirigido
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

print("Muestra el grafo antes del recorrido: \n")
for key, lista in grafo.items():
	print(key)
	print(lista)
		
visitados = []
pila = []

origen = input("Ingresa un nodo: ")
print("\nLista de recorrido en profundidad\n")
#agregamos el nodo origen a la pila
pila.append(origen)
while pila:
	
    #el ultimo elemento de la pila es el actual
	actual = pila.pop()
    #si no lo hemos visitado, lo imprimimos
	if actual not in visitados:
		print("Vertice actual -> ", actual)
		visitados.append(actual)
	#agregamos los adyacentes a la pila
	for key, lista in grafo[actual]:
		if key not in visitados:
			pila.append(key)

print()

