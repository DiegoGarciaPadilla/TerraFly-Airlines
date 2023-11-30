# Proyecto: TerraFly Airlines
El proyecto consiste en desarrollar un programa que permita a los usuarios de TerraFly Airlines reservar vuelos, así como a los administradores de la aerolínea administrar los vuelos y las reservaciones.

## Descripción del avance 1
Se crearon las clases `Airport` y `Sorts`. La clase `Airport` tiene los atributos `name`, `city`, `country`, `IATA`, `latitude` y `longitude`. La clase `Sorts` tiene el método publico `sort`, que a través de un método privado `mergeSort` ordena un arreglo de objetos de la clase `Airport` por orden alfabético considerando el código IATA de cada aeropuerto. El método `mergeSort` es un método de ordenamiento merge sort que ordena un arreglo de objetos de la clase `Airport` por orden alfabético considerando el código IATA de cada aeropuerto. El método `merge` es un método auxiliar del método `mergeSort`.

## Descripción del avance 2
Se implementó la clase `Graph` y `CSVReader`. La clase `Graph` implementa la estructura de datos con la finalidad de crear una red de conexiones entre aeropuertos. La clase `CSVReader` es una clase que lee un archivo CSV y lo convierte en un vector de vectores de strings.

### Cambios sobre el primer avance
1. Creación de la clase `Graph`.
2. Creación de la clase `CSVReader`.
3. Modificación de la clase `Airport` para que tenga un atributo `connections` que es un vector de objetos de la clase `Airport`, además de metodos para agregar y eliminar conexiones con otros aeropuertos.

## Descripción del avance 3
Se implementó la estructura de lista ligada en la clase de `LinkedList`, la cual será útil para realizar algunas operaciones en los grafos. Por ejemplo: como una salida para el algoritmo de Dijkstra, para almacenar los aeropuertos que se visitan en el algoritmo de Dijkstra, etc.

### Cambios sobre el segundo avance
1. Creación de la clase `LinkedList`, con la clase `LLNode` como clase anidada.

## Entrega final
En esta versión del proyecto, se implementó la funcionalidad de que los usuarios puedan reservar vuelos, limitando que sólo se pueda reservar un vuelo a otro aeropuerto que tenga conexión con el aeropuerto de origen. Además, los vuelos se pueden guardar en un archivo CSV.

### Cambios sobre el tercer avance avance
1. Cambiar la clase `CSVReader` por la clase `HandleCSV`: Esto se hizo para que la clase `HandleCSV` sea más general y pueda leer y escribir archivos CSV.
2. Implementación de la funcionalidad de que los usuarios puedan reservar vuelos: En el archivo `main.cpp`, se implementó la funcionalidad de que los usuarios puedan reservar vuelos, limitando que sólo se pueda reservar un vuelo a otro aeropuerto que tenga conexión con el aeropuerto de origen. Además, los vuelos se pueden guardar en un archivo CSV.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

```{bash}
g++ main.cpp -o terrafly
./terrafly
```

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./terrafly` 

## Descripción de las entradas del avance de proyecto
El programa lee dos archivos CSV: `airports.csv` y `connections.csv`. El archivo `airports.csv` contiene información sobre los aeropuertos y el archivo `connections.csv` contiene información sobre las conexiones entre aeropuertos.

## Descripción de las salidas del avance de proyecto
Cuando el usuario reserva un vuelo, el programa imprime la información del vuelo reservado. Además, el programa guarda la información del vuelo reservado en un archivo CSV llamado `flights.csv`.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Considero que he desarrollado esta competencia porque he analizado la complejidad de los algoritmos de ordenamiento que he usado en el programa. Por ejemplo, en el caso del algoritmo de ordenamiento merge sort, he analizado su complejidad en el peor caso, en el mejor caso y en el caso promedio. siendo O(n log n) en el peor caso, O(n log n) en el mejor caso y O(n log n) en el caso promedio.
**NOTA:** El análisis de complejidad está en los comentarios de los headers correspondientes

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Considero que he desarrollado esta competencia porque he analizado la complejidad de las estructuras de datos que he usado en el programa y los métodos que he implementado para manipularlas.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Elegí el algoritmo de ordenamiento merge sort porque es un algoritmo de ordenamiento eficiente y estable. Además, es un algoritmo de ordenamiento recursivo, lo cual me permite practicar la recursividad.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Los grafos son una estructura de datos adecuada para representar redes y conexiones entre objetos. Por lo tanto, elegí usar grafos para representar las conexiones entre aeropuertos.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
La clase `Graph` contiene métodos para consultar información de las estructuras de manera correcta, por ejemplo, imprimir la información de los aeropuertos y las conexiones entre aeropuertos.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
La clase `CSVReader` contiene métodos para leer archivos CSV y cargar los datos a las estructuras de manera correcta.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
En el programa, se implementan mecanismos para consultar información de las estructuras de manera correcta. Por ejemplo, la clase `Graph` contiene métodos para consultar información de las estructuras de manera correcta, por ejemplo, imprimir la información de los aeropuertos y las conexiones entre aeropuertos. Además, se planea implementar el algoritmo de Dijkstra para encontrar la ruta más corta entre dos aeropuertos.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En el programa, se implementan mecanismos para leer archivos CSV y cargar los datos a las estructuras de manera correcta. Por ejemplo, la clase `CSVReader` contiene métodos para leer archivos CSV y cargar los datos a las estructuras de manera correcta.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
En el programa, se implementan mecanismos para guardar los datos de las estructuras de manera correcta. Por ejemplo, la clase `HandleCSV` contiene métodos para guardar los datos de las estructuras de manera correcta.