@echo off
REM MAKEFILE for 32K ROMs using SDCC compiler
REM CFILENAME = Source name without extension
REM ROMFILENAME = ROM file name without extension
SET CFILENAME=HelloWorld
SET ROMFILENAME=HELLOW32
SET CODELOC=0x4050
SET CRT=libs\crt0_MSX32kROM4000.rel
REM add paths from our objects files into LIBn variables
REM don't erase empty variables
SET LIB0=
SET LIB1=
SET LIB2=
SET LIB3=
SET LIB4=
SET LIB5=
SET LIB6=
SET LIB7=
SET LIB8=
SET LIB9=
SET LIB10=
SET LIB11=
SET LIB12=
if exist build\ goto NEXTSTEP1
echo MAKEDIR build
md build
:NEXTSTEP1
if exist bin\ goto NEXTSTEP2
echo MAKEDIR bin
md bin
:NEXTSTEP2
REM get SDCC version
sdcc -v
if not exist build\%CFILENAME%.ihx goto COMPILA
del build\%CFILENAME%.ihx
:COMPILA
echo Compiling...
sdcc -mz80 -o build\ --code-loc %CODELOC% --data-loc 0xC000 --use-stdout --no-std-crt0 %CRT% %LIB0% %LIB1% %LIB2% %LIB3% %LIB4% %LIB5% %LIB6% %LIB7% %LIB8% %LIB9% %LIB10% %LIB11% %LIB12% src\%CFILENAME%.c
if not exist build\%CFILENAME%.ihx goto SALIDA
hex2bin -e bin -s 4000 -l 8000 build\%CFILENAME%.ihx
copy build\%CFILENAME%.bin bin\%ROMFILENAME%.ROM
pause
exit /b
:SALIDA
echo ERROR
pause
exit /b