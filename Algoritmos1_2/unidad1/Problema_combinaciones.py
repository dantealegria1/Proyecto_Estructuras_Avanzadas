#programa que me da las combinaciones de un equipo de basketball
#Su big O es O(n^2)
from itertools import combinations
cantidad=int(input("Dame la cantidad de jugadores que tienes "))
jugadores = []
for i in range(cantidad):
    jugador = input(f"Ingresa el nombre del jugador {i + 1}: ")
    jugadores.append(jugador)
print(f"Posibles quintetos")
temp = combinations(jugadores, 5)
for i in list(temp):
    print (i)
    
