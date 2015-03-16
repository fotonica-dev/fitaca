############################################################################################
17 JULIO 2013 V 6.0.32
-Se introduce una nueva estrategia de marcaje: Componer. En esta estrategia se podr� ir introduciendo varios objetos incluyendo la posici�n de origen de cada objeto.
-Se introduce el marcaje de texto circular indicando radio, �ngulo de inicio y posici�n inicial.
-Se utiliza la se�al digital de salida de ExtractorEnable como se�al MarkInProgress para el l�ser de fibra. La se�al habitual de markinprogress se est� empleando para realizar la activaci�n del booster del l�ser de fibra.



###########################################################################################
11 JULIO 2013 v 6.0.31
-Se fuerza que los Datamatrix sean cuadrados. Puede forzarse que tengan tama�o fijo aunque no esta activo todavia
-Se incorpora el QR cambiando los ficheros de constantes y variables y siguiendo la misma
estrategia de lectura del bitmap generado para los Datamatrix.
-Se cambia ligeramente la forma del car�cter G en la font rapida.
-Se introduce el car�cter di�metro en la font r�pida.
-Se cambia la disposici�n de la pantalla de introducci�n de texto


############################################################################################
23 Junio 2013 v 6.0.30
-Se modifica la lectura del error al mandar la se�al mip a la tarjeta NI. si da un error
se vuelve a enviar el comando.
-Ademas se incrementa el numero de errores consecutivos en la lectura de laser OK a 5
-Estos 2 cambios aumentan la robustez del sistema cuando se marca tuberia a alta velocidad
especialmente con laser de fibra. El sistema se paraba usando l�ser de fibra cuando detectaba que la orden no hab�a sido bien recibida por la tarjeta NI. Lo mismo ocurr�a con un numero m�ximo de 2 errores en la lectura de la se�al de l�ser OK


############################################################################################
13 Mayo 2013 v 6.0.29
-Se vuelve a desactivar la actualizaci�n del fichero itaca.dat. Da problemas cuando se usa los botones de cambio de velocidad, guardar fichero y otros.

############################################################################################
9 Abril 2013 v 6.0.27
-Se introduce un control que resetea el contador cuando se produce un cambio de fecha.
La solicitud viene de Sanho para la instalaci�n de Paper cups

############################################################################################
5 Abril 2013 v 6.0.26

-Se introduce un cambio para guardar los datos del fichero itaca.dat en la CF en todos los
casos, no solo cuando se apaga ordenadamente
-Se introduce un c�lculo muy aproximado del factor de correcci�n empleando la correccion
pincushion y barril. La distorsi�n residual es peque�a aunque no se introducen todavia
ficheros de correccion ajustables.
-En el caso de emplear un l�ser de fibra se inicia el oscilador nada mas aceptar el marcaje.
Se introduce un retardo de 1 segundo para asegurarnos de que el oscilador esta en marcha
con tiempo suficiente
-En el caso de emplear un l�ser de fibra se para el oscilador al terminar prueba de marcaje,
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
	Usamos la se�al de activaci�n de galvos para activar el oscilador del l�ser de fibra
	Iniciamos el tren de pulsos de manera constante desde la inicializaci�n del laser
	Usamos la se�al de activacion de laser durante la marca para encender/apagar el booster
	Usamos la se�al de Enable del l�ser para pasarla por la seta y atacar el Emerg. Stop
	No podemos controlar la potencia del laser que se coloca fija al 90%


#############################################################################################
5/Junio/2012 v5.09

- Repetici�n de la matriz en horizontal y en vertical (Tabla), parametrizando tanto el n�mero de
repeticiones como la separaci�n entre ellas, para cada sentido 

- Precorte: se traza en el medio del campo, seg�n el avance ser� horizontal o vertical;
el resto de la marca se desplaza a continuaci�n del precorte, "desperdiciando" medio campo

- Las dos funciones anteriores se acceden con un bot�n nuevo de "Tabla-Precorte" debajo del de
Trabajos; el bot�n se puede ocultar con una nueva opci�n del itaca_protected_settings llamada
"8 - Table-Slitting". Si se desactiva la funci�n de tabla-precorte se oculta el bot�n y no se realizan 
tablas ni precorte al calcular la matriz aunque hubieran estado definidos previamente. El estado
se guarda en el archivo tablaprecorte.bin. Si no existe el archivo se considera desactivada.

- BUG: puerto serie, se impide que se actualicen l�neas (siempre bloque 1) que sean de tipo
gr�fico

#############################################################################################
25/Mayo/2012 v5.08

- Bot�n de Reset del contador (petici�n de Trebol)

- Se dejan activadas por defecto las trazas del puerto serie, para poder ver los mensajes con
dmesg

- BUG: puerto serie (arreglado en Famosa); si un mensje al puerto serie quedaba cortado por
el timer del puerto serie se perd�a el inicio de la l�nea; ahora el mensaje se reconstruye 
uniendo lo recibido en un periodo con lo recibido el periodo siguiente

- PENDIENTE: Edici�n de mensajes largos - visualizaci�n correcta, y posibilidad de modificar 
un mensaje en cualquier punto sin borrar lo anterior (no lo vamos a hacer ahora, sino con la
nueva versi�n de coder UNICODE + GTK)

#############################################################################################
22/Febrero/2012 v5.07

- Gesti�n de turnos: los tiempos y textos se modifican en configuraci�n. Para introducir un turno
se utiliza un formato nuevo en el campo de hora

- Ahora s�: Optimizaci�n del interfaz del puerto paralelo: se minimizan los accesos al escribir
en los galvos y al leer las cuentas del encoder (ahora en 8 bits en lugar de 16 bits). Con 
el firmware v0.8.1 en la FPGA

- Se introduce un script de actualizaci�n completa que debe funcionar haciendo doble click en
konqueror a partir de la imagen v5.07 (porque se asocia la acci�n sh para ejecutar el archivo
en lugar de editarlo).

- Tambi�n hay script de restauraci�n desde directorios .old

- India: caracteres nuevos (rupia y logo ISI), 

- Cambios en el control de la posici�n. En la FPGA se ahorran las escrituras en los galvos
consecutivas del mismo valor; y se saca una traza si hay un salto en los galvos superior
a 0.1V

- Queda pendiente controlar el desplazamiento horizontal con la estrategia de fuera de campo

BUGS:
- los campos variables no se actualizaban correctamente en la l�nea 4 tras pulsar STOP
- al cambiar la velocidad constante no se actualizaba el widget informativo de arriba
- traza que quedaba en estrategia de fuera de campo, eliminada

#############################################################################################
24/Enero/2012 v5.06

- Se introducen dos opciones en la configuraci�n para poder desactivar el
control de errores de campo y de galvos

#############################################################################################
12/Enero/2012 v5.05

- Se arreglan bugs diversos de la versi�n 5.04

- Se hace que el control por puerto serie pueda actualizar las 4 l�neas de texto, aunque de
momento s�lo en el primer bloque

- Se aumenta el valor absoluto del error de galvos de 500 a 2000!

#############################################################################################
10/Enero/2012 v5.04

- Se a�ade una cuarta l�nea de texto, para India y Korea (para que se pueda usar para el human
readable text en los c�digos de barras). Para ello hay que reorganizar el interfaz principal,
los comandos del puerto serie, etc.

#############################################################################################
26/Diciembre/2011 v5.03

- Optimizaci�n del interfaz del puerto paralelo: se minimizan los accesos al escribir en los
galvos y al leer las cuentas del encoder (ahora en 8 bits en lugar de 16 bits). Ahora s�.

- Bloques de datos por l�nea y control por FPGA pendientes de realizar pruebas para completar
el desarrollo

#############################################################################################
5/Diciembre/2011 v5.02

- Optimizaci�n del interfaz del puerto paralelo: se minimizan los accesos al escribir en los
galvos y al leer las cuentas del encoder (ahora en 8 bits en lugar de 16 bits). No se completa...

#############################################################################################
11/Noviembre/2011 v5.0

- INTEGRACI�N DE LAS VERSIONES DE CON COMEDI Y CON FPGA EN EL MISMO SW

- Revisi�n Validaci�n

- Configuraci�n: separaci�n par�metros avanzados y de la instalaci�n

- Scripts avanzados en ingl�s (itaca_protected_settings)

- Bugs varios

#############################################################################################
22/Julio/2011 v4.1

- Correcciones en la gesti�n de los trabajos: ventanas emergentes de confirmaci�n para Cargar
y Guardar trabajos; cada vez que se carga la ventana de trabajos se vac�a el campo de texto 
con el nombre, para tener que hacer expl�cito el trabajo cuando se quiera cargar o guardar; se 
elimina la "�" del teclado en la ventana de trabajos, porque el sistema de archivos no permite
archivos con esa letra

- Red: por defecto se habilita s�lo eth1. Si se quieren habilitar eth0 hay que hacer
rc-update add net.eth0 default; la configuraci�n de los interfaces (IPs, gw, etc.) 
est� en /etc/conf.d/net.

- Se cambian algunos par�metros del arranque en /etc/conf.d/rc, para que arranque m�s r�pido

#############################################################################################
15/Julio/2011 v4.0

- Se introduce la validaci�n del SW contra el HW: se convierten las MAC del ordenador en n�meros
hexadecimales (quitando los ":") y se aplica: eth0 * 0x28660 + eth1; el resultado debe ser igual
que el n�mero en /etc/conf.d/itaca; si no lo es se pone el led de estado en rojo con el
mensaje de "Validaci�n" y se desactiva permanentemente el bot�n de Marcar

#############################################################################################
11/Abril/2011 v3.0

- Estrategias de marcaje: Car�cter (normal), �tomos y Fuera de Campo (por �tomos tambi�n); se
pueden cambiar en la configuraci�n

- En la estrategia de fuera de campo se pueden mandar textos m�s largos que el campo (hasta
255 caracteres) siempre que se desplacen en el sentido del avance

- En la pantalla de modificaci�n de texto se hace m�s alto el widget de la l�nea para poder
mostrar textos m�s largos (la soluci�n definitiva fet�n ser� cambiar el widget de Output
Multil�nea por un widget de Text Output, de forma que pueda aparecer una barra de scroll 
cuando sea necesario; pero eso afecta tambi�n a los widgets del teclado, ProcesarCaracter
y CargarTexto - un l�o razonable)
 
- Los �tomos se ordenan (en �tomos y Fuera de Campo) primiero por el criterio de los que salen
del campo, y luego en orden de forma que se minimmicen los saltos aleatorios

- El desplazamiento horizontal/vertical se suma/resta al retardo, seg�n corresponda, en la
estrategia de Fuera de Campo

- Se a�aden los campos de Calibraci�n Encoder, Velocidad Constante, Retardo y Separaci�n entre
Disparos en la pantalla principal, cuando est� activado el servicio t�cnico

- PENDIENTES:
Presentaci�n campos largos en pantalla de modificar texto, con widget de texto en lugar de output
y barras de scr
Trabajos: cuando no hay ninguno inhabilitar el bot�n de Cargar


#############################################################################################
#############################################################################################
#############################################################################################
25/Febrero/2011 v2.15

- Reordenaci�n y optimizaci�n de matrices: se calculan los �tomos (estructuras PU PD ... PD) 
de la matriz y se reordenan de forma que se hagan los que est�n m�s pr�ximos a salir del
campo en todos los casos

- Se arregla un bug por el que los cambios online en la velocidad de marcaje no ten�an efecto

- PLATAFORMA: se hace e2fsck sobre /dev/sda1 (arreglando los problemas que daba) y /dev/sdb2
poni�ndoles las etiquetas "boot" e "itaca" respectivamente, para que al transferir la imagen
a una llave usb se monte (la llave usb) como /media/boot y /media/itaca, y poder hacer 
backup/restore; se crea el ejecutable /usr/local/bin/SetBackup para poder realizar backup
o restore a/desde /media/itaca/rootFLS (s�lo funcionar� con una llave usb con la imagen del 
sistema o, en sudefecto, un directorio /rootFLS/itaca creado); el restore s�lo se consolidar�
(copiado a /rootFLS/itaca) cuando se haga el apagado ordenado, si no habr� que volver a hacerlo

Tambi�n se crea un script SetItaca_usb.sh (junto a los cambios de splash correspondientes) 
para poder adaptar la imagen de una llave USB, es decir, el proceso para hacer una llave USB
arrancable es hacer dd de la imagen, arrancar con la USB y ejecutar el script

Se hace un peque�o cambio en la splash de arranque para que se vea mejor la barra de progreso

#############################################################################################
15/Febrero/2011 v2.14

Se arreglan varios temas relacionados con PLTs:

- Se corrige elmensaje de error cuando un plt no tiene m�s que una dimensi�n (Xmax=Xmin=0 o 
Ymax=Ymin=0) para que en lugar de decir "marca fuera de l�mites" diga "Archivo PLT incorrecto" 

- Tambi�n es un PLT incorrecto el que no empieza con PU y luego PD en los dos primeros vectores

- Se incorpora el proceso de PLTs de Scaps, Autocad 9 y AB Viewer

- Se cambia el proceso de PLTs de forma que se procese la expresi�n PA y estos PLTs sean v�lidos

- Se optimiza el proceso de PLTs para evitar redundancias: coordenadas repetidas, etc.

#############################################################################################
3/Febrero/2011 v2.13

- Se arregla un bug en Inicializar_Marcaje: al calcular las constantes Kx_Cuentas_a_Bits y
Ky_Cuentas_a_Bits se utilizaba siempre la calibraci�n del encoder, cuando en el caso de 
velocidad constante hay que usar siempre el factor 25.0 como calibraci�n del encoder

- Al introducir la opci�n de reverso la reordenaci�n de la matriz (al final de CalcularMatriz)
para empezar por el final se realiza en los siguientes casos:
// Si las letras est�n pegadas a la izquierda porque "avanzan" hacia la derecha y no hay reverso,
// o est�n pegadas a la derecha porque "avanzan" hacia la izquierda y s� hay reverso
// o est�n pegadas arriba porque "avanzan" hacia abajo

Antes no se ten�a en cuenta el estado de la opci�n de Reverso para la optimizaci�n

- Se elimina la referencia al n�mero de versi�n en el GUI del programa de configuraci�n para
no tener que actualizarlo cada vez que se cambie de versi�n del Itaca

#############################################################################################
17/Enero/2011 v2.12

- Cambios en el font RAPIDA: se a�ade una l�nea horizontal en la base del "1", y se acorta la
longitud del gui�n en un 30%

- Protecci�n por contrase�a: en el programa de configuraci�n se pide al aceptar los cambios
para evitar tener que rehacer los cambios tras meter la contrase�a; los botones de importar
gr�ficos y cambiar fecha/hora quedan sin protecci�n por contrase�a. El programa �taca se
queda como estaba (hay que volver a hacer cualquier cambio tras introducir la contrase�a)

- Impresi�n "en espejo" (para imprimir materiales por detr�s), se activa en configuraci�n

- L�mite de archivos PLT para impedir que el programa salga de mala manera, e informaci�n
al usuario cuando el fichero es demasiado grande. Constante en constantes.h, fijada a 
30.000 l�neas v�lidas (que empiecen por PU o PD) como mucho

- Control de disparos "esp�reos": si est� el marcaje din�mico activado y hay 10 disparos sin
movimiento del encoder se detiene la marcaci�n - se supone que es fallo del encoder y se 
muestra en el bot�n con una alarma que hay que reconocer en el Led de estado para volver a 
armar el sistema

- Cambios de la marca "online": si el servicio t�cnico est� arrancado se pueden cambiar 
todas las caracter�sticas de la marca -excepto el contenido de las l�neas y la fuente- mientras el
sistema est� marcando; Comentarios: dentro de una marca no hay cambios, los vectores ya
est�n calculados, las diferencias son entre marcas; por lo mismo no tiene sentido variar
los par�metros dentro de una prueba de marcaje; los cambios se notar�n dentro de 2 marcas,
ya que la siguiente ya est� calculada...

- La velocidad de marcaje cambia de 100 en 100 por encima de 500, y de 25 en 25 por debajo,
hasta 25 de m�nimo

- Se sube el m�ximo de la velocidad de salto de 20.000 a 50.000 mm/s

#############################################################################################
14/Septiembre/2010 v2.11

- La potencia m�nima se limita a 1% en lugar de al 0%, ya que este �ltimo no funcionaba y 
sal�a el 100% de potencia

- Disparo interno: se arregla, no funcionaba bien la separaci�n entre disparos porque la l�nea
del archivo de configuraci�n de la separaci�n era m�s larga que el array de lectura (100); 
subiendo el array de lectura a [255] se ha arreglado el problema

#############################################################################################
30/Junio/2010 v2.10

- Si se quedaba el flag de desarrollo el programa hac�a una segmentation fault al apagar, y
por tanto no se apagaba el sistema - arreglado

- Las contrase�as (Itaca y Config) se leen de un archivo binario, y se pueden cambiar con 
el script SetPasswords (con la contrase�a 3gl0ria6); si no existen estos archivos funcionan
las contrase�as por defecto

- En la imagen por defecto se desactivan las contrase�as

- Se elimina el Modo Normal/Car�cter del programa de configuraci�n (se har� m�s adelante una
optimizaci�n de la matriz siempre activa)

- La funcionalidad se guarda ahora en funcionalidad.bin en lugar de itaca.bin

- Se edita /etc/conf.d/local.start para poner & al final de la �ltima l�nea y evitar as� los
caracteres raros al arrancar las X

#############################################################################################
2/Junio/2010 v2.9

- Introducidos los niveles de acceso: se gestionan con el programa SetAcceso (3gl0ria6)
La contrase�a de supervisor en el programa es 3687, y 1489 la de administrador en el programa
de configuraci�n. Tras activar los cambios de supervisor el control de acceso se reactiva por
su cuenta a los 2 minutos

- Optimizaci�n: se reordena la matriz al calcularla para empezar siempre por la zona que va
a salir antes del campo, es decir, por el final de las l�neas o por la tercera l�nea, cuando
toque, seg�n sea la relaci�n entre configuraci�n y avance

- Integraci�n disparo interno

- Cambios en el programa de configuraci�n: disparo interno, nueva disposici�n de elementos, etc

- Se arregla un bug en CalcularMatriz, para l�neas con una �nica letra "I"

#############################################################################################
13/Mayo/2010 v2.8

- Se corrige un bug en los plts que provocaba que al cambiar de archivo plt la aplicaci�n 
cascara de vez en cuando

- Se aumenta el n�mero m�ximo de l�neas de archivos plt de 3.000 a 30.000 para poder procesar 
archivos plt grandes (provocaba un cascotazo)

- Se corrige un bug: cuando se define un retardo en mm tras el disparo de la fotoc�lula se 
pierde la primera marca (en realidad se hace sin retardo): ya no, ahora va todo bien

#############################################################################################
23/Abril/2010 v2.7

- Se introduce el n�mero de lecturas consecutivas del nivel de disparo en configuraci�n; a partir
de ese n�mero de lecturas se considera que ha habido un disparo, si no no (filtro SW)

- Arreglado el chasquido en Campo y Prueba de Marcaje, obteniendo la posici�n antes

- El arranque del sistema es m�s r�pido (ya no para casi en el 20%) porque se han borrado
archivos innecesarios de /rootFLS y /varFLS que se copiaban en el arranque

#############################################################################################
20/Abril/2010 v2.6

- Eliminado font lineas (queda s�lo para dcm, en itaca_v2.5.dcm)

- Cambios traducci�n italiano, en itaca y config

- Cambios programa configuraci�n: flechas dobles en los contadores, activar o no widgets de
marcaci�n din�mica en funci�n del estado seleccionado

- Retardo desde el disparo de la marca, en distancia (mm) a�adido al programa de configuraci�n
y al ejecutable itaca_*

#############################################################################################
11/Marzo/2010 v2.5

- Terminado en DCM para el funcionamiento correcto de todos los casos de comunicaci�n por puerto
serie, con su aut�mata; el perido de lectura del puerto serie pasa a ser 200ms para leer
siempre bien los comandos (si era mayor a veces se mezclaban). Hecho el 2/3/2010

- El control del sistema mediante el puerto serie provoca cambios en la gesti�n de threads:
la lectura del puerto serie se hace con un thread de Fltk (Fl::add_timeout Fl::repeat_timeout)
y el control de ejecuci�n de listas tambi�n (Fl::add_timeout en StartEjecucion y 
Fl::remove_timeout en StopEjecucion)

- Se crea una variable de Control por el puerto serie que se incorpora al archivo de configuraci�n, 
aunque no es modificable todav�a con la herramienta de configuraci�n, sino editando el archivo

- Se modifica la rutina de salida ExitOrdenadamente para que se apague el ordenador tambi�n cuando
hay un error de DAQ (antes hac�a un segmentation fault y al no terminar bien no llegeba al init 0
en el script de arranque)

- Se modifica una regla udev para que la red eth1 funcione siempre bien, en el conector de arriba
y con la direcci�n 192.168.0.1 (antes depend�a de la mac y se renombraba a ethX)

- Se modifica la llamada a servidor VNC para arrancarlo con el kde (.kde/Autostart/start) en lugar
de cada vez que se iniciaba el �taca; se arranca con una opci�n que evita que se apague (-forever)
y forzando siempre el puerto 5900 (-rfbport 5900)

- Se escribe la partici�n /dev/sda1 tomando la de la imagen del multiscan, porque la del �taca ten�a
un extra�o error que no permit�a que se montara; ahora va todo bien

#############################################################################################
9/Febrero/2010 v2.4s

- Se incorpora el control del sistema mediante el puerto serie, de una forma muy limitada, 
para el proyecto de 50 l�seres en Valencia (versi�n preliminar)

#############################################################################################
18/Enero/2010 v2.4

- Se incluye un nuevo script, SetFuncionalidad (en versi�n .c y .fl, porque al principio no
consegu�a que funcionara la primera, aunque finalmente s�), para poder cambiar entre 
funcionalidad S�lo texto y Completa (m�s c�digos de barras y gr�ficos). La contrase�a
para realizar cambios es "3y0landa6" (sin comillas); el mecanismo se basa en el archivo
binario itaca.bin (ver detalles en el c�digo)

- Se saca el valor de activaci�n de los galvos al archivo de configuraci�n itaca.conf para
que se pueda adaptar el sistema a los galvos CTI

#############################################################################################
13/Enero/2010 v2.3.2

- C�digos de barras, gr�ficos plt, etc. primera versi�n completa

- En el programa de configuraci�n se incluye un bot�n para importar gr�ficos plt
que est�n en la ra�z de dispositivos usb conectados

- Se hacen m�s s�lidas las lecturas de archivos: si algo falla se copian de /rootFLS y con
volver a iniciar el programa debe funcionar correctamente

#############################################################################################
10/Diciembre/2009 v2.1

- C�digos de barras en memoria basados en bitmaps en lugar de archivos svg, para resolver
la inversi�n de c�digos

- Problema de marcaje a baja velocidad:

#############################################################################################
4/Diciembre/2009 v2.0.2

- C�digos de barras

- Desactivado el control de errores de galvos

#############################################################################################
2/Diciembre/2009 v2.0.1 - feria Aipimifa

- C�digos de barras con tipos de l�nea activados s�lo en Servicio T�cnico

#############################################################################################
15/Noviembre/2009 v2.0 - feria empack

- C�digos de barras, versi�n b�sica


#############################################################################################
25/Octubre/2009 v1.9 - enviada a Italia

- Correcci�n de numerosos bugs relacionados con los campos variables

#############################################################################################
1/Octubre/2009 v1.7

- Internacionalizaci�n: espa�ol, ingl�s, italiano

- Arranca aunque no haya DAQ (ya no hace segmentation fault)

- Formatos de fecha, hora, serie no predefinidos, sino codificados

- Se pueden meter todos los campos calculados que se quiera (dos fechas, por ejemplo)

- Aplicaci�n para el cambio de hora del sistema

- Aplicaci�n para la gesti�n del archivo de configuraci�n

#############################################################################################
16/Julio/2009 v1.6.1

- Se aumenta el tama�o m�ximo de los caracteres a 25 mm

- Se incluye un nuevo formato de fecha: SSD, que codifica la semana del a�o (01-53) y el d�a
de la semana (1-7)

#############################################################################################
8/Julio/2009 v1.6

- N�meros de serie: se define un n�mero final, se formatea al n�mero de d�gitos introducido,
se visualiza y modifica el n�mero de unidad dentro del lote; s�lo se permite reiniciar la 
serie o cambiar el n�mero actual en el lote si se est� editando la l�nea que tiene el n�mero
de serie; se corrigen bugs relacionados con el mantenimiento de la secuencia

- Se corrige el bug al cambiar la velocidad sin texto definido en las l�neas: ya no se 
recalcula la matriz

- Se fuerza la restauraci�n del cursor en forma de flecha (default) al volver de la ventana 
de modificaci�n del texto

- Se modifican los fonts de campos variables a terminal en lugar de times

#############################################################################################
18/Noviembre/2008 v1.0

- Versi�n 1.0 del codificador �taca
