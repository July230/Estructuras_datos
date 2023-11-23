# Proyecto: Tabla de clasificación
Escribe aquí un overview general de tu proyecto

Este proyecto consiste en una tabla de clasificación de jugadores

## Descripción del avance 1
Pega aquí la descripción de tu primer avance.

El avance 1 consiste en el despliegue de dos listas de jugadores:  
Una lista en la que los jugadores se encuentran desordenados.  
Una lista en la que los jugadores están ordenados por puntaje de forma descendente. En este avance no se implementa la búsqueda.

Se toma el vector jugadores como parámetro para ordenar a los jugadores de forma descendente con el fin de encontrar a los jugadores con mayor puntaje. Esto crea una lista de clasificación similar a la vista en videojuegos o deportes, donde el jugador mejor valorado se encuentra en el primer lugar de la lista. 

## Descripción del avance 2
Escribe aquí la descripción de lo que contiene este avance. 

El avance dos implementa la carga de los datos en una estructura de datos, conservando la funcionalidad de carga de un archivo CSV y ordenamiento. Se implementa un árbol de búsqueda binaria para implementar la búsqueda cuyo parámetro es alfabético, para ordenar a los jugadores en el árbol se sobrecargan los operadores "<" y ">".
Se implementa la inserción de nuevos jugadores en la estructura utilizada, la cual es un árbol de búsqueda binaria.

### Cambios sobre el primer avance
1. Escribe la lista de cambios realizados sobre el planteamiento original: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.

3.  Uso de arbol binario: Se utiliza un árbol de búsqueda binaria para implementar la búsqueda e inserción de nuevos elementos.
4. Clase Player: La clase player ya no es declarada como clase template debido a que sólo se encarga de crear objetos tipo Player.
5. Sobrecarga de operadores: Se implementa una sobrecarga de operadores "<" y ">" para hacer la comparación entre datos tipo "string" y ordenarlos alfabéticamente.
6. Nuevas funcionalidades: El archivo main.cpp ahora tiene las opciones adicionales de ordenar la lista alfabéticamente, hacer la búsqueda de elementos por su nombre y agregar nuevos elementos.

## Descripción del avance 3
Escribe aquí la descripción de lo que contiene este avance.

Este avance incorpora la eliminación de jugadores de la lista por medio del árbol de búsqueda binaria utilizado. El programa toma como entrada un archivo CSV y a partir de ahí se puede hacer tanto la inserción como la eliminación de jugadores, el parámetro es por orden alfabético. Los cambios se verán reflejados en el archivo CSV.
Para evitar que el árbol se degenere, se implementaron las funciones para un árbol AVL.

### Cambios sobre el segundo avance
1. Escribe la lista de cambios realizados sobre el planteamiento pasado: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Eliminar elemento de vector: La eliminación de un elemento en el árbol requirió de una nueva función dedicada a la eliminación de un elemento en los vectores con el fin de que los cambios se vean reflejados en los casos de inserción y eliminación.
3. Sobreescritura de archivo: Este avance implementa la sobreescritura del archivo de entrada CSV a partir del árbol de búsqueda binaria
4. Implementación AVL: Para evitar la degeneración del árbol, se incorporaron las funciones para balancearlo.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ arbol.h archivo.h player.h main.cpp -o tercer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercer_avance` 

## Descripción de las entradas del avance de proyecto
Escribe aquí la descripción de las entradas del proyecto, por ejemplo, si de entrada se requieren varios archivos, hay que indicar el formato de cada uno de ellos, y proporcionar un ejemplo de los datos de cada archivo.


El programa tomará como entrada un archivo CSV (Valores Separados por Comas), dada la sencillez, legibilidad y compatibilidad del archivo, así como la facilidad de editarlo. Dicho archivo se llama "players.csv" y contiene los nombres, id y puntuaciones de los jugadores, separados por comas y sin espacios.
El método cargarCSV en el arhivo "archivo.h" es el responsable de leer las líneas del archivo csv e introducir su contenido en un vector jugadores. Dicho vector será utilizado como parámetro por referencia para el ordenamiento por puntaje. A partir del archivo CSV, el usuario tiene la opción de agregar nuevos jugadores.
En el caso del árbol de búsqueda binaria, tambien toma el archivo "players.csv" e introduce cada línea en un nodo del árbol, dicho árbol ordenará la lista de manera alfabética y permitirá hacer la búsqueda por nombre.
En este avance se ha incorporado la escritura en el archivo "players.csv", en este caso, el archivo se sobreescribirá con los datos que contenga el árbol, lo que significa que el orden en el que el archivo se leyó, será diferente al archivo resultante, como el árbol prioriza el orden alfabético, el archivo resultante estará en orden alfabético. El usuario puede agregar jugadores y se ha implementado la eliminación de jugadores.


## Descripción de las salidas del avance de proyecto
Escribe aquí la descripción de los resultados de la ejecución de tu programa.

El programa utilizará la puntuación de los jugadores como parámetro para ordenarlos, el valor de salida será el arreglo de jugadores ordenado de forma descendente, creando una lista de clasificación por puntaje.

El árbol de búsqueda binaria mostrará la lista de jugadores pero en orden alfabético (así como el recorrido preorder), también se usa el mismo árbol para hacer la búsqueda de un jugador por nombre, si el jugador existe, se muestran los datos de ese jugador, en caso de que no exista, se muestra un mensaje indicando que no se encontró. El usuario tendrá la opción de agregar a un nuevo jugador escribiendo nombre, ID y puntaje, este nuevo jugador se verá reflejado tanto el el vector como en el árbol.
Se ha agregado la eliminación de un jugador en la que el parámetro de eliminación es el nombre del jugador. Las inserciones y eliminaciones se verán reflejadas en el archivo "players.csv", así como en la salida de datos y en los vectores.
El archivo resultante estará ordenado alfabéticamente, esto requirió de la implementación de un árbol AVL con el fin de evitar que el árbol tienda a O(n) cuando se le da un archivo ordenado como entrada.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

ShellSort es un algoritmo de ordenamiento similar a otros como BubbleSort o InsertionSort. Se caracteriza por hacer comparaciones en pares que se encuentran en posiciones alejadas, reduciendo progresivamente la brecha entre los elementos a ser comparados. 
En este caso el valor de la brecha comienza siendo el valor de la mitad del arreglo jugadores, reduciendose a la mitad por cada vez que se hacen las comparaciones. 
En el peor caso, ShellSort realiza alrededor de O(n^2) comparaciones, lo que lo coloca en la misma categoría que algoritmos de ordenamiento como SelectionSort o BubbleSort. Sin embargo, ShellSort mejora el rendimiento de BubbleSort y las compraciones dependen en gran medida de la secuencia de brechas utilizada. En promedio, y dependiendo de las secuencias de la brecha, ShellSort llega a realizar alrededor de O(n(log(n))^2) comparaciones. 
ShellSort es un algoritmo de ordenamiento "in situ", es decir, ordena los elementos en su ubicación original sin requerir de memoria adicional, en contraste a otros como MergeSort, los cuales requieren de memoria auxiliar. También es un algoritmo que es más sencillo de implementar y la complejidad de lectura es menor a otros algoritmos. 
Dado que en este caso la base de datos no es muy grande, ShellSort es una buena opción.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

Un árbol de búsqueda binaria es una estructura de datos no lineal caracterizada por ordenar y almacenar los datos de manera eficiente, usualmente requiere de recursividad. El árbol parte de una raiz la cual se divide en dos "hijos" por cada "nodo", estos se conocen como: hijo izquierdo e hijo derecho y el árbol ordena los nodos de manera que se cumple cierta prioridad:
Todos los subnodos de su lado izquierdo son menores a la raíz al mismo tiempo que los subnodos del árbol derecho son mayores a la raíz. Esta forma de ordenamiento facilita la búsqueda, inserción y eliminación eficiente de datos en la estructura del árbol. 
Gracias a estas características, un árbol de búsqueda binaria tiene una complejidad de O(log(n)) para el acceso, búsqueda, inserción y eliminación de elementos, lo que significa que su tiempo de ejecución aumenta de manera gradual conforme el tamaño del árbol aumenta, en contraste a otras estructuras de datos cuya complejidad es O(n).
El peor caso ocurre cuando el árbol no esta balanceado, es decir, tiene más nodos de un lado que del otro, lo que lo "desequilibra", provocando que su complejidad tienda a O(n), perdiendo las propiedades que le dan ventaja y dejándolo en la misma categoría que estructuras lineales como listas ligadas, pilas o filas. Para garantizar que el árbol conserve un rendimiento óptimo, se suelen utilizar árboles equilibrados, como los árboles AVL, cuyo objetivo es redistribuir los nodos de tal forma que el árbol se mantenga balanceado.
Un árbol AVL es un tipo de árbol que fue ideado por los matemátivos Adelson-Velskii y Landis (AVL). Los árboles AVL están siempre equilibrados de tal modo que para todos los nodos, la altura de la rama izquierda no difiere en más de una unidad de la altura de la rama derecha o viceversa. Esta propiedad hace que la complejidad se mantenga e O(log(n)).

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

Un análisis de complejidad del programa requiere de un análisis a sus componentes.


archivo.h

CargarCSV: Lee cada línea del archivo CSV de entrada hasta que ya no hay más elementos, creando un objeto tipo Player por cada elemento y agregándolo al vactor jugadores, esto significa que su complejidad de O(n), donde n es el número de líneas.

OrdenaShell: Este es el algoritmo de ordenamiento Shellsort en el que el peor caso es O(n^2) y que, dependiendo de las secuencias, hace O(nlog(n)^2) comparaciones, en el mejor caso, hace O(nlog(n)) comparaciones.

eliminarJugador: Utiliza la función remove_if y erase, ambas operaciones lineales. La complejidad total sería O(n), donde n es la longitud del vector.

arbol.h, Árbol de búsqueda binaria:

CargarArchivo: Esta función lee cada línea del archivo CSV y los inserta al árbol de busqueda binaria. Al tomar en cuenta que la inserción de un elemento en el árbol tiene una complejidad de O(log(n)) y que en el archivo hay "n" líneas, entonces la complejidad sería de O(nlog(n)).

sucesor: Sucesor tiene por objetivo encontrar el nodo sucesor al hacer la eliminación de un elemento, dado que la estructura es un árbol binario, su complejidad para encontrar al sucesor es O(los(n)), en el peor de los casos, cuando el árbol se ha degenerado, tiende a O(n).

InsertaJugador: Esta función inserta un jugador en el árbol, en promedio, tendría que hacer O(log(n)) comparaciones, sin embargo, si el árbol está degenerado, debe hacer O(n) comparaciones.

borraJugador: Esta función elimina un jugador del árbol, de manera similar a Inserta jugador, tendría que hacer O(log(n)) comparaciones en promedio y O(n) comparaciones si el árbol está degenerado.

Buscar: Busca un jugador en el árbol. En el peor caso, tendría que recorrer la altura del árbol haciendo O(n) comparaciones, la complejidad de esta función es O(log(n)) al hacer las búsquedas en un árbol binario.

inorder y preorder: Ambas funciones realizan un recorrido completo del árbol, visitando cada nodo una vez. Al hacer una operación por nodo y hacer un recorrido de todos los elementos, su complejidad es O(n)

sobreescribir: Escribe todos los elementos del árbol en un archivo. Si consideramos que cada operación de escritura es O(1), la complejidad sería O(n), donde n es el número de nodos en el árbol, dando un total de n líneas.

verificar: Verificar tiene el objetivo de obtener la diferencia de balance para determinar si es necesario un balanceo. La complejidad depende de si el árbol necesita ser balanceado. En el peor caso, si el árbol está desbalanceado y se necesita realizar una rotación, la complejidad sería O(log n), ya que la altura del árbol en un AVL está limitada por log(n).

balancear: La función balancear realiza las rotaciones necesarias para balancear el árbol. Su complejidad también es O(log n) en el peor caso, ya que está limitada por la altura del árbol en un AVL.

main.cpp:

El archivo "main.cpp" consiste en un menu en el que el usuario selecciona n opciones, por cada opción, se hace una instancia de las operaciones analizadas anteriormente.

La complejidad total del programa dependerá de la combinación de operaciones realizadas y cómo afectan al árbol AVL. En la mayoría de los casos, la complejidad dominante será logarítmica (O(log n)) debido a la naturaleza equilibrada del árbol AVL.
Sin embargo, es necesario tomar en cuenta que en el peor de los casos el programa tiene una complejidad de O(n^2) debido al algoritmo de ordenamiento usado para el puntaje, Shellsort, cuya complejidad es O(nlog(n)^2).




### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

El algoritmo de ordenamiento utilizado por el programa será shellsort cuya complejidad promedio es O(n(log(n)^2)), es implementado en el archivo "archivo.h" a través de la función ordenaShell(), la cual toma como parámetro el vector de jugadores.
La razon de la elección de este algoritmo es la poca cantidad de jugadores en el archivo CSV, incluso con una cantidad moderadamente grande, ShellSort sigue siendo una opción viable y sencilla de implementar. 
El algoritmo hace las comparaciones a través del método get_puntos(), definido en el archivo "player.h". El ordenamiento se hace de forma descendente dejando al jugador con más puntos encabezando la lista y al jugador de menor puntaje como último lugar.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

Para este proyecto se utilizará un árbol de búsqueda binaria desarrollado en el archivo "arbol.h", para ordenar a los jugadores alfabéticamente y se utilizará el mismo árbol para la implementación de la búsqueda de un jugador por su nombre. La ventaja de utilizar un árbol de búsqueda binaria es que su tiempo de ejecución es menor a otras estructuras, siendo de O(log(n)), gracias a la propiedades para ordenar los datos. 
En este caso, el árbol de búsqueda binaria se ha implementado para ordenar a los jugadores de manera alfabética. Las comparaciones se hicieron a través de sobrecarga de operadores de comparación en la clase Player y se utilizó la función strcmp() de la librería string.h para hacer comparaciones entre caracteres tipo string. Estas comparaciones devuelven valores numéricos entre -1, 0 y 1, estos valores son utilizados para las comparaciones.
Al implementar un árbol de búsqueda binaria, la búsqueda se vuelve más eficiente, en este caso, la búsqueda es a través del nombre del jugador usando los métodos buscar() y buscaJugador(), y dado que el árbol tiene un tiempo de ejecución menor, la búsqueda es más rápida.
La inserción de jugadores se implementa a través del método InsertaJugador() que utiliza el método insertar como auxiliar, si bien la estructura toma como entrada el archivo CSV, también es posible agregar nuevos elementos, los nuevos jugadores se verán reflejados en el archivo csv.
La eliminación de jugadores se implementa a través del método borraJugador() que utiliza el método borrar como auxiliar, el árbol puede usarse para eliminar a jugadores cargados previamente del archivo CSV y los cambios se verán reflejados en el mismo archivo CSV.
Se han implementado las funciones para un árbol AVL, de forma que el árbol se mantendrá balanceado.


### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

Se ha implementado la búsqueda de elementos a través del árbol de búsqueda binaria, utilizando como parámetro el nombre un jugador. El programa puede devolver tres listas, una desordenada, una ordenada por puntaje y otra ordenada alfabéticamente. El usuario puede consultar los nombres de los jugadores en las listas, sin embargo, este método es menos eficiente cuando hay cada vez más elementos. En este caso, el usuario tiene la opción de escribir el nombre de un jugador, y si este existe, se verá reflejado en las salida de datos. 
También está la opción de agregar nuevos elementos al árbol de búsqueda binaria, y el usuario podrá consultar ese nuevo elemento insertado. También es posible eliminar a un jugador, el cambio se verá reflejado en la salida de datos.


#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

La carga de elementos en el árbol de búsqueda se hace en la clase Arbol en el archivo "arbol.h", siguiendo un proceso similar al hecho en la clase Archivo. Se emplea la misma librería "fstream" y la sintaxis para la carga del archivo es igual, lo que lo diferencia es la inserción de elementos. 
Para insertar elementos tipo Player en el árbol de búsqueda binaria se crea un objeto tipo Player y se utiliza el método InsertaJugador() definido en la misma clase, dicho método utiliza el método insertar(), el cual se encarga de introducir elementos en el árbol. Dado que la carga se hace línea por línea, la raíz del árbol será el primer elemento en el archivo "players.csv", a partir de ese elemento, las comparaciones determinarán su posición en la estructura del árbol. Sin embargo, al incorporar funciones para crear un árbol AVL, por cada inserción, se hace una comprobación para balancear, de esa forma se evita que el árbol se degenere. Al hacer esto, la raíz del árbol puede cambiar conforme se introducen elementos.
Para visualizar la forma en la que han insertado los elementos en el árbol, se muestran los recorridos en orden y preorder, siendo el segundo necesario para determinar la raiz del árbol.


### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

Para la escritura del archivo se ha implementado la función "sobreescribir" en el archivo "arbol.h", la cual se apoya de la función "escribir". Se emplea la librería "fstream" y el archivo se abre en modo escritura usando "ofstream". Las funciones toman el árbol como base y sobreescriben el archivo "players.csv" con el contenido del árbol, lo que significa que el archivo resultante estará ordenado alfabéticamente.
El archivo se abre de manera "truncada", es decir, si el archivo ya existe, se vaciará antes de escribir nuevos datos en él. Si el archivo no existe, se creará uno nuevo. Se asegura que el archivo esté vacío antes de escribir los nuevos datos, asegurando que solo contenga la información del árbol que se tiene en ese momento.
Para evitar que el árbol se degenere al introducir un archivo ya ordenado, se incorporaron las funciones para crear un árbol AVL, de forma que los elementos en el árbol se balancean conforme estos son agregados al árbol. 
