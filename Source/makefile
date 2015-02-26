#
CFLAGS=-Wall -g
XMLFLAGS=`xml2-config --cflags` -g
LIBS=`xml2-config --libs`

# Regla para generar todos los ejecutables: tanto el del prototipo como los de las pruebas separadas

all: Juego cabecera PruebaEspacio PruebaUnion PruebaJugador PruebaInventario PruebaObjeto PruebaConjunto

# Regla para generar todos los archivos objeto

ArchivosObjeto: PirateShip.c Accion.c Mundo.c Espacio.c Union.c Jugador.c Inventario.c Objeto.c Conjunto.c Lectorxml.c ReglasDialogo.c LectorReglasDialogo.c UtilCadena.c Animacion.c ClienteEspacio.c ClienteUnion.c ClienteJugador.c ClienteInventario.c ClienteConjunto.c ClienteObjeto.c
	gcc $(XMLFLAGS) -c PirateShip.c Accion.c Mundo.c Espacio.c Union.c Jugador.c Inventario.c Objeto.c Conjunto.c Lectorxml.c ReglasDialogo.c LectorReglasDialogo.c UtilCadena.c Animacion.c ClienteEspacio.c ClienteUnion.c ClienteJugador.c ClienteInventario.c ClienteConjunto.c ClienteObjeto.c

# Regla para generar el juego

Juego: ArchivosObjeto
	gcc $(LIBS) $(CFLAGS) -o PirateShip PirateShip.o Lectorxml.o Accion.o Mundo.o Espacio.o Union.o Jugador.o Inventario.o Conjunto.o Objeto.o ReglasDialogo.o LectorReglasDialogo.o UtilCadena.o Animacion.o

# Reglas para generar cada modulo con su cliente de pruebas por separado

PruebaEspacio: ArchivosObjeto
	gcc -o PruebaEspacio ClienteEspacio.o Espacio.o Conjunto.o

PruebaUnion: ArchivosObjeto
	gcc -o PruebaUnion ClienteUnion.o Union.o

PruebaJugador: ArchivosObjeto
	gcc -o PruebaJugador ClienteJugador.o Jugador.o Inventario.o Conjunto.o

PruebaInventario: ArchivosObjeto
	gcc -o PruebaInventario ClienteInventario.o Inventario.o Conjunto.o

PruebaConjunto: ArchivosObjeto
	gcc -o PruebaConjunto ClienteConjunto.o Conjunto.o

PruebaObjeto: ArchivosObjeto
	gcc -o PruebaObjeto ClienteObjeto.o Objeto.o Conjunto.o


# Regla para limpiar los archivos que se crean en los proceso intermedios
clean:
	rm -f PirateShip.o Accion.o Mundo.o Espacio.o Union.o Jugador.o Inventario.o Objeto.o Conjunto.o Lectorxml.o ReglasDialogo.o LectorReglasDialogo.o UtilCadena.o Animacion.o ClienteEspacio.o ClienteUnion.o ClienteJugador.o ClienteInventario.o ClienteConjunto.o ClienteObjeto.o

cabecera:
	@ echo "--------------------------------------------------------------"
	@ echo " Proyecto desarrollado por el grupo 01, compuesto por  "
	@ echo "      Colmenar Guindal, Irene;"
	@ echo "      Cornet Recchimuzzi, Juan Manuel;"
	@ echo "      Ortiz Martin, Alejandro;"
	@ echo "--------------------------------------------------------------"
