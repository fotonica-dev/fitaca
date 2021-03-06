// Tipos
typedef unsigned char BYTE;		// 8 bits
typedef unsigned short int WORD;	// 16 bits

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Variables Globales
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Velocidad de marcaje
static int VelocidadMarcaje;

// Potencia L�ser
static int PotenciaLaser;

// Periodo del tren de pulsos utilizado para excitar el L�ser
static int PeriodoTrenPulsos;

// Retardo L�ser On
static int RetardoLaserOn;

// Retardo L�ser Off
static int RetardoLaserOff;

// Velocidad de salto
static int VelocidadSalto;

// Retardo de salto
static int RetardoSalto;

// Retardo de pol�gono
static int RetardoPoligono;

// Retardo de marcaje
static int RetardoMarcaje;

// Factor de calibraci�n del fichero de correcci�n
static float CalibracionCorreccion;

// Marcaje Din�mico Activo: 
// 0 - desactivado 
// 1 - activado con velocidad variable (usa encoder)
// 2 - activado con velocidad constante (no usa encoder)
static int MarcajeDinamicoActivo;

// Calibraci�n del encoder
static float CalibracionEncoder;

// Velocidad de la l�nea: se utiliza cuando la velocidad de la l�nea es constante
static float VelocidadLinea;

// Incremento de cuentas del encoder en cada periodo: es un float porque si la velocidad es constante hae falta precisi�n float
static float IncrementoCuentasPeriodo;
static float IncrementoAcumulado;

// Valor de activaci�n de los galvos
static int ValorActivacionGalvos;		// Valor digital (0 o 1) que se escribe para activar los galvos (multiscanx.conf)

// Tensi�n de alimentaci�n del galvo que desplaza al extremo del campo (V), 
// que corresponde al m�ximo desplazamiento horizontal o vertical en bits
static float VGalvoRef_MaximoBits;

// M�xima tensi�n aplicable a los galvos, se calcular� como un 1% m�s que la anterior
static float VGalvoMax;

// Valor digital (0 o 1) que se considera de disparo de la fotoc�lula
static unsigned int ValorDisparo;

// Retardo de disparo tras la detecci�n de la fotoc�lula
static int RetardoDisparo_mm, RetardoDisparo_cuentas;

// Retardo de disparo adicional generado por el offset
static int RetardoDisparo_cuentas_adicional;

// Variable de estado para controlar si se est� esperando el retardo de disparo de la fotoc�lula
static int EsperaRetardoDisparo;		

// Variables relacionadas con el n�mero de lecturas consecutivas de la fotoc�lula para considerar un disparo
static int LecturasConsecutivasDisparo;
static int MinimoLecturasConsecutivasDisparo = 1; // Por si acaso el fichero de configuraci�n no tiene la variable se predefine un valor

// Ventana activa desde donde se invoca la ventana de mensajes
static unsigned int VentanaActiva = VPrincipal;	// Ventana Principal

// Idioma del interfaz
static int Idioma;

// Funcionalidad
static int Funcionalidad;

// Control de acceso
static int ControlAcceso;
static char Password[10], PasswordUsuario[10];

// Estrategia de marcaje
static int Estrategia;			// 0-car�cter, 1-�tomos, 2-�tomos fuera de campo, 3-componer

//Tipo de Laser
static int TipoLaser;			//1-CO2, 2-Fiber

//Fichero Correccion Activo
static int FicheroCorreccionActivo;	//0-Desactivado, 1-Activado

//MovimientoInicialGalvos
static int MovimientoInicialGalvos;	//0-Desactivado, 1-Activado

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Datos de las l�neas de texto

// Numero de bloques reales
static int NumeroBloques;

// Texto de las l�neas
// L�nea 1
static char LineaTexto1[NumeroBloquesLinea][NumeroMaximoCaracteresLinea];

// L�nea 2
static char LineaTexto2[NumeroBloquesLinea][NumeroMaximoCaracteresLinea];

// L�nea 3
static char LineaTexto3[NumeroBloquesLinea][NumeroMaximoCaracteresLinea];

// L�nea 4
static char LineaTexto4[NumeroBloquesLinea][NumeroMaximoCaracteresLinea];

// Altura de las l�neas
static float AlturaLineaTexto1[NumeroBloquesLinea];
static float AlturaLineaTexto2[NumeroBloquesLinea];
static float AlturaLineaTexto3[NumeroBloquesLinea];
static float AlturaLineaTexto4[NumeroBloquesLinea];

// Anchura de las l�neas
static float AnchuraLineaTexto1;
static float AnchuraLineaTexto2;
static float AnchuraLineaTexto3;
static float AnchuraLineaTexto4;

// textos entre campos variables
static char lineaanterior[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];
static char lineamedio[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];
static char lineamedio2[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];
static char lineafinal[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];

// l�nea que se est� calculando para EncontrarParametros y para lanzar la ventana de campos variables
static int LineaCalcular;

// bloque que se est� calculando para EncontrarParametros y para lanzar la ventana de campos variables
static int BloqueCalcular;

// Marca centrada
static bool Centrado;

// Impresi�n en el reverso del material (en espajo)
static bool Reverso;

// Marca fuera de l�mites
static bool FueraLimites;

// Para controlar que el plt no se pasa de tama�o (n�mero de l�neas >= MaximoLineasArchivoPlt)
static bool pltDemasiadoGrande; 

// Para controlar que el plt no sea incorrecto: menos de 2 l�neas (PU y PD) o altura 0
static bool pltIncorrecto; 

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Campos variables

static int StatusFecha[NumeroLineasTexto][NumeroBloquesLinea], 
	       StatusHora[NumeroLineasTexto][NumeroBloquesLinea], 
	       StatusNumeroSerie[NumeroLineasTexto][NumeroBloquesLinea]; 	// Controlan si hay definidos campos variables

static int OrdenFecha[NumeroLineasTexto][NumeroBloquesLinea], 
	       OrdenHora[NumeroLineasTexto][NumeroBloquesLinea], 
	       OrdenNumeroSerie[NumeroLineasTexto][NumeroBloquesLinea];	// Guarda el orden de los campos para cada l�nea

// Texto antes y despu�s de los campos
static char textoanteriorfecha[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea]; 
static char textoposteriorfecha[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];	
static char textoanteriorhora[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];
static char textoposteriorhora[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];
static char textoanteriorserie[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];
static char textoposteriorserie[NumeroLineasTexto][NumeroBloquesLinea][NumeroMaximoCaracteresLinea];

static int ValorFormatoFecha1[NumeroLineasTexto][NumeroBloquesLinea];
static int ValorFormatoFecha2[NumeroLineasTexto][NumeroBloquesLinea];
static int ValorFormatoFecha3[NumeroLineasTexto][NumeroBloquesLinea];
static int ValorSeparadorFecha[NumeroLineasTexto][NumeroBloquesLinea];

static int ValorFormatoHora1[NumeroLineasTexto][NumeroBloquesLinea];		
static int ValorFormatoHora2[NumeroLineasTexto][NumeroBloquesLinea];
static int ValorFormatoHora3[NumeroLineasTexto][NumeroBloquesLinea];
static int ValorSeparadorHora[NumeroLineasTexto][NumeroBloquesLinea];

static int ValorFuente;			                

// Almacena los formatos de la fecha: 3 idiomas (ESP, ING, ITA), 9 formatos, LongitudMaximaStringFecha caracteres
static char FormatoFecha[Idiomas][FormatosFecha][LongitudMaximaStringFecha] = {
	{ " ", "DD", "DDD", "DIA", "MM", "MMM", "MES", "AA", "AAAA", "SS", "DS", "JJ" },
	{ " ", "DD", "DDD", "DAY", "MM", "MMM", "MONTH", "YY", "YYYY", "WW", "DW", "JJ" },
	{ " ", "GG", "GGG", "GIORNO", "MM", "MMM", "MESI", "AA", "AAAA", "SS", "GS", "JJ" }
};	

static char FormatoCompletoFecha[NumeroLineasTexto][NumeroBloquesLinea][LongitudMaximaStringFecha];

static char SeparadorFecha[SeparadoresFecha][2] = { " ", "/", ":", "-", "." };

// String donde se almacena la fecha formateada
static char Fecha[NumeroLineasTexto][NumeroBloquesLinea][LongitudMaximaStringFecha];

// Caducidad en meses
static int Caducidad[NumeroLineasTexto][NumeroBloquesLinea];	

// Almacena los formatos de la hora: 3 idiomas (ESP, ING, ITA), 4 formatos, LongitudMaximaStringHora caracteres
static char FormatoHora[Idiomas][FormatosHora][LongitudMaximaStringHora] = { 
	{ " ", "HH", "hh", "MM", "SS", "turno" }, 
	{ " ", "HH", "hh", "MM", "SS", "shift" }, 
	{ " ", "OO", "oo", "MM", "SS", "spostare" }
};

static char FormatoCompletoHora[NumeroLineasTexto][NumeroBloquesLinea][LongitudMaximaStringHora];

static char SeparadorHora[SeparadoresHora][2] = { " ", "/", ":", "-", "." };

// String donde se almacena la hora formateada
static char Hora[NumeroLineasTexto][NumeroBloquesLinea][LongitudMaximaStringHora];

// Almacena los nombres de fuentes: 3 idiomas (ESP, ING, ITA), 10 fonts, LongitudMaximaStringFuente caracteres
static char Fuentes[Idiomas][NumeroFuentes][LongitudMaximaStringFuente] = {
	{"arial", "book antigua", "courier", "palatino", "r�pida", "r�pida doble", "r�pida pet", "sencilla", "times new roman", "india"},
	{"arial", "book antigua", "courier", "palatino", "speed", "speed double", "speed pet", "simple", "times new roman", "india"},
	{"arial", "book antigua", "courier", "palatino", "veloce", "veloce doppia", "veloce pet", "semplice", "times new roman", "india"}
};

// String donde se almacena la fuente actual
//static char Fuente[LongitudMaximaStringFuente];

// N�mero de serie
static long int NumeroSerie[NumeroLineasTexto][NumeroBloquesLinea];		
static long int NumeroSerieInicial[NumeroLineasTexto][NumeroBloquesLinea];
static long int NumeroSerieFinal[NumeroLineasTexto][NumeroBloquesLinea];
static unsigned int NumeroDigitosNumeroSerie[NumeroLineasTexto][NumeroBloquesLinea];

// N�mero de serie en formato string
static char strNumeroSerie[NumeroLineasTexto][NumeroBloquesLinea][20];	

// N�mero de unidades por lote
static long int NumeroUnidadesLote[NumeroLineasTexto][NumeroBloquesLinea];
static long int NumeroUnidadesLoteActual[NumeroLineasTexto][NumeroBloquesLinea];		

static int indice = 0;		// indice para saber cu�l es el cuadro de texto activo
            			// al utilizar el teclado en pantalla

// Reset automatico del numero de serie por cambio de fecha
static int ResetSerieFecha;	//0-Desactivado, 1-Activado

// Valor de fecha al inicio para resetear el numero de serie
static char FechaInicioMarca[LongitudMaximaStringFecha];

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// C�digos de barras

struct zint_symbol *BarcodeSymbol[NumeroLineasTexto][NumeroBloquesLinea];		// Objeto c�digo de barras

//static int StatusBarcode[NumeroLineasTexto];    		// Controla si est� activo el c�digo de barras en cada l�nea
//static int TipoBarcode[NumeroLineasTexto]; 			// Guarda el tipo de c�digo de barras

static int InvertirBarcode[NumeroLineasTexto][NumeroBloquesLinea]; 			// Controla si hay que invertir el c�digo de barras
static int SeparacionBarrasBarcode[NumeroLineasTexto][NumeroBloquesLinea]; 		// Guarda la separaci�n entre barras del c�digo, en %
static int EscalaBarcode[NumeroLineasTexto][NumeroBloquesLinea]; 			// Guarda la escala del c�digo, en %

//static int MostrarTextoBarcode[NumeroLineasTexto]; 		// Controla si hay que mostrar el texto del c�digo
//static float AlturaTextoBarcode[NumeroLineasTexto]; 		// Guarda la altura del texto del c�digo, en mm
//static float SeparacionTextoBarcode[NumeroLineasTexto]; 	// Guarda la separaci�n del texto al c�digo, en mm

// Nombre del archivo plt
static char NombreArchivoPlt[NumeroLineasTexto][NumeroBloquesLinea][50];
static int xMaxPlt, yMaxPlt, xMinPlt, yMinPlt;

// Tama�o del spot - afecta s�lo al n�mero de l�neas verticales de cada barra, al generar barcodes
static int Spot;			// tama�o del spot en micras
static int SpotBits;			// tama�o del spot en bits

// Nombre del archivo del trabajo seleccionado
//static char NombreTrabajo[50];
static int ValorTrabajo;		// guarda el �ndice del trabajo actual seleccionado

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tipos de l�nea

// Almacena los nombres de los tipos de l�nea: 3 idiomas (ESP, ING, ITA), 9 tipos, LongitudMaximaStringTipoLinea caracteres
//static char strTiposLinea[Idiomas][NumeroTiposLinea][LongitudMaximaStringTipoLinea] = {
//	{"Texto", "Gr�fico", "C�digo 128", "C�digo 39", "C�digo EAN", "C�digo Entrelazado 2-5", "C�digo Datamatrix", "C�digo PDF417", "C�digo ITF-14" },
//	{"Text", "Graph", "Barcode 128", "Barcode 39", "Barcode EAN", "Barcode Interleaved 2-5", "Barcode Datamatrix", "Barcode PDF417", "Barcode ITF-14" },
//	{"Text", "Graph", "Barcode 128", "Barcode 39", "Barcode EAN", "Barcode Interleaved 2-5", "Barcode Datamatrix", "Barcode PDF417", "Barcode ITF-14" },
//};

// Almacena los n�meros de los tipos de l�nea: 9 tipos; los dos primeros corresponden a texto y gr�fico
//static int numTiposLinea[NumeroTiposLinea] = {0, 1, 20, 8, 13, 3, 71, 55, 89};

static char strTiposLinea[Idiomas][NumeroTiposLinea][LongitudMaximaStringTipoLinea] = {
	{"Texto", "Gr�fico", "Texto circular", "C�digo 128", "C�digo 39", "EAN", "Datamatrix", "ITF-14", "QR" },
	{"Text", "Graph", "Circular text", "Barcode 128", "Barcode 39", "EAN", "Datamatrix", "ITF-14", "QR" },
	{"Text", "Graph", "Texto circular", "Barcode 128", "Barcode 39", "EAN", "Datamatrix", "ITF-14", "QR" },
};

// Almacena los n�meros de los tipos de l�nea: 10 tipos; los dos primeros corresponden a texto y gr�fico
static int numTiposLinea[NumeroTiposLinea] = {0, 1, 2, 20, 8, 13, 71, 89, 58};

static int ValorTipoLinea[NumeroLineasTexto][NumeroBloquesLinea]; 		// Guarda el tipo de cada l�nea

//Angulo y Radio CentroX y CentroY del texto circular
static double AnguloTextoCircular[NumeroLineasTexto][NumeroBloquesLinea];
static double RadioTextoCircular[NumeroLineasTexto][NumeroBloquesLinea];
static double CentroXTextoCircular[NumeroLineasTexto][NumeroBloquesLinea];
static double CentroYTextoCircular[NumeroLineasTexto][NumeroBloquesLinea];

//Posicion Texto
static double MinXTexto[NumeroLineasTexto][NumeroBloquesLinea];
static double MinYTexto[NumeroLineasTexto][NumeroBloquesLinea];

//Posicion Grafico
static double MinXGrafico[NumeroLineasTexto][NumeroBloquesLinea];
static double MinYGrafico[NumeroLineasTexto][NumeroBloquesLinea];

//Posicion Barcode
static double MinXBarcode[NumeroLineasTexto][NumeroBloquesLinea];
static double MinYBarcode[NumeroLineasTexto][NumeroBloquesLinea];

// Turnos
static int HoraInicioTurno[NumeroTurnos];
static int MinutoInicioTurno[NumeroTurnos];

static int HoraFinTurno[NumeroTurnos];
static int MinutoFinTurno[NumeroTurnos];

static int MinutoDiaInicioTurno[NumeroTurnos]; // el minuto de todos los minutos del d�a
static int MinutoDiaFinTurno[NumeroTurnos];

static char TextoTurno[NumeroTurnos][NumeroCaracteresTextoTurnos];

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Otras variables

// Proceso
static char LineaTexto[NumeroMaximoCaracteresLinea];

// Offsets de la pantalla
static int xOffsetPantalla, yOffsetPantalla; // en bits
static int Horizontal, Vertical; // en mm

// Semicampo
static float Semicampo; // Mitad del campo en mm

// Orientaci�n y avance
static int Orientacion, Avance;

// Justificaci�n
static int JustificacionIzquierda, JustificacionDerecha, JustificacionCentro;

// Estado
static int ArchivoFuentesAbierto;	// Controla si ya se ha leido el archivo de fuentes
static int Actualizar;			// Controla si hay que actualizar la matriz
static int PruebaMarcaje;		// Controla si se trata de una prueba de marcaje
static int EnEjecucion;			// Controla si se est� en el bucle de ejecuci�n
static int SistemaOk;			// Controla si las variables de estado del laser est�n OK
static int MarcajeOk;			// Controla si el proceso de marcaje esta ok (campo, tensi�n m�xima galvos...)
static int Apagar;			// Para una salida ordenada del programa
static unsigned long long Contador;	// Almacena el n�mero de marcas realizadas

//static int actualizarfecha, actualizarhora, actualizarserie; // Control de la actualizaci�n de campos variables

// Duraci�n de marca
static RTIME tInicioMarca, tFinMarca;

// Disparo interno
static int TipoDisparo;
static int SeparacionEntreDisparos_mm, EsperaSeparacionEntreDisparos;
static long SeparacionEntreDisparos_cuentas;
static float IncrementoAcumulado_Espera;
static lsampl_t ValorCuentasActual_Espera, ValorCuentasAnterior_Espera;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Datos del archivo de fuentes
static unsigned int xMaxFont, yMaxFont;
static char ArchivoFuentes[3000][50]; // 3.000 l�neas de hasta 50 caracteres cada una
static int NumeroLineasArchivoFuentes;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Proceso de l�neas: intercambio de informaci�n entre CalcularMatriz y EncontrarParametros
static unsigned int AnchuraCaracterAnterior;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vectores
static char TipoMarcaje[NumeroMaximoVectores][3];// PU o PD. N�mero de l�neas igual al n�mero m�ximo de vectores
static int SaltoDentroAtomo[NumeroMaximoVectores];	// vale 1 cuando un salto (PU) est� dentro de una letra, para no crear un �tomo nuevo
static int xValues[NumeroMaximoVectores];	// Coordenada X. N�mero de l�neas igual al n�mero m�ximo de vectores
static int yValues[NumeroMaximoVectores];	// Coordenada Y. N�mero de l�neas igual al n�mero m�ximo de vectores
static int uValues[NumeroMaximoVectores];	// Umbral correspondiente al �tomo al que corresponde el vector

static unsigned long NumeroVectores;		// N�mero de vectores de la marca en curso
static long xValuesOrigenMV, yValuesOrigenMV;	// Guarda las coordenadas de origen de nuevos microvectores
static long xValuesPosicion, yValuesPosicion;	// Guarda las coordenadas de posici�n durante la ejecuci�n
static long xValuesPosicionMedida, yValuesPosicionMedida;	// Guarda las coordenadas de posici�n medidas
static long xValuesMax, xValuesMin, yValuesMax, yValuesMin; // Guarda m�ximos y m�nimos de la matriz
static double xBitsDouble, yBitsDouble;		// Para hacer la mmultiplicaci�n en EjecutarMicrovector s�lo una vez

// para operaciones sobre la matriz, guardar valores temporalmente
static char TipoMarcaje_tmp[NumeroMaximoVectores][3];// PU o PD. N�mero de l�neas igual al n�mero m�ximo de vectores
static int xValues_tmp[NumeroMaximoVectores];	// Coordenada X. N�mero de l�neas igual al n�mero m�ximo de vectores
static int yValues_tmp[NumeroMaximoVectores];	// Coordenada Y. N�mero de l�neas igual al n�mero m�ximo de vectores

//static int xValuesInicioMarca, yValuesInicioMarca;	// Guarda las coordenadas del inicio de la marca
//static int xValuesFinMarca, yValuesFinMarca;		// Guarda las coordenadas del final de la marca

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �tomos
typedef struct {

	unsigned int Inicio;
	unsigned int Longitud;
	int Xmin;
	int Xmax;
	int Ymin;
	int Ymax;
	int Umbral; // una de las cuatro variables anteriores, dependiendo de la combinaci�n Orientaci�n - Avance

} tipo_atomo;

static tipo_atomo Atomos[NumeroMaximoAtomos];
static unsigned long NumeroAtomos;		// N�mero de atomos de la marca en curso

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Micro Vectores

// Mark Step Size en bits
static unsigned int MarkStepSize;

// Jump Step Size en bits
static unsigned int JumpStepSize;

// Retardo de laser On en n�mero de periodos RT
unsigned int PeriodosRetardoLaserOn;

// Retardo de laser Off en n�mero de periodos RT
unsigned int PeriodosRetardoLaserOff;

// Retardo de marcaje en n�mero de periodos RT
unsigned int PeriodosRetardoMarcaje;

// Retardo de pol�gono en n�mero de periodos RT
unsigned int PeriodosRetardoPoligono;

// Retardo de salto en n�mero de periodos RT
unsigned int PeriodosRetardoSalto;

// Lista 0 - S�lo paraMoverGalvos
static int Lista0_Open;					// Para controlar si la lista est� abierta
static int Lista0_Exe;					// Para controlar la ejecuci�n de la lista
static unsigned long Lista0_NumeroMicroVectores;	// N�mero de micro vectores
static int Lista0_EstadoLaser[NumeroMaximoMicroVectores];	// Estado del l�ser en cada microvector
static int Lista0_xBits[NumeroMaximoMicroVectores];	// 
static int Lista0_yBits[NumeroMaximoMicroVectores];	// 

// Lista 1
static int Lista1_Open;					// Para controlar si la lista est� abierta
static int Lista1_Exe;					// Para controlar la ejecuci�n de la lista
static unsigned long Lista1_NumeroMicroVectores;	// N�mero de micro vectores
static int Lista1_EstadoLaser[NumeroMaximoMicroVectores];	// Estado del l�ser en cada microvector
static long Lista1_xBits[NumeroMaximoMicroVectores];	// 
static long Lista1_yBits[NumeroMaximoMicroVectores];	// 

static long Lista1_Umbral[NumeroMaximoMicroVectores];

// Lista 2
static int Lista2_Open;					// Para controlar si la lista est� abierta
static int Lista2_Exe;					// Para controlar la ejecuci�n de la lista
static unsigned long Lista2_NumeroMicroVectores;	// N�mero de micro vectores
static int Lista2_EstadoLaser[NumeroMaximoMicroVectores];	// Estado del l�ser en cada microvector
static int Lista2_xBits[NumeroMaximoMicroVectores];	// 
static int Lista2_yBits[NumeroMaximoMicroVectores];	// 

static long Lista2_Umbral[NumeroMaximoMicroVectores];

// Ejecuci�n de listas
static unsigned long MicroVector;	// Microvector en ejecuci�n
static int EsperaFotocelula;		// Variable de estado para controlar si se est� esperando el
					// disparo de la fotoc�lula
static int CambioFotocelula;		// Variable de estado para controlar si ha cambiado el
					// valor de la fotoc�lula
static int ResetJumpList;		// Variable de estado para controlar si hay que volver 
					// din�micamente al origen

static long xOffsetDinamico, yOffsetDinamico;	// N�mero de bits que hay que desplazar la marca para sacarla del campo
static long uOffsetDinamico;	// Para que con el umbral no haya que saber si es en x o en y, ser� igual a uno de los anteriores

static long UmbralActual;		// guarda el umbral actual

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constantes para conversiones

// Pasar de Bits a Voltios
static double Kx_Bits_a_Voltios;	// Galvo x
static double Ky_Bits_a_Voltios;	// Galvo y

// Pasar de Cuentas a Bits, en la coordenada X y en la Y
static double Kx_Cuentas_a_Bits, Ky_Cuentas_a_Bits;
static double Ku_Cuentas_a_Bits;	// esta variable se usa para no tener que saber si el c�lculo del umbral se hace en X o en Y
					// ser� igual a una de las variables anteriores

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Watchdog
static int fd_watchdog; 		// file descriptor
static int ErrorWatchdog;		// Controla errores de vectores, listas, etc

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Puerto serie
static int fd_puertoserie; 		// file descriptor
static int ErrorPuertoSerie;		// Controla errores relacionados con el puerto serie
static bool ModoImpresionSerie;		// para controlar si se activa la impresi�n desde el puerto serie
static int ErrorEjecucionListas;	// Controla errores relacionados con el bucle de ejecuci�n de listas

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// GUI fltk
static int Anchura;
static int Espaciado;
static float SeparacionLineas;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tarjeta Control
static unsigned int FotocelulaDIValue;		// Variable para la lectura de la fotoc�lula
static unsigned int LaserOkDIValue = LOW; 	// Variable para la lectura de la entrada digital del pedal
static int ErrorLaserOk;			// Controla el error de LaserOK
//static unsigned int TemperaturaDIValue = LOW; 	// Variable para la lectura de la entrada digital del pedal
static int ErrorTemperatura;			// Controla el error de Temperatura
static unsigned int ExtractorDIValue = LOW; 	// Variable para la lectura de la entrada digital del pedal
static int ErrorExtractor;			// Controla el error de Extractor
static int ExtractorActivado;			// Variable de estado para saber si el extractor est� activado
static int ErrorVectores;			// Controla errores de vectores, listas, etc
static int ErrorCampo;				// Controla errores de campo insuficiente durante la ejecuci�n
static int ErrorDAQ;				// Variable de estado para propagar el error en la tarjeta DAQ
static int ErrorFPGA;				// Variable de estado para propagar el error en la tarjeta FPGA
static int ErrorEncoder;			// Variable de estado para controlar el error de encoder con marcaje din�mico
static int ErrorValidacion;			// Variable de estado para controlar el error de validaci�n del SW

// Control de errores
static int ErroresConsecutivosCampoX=0;		// N�mero de errores consecutivos de campo en X
static int ErroresConsecutivosCampoY=0;		// N�mero de errores consecutivos de campo en Y
static int ErroresConsecutivosGalvos=0;		// N�mero de errores consecutivos de galvos
static int ErroresConsecutivosLaserOk=0;	// N�mero de errores consecutivos de galvos
static int ErroresConsecutivosExtractor=0;	// N�mero de errores consecutivos de galvos
//static int ErroresConsecutivosTemperatura=0;	// N�mero de errores consecutivos de galvos
static int ContadorDisparosParado = 0;		// Cuenta los disparos mientras el equipo est� parado y hay marcaje din�mico

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Control de errores en galvos
//static F64 VanteriorX, VanteriorY;	// Variables para guardar los �ltimos voltajes escritos a los galvos
//static double VposicionX, VposicionY;	// Variables para leer la posici�n de los galvos
static int ErrorGalvos;			// Variable de estado para propagar el error en los galvos
//static int PosicionControlada;	// Variable de estado para saber si los galvos est�n en posici�n controlada

// Variables para la lectura de las cuentas del encoder
static lsampl_t ValorCuentasActual, ValorCuentasAnterior;
static lsampl_t ValorCuentasActual_Estado, ValorCuentasAnterior_Estado;
static float IncrementoCuentas_Estado;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Control de estado
static volatile int endhandler = ON;
static volatile int endthread = ON;
static int EstadoLaser = OFF;
static int PuertoSerieActivo;
static int ActualizarPuertoSerie;
static char Str_Modoreposo[] = {0x07, 0x08, 0x07, 0x05};
static char Str_Modoimpresion[] = {0x07, 0x08, 0x07, 0x06};
static char Str_Linea1recibida[] = {0x07, 0x08, 0x08, 0x01};
static char Str_Linea2recibida[] = {0x07, 0x08, 0x08, 0x02};
static char Str_Linea3recibida[] = {0x07, 0x08, 0x08, 0x03};
static char Str_Linea4recibida[] = {0x07, 0x08, 0x08, 0x04};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// variables de RTAI
static RT_TASK *maint;				// Tarea buddy en tiempo real
static int timerthread;				// Thread del timer
static RT_TASK *timer_task_handler;		// Task RTAI del timer
static int ErrorRTAI;				// Variable de estado para propagar el error en RTAI
static RTIME Periodo;				// Periodo en internal counts
static pthread_t id_thread_timer_estado;	// Thread del timer de estado (no RT)
static int ErrorTimerEstado;			// Variable de estado para propagar el error de creaci�n del thread
//static pthread_t id_thread_timer_puerto_serie;	// Thread del timer de escucha del puerto serie (no RT)
//static int ErrorTimerPuertoSerie;		// Variable de estado para propagar el error de creaci�n del thread

/////////////////////////////////////////////////////////////////////////////////////////////////////////
static int PERIODO_MICROSEGUNDOS; 	// Periodo del sistema en microsegundos
static int ServicioTecnico;	 	// Activaci�n de la funcionalidad de Servico T�cnico
static bool ConfiguracionModificada;	// Para saber si se ha cambiado alg�n dato de configuraci�n y hay que escribir el archivo itaca.conf

// Tipo de sistema de control
static int Control;			// 0-DAQ, 1-FPGA

// Control de errores

// Define si se controla o no el error de campo
static int ControlarErrorCampo; 

// Define si se controla o no el error de los galvos
static int ControlarErrorGalvos;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMEDI variables
comedi_t *comedi_device;		// dispositivo comedi
//comedi_range *RangoAI, *RangoAO;	// rangos de entrada y salida anal�gica
lsampl_t MaxdataAI, MaxdataAO;		// m�ximos en los canales de entrada y salida anal�gica
unsigned laser_up_ticks, laser_down_ticks;
lsampl_t MaxdataContadorEncoder;	// m�ximo en el contador del encoder
double kFromPhysAO;			// para calcular el valor en las escrituras anal�gicas en comedi
double kFromPhysFPGA;			// para calcular el valor en las escrituras anal�gicas en la FPGA
lsampl_t Counter_Mode;			// configuraci�n del contador del tren de pulsos

static unsigned short int Laser_Up_Ticks, Laser_Down_Ticks;	// 16 bits

unsigned Clock_Period_ns;		// clock para el tren de pulsos

//static bool ImprimirMV = false;

// Mensaje parcial del puerto serie
static char StrParcial[NumeroMaximoCaracteresLinea];

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// TABLA Y PRECORTE
/////////////////////////////////////////////////////////////////////////////////////////////////////////
static int ControlTablaPrecorte;
static int NumeroFilas = 1;
static float SeparacionFilas = 0.0;
static int NumeroColumnas = 1;
static float SeparacionColumnas = 0.0;
static int xSeparacionColumnas, ySeparacionFilas;
static int Precorte;
static float SeparacionPrecorte = 0.0;
static int SeparacionPrecorteBits, LongitudPrecorte, VelocidadPrecorte;

int xcorregido;
int ycorregido;
double xcorregidoMV;
double ycorregidoMV;

