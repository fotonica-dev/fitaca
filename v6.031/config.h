// Include files
#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/io.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

// fltk
#include <string.h>
#include <cstdlib>

// Constantes
# define debug		false

// Idiomas
#define	Idiomas		3
#define	ESP		0
#define	ING		1
#define	ITA		2

// Disparo
#define DISPAROEXTERNO	0
#define DISPAROINTERNO	1

#define ON		1
#define OFF		0

// Password de configuraci�n por defecto
#define PASSWORD	"1489"

// Turnos
#define NumeroTurnos	6
#define NumeroCaracteresTextoTurnos	10

// Variables Globales
static char ValoresIdioma[Idiomas][Idiomas][15] = { 
	{ "Espa�ol", "Ingl�s", "Italiano" }, 
	{ "Spanish", "English", "Italian" }, 
	{ "Spagnolo", "Inglese", "Italiano" }
};

static char ValoresActivacion[Idiomas][2][15] = { 
	{ "Desactivado", "Activado" }, 
	{ "Disabled", "Enabled" }, 
	{ "Disabilitato", "Attivato" }
};

static char ValoresDinamico[Idiomas][3][25] = { 
	{ "Desactivado", "Activado", "Vel. constante" }, 
	{ "Disabled", "Enabled", "Constant speed" }, 
	{ "Disabilitato", "Attivato", "Vel. costante" }
};

static char ValoresTipoDisparo[Idiomas][2][15] = { 
	{ "Externo", "Interno" }, 
	{ "Extern", "Intern" }, 
	{ "Esterno", "Interno" }
};

static char ValoresEstrategia[Idiomas][4][15] = { 
	{ "Car�cter", "�tomos", "Fuera de campo", "Componer" }, 
	{ "Character", "Atoms", "Out of field", "Compose" }, 
	{ "Carattere", "Atomi", "Fuori Campo", "Componer" }
};

static char ValoresControl[Idiomas][2][15] = { 
	{ "DAQ", "FPGA" }, 
	{ "DAQ", "FPGA" }, 
	{ "DAQ", "FPGA" }
};

static char ValoresTipoLaser[Idiomas][2][15] = {
	{ "CO2", "Fibra" },
	{ "CO2", "Fiber" },
	{ "CO2", "Fibra" }
};

static char ValoresFicheroCorreccionActivo[Idiomas][2][15] = {
	{ "No Activo", "Activo" },
	{ "Not Active", "Active" },
	{ "No Activo", "Activo" }
};


// Turnos
static int HoraInicioTurno[NumeroTurnos];
static int MinutoInicioTurno[NumeroTurnos];

static int HoraFinTurno[NumeroTurnos];
static int MinutoFinTurno[NumeroTurnos];

static char TextoTurno[NumeroTurnos][NumeroCaracteresTextoTurnos];

// Control de acceso
static int ControlAcceso;
static char Password[10], PasswordConfiguracion[10];

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

// Orientaci�n y avance
static int Orientacion, Avance;

// Retardo de disparo tras la detecci�n de la fotoc�lula
static int RetardoDisparo;

// M�nimo del n�mero de lecturas consecutivas para considerar que ha sido un disparo
static int MinimoLecturasConsecutivas;

// Marcaje Din�mico Activo: 
// 0 - desactivado 
// 1 - activado con velocidad variable (usa encoder)
// 2 - activado con velocidad constante (no usa encoder)
static int MarcajeDinamicoActivo;

// Calibraci�n del encoder
static float CalibracionEncoder;

// Velocidad de la l�nea: se utiliza cuando la velocidad de la l�nea es constante
static float VelocidadLinea;

static int ValorActivacionGalvos;		// Valor digital (0 o 1) que se escribe para activar los galvos (multiscanx.conf)

// Tensi�n de alimentaci�n del galvo que desplaza al extremo del campo (V), 
// que corresponde al m�ximo desplazamiento horizontal o vertical en bits
static float VGalvoRef_MaximoBits;

static int ExtractorActivado;		// Variable de estado para saber si el extractor est� activado

// Valor digital (0 o 1) que se considera de disparo de la fotoc�lula
static unsigned int ValorDisparo;

static int PERIODO_MICROSEGUNDOS; 	// Periodo del sistema en microsegundos

static int ServicioTecnico;	 	// Activaci�n de la funcionalidad de Servico T�cnico

// Idioma del interfaz
static int Idioma;

// Tama�o del spot
static int Spot;

// Control Puerto Serie
static int PuertoSerieActivo;

// Marca centrada
static int Centrado;

// Impresi�n en el reverso del sustrato
static int Reverso;

// Tipo de disparo: externo o interno
static int TipoDisparo;
static int SeparacionEntreDisparos_mm;

// Estrategia de marcaje
static int Estrategia;			// 0-car�cter, 1-�tomos, 2-�tomos fuera de campo, 3-Componer

// Tipo de sistema de control
static int Control;			// 0-DAQ, 1-FPGA

// Tipo de laser
static int TipoLaser;			// 0-CO2, 1-Fibra

// Fichero Configuracion
static int FicheroCorreccionActivo;	// 0-No activo, 1-Activo

// Compilaci�n: opciones avanzadas
static int ConfigAvanzada;		// 0-false, 1-true

// Control de errores

// Define si se controla o no el error de campo
static int ControlarErrorCampo; 

// Define si se controla o no el error de los galvos
static int ControlarErrorGalvos;

// para editar los turnos
static int indice;

