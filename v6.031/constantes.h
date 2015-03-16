/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTANTES
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Si está activado no se arranca el watchdog
#define ENDESARROLLO	0

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constantes lógicas para facilitar la interpretación del código
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#define HIGH		1
#define LOW		0
#define ON		1
#define OFF		0
#define NoError		0

// Ventana activa de donde se procede antes de sacar la ventana de mensajes
#define VPrincipal	0
#define VModificar	1
#define VDetalles	2
#define VPassword	3
#define VTrabajos	4
#define VConfirmarCargarTrabajo		5
#define VConfirmarGuardarTrabajo	6
#define VRepeticiones	7
#define VPasswordTrabajos	8
#define VConfirmarBorrarTrabajo	9

// Idiomas
#define	Idiomas		3
#define	ESP		0
#define	ING		1
#define	ITA		2

// Tipos de línea
#define	TEXTO		0
#define GRAFICO		1
#define TEXTOCIRCULAR	2

// Funcionalidad
#define SOLOTEXTO	0
#define COMPLETA	1	
#define BLOQUES		2	

// Tipo de disparo
#define DISPAROEXTERNO	0
#define DISPAROINTERNO	1

// Modo de funcionamiento
#define MODONORMAL	0
#define MODOCARACTER	1

// Password de supervisor
#define PASSWORD	"3687"

// Constantes para el ordenamiento de átomos
#define XMAX		0
#define XMIN		1
#define YMAX		2
#define YMIN		3

// Constantes de control
#define DAQ		0
#define FPGA		1

// Turnos
#define NumeroTurnos	6
#define NumeroCaracteresTextoTurnos	10

//Tipo de Laser
//#define Tipolaser	1

//Error fijo de la posicion de los galvos en la inicializacion
//#define MovimientoInicialGalvos	1

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Debug
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#define debug_ciclos 				false
#define debug_monitorizacion 			false
#define debug_daq 				false
#define debug_listas				false
#define debug_vectores				false
#define debug_Mvectores				false
#define debug_EjecucionMvectores 		false
#define debug_encoder				false
#define debug_espera				false
#define debug_errores				true
#define debug_testado				false
#define debug_fotocelula 			false
#define debug_posicion				false
#define debug_resto				false
#define debug_step				false
#define debug_aodata				false
#define debug_texto				false
#define debug_camposvariables			false
#define debug_barcode				false
#define debug_plt				false
#define debug_puertoserie			true
#define debug_retardodisparo			false
#define debug_FPGA				false

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// TIEMPOS
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Periodo wait (s): tiempo entre comprobaciones del estado de ejecución de las listas en el bucle
// de ejecución de listas
#define PERIODO_WAIT	0.00001

// Periodo del timer de estado (microsegundos) y pateo del watchdog
#define PERIODO_ESTADO	1000000

// Periodo del timer de escucha del puerto serie (segundos)
#define PERIODO_PUERTOSERIE	0.200

// Timeout desde la desactivación del control de acceso hasta su activación automática (segundos)
#define TIMEOUT_CONTROLACCESO	120

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMEDI - ni pci6221: hay un modelo con conector de 37 pines, y otro con conector de 68 pines
// Por defecto se trata de la tarjeta de 37 pines; en caso contrario hay que activar el define de 68pines
// justo a continuación
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// #define _68pines

// ENTRADAS ANALÓGICAS:

// Las entradas analógicas se van a realizar en el subdevice 0
#define comedi_subdevice_AI			0

// Entrada analógica para la medida de la coordenada X del galvo en V
#define comedi_canalAI_PosicionX		0

// Entrada analógica para la medida de la coordenada Y del galvo en V
#define comedi_canalAI_PosicionY		1	

// SALIDAS ANALÓGICAS:

// Las salidas analógicas se van a realizar en el subdevice 1
#define comedi_subdevice_AO			1

// Salida de la señal de control del galvo X
#define comedi_canalAO_GalvoX			0		

// Salida de la señal de control del galvo Y
#define comedi_canalAO_GalvoY			1

// ENTRADAS DIGITALES:

// LASER OK

// La entrada digital de Laser Ok se va a realizar en el subdevice 7 (P1)
#define comedi_subdevice_LaserOk		7

// En el canal 1 se lee la señal de laser OK procedente del láser (P1.1)
#define comedi_canalDI_LaserOk			1	

// FOTOCÉLULA versión 68 pines
#ifdef _68pines

	// La entrada digital de la fotocélula se va a realizar en el subdevice 2 (P0)
	#define comedi_subdevice_Fotocelula	2

	// En el canal 5 se lee la señal de disparo de la fotocélula (P0.5)
	#define comedi_canalDI_Fotocelula	5

// FOTOCÉLULA versión 37 pines
#else

	// La entrada digital de la fotocélula se va a realizar en el subdevice 2 (P0)
	#define comedi_subdevice_Fotocelula	2

	// En el canal 0 se lee la señal de disparo de la fotocélula (P0.0)
	#define comedi_canalDI_Fotocelula	0	

#endif

// EXTRACTOR

// La entrada digital de Extractor Ok se va a realizar en el subdevice 7 (P1)
#define comedi_subdevice_ExtractorOk		7	

// En el canal 3 se lee la señal de extractor OK procedente del extractor (P1.3)
#define comedi_canalDI_ExtractorOk		3


// SALIDAS DIGITALES:

// Constante para enrutar las salidas digitales PFI
//#define NI_PFI_OUTPUT_DO 			16

// LASER ENABLE versión 68 pines
#ifdef _68pines

	// La salida digital de Laser Enable se va a realizar en el subdevice 2 (P0)
	#define comedi_subdevice_LaserEnable	2

	// En el canal 0 se activa la señal de Laser Enable (P0.0)
	#define comedi_canalDO_LaserEnable	0	

// LASER ENABLE versión 37 pines
#else

	// La salida digital de Laser Enable se va a realizar en el subdevice 7 (P1)
	#define comedi_subdevice_LaserEnable	7

	// En el canal 2 se activa la señal de Laser Enable (P1.2)
	#define comedi_canalDO_LaserEnable	2	

#endif

// CONTROL ENABLE

// La salida digital de Control de línea se va a realizar en el subdevice 2 (P0)
#define comedi_subdevice_ControlEnable		2

// En el canal 1 se activa la señal de Control de Línea (P0.1)
#define comedi_canalDO_ControlEnable		1	

// ACTIVACIÓN GALVOS versión 68 pines
#ifdef _68pines

	// La salida digital de Activación de Galvos se va a realizar en el subdevice 2 (P0)
	#define comedi_subdevice_ActivacionGalvos	2

	// En el canal 6 se activa la señal de alimentación de galvos (P0.6)
	#define comedi_canalDO_ActivacionGalvos		6

// ACTIVACIÓN GALVOS versión 37 pines
#else

	// La salida digital de Activación de Galvos se va a realizar en el subdevice 7 (P1)
	#define comedi_subdevice_ActivacionGalvos	7

	// En el canal 0 se activa la señal de alimentación de galvos (P1.0)
	#define comedi_canalDO_ActivacionGalvos		0

#endif

// MARK IN PROGRESS versión 68 pines
#ifdef _68pines

	// La salida digital de Mark in Progress se va a realizar en el subdevice 2 (P0)
	#define comedi_subdevice_MarkInProgress		2

	// En el canal 2 se activa la señal de Mark in Progress (P0.2)
	#define comedi_canalDO_MarkInProgress		2

// MARK IN PROGRESS versión 37 pines
#else

	// La salida digital de Mark in Progress se va a realizar en el subdevice 7 (P1)
	#define comedi_subdevice_MarkInProgress		7

	// En el canal 4 se activa la señal de Mark in Progress (P1.4)
	#define comedi_canalDO_MarkInProgress		4	

#endif

// EXTRACTOR ENABLE versión 68 pines
#ifdef _68pines

	// La salida digital de Extractor Enable se va a realizar en el subdevice 2 (P0)
	#define comedi_subdevice_ExtractorEnable	2

	// En el canal 3 se activa la señal de Activación del Extractor (P0.3)
	#define comedi_canalDO_ExtractorEnable		3	

// EXTRACTOR ENABLE versión 37 pines
#else

	// La salida digital de Extractor Enable se va a realizar en el subdevice 7 (P1)
	#define comedi_subdevice_ExtractorEnable	7

	// En el canal 5 se activa la señal de Activación del Extractor (P1.5)
	#define comedi_canalDO_ExtractorEnable		5	

#endif

// CONTADORES:

// Contador para generar el tren de pulsos que excitará al láser: subdevice 11 -> contador 0
#define comedi_subdevice_ContadorLaser		11
#define comedi_ContadorLaser_Canal		0
#define comedi_ContadorLaser_Routing		NI_PFI_OUTPUT_GOUT0

// Subdevice digital donde se producirá la salida (P1)
#define comedi_subdevice_ContadorLaser_DO	7 

// Canal del subdevice digital donde se producirá la salida (P1.7)
#define comedi_canalDO_ContadorLaser		7

// Contador para detectar el tren de pulsos procedente del encoder: subdevice 12 -> contador 1
#define comedi_subdevice_ContadorEncoder	12
#define comedi_ContadorEncoder_Canal		0

// Subdevice digital donde se producirá la entrada (P1)
#define comedi_subdevice_ContadorEncoder_DI	7

// Canal del subdevice digital donde se producirá la entrada (P1.6)
#define comedi_canalDI_ContadorEncoder		6

// Que corresponde en la ni pci 6221 al PFI 6
#define SOURCE_PFI_CHANNEL			6

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// FPGA
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTROS DEL PUERTO PARALELO (Modo EPP)

// Base puerto paralelo: 0x0378
#define BASE_ADDRESS_PUERTO_PARALELO		0x0378

// Status: Base + 1
#define REGISTRO_STATUS				0x0379		

// Addr: Base + 3
#define REGISTRO_ADDR				0x037B

// Data: Base + 4
#define REGISTRO_DATA				0x037C

// Máscara para detectar si hay un time out en la comunicación EPP
// (bit 5 en el registro de status)
#define MASCARA_EPP_TIME_OUT			0x20

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMANDOS FPGA: se escriben en el registro de direcciones del puerto paralelo

// Comandos de administración de la FPGA
#define COMANDO_ADMIN_FPGA			0xF0	

// Unconfigure la FPGA: Al salir del programa hay que desconfigurar la FPGA
// para poder cargarla en el siguiente arranque
#define ARG_UNCONFIGURE_FPGA			0xF	

// Comando para poner todas las salidas de la FPGA a 0, al salir del programa
#define ARG_RESET_IO				0xE

#define COMANDO_LASER				0x10

#define COMANDO_LASER_ENABLE			0x20

#define COMANDO_GALVOS				0x30

#define COMANDO_ENCODER				0x40

#define COMANDO_CONTROL				0x50

#define COMANDO_EXTRACTOR			0x60

#define COMANDO_MARK_IN_PROGRESS		0x70

// Comandos unarios para la lectura de entradas digitales: tras recibir el comando la FPGA pone la señal
// digital en el bit ; para leerlo hay que aplicar una máscara en el registro de Status para leer 
// el Pin 13 (Select) en el bit 4 del registro de Status
#define COMANDO_LEER_DI				0x80
#define ARG_LEER_LASER_OK			0x1
#define ARG_LEER_TEMPERATURA_OK			0x2
#define ARG_LEER_EXTRACTOR_OK			0x3

#define MASCARA_ENTRADAS_DIGITALES		0x10

// La fotocélula está "hard wired" en el bit 5 del registro de Status (Pin 12 - Paper Out)
// Sólo hace falta una máscara
#define MASCARA_ENTRADA_FOTOCELULA		0x20

// Comandos para el tren de pulsos del láser
#define COMANDO_LASER_TICKS			0x90
#define ARG_LASER_UP_TICKS_LSB			0x1
#define ARG_LASER_UP_TICKS_MSB			0x2
#define ARG_LASER_DOWN_TICKS_LSB		0x3
#define ARG_LASER_DOWN_TICKS_MSB		0x4

// Comando para leer las cuentas del encoder
#define COMANDO_LEER_CUENTAS_ENCODER		0xA0	

// Máximo de cuentas del encoder: 8 bits
#define MAX_CONTADOR_ENCODER			0xFF	

// Comandos para escribir el galvo X
#define COMANDO_ESCRIBIR_POSICION_GALVO_X	0xB0 // Los 4 primeros bits son el comando, los 4 siguientes son para completar hasta los 12 bits

// Comandos para escribir el galvo Y
#define COMANDO_ESCRIBIR_POSICION_GALVO_Y	0xC0 // Los 4 primeros bits son el comando, los 4 siguientes son para completar hasta los 12 bits


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTANTES RELATIVAS A LA MARCA
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Número máximo de caracteres en cada línea de texto
#define NumeroMaximoCaracteresLinea	254

// Altura máxima y mínima de las líneas (mm)
#define AlturaMaximaLinea		10
#define AlturaMinimaLinea		1

// Número máximo de vectores en total en la marca
#define NumeroMaximoVectores	100000

// Número máximo de átomos (estructuras PU PD ... PD) en total en la marca:  NumeroMaximoVectores/2
#define NumeroMaximoAtomos	50000

// Número de listas de microvectores
#define NumeroListas			2

// Número máximo de microvectores en cada lista
#define NumeroMaximoMicroVectores	1000000

// Número máximo de bits en desplazamiento horizontal o vertical desde el origen de coordenadas
#define MaximoBits			32768

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTANTES RELATIVAS AL TEXTO
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Número de líneas de texto
#define NumeroLineasTexto		4

// Número máximo de bloques en las líneas de texto
#define NumeroBloquesLinea		3

// Longitud máxima del string de fecha
#define LongitudMaximaStringFecha	30

// Longitud máxima del string de hora
#define LongitudMaximaStringHora	10

// Longitud máxima del string de fuente
#define LongitudMaximaStringFuente	25

// Número de formatos de fecha
#define FormatosFecha 			12

// Número de separadores de fecha
#define SeparadoresFecha		5

// Número de formatos de hora
#define FormatosHora 			6

// Número de separadores de hora
#define SeparadoresHora			5

// Número de fuentes de caracteres
#define NumeroFuentes 			10

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTANTES RELATIVAS AL CÓDIGO DE BARRAS
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Máxima coordenada en Y del código - parámetro height del objeto símbolo
//#define YMAX_BARCODE			50

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTANTES RELATIVAS AL PROCESO DE ARCHIVOS PLT
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Número máximo de líneas con texto en el archivo PLT: si hay más líneas se dará un mensaje de error
#define MaximoLineasArchivoPlt 		30000

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTANTES RELATIVAS AL TIPÒ DE LÍNEA
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Longitud máxima del string de tipos de líneas
#define LongitudMaximaStringTipoLinea	30

// Número de tipos de códigos de líneas (incluyendo texto, gráfico y diversos códigos de barras)
#define NumeroTiposLinea		9

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONTROL DE ERRORES
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Define si se controla o no el error de campo
//#define ControlarErrorCampo			ON - ahora es una variable modificable en configuración

// Control del número máximo de errores consecutivos para que salte el error de campo
#define MaximoErroresConsecutivosCampo		5

// Define si se controla o no el error de los galvos
//#define ControlarErrorGalvos			ON - ahora es una variable modificable en configuración

// Tolerancia admitida en la comparación entre la posición teórica y la posición medida en tanto por uno
#define ToleranciaPosicionTantoPorUno		0.10

// Tolerancia admitida en la comparación entre la posición teórica y la posición medida en bits
#define ToleranciaPosicionBits			2000	

// Control del número máximo de errores consecutivos para que salte el error de galvos
#define MaximoErroresConsecutivosGalvos		10

// Control del número máximo de errores consecutivos para que salte el error de LaserOk
#define MaximoErroresConsecutivosLaserOk	10

// Control del número máximo de errores consecutivos para que salte el error de extractor
#define MaximoErroresConsecutivosExtractor	10

// Control del número máximo de disparos con marcaje dinámico y el encoder parado para dar error de encoder
#define MaximoDisparosParado			10

// Factor para la lectura de la posición
#define FactorPosicion				-2


////////////////////////////////////////////////////////////////////////////////////////////////////////
// DATOS DEL FICHERO DE CORRECCION
////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FCX00	0
#define FCX01	0
#define FCX02	0
#define FCX10	15221
#define FCX11	15221
#define FCX12	15254
#define FCX20	31043
#define FCX21	30773
#define FCX22	29991
#define FCY00	0
#define FCY01	15798
#define FCY02	31043
#define FCY10	0
#define FCY11	16086
#define FCY12	31318
#define FCY20	0
#define FCY21	16384
#define FCY22	32467

