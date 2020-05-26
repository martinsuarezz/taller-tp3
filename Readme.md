# Informe TP3: Adivina el número

**Martín Andrés Suarez**

**Padrón: 101.540**

**Repositorio: `https://github.com/martinsuarezz/taller-tp3`**

--------------

## Modelo general

El trabajo dispone de dos ejecutables, el servidor y el cliente.

El cliente tiene un modelo bastante sencillo. La clase Client se encarga de la ejecución general del programa. Recibe por entrada estándar los comandos del usuario e imprime las respuestas del servidor. La comunicación de mensajes está delegada en un objeto Comunicador que se encarga de establecer conexión con el servidor, enviarle los comandos y recibir las respuestas.

El servidor posee una arquitectura más compleja basada en ejecución multihilo. El hilo principal se encarga de preparar todo el funcionamiento y luego se queda esperando el comando 'q' por entrada estándar para saber cuando cerrar las operaciones.

El hilo principal se encarga además de leer el archivo de números, mediante el objeto NumberList y pasarselo al objeto Acceptor.

El objeto Acceptor, que corre en otro hilo de ejecución, se encarga de coordinar las conexiones al servidor. Mantiene un socket seteado para escuchar conexiones entrantes y acepta a todos los clientes que intenten establecer conexión. Una vez que acepta un cliente, crea una clase ClientHandler, que también se ejecuta en otro hilo. Esta clase ClientHandler se comunica con el cliente y ejecuta la lógica general del juego.

El objeto Acceptor, mantiene referencias a los ClientHandler en ejecución, cerrando y eliminando a los que hayan finalizado, actualizando las estadísticas de ganadores y perdedores.

Cuando el servidor recibe la orden de cerrarse, le comunica al objeto Acceptor que no reciba más conexiones. Este espera que todos los clientes finalicen y luego termina su ejecución. De esta manera, el servidor puede cerrarse de manera ordenada cerrando todos los hilos de ejecución.

A continuación un diagrama de clases del modelo del cliente:

![Diagrama de Command](https://github.com/martinsuarezz/taller-tp3/blob/master/img/diagrama_clases2.png)

## Uso de polimorfismo en los comandos de ejecución

Para cumplir uno de los requisitos del trabajo práctico, hice uso de polimorfismo en la clase Command.

La clase abstracta Command, junto con las clases que heredan de esta, se utilizan en el servidor para modelar los distintos comandos que puede recibir del usuario.

Cuando el servidor recibe un comando se lo pasa al método de clase _Command::getCommand(vector[char] commndo)_. Este método devuelve un objeto que hereda de Command. Por ejemplo, si le paso el comando 'h', me va a devolver una instancia de HelpCommand(). De esta manera el objeto Command actúa también como una suerte de Factory.

Las clases que heredan de Command son: HelpCommand, SurrenderCommand, NumberCommand, LastNumberCommand.

Cada una de estos objetos al llamarlos con el operador (), devuelve la respuesta que se le debe enviar al cliente. Además, como mantienen referencias al ClientHandler pueden modificar su estado. Por ejemplo, la clase SurrenderCommand, obtenida cuando el cliente decide rendirse, le notifica al ClientHandler que el cliente ha perdido la partida.

Las clases NumberCommand y LastNumberCommand ejecutan la lógica del juego propiamente dicho.

![Diagrama de Command](https://github.com/martinsuarezz/taller-tp3/blob/master/img/diagrama_clases.png)
