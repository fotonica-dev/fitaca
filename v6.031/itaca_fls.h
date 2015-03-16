//==============================================================================
//
// Título:      Itaca
//
// Objetivo:    Coder en Linux aprovechando la infraestructura de tiempo real 
//		desarrollada para Resurfacing, y utilizando driver Comedi
//		
// Creado:	Mayo 2009 v1.3 A. López
//
//		Las versiones anteriores son para la DAQ NI pci6221 de 68 pines
//		Esta versión v1.3 es para la DAQ NI pci6221 de 37 pines
//		
//		Para versiones posteriors ver readme.txt
//
//		kernel 2.6.23.9 - vanilla compilado con genkernel 
//		(a partir de una instalación de gentoo)	
//
//		rtai 3.6
//		comedi 0.7.76 
//		comedilib 0.9.0
//		fltk/fluid 1.1.7
//		i686-pc-linux-gnu-g++ (GCC) 4.1.1 (Gentoo 4.1.1-r3)
//		Qt: 3.3.8
//		KDE: 3.5.8
//
// Copyright:   Fotonica Laser Systems
//
//==============================================================================

// /*

// Versiones:	
// 		v1.0 Septiembre 2008
		
// 		v1.1 Febrero 2009

// 		v1.2 Abril 2009
		
// 		v1.3 Mayo 2009
		
// 		- Adaptación a DAQ NI pci6221 37 pines
// 		- Comprobación de posición de galvos 
// 		- Comprobación de que la marca ha cabido en el campo
// 		- Velocidad constante (sin encoder)
// 		- Presentación de velocidad y tiempo marca
// 		- Control de overflow de encoder
		
// 		Para versiones posteriors ver readme.txt

// */

//==============================================================================
// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef itaca_fls_h
#define itaca_fls_h
#include <FL/Fl.H>
#include "includes.h" //includes del programa
#include "constantes.h" //constantes del programa
#include "variables.h" //variables globales
#include <FL/Fl_Double_Window.H>
extern Fl_Double_Window *VentanaPrueba;
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
extern Fl_Button *Aceptar_VentanaPrueba;
extern Fl_Button *Cancelar_VentanaPrueba;
extern "C" { Fl_Double_Window* Make_Window_Confirmar_Prueba(); }
extern Fl_Double_Window *VentanaMarcar;
extern Fl_Button *Aceptar_VentanaMarcar;
extern Fl_Button *Cancelar_VentanaMarcar;
extern "C" { Fl_Double_Window* Make_Window_Confirmar_Marcar(); }
extern Fl_Double_Window *VentanaApagarSistema;
extern Fl_Button *Aceptar_VentanaApagarSistema;
extern Fl_Button *Cancelar_VentanaApagarSistema;
extern "C" { Fl_Double_Window* Make_Window_Confirmar_Apagar(); }
extern Fl_Double_Window *VentanaModificarTexto;
extern Fl_Box *LogoItacaVentanaModificar;
extern Fl_Group *GrupoFecha;
extern Fl_Button *BotonFecha;
#include <FL/Fl_Choice.H>
extern Fl_Choice *ChoiceFormatoFecha1;
extern Fl_Choice *ChoiceFormatoFecha2;
extern Fl_Choice *ChoiceFormatoFecha3;
extern Fl_Choice *ChoiceSeparadorFecha;
#include <FL/Fl_Counter.H>
extern Fl_Counter *IndicadorCaducidad;
extern Fl_Group *GrupoHora;
extern Fl_Button *BotonHora;
extern Fl_Choice *ChoiceFormatoHora1;
extern Fl_Choice *ChoiceFormatoHora2;
extern Fl_Choice *ChoiceFormatoHora3;
extern Fl_Choice *ChoiceSeparadorHora;
extern Fl_Group *GrupoSerie;
extern Fl_Button *BotonSerie;
#include <FL/Fl_Output.H>
extern Fl_Output *CuadroTextoSerie;
extern Fl_Output *CuadroTextoSerieFinal;
extern Fl_Group *FrameLote;
extern Fl_Output *CuadroTextoUnidadesLote;
extern Fl_Output *CuadroTextoUnidadesLoteActual;
extern Fl_Button *BotonReiniciarSerie;
#include <FL/Fl_Check_Button.H>
extern Fl_Check_Button *CheckResetSerieFecha;
extern Fl_Output *CuadroTextoLinea;
extern Fl_Group *GrupoTeclado;
extern Fl_Button *Boton1;
extern Fl_Button *Boton2;
extern Fl_Button *Boton3;
extern Fl_Button *Boton4;
extern Fl_Button *Boton5;
extern Fl_Button *Boton6;
extern Fl_Button *Boton7;
extern Fl_Button *Boton8;
extern Fl_Button *Boton9;
extern Fl_Button *Boton0;
extern Fl_Button *BotonBorrar;
extern Fl_Button *BotonQ;
extern Fl_Button *BotonW;
extern Fl_Button *BotonE;
extern Fl_Button *BotonR;
extern Fl_Button *BotonT;
extern Fl_Button *BotonY;
extern Fl_Button *BotonU;
extern Fl_Button *BotonI;
extern Fl_Button *BotonO;
extern Fl_Button *BotonP;
extern Fl_Button *BotonA;
extern Fl_Button *BotonS;
extern Fl_Button *BotonD;
extern Fl_Button *BotonF;
extern Fl_Button *BotonG;
extern Fl_Button *BotonH;
extern Fl_Button *BotonJ;
extern Fl_Button *BotonK;
extern Fl_Button *BotonL;
extern Fl_Button *BotonEnhe;
extern Fl_Button *BotonX;
extern Fl_Button *BotonC;
extern Fl_Button *BotonV;
extern Fl_Button *BotonB;
extern Fl_Button *BotonN;
extern Fl_Button *BotonM;
extern Fl_Button *BotonComa;
extern Fl_Button *BotonPunto;
extern Fl_Button *BotonZ;
extern Fl_Button *BotonEspacio;
extern Fl_Button *BotonBarra;
extern Fl_Button *BotonDosPuntos;
extern Fl_Button *BotonMas;
extern Fl_Button *BotonMenos;
extern Fl_Button *BotonRupia;
extern Fl_Button *BotonISI;
extern Fl_Button *BotonDiametro;
extern Fl_Button *Cancelar_VentanaModificarTexto;
extern Fl_Button *Aceptar_VentanaModificarTexto;
extern "C" { Fl_Double_Window* Make_Window_Modificar_Texto(); }
extern Fl_Double_Window *VentanaDetallesLinea;
extern Fl_Choice *ChoiceTipoLinea;
extern Fl_Group *GrupoBarcode;
#include <FL/Fl_Round_Button.H>
extern Fl_Round_Button *CheckInvertirBarcode;
extern Fl_Counter *IndicadorEscalaBarcode;
extern Fl_Counter *IndicadorSeparacionBarrasBarcode;
extern Fl_Counter *BarcodeMinX;
extern Fl_Counter *BarcodeMinY;
extern Fl_Group *GrupoGrafico;
#include <FL/Fl_File_Browser.H>
extern Fl_File_Browser *FileBrowserArchivosPlt;
extern Fl_Counter *GraficoMinX;
extern Fl_Counter *GraficoMinY;
extern Fl_Button *Cancelar_VentanaDetallesLinea;
extern Fl_Button *Aceptar_VentanaDetallesLinea;
extern Fl_Group *GrupoTextoCircular;
extern Fl_Counter *Angulo;
extern Fl_Counter *Radio;
extern Fl_Counter *TextoCircularCentroX;
extern Fl_Counter *TextoCircularCentroY;
extern Fl_Group *GrupoTexto;
extern Fl_Counter *TextoMinX;
extern Fl_Counter *TextoMinY;
extern "C" { Fl_Double_Window* Make_Window_Detalles_Linea(); }
extern Fl_Double_Window *VentanaTrabajos;
extern Fl_Box *LogoItacaVentanaTrabajos;
extern Fl_File_Browser *FileBrowserArchivosTrabajos;
extern Fl_Output *CuadroTextoTrabajo;
extern Fl_Group *GrupoTecladoTrabajos;
extern Fl_Button *Boton1t;
extern Fl_Button *Boton2t;
extern Fl_Button *Boton3t;
extern Fl_Button *Boton4t;
extern Fl_Button *Boton5t;
extern Fl_Button *Boton6t;
extern Fl_Button *Boton7t;
extern Fl_Button *Boton8t;
extern Fl_Button *Boton9t;
extern Fl_Button *Boton0t;
extern Fl_Button *BotonBorrart;
extern Fl_Button *BotonQt;
extern Fl_Button *BotonWt;
extern Fl_Button *BotonEt;
extern Fl_Button *BotonRt;
extern Fl_Button *BotonTt;
extern Fl_Button *BotonYt;
extern Fl_Button *BotonUt;
extern Fl_Button *BotonIt;
extern Fl_Button *BotonOt;
extern Fl_Button *BotonPt;
extern Fl_Button *BotonAt;
extern Fl_Button *BotonSt;
extern Fl_Button *BotonDt;
extern Fl_Button *BotonFt;
extern Fl_Button *BotonGt;
extern Fl_Button *BotonHt;
extern Fl_Button *BotonJt;
extern Fl_Button *BotonKt;
extern Fl_Button *BotonLt;
extern Fl_Button *BotonEnhet;
extern Fl_Button *BotonXt;
extern Fl_Button *BotonCt;
extern Fl_Button *BotonVt;
extern Fl_Button *BotonBt;
extern Fl_Button *BotonNt;
extern Fl_Button *BotonMt;
extern Fl_Button *BotonZt;
extern Fl_Button *BotonEspaciot;
extern Fl_Button *BotonMenost;
extern Fl_Button *Cargar_VentanaTrabajos;
extern Fl_Button *Guardar_VentanaTrabajos;
extern Fl_Button *Cancelar_VentanaTrabajos;
extern Fl_Button *Borrar_VentanaTrabajos;
extern "C" { Fl_Double_Window* Make_Window_Trabajos(); }
extern Fl_Double_Window *VentanaMensaje;
extern Fl_Box *BoxVentanaMensaje;
extern Fl_Button *Aceptar_VentanaMensaje;
extern "C" { Fl_Double_Window* Make_Window_Mensaje(); }
extern Fl_Double_Window *VentanaPassword;
extern Fl_Output *CuadroTextoPassword;
extern Fl_Group *GrupoTecladop;
extern Fl_Button *Boton1p;
extern Fl_Button *Boton2p;
extern Fl_Button *Boton3p;
extern Fl_Button *Boton4p;
extern Fl_Button *Boton5p;
extern Fl_Button *Boton6p;
extern Fl_Button *Boton7p;
extern Fl_Button *Boton8p;
extern Fl_Button *Boton9p;
extern Fl_Button *Boton0p;
extern Fl_Button *BotonBorrarp;
extern Fl_Button *Cancelar_VentanaPassword;
extern Fl_Button *Aceptar_VentanaPassword;
extern "C" { Fl_Double_Window* Make_Window_Password(); }
extern Fl_Double_Window *VentanaConfirmarCargarTrabajo;
extern Fl_Button *Aceptar_VentanaConfirmarCargarTrabajo;
extern Fl_Button *Cancelar_VentanaConfirmarCargarTrabajo;
extern "C" { Fl_Double_Window* Make_Window_Confirmar_CargarTrabajo(); }
extern Fl_Double_Window *VentanaConfirmarGuardarTrabajo;
extern Fl_Button *Aceptar_VentanaConfirmarGuardarTrabajo;
extern Fl_Button *Cancelar_VentanaConfirmarGuardarTrabajo;
extern "C" { Fl_Double_Window* Make_Window_Confirmar_GuardarTrabajo(); }
extern Fl_Double_Window *VentanaConfirmarBorrarTrabajo;
extern Fl_Button *Aceptar_VentanaConfirmarBorrarTrabajo;
extern Fl_Button *Cancelar_VentanaConfirmarBorrarTrabajo;
extern "C" { Fl_Double_Window* Make_Window_Confirmar_BorrarTrabajo(); }
extern Fl_Double_Window *VentanaFPGA;
extern Fl_Button *Aceptar_VentanaFPGA;
extern Fl_Button *LaserOn;
extern Fl_Button *LaserOff;
extern Fl_Button *TicksUp;
extern Fl_Button *TicksDown;
extern Fl_Button *GalvosOn;
extern Fl_Button *GalvosOff;
extern Fl_Button *ControlOn;
extern Fl_Button *ControlOff;
extern Fl_Button *LaserEnableOn;
extern Fl_Button *LaserEnableOff;
extern Fl_Button *ExtractorOn;
extern Fl_Button *ExtractorOff;
extern Fl_Button *MarkInProgressOn;
extern Fl_Button *MarkInProgressOff;
extern Fl_Button *Unconfigure;
extern Fl_Button *Reset;
extern Fl_Button *EncoderOn;
extern Fl_Button *EncoderOff;
#include <FL/Fl_Value_Output.H>
extern Fl_Value_Output *CuentasEncoder;
extern Fl_Button *LeerEncoder;
extern Fl_Value_Output *Fotocelula;
extern Fl_Button *LeerFotocelula;
extern Fl_Value_Output *LaserOk;
extern Fl_Button *LeerLaserOk;
extern Fl_Value_Output *TemperaturaOk;
extern Fl_Button *LeerTemperaturaOk;
extern Fl_Value_Output *ExtractorOk;
extern Fl_Button *LeerExtractorOk;
extern Fl_Button *LeeGalvoX;
extern Fl_Value_Output *GalvoX;
extern Fl_Button *LeeGalvoY;
extern Fl_Value_Output *GalvoY;
extern Fl_Counter *FPGAEscribirGalvoX;
extern Fl_Counter *FPGAEscribirGalvoY;
extern "C" { Fl_Double_Window* Make_Window_FPGA(); }
extern Fl_Double_Window *VentanaRepeticiones;
extern Fl_Group *GrupoFilas;
extern Fl_Counter *IndicadorFilas;
extern Fl_Counter *IndicadorSeparacionFilas;
extern Fl_Group *GrupoColumnas;
extern Fl_Counter *IndicadorColumnas;
extern Fl_Counter *IndicadorSeparacionColumnas;
extern Fl_Group *GrupoPrecorte;
extern Fl_Round_Button *CheckPrecorte;
extern Fl_Counter *IndicadorLongitudPrecorte;
extern Fl_Counter *IndicadorSeparacionPrecorte;
extern Fl_Counter *IndicadorVelocidadPrecorte;
extern Fl_Button *Cancelar_VentanaRepeticiones;
extern Fl_Button *Aceptar_VentanaRepeticiones;
extern "C" { Fl_Double_Window* Make_Window_Repeticiones(); }
extern "C" { void CargarVentanaModificarTexto(); }
extern "C" { void CargarVentanaDetallesLinea(); }
extern "C" { void CargarVentanaTrabajos(); }
extern "C" { void CargarVentanaPassword(); }
extern "C" { void CargarVentanaConfirmarCargarTrabajo(); }
extern "C" { void CargarVentanaConfirmarGuardarTrabajo(); }
extern "C" { void CargarVentanaConfirmarBorrarTrabajo(); }
extern "C" { void CargarVentanaRepeticiones(); }
extern "C" { int CrearBarcode(int linea, int bloque); }
extern "C" { void CargarTexto(); }
extern "C" { void ProcesarCaracter(const char *caracter); }
extern "C" { void ProcesarTexto(); }
extern "C" { void LineaTexto_calcular(int linea, int bloque); }
extern "C" { int Leer_Configuracion(); }
extern "C" { int Escribir_Configuracion(); }
extern "C" { int Leer_DAT(char ArchivoDat[50]); }
extern "C" { int Escribir_DAT(char ArchivoDat[50]); }
extern "C" { void Inicializar_Marcaje(); }
extern "C" { int Inicializar_Control(); }
extern "C" { int Inicializar_DAQ_comedi(); }
extern "C" { int Desactivar_DAQ_comedi(); }
extern "C" { int Inicializar_FPGA(); }
extern "C" { int DescargarFirmwareFPGA(); }
extern "C" { int Desactivar_FPGA(); }
extern "C" { int Inicializar_Galvos(); }
extern "C" { int Inicializar_RTAI(); }
extern "C" { void Desactivar_RTAI(); }
extern "C" { int Inicializar_thread_estado(); }
extern "C" { void *timer_estado(void *); }
extern "C" { int Desactivar_thread_estado(); }
extern "C" { int Inicializar_PuertoSerie(); }
extern "C" { void ControlPuertoSerie(void *); }
extern "C" { bool CaracterValido(int num); }
extern "C" { int Desactivar_PuertoSerie(); }
extern "C" { void ProcesarError(); }
extern "C" { void *timer_handler(void *args); }
extern "C" { int Inicializar_Laser(); }
extern "C" { int Desactivar_Laser(); }
extern "C" { int Control_Laser(int OnOff); }
extern "C" { int Inicializar_Encoder(); }
extern "C" { int Desactivar_Encoder(); }
extern "C" { int CalcularMatriz(); }
extern "C" { int CalcularMatrizCaracter(); }
extern "C" { int CalcularMatrizAtomos(); }
extern "C" { int CalcularMatrizFueraCampo(); }
extern "C" { int CalcularMatrizComponer(); }
extern "C" { void OrdenarAtomos(tipo_atomo atomos[], int tipo, int inicio, int fin); }
extern "C" { void OrdenarAtomosFueraCampo(tipo_atomo atomos[], int tipo, int inicio, int fin); }
extern "C" { int EncontrarParametros(char caracter); }
extern "C" { int LeerArchivoFuentes(); }
extern "C" { int EncontrarParametrosBarcode(); }
extern "C" { int EncontrarParametrosPlt(); }
extern "C" { int LeerArchivoPlt(char ArchivoPlt[MaximoLineasArchivoPlt][50]); }
extern "C" { int CalcularMatrizCampo(); }
extern "C" { void DescargarLista(int lista); }
extern "C" { int EjecutarLista(short lista); }
extern "C" { int Set_Start_List(int lista); }
extern "C" { int Set_End_Of_List(int lista); }
extern "C" { int Mark(int xdestino, int ydestino); }
extern "C" { int MarkPrecorte(int xdestino, int ydestino); }
extern "C" { int Jump(int xdestino, int ydestino); }
extern "C" { int PolA(int xdestino, int ydestino); }
extern "C" { int PolB(int xdestino, int ydestino); }
extern "C" { int PolC(int xdestino, int ydestino); }
extern "C" { int CalcularMarkStepSize(); }
extern "C" { int CalcularJumpStepSize(); }
extern "C" { int StartEjecucion(); }
extern "C" { int StopEjecucion(); }
extern "C" { void ControlEjecucionListas(void*); }
extern "C" { int ControlMarkInProgress(int OnOff); }
extern "C" { int EjecutarMicrovector(int lista); }
extern "C" { int ActualizarFechaHoraSerie(); }
extern "C" { void CalcularTurno(struct tm *loctime, char* returnstr); }
extern "C" { int Mayusculas(char caracter); }
extern "C" { int ObtenerPosicionActual(); }
extern "C" { int CalcularMoverGalvos(int xdestino, int ydestino); }
extern "C" { void MoverGalvos(); }
extern "C" { int ComprobarPosicion(int x_teorica, int y_teorica); }
void InicializarIndicadorHorizontal();
void InicializarIndicadorVertical();
lsampl_t itaca_comedi_from_phys(double volts);
double itaca_comedi_to_phys(lsampl_t dato);
lsampl_t itaca_comedi_reset(comedi_t *device, unsigned subdevice);
lsampl_t itaca_comedi_arm(comedi_t *device, unsigned subdevice, unsigned target);
lsampl_t itaca_comedi_set_counter_mode(comedi_t *device, unsigned subdevice, unsigned channel, unsigned mode_bits);
lsampl_t itaca_comedi_set_clock_source(comedi_t *device, unsigned subdevice, unsigned clock, unsigned period_ns);
lsampl_t itaca_comedi_set_gate_source(comedi_t *device, unsigned subdevice, unsigned channel,
	unsigned gate_index, unsigned gate_source);
lsampl_t itaca_comedi_set_routing(comedi_t *device, unsigned subdevice, unsigned channel, unsigned routing);
extern "C" { void ActualizaUI(void *); }
extern "C" { void ActualizaControlAcceso(void *); }
extern "C" { void ExitOrdenadamente(); }
extern "C" { void Inicializar_Widgets(); }
extern "C" { int ValidarSistema(); }
short int FPGA_from_phys(double volts);
double FPGA_to_phys(short int dato);
extern "C" { void EscribirGalvoX_FPGA(short valor); }
extern "C" { void EscribirGalvoY_FPGA(short valor); }
extern "C" { short LeerPosicionGalvoX_FPGA(); }
extern "C" { short LeerPosicionGalvoY_FPGA(); }
extern "C" { unsigned short LeerCuentasEncoder_FPGA(); }
float Maximo(float a, float b, float c);
extern "C" { int Iniciar_Oscilador_Fibra(); }
extern "C" { int Llevar_Galvos_Origen(); }
extern "C" { int CalcularCorreccionVector(int xsincorregir, int ysincorregir); }
extern "C" { int CalcularCorreccionMicrovector(double xsincorregirMV,double ysincorregirMV); }
extern "C" { int Parar_Oscilador_Fibra(); }
extern Fl_Double_Window *VentanaPrincipal;
extern Fl_Box *LedLaser;
extern Fl_Button *LedEstado;
extern Fl_Box *LogoItacaVentanaPrincipal;
extern Fl_Box *BoxVersionSW;
extern Fl_Value_Output *CuadroTextoContador;
extern Fl_Value_Output *CuadroTextoVLinea;
extern Fl_Value_Output *CuadroTextoTMarca;
extern Fl_Group *GrupoControlIntensidad;
extern Fl_Counter *IndicadorPotencia;
extern Fl_Counter *IndicadorVelocidad;
extern Fl_Group *GrupoControlMarca;
extern Fl_Counter *IndicadorHorizontal;
extern Fl_Counter *IndicadorVertical;
extern Fl_Choice *ChoiceFuente;
extern Fl_Counter *IndicadorAnchura;
extern Fl_Counter *IndicadorEspaciado;
extern Fl_Counter *IndicadorSeparacion;
extern Fl_Group *SubgrupoJustificacion;
extern Fl_Round_Button *CheckJustificacionCentro;
extern Fl_Round_Button *CheckJustificacionDerecha;
extern Fl_Round_Button *CheckJustificacionIzquierda;
extern Fl_Group *GrupoControlTexto;
extern Fl_Group *SubGrupoLinea1;
extern Fl_Output *CuadroTextoLinea1;
extern Fl_Counter *IndicadorAlturaLinea1;
extern Fl_Button *BotonDetallesLinea1;
extern Fl_Group *SubGrupoLinea2;
extern Fl_Output *CuadroTextoLinea2;
extern Fl_Counter *IndicadorAlturaLinea2;
extern Fl_Button *BotonDetallesLinea2;
extern Fl_Group *SubGrupoLinea3;
extern Fl_Output *CuadroTextoLinea3;
extern Fl_Counter *IndicadorAlturaLinea3;
extern Fl_Button *BotonDetallesLinea3;
extern Fl_Group *SubGrupoLinea4;
extern Fl_Output *CuadroTextoLinea4;
extern Fl_Counter *IndicadorAlturaLinea4;
extern Fl_Button *BotonDetallesLinea4;
extern Fl_Group *GrupoControlTextoBloques;
extern Fl_Group *SubGrupoLinea1Bloques;
extern Fl_Output *CuadroTextoLinea1Bloque1;
extern Fl_Counter *IndicadorAlturaLinea1Bloque1;
extern Fl_Button *BotonDetallesLinea1Bloque1;
extern Fl_Output *CuadroTextoLinea1Bloque2;
extern Fl_Counter *IndicadorAlturaLinea1Bloque2;
extern Fl_Button *BotonDetallesLinea1Bloque2;
extern Fl_Output *CuadroTextoLinea1Bloque3;
extern Fl_Counter *IndicadorAlturaLinea1Bloque3;
extern Fl_Button *BotonDetallesLinea1Bloque3;
extern Fl_Group *SubGrupoLinea2Bloques;
extern Fl_Output *CuadroTextoLinea2Bloque1;
extern Fl_Counter *IndicadorAlturaLinea2Bloque1;
extern Fl_Button *BotonDetallesLinea2Bloque1;
extern Fl_Output *CuadroTextoLinea2Bloque2;
extern Fl_Counter *IndicadorAlturaLinea2Bloque2;
extern Fl_Button *BotonDetallesLinea2Bloque2;
extern Fl_Output *CuadroTextoLinea2Bloque3;
extern Fl_Counter *IndicadorAlturaLinea2Bloque3;
extern Fl_Button *BotonDetallesLinea2Bloque3;
extern Fl_Group *SubGrupoLinea3Bloques;
extern Fl_Output *CuadroTextoLinea3Bloque1;
extern Fl_Counter *IndicadorAlturaLinea3Bloque1;
extern Fl_Button *BotonDetallesLinea3Bloque1;
extern Fl_Output *CuadroTextoLinea3Bloque2;
extern Fl_Counter *IndicadorAlturaLinea3Bloque2;
extern Fl_Button *BotonDetallesLinea3Bloque2;
extern Fl_Output *CuadroTextoLinea3Bloque3;
extern Fl_Counter *IndicadorAlturaLinea3Bloque3;
extern Fl_Button *BotonDetallesLinea3Bloque3;
extern Fl_Group *SubGrupoLinea4Bloques;
extern Fl_Output *CuadroTextoLinea4Bloque1;
extern Fl_Counter *IndicadorAlturaLinea4Bloque1;
extern Fl_Button *BotonDetallesLinea4Bloque1;
extern Fl_Output *CuadroTextoLinea4Bloque2;
extern Fl_Counter *IndicadorAlturaLinea4Bloque2;
extern Fl_Button *BotonDetallesLinea4Bloque2;
extern Fl_Output *CuadroTextoLinea4Bloque3;
extern Fl_Counter *IndicadorAlturaLinea4Bloque3;
extern Fl_Button *BotonDetallesLinea4Bloque3;
extern Fl_Group *GrupoControlOperacion;
#include <FL/Fl_Light_Button.H>
extern Fl_Light_Button *BotonMarcar;
extern Fl_Light_Button *BotonPrueba;
extern Fl_Button *BotonStop;
extern Fl_Button *BotonTrabajos;
extern Fl_Button *BotonTablaPrecorte;
extern Fl_Button *BotonApagar;
extern Fl_Light_Button *BotonLaser;
extern Fl_Light_Button *BotonCampo;
extern Fl_Counter *CounterEncoder;
extern Fl_Counter *CounterVelocidadLinea;
extern Fl_Counter *CounterRetardoDisparo;
extern Fl_Counter *CounterSeparacionEntreDisparos;
extern Fl_Button *BotonFPGA;
extern Fl_Button *BotonResetContador;
extern "C" { int Leer_Entradas_Temperatura(); }
extern "C" { int Salida_PWM_Ventilador(); }
#endif
