#
# ZDS II Make File - projektet, Debug
#

CC = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy
#   -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc -NOjmpopt
#   -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse
#   -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L -NOoptlink
#   -optsize -peephole -NOpromote -quiet -regvar -revaa -NOsdiopt
#   -shortsize:16
#   -stdinc:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict
#   -usrinc:"C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\projektet_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\projektet_Debug.asmsw

OUTDIR = C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\

Debug: projektet

deltarget: 
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\projektet.lod  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\projektet.lod

clean: 
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\projektet.lod  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\projektet.lod
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\zsldevinit.obj  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\zsldevinit.obj
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\main.obj  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\main.obj
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\ansi.obj  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\ansi.obj
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\draw.obj  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\draw.obj
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\hardware.obj  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\hardware.obj
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\led.obj  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\led.obj
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\sin.obj  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\sin.obj
	@if exist C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\spil.obj  \
            del C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\spil.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\zsldevinit.obj  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\main.obj  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\ansi.obj  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\draw.obj  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\hardware.obj  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\led.obj  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\sin.obj  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\spil.obj

projektet: $(OBJS)
	 $(LINK)  @C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\projektet_Debug.linkcmd

C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\zsldevinit.obj :  \
<<<<<<< HEAD
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\zsldevinit.asm
=======
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
>>>>>>> b73b5eae283dbe68e10ee58c0bc35d7a973d72c5
	 $(ASM)  $(AFLAGS) C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\zsldevinit.asm

C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\main.obj :  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\main.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\LED.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\ansi.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\hardware.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\main.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\sin.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\spil.h
	 $(CC)  $(CFLAGS) C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\main.c

C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\ansi.obj :  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\ansi.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\ansi.c

C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\draw.obj :  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\draw.c
	 $(CC)  $(CFLAGS) C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\draw.c

C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\hardware.obj :  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\hardware.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\LED.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\ansi.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\hardware.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\main.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\sin.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\spil.h
	 $(CC)  $(CFLAGS) C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\hardware.c

C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\led.obj :  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\led.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\charset.h
	 $(CC)  $(CFLAGS) C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\led.c

C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\sin.obj :  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\sin.c  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\sin.h
	 $(CC)  $(CFLAGS) C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\sin.c

C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\PROJEC~1\spil.obj :  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\spil.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\LED.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\ansi.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\hardware.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\main.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\sin.h  \
            C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\spil.h
	 $(CC)  $(CFLAGS) C:\Users\Nikolaj\OneDrive\DTU\28900~1.SEM\3UGERS~1\Z8encore\REFLEX~1\include\src\spil.c

