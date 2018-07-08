# SDCC C MSX 32K 4000h ROM startup file (CRT)

Version: 1.1

Date: 12/04/2018

Author: mvac7/303bcn

Architecture: MSX

Format: C Object (SDCC .rel)

Programming language: C

WEB:
 
mail: mvac7303b@gmail.com



History of versions:
- v1.1 (12/04/2018) Current version
- v1.0 (25/04/2010) Initial version



## 1. Introduction

This project is an opensource library (object type).

Startup file (CRT) for developing MSX 32K ROM applications using Small Device C Compiler (SDCC). 

This CRT includes the header of the MSX ROM, initializes the stack, configures 
the second page of the ROM, and executes the main function. 
The ROM is allocated in the second bank (4000h).
  
It includes winOS and Linux scripts for compiling a 32K projects.  
This script compile and generate the binary with the appropriate size.

This startup uses the rutine *find_rom_page_2* created by **Eduardo Robsy**


Example for compile and create a 32K ROM binary:
  
`sdcc -mz80 --code-loc 0x4050 --data-loc 0xC000 --use-stdout --no-std-crt0 crt0_MSX32kROM4000.rel CFILENAME.c`                           
`hex2bin -e ROM -s 4000 -l 8000 CFILENAME.ihx`   <--- generate a binary file and fill to 32768 Bytes size (8000h) 


In the test\ folder you will find an example (HelloWorld).



## 2. Acknowledgments
  
Thanks for Info & help, to:

* Avelino Herrera > http://msx.atlantes.org/index_es.html
* Nerlaska > http://albertodehoyonebot.blogspot.com.es
* Eduardo Robsy
* Fubu > http://www.gamerachan.org/fubu/
* Marq/Lieves!Tuore > http://www.kameli.net/lt/
* Sapphire/Z80ST > http://z80st.auic.es/
* Pentacour > http://pentacour.com/
* JamQue/TPM > http://www.thepetsmode.com/
* Andrear > http://andrear.altervista.org/home/msxsoftware.php
* Konamiman > https://www.konamiman.com
* MSX Assembly Page > http://map.grauw.nl/resources/msxbios.php
* Portar MSX Tech Doc > http://nocash.emubase.de/portar.htm
* MSX Resource Center > http://www.msx.org/
* Karoshi MSX Community > http://karoshi.auic.es/
* BlueMSX >> http://www.bluemsx.com/
* OpenMSX >> http://openmsx.sourceforge.net/
* Meisei



## 3. Requirements

* Small Device C Compiler (SDCC) v3.6 http://sdcc.sourceforge.net/
* Hex2bin v2.2 http://hex2bin.sourceforge.net/ 



## 4. How to use the script

In this project, you have the MAKEFILE for Windows and Linux OS.

To adapt the script to your project, you must follow the following steps:

1. Copy the **Makefile** into the root path of your project.
2. Edit the Makefile with your favourite editor.
3. Put the sourcecode file name without extension at `CFILENAME` field.
4. Put the output ROM file name without extension at `ROMFILENAME` field.
5. Place the file paths of the objects in the `LIBn` fields.

To work, need this directory structure:

- src\      <--- sources
- include\  <--- headers (.h) files
- libs\     <--- libraries or object (.rel) files.
- build\    <--- output files from compilator
- bin\      <--- result ROM file

The script will create the \build and \bin directories, when they do not exist.
