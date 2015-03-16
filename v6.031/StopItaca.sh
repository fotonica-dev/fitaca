# Mata el programa 
kill -9 ` ps ax | grep ./itaca | grep -v grep | awk '{print $1}' `

# Detiene el watchdog
echo V > /dev/watchdog
