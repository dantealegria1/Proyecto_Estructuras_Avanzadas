/**
 * Este algoritmo recorre un grafo en anchura
 * usando una cola
 * @param {Array} grafo matriz de adyacencia
 * @param {Number} inicio nodo de inicio
 * @returns {Array} recorrido
 */
// creamos la matriz de adyacencia
let grafo = [
  [0, 0, 0, 0, 0, 0, 0], // A (0)
  [1, 0, 1, 0, 0, 0, 1], // H (1)
  [0, 0, 0, 0, 0, 0, 0], // T (2)
  [0, 1, 0, 0, 0, 0, 0], // B (3)
  [0, 1, 0, 0, 0, 0, 0], // R (4)
  [0, 0, 0, 0, 1, 0, 0], // C (5)
  [0, 0, 0, 1, 0, 1, 0], // D (6)
]

// array de visitados inicializado en ceros
let visitados = Array(grafo.length).fill(0)

// inicializamos la cola
// la funcion para agragar elementos es push
// la funcion para sacar elementos es shift
let cola = []

// inicializamos el array de recorrido
let resultado = []

// generar un numero aleatorio entre 0 y n-1
let inicio // = 6 -> para que sea como en el ejercicio (D)
do {
  inicio = Math.floor(Math.random() * grafo.length)
} while (!grafo[inicio].includes(1))


// agregamos el nodo inicial a la cola
cola.push(inicio)
// marcamos el nodo inicial como visitado
visitados[inicio] = 1
// agregamos el nodo inicial al resultado
resultado.push(inicio)

// el algoritmo de recorrido seguirá hasta que la cola esté vacía
// lo que significa que ya no hay más nodos por visitar
while (cola.length > 0) {
  // obtenemos el primer elemento de la cola (la funcion shift tambien elimina)
  let nodo = cola.shift()

  // recorremos los nodos adyacentes al nodo actual
  // *siempre el primer nodo tendra al menos un adyacente ya que 
  // *cuando obtenemos el primer nodo revisamos que tenga adyacentes
  for (let i = 0; i < grafo[nodo].length; i++) {
    // si hay un nodo adyacente y no ha sido visitado
    if (grafo[nodo][i] === 1 && visitados[i] === 0) {
      // lo agregamos a la cola para en la siguiente iteración visitarlo
      cola.push(i)
      // y lo marcamos como visitado
      visitados[i] = 1
      // y lo agregamos al resultado
      resultado.push(i)
    }
  }
}

console.log(resultado)
