#!/bin/bash

# monta la partici�n en modo de escritura
mount / -o rw,remount

# saca la ventana del cambio de fecha y hora
kcmshell clock
#kcmshell --lang es clock

# actualiza el reloj de la BIOS
hwclock --systohc

# monta la partici�n en modo de lectura
mount / -o ro,remount
