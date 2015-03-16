############################################################################################
17 JULIO 2013 V 6.0.32
-Se introduce una nueva estrategia de marcaje: Componer. En esta estrategia se podr‡ ir introduciendo varios objetos incluyendo la posici—n de origen de cada objeto.
-Se introduce el marcaje de texto circular indicando radio, ‡ngulo de inicio y posici—n inicial.
-Se utiliza la se–al digital de salida de ExtractorEnable como se–al MarkInProgress para el l‡ser de fibra. La se–al habitual de markinprogress se est‡ empleando para realizar la activaci—n del booster del l‡ser de fibra.



###########################################################################################
11 JULIO 2013 v 6.0.31
-Se fuerza que los Datamatrix sean cuadrados. Puede forzarse que tengan tamaño fijo aunque no esta activo todavia
-Se incorpora el QR cambiando los ficheros de constantes y variables y siguiendo la misma
estrategia de lectura del bitmap generado para los Datamatrix.
-Se cambia ligeramente la forma del car‡cter G en la font rapida.
-Se introduce el car‡cter di‡metro en la font r‡pida.
-Se cambia la disposici—n de la pantalla de introducci—n de texto


############################################################################################
23 Junio 2013 v 6.0.30
-Se modifica la lectura del error al mandar la señal mip a la tarjeta NI. si da un error
se vuelve a enviar el comando.
-Ademas se incrementa el numero de errores consecutivos en la lectura de laser OK a 5
-Estos 2 cambios aumentan la robustez del sistema cuando se marca tuberia a alta velocidad
especialmente con laser de fibra. El sistema se paraba usando l‡ser de fibra cuando detectaba que la orden no hab’a sido bien recibida por la tarjeta NI. Lo mismo ocurr’a con un numero m‡ximo de 2 errores en la lectura de la se–al de l‡ser OK


############################################################################################
13 Mayo 2013 v 6.0.29
-Se vuelve a desactivar la actualizaci—n del fichero itaca.dat. Da problemas cuando se usa los botones de cambio de velocidad, guardar fichero y otros.

############################################################################################
9 Abril 2013 v 6.0.27
-Se introduce un control que resetea el contador cuando se produce un cambio de fecha.
La solicitud viene de Sanho para la instalación de Paper cups

############################################################################################
5 Abril 2013 v 6.0.26

-Se introduce un cambio para guardar los datos del fichero itaca.dat en la CF en todos los
casos, no solo cuando se apaga ordenadamente
-Se introduce un cálculo muy aproximado del factor de corrección empleando la correccion
pincushion y barril. La distorsión residual es pequeña aunque no se introducen todavia
ficheros de correccion ajustables.
-En el caso de emplear un láser de fibra se inicia el oscilador nada mas aceptar el marcaje.
Se introduce un retardo de 1 segundo para asegurarnos de que el oscilador esta en marcha
con tiempo suficiente
-En el caso de emplear un láser de fibra se para el oscilador al terminar prueba de marcaje,
campo o al presionar stop.


############################################################################################
10 Marzo 2013 v6.0.21

-Se introducen variables para seleccionar el tipo de laser: CO2 o fibra
-Se introducen variables para activar el fichero de correccion
-Se introduce en el fichero de configuracion la posibilidad de seleccionar el tipo de laser
empleado.
-Se soluciona el problema de llevar los galvos al origen cuando esta desactivada la opcion
de leer la posicion de los galvos.
-Se introducen varios cambios para realizar el control de los laseres de fibra: Manlight,
Quantel y Maxphotonics. Los cambios mas importantes son:
	Usamos la señal de activación de galvos para activar el oscilador del láser de fibra
	Iniciamos el tren de pulsos de manera constante desde la inicialización del laser
	Usamos la señal de activacion de laser durante la marca para encender/apagar el booster
	Usamos la señal de Enable del láser para pasarla por la seta y atacar el Emerg. Stop
	No podemos controlar la potencia del laser que se coloca fija al 90%


#############################################################################################
5/Junio/2012 v5.09

- Repetición de la matriz en horizontal y en vertical (Tabla), parametrizando tanto el número de
repeticiones como la separación entre ellas, para cada sentido 

- Precorte: se traza en el medio del campo, según el avance será horizontal o vertical;
el resto de la marca se desplaza a continuación del precorte, "desperdiciando" medio campo

- Las dos funciones anteriores se acceden con un botón nuevo de "Tabla-Precorte" debajo del de
Trabajos; el botón se puede ocultar con una nueva opción del itaca_protected_settings llamada
"8 - Table-Slitting". Si se desactiva la función de tabla-precorte se oculta el botón y no se realizan 
tablas ni precorte al calcular la matriz aunque hubieran estado definidos previamente. El estado
se guarda en el archivo tablaprecorte.bin. Si no existe el archivo se considera desactivada.

- BUG: puerto serie, se impide que se actualicen líneas (siempre bloque 1) que sean de tipo
gráfico

#############################################################################################
25/Mayo/2012 v5.08

- Botón de Reset del contador (petición de Trebol)

- Se dejan activadas por defecto las trazas del puerto serie, para poder ver los mensajes con
dmesg

- BUG: puerto serie (arreglado en Famosa); si un mensje al puerto serie quedaba cortado por
el timer del puerto serie se perdía el inicio de la línea; ahora el mensaje se reconstruye 
uniendo lo recibido en un periodo con lo recibido el periodo siguiente

- PENDIENTE: Edición de mensajes largos - visualización correcta, y posibilidad de modificar 
un mensaje en cualquier punto sin borrar lo anterior (no lo vamos a hacer ahora, sino con la
nueva versión de coder UNICODE + GTK)

#############################################################################################
22/Febrero/2012 v5.07

- Gestión de turnos: los tiempos y textos se modifican en configuración. Para introducir un turno
se utiliza un formato nuevo en el campo de hora

- Ahora sí: Optimización del interfaz del puerto paralelo: se minimizan los accesos al escribir
en los galvos y al leer las cuentas del encoder (ahora en 8 bits en lugar de 16 bits). Con 
el firmware v0.8.1 en la FPGA

- Se introduce un script de actualización completa que debe funcionar haciendo doble click en
konqueror a partir de la imagen v5.07 (porque se asocia la acción sh para ejecutar el archivo
en lugar de editarlo).

- También hay script de restauración desde directorios .old

- India: caracteres nuevos (rupia y logo ISI), 

- Cambios en el control de la posición. En la FPGA se ahorran las escrituras en los galvos
consecutivas del mismo valor; y se saca una traza si hay un salto en los galvos superior
a 0.1V

- Queda pendiente controlar el desplazamiento horizontal con la estrategia de fuera de campo

BUGS:
- los campos variables no se actualizaban correctamente en la línea 4 tras pulsar STOP
- al cambiar la velocidad constante no se actualizaba el widget informativo de arriba
- traza que quedaba en estrategia de fuera de campo, eliminada

#############################################################################################
24/Enero/2012 v5.06

- Se introducen dos opciones en la configuración para poder desactivar el
control de errores de campo y de galvos

#############################################################################################
12/Enero/2012 v5.05

- Se arreglan bugs diversos de la versión 5.04

- Se hace que el control por puerto serie pueda actualizar las 4 líneas de texto, aunque de
momento sólo en el primer bloque

- Se aumenta el valor absoluto del error de galvos de 500 a 2000!

#############################################################################################
10/Enero/2012 v5.04

- Se añade una cuarta línea de texto, para India y Korea (para que se pueda usar para el human
readable text en los códigos de barras). Para ello hay que reorganizar el interfaz principal,
los comandos del puerto serie, etc.

#############################################################################################
26/Diciembre/2011 v5.03

- Optimización del interfaz del puerto paralelo: se minimizan los accesos al escribir en los
galvos y al leer las cuentas del encoder (ahora en 8 bits en lugar de 16 bits). Ahora sí.

- Bloques de datos por línea y control por FPGA pendientes de realizar pruebas para completar
el desarrollo

#############################################################################################
5/Diciembre/2011 v5.02

- Optimización del interfaz del puerto paralelo: se minimizan los accesos al escribir en los
galvos y al leer las cuentas del encoder (ahora en 8 bits en lugar de 16 bits). No se completa...

#############################################################################################
11/Noviembre/2011 v5.0

- INTEGRACIÓN DE LAS VERSIONES DE CON COMEDI Y CON FPGA EN EL MISMO SW

- Revisión Validación

- Configuración: separación parámetros avanzados y de la instalación

- Scripts avanzados en inglés (itaca_protected_settings)

- Bugs varios

#############################################################################################
22/Julio/2011 v4.1

- Correcciones en la gestión de los trabajos: ventanas emergentes de confirmación para Cargar
y Guardar trabajos; cada vez que se carga la ventana de trabajos se vacía el campo de texto 
con el nombre, para tener que hacer explícito el trabajo cuando se quiera cargar o guardar; se 
elimina la "Ñ" del teclado en la ventana de trabajos, porque el sistema de archivos no permite
archivos con esa letra

- Red: por defecto se habilita sólo eth1. Si se quieren habilitar eth0 hay que hacer
rc-update add net.eth0 default; la configuración de los interfaces (IPs, gw, etc.) 
está en /etc/conf.d/net.

- Se cambian algunos parámetros del arranque en /etc/conf.d/rc, para que arranque más rápido

#############################################################################################
15/Julio/2011 v4.0

- Se introduce la validación del SW contra el HW: se convierten las MAC del ordenador en números
hexadecimales (quitando los ":") y se aplica: eth0 * 0x28660 + eth1; el resultado debe ser igual
que el número en /etc/conf.d/itaca; si no lo es se pone el led de estado en rojo con el
mensaje de "Validación" y se desactiva permanentemente el botón de Marcar

#############################################################################################
11/Abril/2011 v3.0

- Estrategias de marcaje: Carácter (normal), Átomos y Fuera de Campo (por átomos también); se
pueden cambiar en la configuración

- En la estrategia de fuera de campo se pueden mandar textos más largos que el campo (hasta
255 caracteres) siempre que se desplacen en el sentido del avance

- En la pantalla de modificación de texto se hace más alto el widget de la línea para poder
mostrar textos más largos (la solución definitiva fetén será cambiar el widget de Output
Multilínea por un widget de Text Output, de forma que pueda aparecer una barra de scroll 
cuando sea necesario; pero eso afecta también a los widgets del teclado, ProcesarCaracter
y CargarTexto - un lío razonable)
 
- Los átomos se ordenan (en Átomos y Fuera de Campo) primiero por el criterio de los que salen
del campo, y luego en orden de forma que se minimmicen los saltos aleatorios

- El desplazamiento horizontal/vertical se suma/resta al retardo, según corresponda, en la
estrategia de Fuera de Campo

- Se añaden los campos de Calibración Encoder, Velocidad Constante, Retardo y Separación entre
Disparos en la pantalla principal, cuando está activado el servicio técnico

- PENDIENTES:
Presentación campos largos en pantalla de modificar texto, con widget de texto en lugar de output
y barras de scr
Trabajos: cuando no hay ninguno inhabilitar el botón de Cargar


#############################################################################################
#############################################################################################
#############################################################################################
25/Febrero/2011 v2.15

- Reordenación y optimización de matrices: se calculan los átomos (estructuras PU PD ... PD) 
de la matriz y se reordenan de forma que se hagan los que están más próximos a salir del
campo en todos los casos

- Se arregla un bug por el que los cambios online en la velocidad de marcaje no tenían efecto

- PLATAFORMA: se hace e2fsck sobre /dev/sda1 (arreglando los problemas que daba) y /dev/sdb2
poniéndoles las etiquetas "boot" e "itaca" respectivamente, para que al transferir la imagen
a una llave usb se monte (la llave usb) como /media/boot y /media/itaca, y poder hacer 
backup/restore; se crea el ejecutable /usr/local/bin/SetBackup para poder realizar backup
o restore a/desde /media/itaca/rootFLS (sólo funcionará con una llave usb con la imagen del 
sistema o, en sudefecto, un directorio /rootFLS/itaca creado); el restore sólo se consolidará
(copiado a /rootFLS/itaca) cuando se haga el apagado ordenado, si no habrá que volver a hacerlo

También se crea un script SetItaca_usb.sh (junto a los cambios de splash correspondientes) 
para poder adaptar la imagen de una llave USB, es decir, el proceso para hacer una llave USB
arrancable es hacer dd de la imagen, arrancar con la USB y ejecutar el script

Se hace un pequeño cambio en la splash de arranque para que se vea mejor la barra de progreso

#############################################################################################
15/Febrero/2011 v2.14

Se arreglan varios temas relacionados con PLTs:

- Se corrige elmensaje de error cuando un plt no tiene más que una dimensión (Xmax=Xmin=0 o 
Ymax=Ymin=0) para que en lugar de decir "marca fuera de límites" diga "Archivo PLT incorrecto" 

- También es un PLT incorrecto el que no empieza con PU y luego PD en los dos primeros vectores

- Se incorpora el proceso de PLTs de Scaps, Autocad 9 y AB Viewer

- Se cambia el proceso de PLTs de forma que se procese la expresión PA y estos PLTs sean válidos

- Se optimiza el proceso de PLTs para evitar redundancias: coordenadas repetidas, etc.

#############################################################################################
3/Febrero/2011 v2.13

- Se arregla un bug en Inicializar_Marcaje: al calcular las constantes Kx_Cuentas_a_Bits y
Ky_Cuentas_a_Bits se utilizaba siempre la calibración del encoder, cuando en el caso de 
velocidad constante hay que usar siempre el factor 25.0 como calibración del encoder

- Al introducir la opción de reverso la reordenación de la matriz (al final de CalcularMatriz)
para empezar por el final se realiza en los siguientes casos:
// Si las letras están pegadas a la izquierda porque "avanzan" hacia la derecha y no hay reverso,
// o están pegadas a la derecha porque "avanzan" hacia la izquierda y sí hay reverso
// o están pegadas arriba porque "avanzan" hacia abajo

Antes no se tenía en cuenta el estado de la opción de Reverso para la optimización

- Se elimina la referencia al número de versión en el GUI del programa de configuración para
no tener que actualizarlo cada vez que se cambie de versión del Itaca

#############################################################################################
17/Enero/2011 v2.12

- Cambios en el font RAPIDA: se añade una línea horizontal en la base del "1", y se acorta la
longitud del guión en un 30%

- Protección por contraseña: en el programa de configuración se pide al aceptar los cambios
para evitar tener que rehacer los cambios tras meter la contraseña; los botones de importar
gráficos y cambiar fecha/hora quedan sin protección por contraseña. El programa Ítaca se
queda como estaba (hay que volver a hacer cualquier cambio tras introducir la contraseña)

- Impresión "en espejo" (para imprimir materiales por detrás), se activa en configuración

- Límite de archivos PLT para impedir que el programa salga de mala manera, e información
al usuario cuando el fichero es demasiado grande. Constante en constantes.h, fijada a 
30.000 líneas válidas (que empiecen por PU o PD) como mucho

- Control de disparos "espúreos": si está el marcaje dinámico activado y hay 10 disparos sin
movimiento del encoder se detiene la marcación - se supone que es fallo del encoder y se 
muestra en el botón con una alarma que hay que reconocer en el Led de estado para volver a 
armar el sistema

- Cambios de la marca "online": si el servicio técnico está arrancado se pueden cambiar 
todas las características de la marca -excepto el contenido de las líneas y la fuente- mientras el
sistema está marcando; Comentarios: dentro de una marca no hay cambios, los vectores ya
están calculados, las diferencias son entre marcas; por lo mismo no tiene sentido variar
los parámetros dentro de una prueba de marcaje; los cambios se notarán dentro de 2 marcas,
ya que la siguiente ya está calculada...

- La velocidad de marcaje cambia de 100 en 100 por encima de 500, y de 25 en 25 por debajo,
hasta 25 de mínimo

- Se sube el máximo de la velocidad de salto de 20.000 a 50.000 mm/s

#############################################################################################
14/Septiembre/2010 v2.11

- La potencia mínima se limita a 1% en lugar de al 0%, ya que este último no funcionaba y 
salía el 100% de potencia

- Disparo interno: se arregla, no funcionaba bien la separación entre disparos porque la línea
del archivo de configuración de la separación era más larga que el array de lectura (100); 
subiendo el array de lectura a [255] se ha arreglado el problema

#############################################################################################
30/Junio/2010 v2.10

- Si se quedaba el flag de desarrollo el programa hacía una segmentation fault al apagar, y
por tanto no se apagaba el sistema - arreglado

- Las contraseñas (Itaca y Config) se leen de un archivo binario, y se pueden cambiar con 
el script SetPasswords (con la contraseña 3gl0ria6); si no existen estos archivos funcionan
las contraseñas por defecto

- En la imagen por defecto se desactivan las contraseñas

- Se elimina el Modo Normal/Carácter del programa de configuración (se hará más adelante una
optimización de la matriz siempre activa)

- La funcionalidad se guarda ahora en funcionalidad.bin en lugar de itaca.bin

- Se edita /etc/conf.d/local.start para poner & al final de la última línea y evitar así los
caracteres raros al arrancar las X

#############################################################################################
2/Junio/2010 v2.9

- Introducidos los niveles de acceso: se gestionan con el programa SetAcceso (3gl0ria6)
La contraseña de supervisor en el programa es 3687, y 1489 la de administrador en el programa
de configuración. Tras activar los cambios de supervisor el control de acceso se reactiva por
su cuenta a los 2 minutos

- Optimización: se reordena la matriz al calcularla para empezar siempre por la zona que va
a salir antes del campo, es decir, por el final de las líneas o por la tercera línea, cuando
toque, según sea la relación entre configuración y avance

- Integración disparo interno

- Cambios en el programa de configuración: disparo interno, nueva disposición de elementos, etc

- Se arregla un bug en CalcularMatriz, para líneas con una única letra "I"

#############################################################################################
13/Mayo/2010 v2.8

- Se corrige un bug en los plts que provocaba que al cambiar de archivo plt la aplicación 
cascara de vez en cuando

- Se aumenta el número máximo de líneas de archivos plt de 3.000 a 30.000 para poder procesar 
archivos plt grandes (provocaba un cascotazo)

- Se corrige un bug: cuando se define un retardo en mm tras el disparo de la fotocélula se 
pierde la primera marca (en realidad se hace sin retardo): ya no, ahora va todo bien

#############################################################################################
23/Abril/2010 v2.7

- Se introduce el número de lecturas consecutivas del nivel de disparo en configuración; a partir
de ese número de lecturas se considera que ha habido un disparo, si no no (filtro SW)

- Arreglado el chasquido en Campo y Prueba de Marcaje, obteniendo la posición antes

- El arranque del sistema es más rápido (ya no para casi en el 20%) porque se han borrado
archivos innecesarios de /rootFLS y /varFLS que se copiaban en el arranque

#############################################################################################
20/Abril/2010 v2.6

- Eliminado font lineas (queda sólo para dcm, en itaca_v2.5.dcm)

- Cambios traducción italiano, en itaca y config

- Cambios programa configuración: flechas dobles en los contadores, activar o no widgets de
marcación dinámica en función del estado seleccionado

- Retardo desde el disparo de la marca, en distancia (mm) añadido al programa de configuración
y al ejecutable itaca_*

#############################################################################################
11/Marzo/2010 v2.5

- Terminado en DCM para el funcionamiento correcto de todos los casos de comunicación por puerto
serie, con su autómata; el perido de lectura del puerto serie pasa a ser 200ms para leer
siempre bien los comandos (si era mayor a veces se mezclaban). Hecho el 2/3/2010

- El control del sistema mediante el puerto serie provoca cambios en la gestión de threads:
la lectura del puerto serie se hace con un thread de Fltk (Fl::add_timeout Fl::repeat_timeout)
y el control de ejecución de listas también (Fl::add_timeout en StartEjecucion y 
Fl::remove_timeout en StopEjecucion)

- Se crea una variable de Control por el puerto serie que se incorpora al archivo de configuración, 
aunque no es modificable todavía con la herramienta de configuración, sino editando el archivo

- Se modifica la rutina de salida ExitOrdenadamente para que se apague el ordenador también cuando
hay un error de DAQ (antes hacía un segmentation fault y al no terminar bien no llegeba al init 0
en el script de arranque)

- Se modifica una regla udev para que la red eth1 funcione siempre bien, en el conector de arriba
y con la dirección 192.168.0.1 (antes dependía de la mac y se renombraba a ethX)

- Se modifica la llamada a servidor VNC para arrancarlo con el kde (.kde/Autostart/start) en lugar
de cada vez que se iniciaba el Ítaca; se arranca con una opción que evita que se apague (-forever)
y forzando siempre el puerto 5900 (-rfbport 5900)

- Se escribe la partición /dev/sda1 tomando la de la imagen del multiscan, porque la del Ítaca tenía
un extraño error que no permitía que se montara; ahora va todo bien

#############################################################################################
9/Febrero/2010 v2.4s

- Se incorpora el control del sistema mediante el puerto serie, de una forma muy limitada, 
para el proyecto de 50 láseres en Valencia (versión preliminar)

#############################################################################################
18/Enero/2010 v2.4

- Se incluye un nuevo script, SetFuncionalidad (en versión .c y .fl, porque al principio no
conseguía que funcionara la primera, aunque finalmente sí), para poder cambiar entre 
funcionalidad Sólo texto y Completa (más códigos de barras y gráficos). La contraseña
para realizar cambios es "3y0landa6" (sin comillas); el mecanismo se basa en el archivo
binario itaca.bin (ver detalles en el código)

- Se saca el valor de activación de los galvos al archivo de configuración itaca.conf para
que se pueda adaptar el sistema a los galvos CTI

#############################################################################################
13/Enero/2010 v2.3.2

- Códigos de barras, gráficos plt, etc. primera versión completa

- En el programa de configuración se incluye un botón para importar gráficos plt
que estén en la raíz de dispositivos usb conectados

- Se hacen más sólidas las lecturas de archivos: si algo falla se copian de /rootFLS y con
volver a iniciar el programa debe funcionar correctamente

#############################################################################################
10/Diciembre/2009 v2.1

- Códigos de barras en memoria basados en bitmaps en lugar de archivos svg, para resolver
la inversión de códigos

- Problema de marcaje a baja velocidad:

#############################################################################################
4/Diciembre/2009 v2.0.2

- Códigos de barras

- Desactivado el control de errores de galvos

#############################################################################################
2/Diciembre/2009 v2.0.1 - feria Aipimifa

- Códigos de barras con tipos de línea activados sólo en Servicio Técnico

#############################################################################################
15/Noviembre/2009 v2.0 - feria empack

- Códigos de barras, versión básica


#############################################################################################
25/Octubre/2009 v1.9 - enviada a Italia

- Corrección de numerosos bugs relacionados con los campos variables

#############################################################################################
1/Octubre/2009 v1.7

- Internacionalización: español, inglés, italiano

- Arranca aunque no haya DAQ (ya no hace segmentation fault)

- Formatos de fecha, hora, serie no predefinidos, sino codificados

- Se pueden meter todos los campos calculados que se quiera (dos fechas, por ejemplo)

- Aplicación para el cambio de hora del sistema

- Aplicación para la gestión del archivo de configuración

#############################################################################################
16/Julio/2009 v1.6.1

- Se aumenta el tamaño máximo de los caracteres a 25 mm

- Se incluye un nuevo formato de fecha: SSD, que codifica la semana del año (01-53) y el día
de la semana (1-7)

#############################################################################################
8/Julio/2009 v1.6

- Números de serie: se define un número final, se formatea al número de dígitos introducido,
se visualiza y modifica el número de unidad dentro del lote; sólo se permite reiniciar la 
serie o cambiar el número actual en el lote si se está editando la línea que tiene el número
de serie; se corrigen bugs relacionados con el mantenimiento de la secuencia

- Se corrige el bug al cambiar la velocidad sin texto definido en las líneas: ya no se 
recalcula la matriz

- Se fuerza la restauración del cursor en forma de flecha (default) al volver de la ventana 
de modificación del texto

- Se modifican los fonts de campos variables a terminal en lugar de times

#############################################################################################
18/Noviembre/2008 v1.0

- Versión 1.0 del codificador Ítaca
