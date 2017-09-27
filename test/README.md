Compile with command:
gcc -o spidev_test spidev_test.c 

Then run with command:
./spidev_test -D /dev/spidev0.x

x is 0 or 1 depending which you want to use

If SPI works correct, should print:

spi mode: 0
bits per word: 8
max speed: 500000

FF FF FF FF FF FF
40 00 00 00 00 95
FF FF FF FF FF FF
FF FF FF FF FF FF
FF FF FF FF FF FF
DE AD BE EF BA AD
F0 0D
