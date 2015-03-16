#!/bin/bash

# desactiva la función de power saving del monitor
/usr/bin/xset -dpms

# desactiva el cursor cuando no se usa, hasta que se mueva
/usr/src/unclutter/unclutter&

# configura el driver comedi
#modprobe ni_pcimio

# VNC
/usr/local/bin/x11vnc&

# Cambia al directorio de trabajo
cd /root/itaca

# Arranca la aplicación
ValorExit=./itaca

# Si se ha salido del programa de forma correcta, apaga el sistema
if $ValorExit -eq "0" 
  then init 0
# si se ha salido de mala manera desactiva el watchdog
else
  echo V > /dev/watchdog
fi
