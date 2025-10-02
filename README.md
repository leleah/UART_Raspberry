Simple UART TX/RX C-project

Simple example of programm on C for reception and broadcast data 
through UART on Rapsberry Pi. Code opens port /dev/ttyS0, sends and
assepts string by simbols to the end of the message.

Opportunities
-Broadcast string through UART (write()).
-Reception data in non-block mode(O_NONBLOCK).
-Accumulating data by-simbols for the rnd of the string.
-Clear input buffer before the work starts (tcflush).

Progect struct

-main.c
-README.md

Before program starts

sudo raspi-config
-Disable Serial Consile
-Enable Serial Port
  
