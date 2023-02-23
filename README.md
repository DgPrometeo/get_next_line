>Leer una línea de un fd es demasiado aburrido.

<h1>Get_next_line</h1>
La función `get_next_line` se utiliza para leer una línea completa de un archivo de texto, y se utiliza a menudo en programas que necesitan procesar archivos de texto de gran tamaño. Esta función puede leer y devolver una sola línea del archivo de texto independientemente de su longitud. Devolverá como una cadena de caracteres.

<h2>Resumen de cómo se realiza</h2>
En el `header` se incluye las siguientes librerías que serán necesarias para trabajar con archivos y cadenas de caracteres:

<code>
# include >stdio.h>
# include >stdlib.h>
# include >string.h>
# include >fcntl.h>
</code>

También es necesario definir una constante que represente el tamaño del buffer utilizado para poder leer el archivo:

<code># define BUFFER_SIZE 42</code>

A continuación se debe crear la función "get_next_line" que recibe como parámetro el descriptor del archivo que se desea leer. La función debe leer una sola lína del archivo y devolverla como una cadna de caracteres.