CFLAGS=-Wall
FUENTES=parser.cpp main.cpp tokens.cpp Codigo.cpp PilaTablaSimbolos.cpp TablaSimbolos.cpp

all: parser prueba

clean:
	rm parser.cpp parser.hpp parser tokens.cpp *~

parser.cpp parser.hpp: parser.y 
	bison -d -o $@ $<

tokens.cpp: tokens.l parser.hpp 
	lex -o $@ $<

parser: $(FUENTES) Codigo.hpp Exp.hpp PilaTablaSimbolos.hpp TablaSimbolos.hpp
	g++ $(CFLAGS) -o $@ $(FUENTES) 

prueba:
	./parser <../pruebaBuena1.dat	
	./parser <../pruebaBuena2.dat
	./parser <../pruebaBuena3.dat
	./parser <../pruebaBuena4.dat
	./parser <../pruebaBuena5.dat
	./parser <../pruebaMala1.dat
	./parser <../pruebaMala2.dat
	./parser <../pruebaMala3.dat
	./parser <../pruebaMala4.dat
	./parser <../pruebaMala5.dat
	./parser <../pruebaMala6.dat

