//==============================================================================
// Include files
//==============================================================================

#include <stdio.h>	/* Standard input/output definitions */
#include <errno.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/io.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

// RTAI
#include <rtai_lxrt.h>
#include <pthread.h>

// Tarjeta ADLINK Daq2502
//#include "conio.h"
//#include "d2kdask.h"

// Comedi
#include <comedilib.h>
//#include <rtai_comedi.h>

// fltk
#include <string.h>	/* String function definitions */
#include <cstdlib>

// watchdog
#include <unistd.h>	/* UNIX standard function definitions */
#include <fcntl.h>	/* File control definitions */
#include <linux/watchdog.h>

// códigos de barras zint
#include <zint.h>

// puerto serie
#include <errno.h>   	/* Error number definitions */
#include <termios.h> 	/* POSIX terminal control definitions */


