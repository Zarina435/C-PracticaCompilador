%{
   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;
   void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
   }

   #include "Codigo.hpp"
   #include "Exp.hpp"
   #include "TablaSimbolos.hpp"
   #include "PilaTablaSimbolos.hpp"
   //#include "Aux.hpp"

   /* Funciones que se usan*/
   expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) ;
   expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) ;
   vector<int> *unir(vector<int> lis1, vector<int> lis2);
   vector<string> *unirStrings (vector<string> lis1, vector<string> lis2);

   Codigo codigo;
   PilaTablaSimbolos stPila;
   string procedimiento;
   bool errores= false;
%}

/* 
   qué atributos tienen los tokens 
*/
%union {
    string *str ; 
    expresionstruct *expr;
    sentenciastruct *sen;
    int number;
    vector<string> *lid;
    vector<int> *numlist;
}

/* 
   declaración de tokens. Esto debe coincidir con tokens.l 
*/

%token <str> TSEMIC TASSIG TDOSPUNTOS TCOMA
%token <str> TIDENTIFIER TINTEGER TFLOAT
%token <str> TLLAVEI TLLAVED TPARENI TPAREND TREF
%token <str> TEQUAL TMAYOR TMENOR TMAYOREQ TMENOREQ TNOTEQUAL
%token <str> TPLUS TMINUS TMUL TDIV
%token <str> TAND TOR TNOT
%token <str> RDEF RMAIN RIF RELSE RWHILE RFOREVER RBREAK RCONTINUE RREAD RPRINT RLET RIN RINTEGER RFLOAT TFOR

%type <str> programa
%type <sen> bloque_ppl //str
%type <sen> bloque
%type <str> decl_bl
%type <str> declaraciones
%type <lid> lista_de_ident
%type <lid> resto_lista_id
%type <str> tipo
%type <str> decl_de_subprogs
%type <str> decl_de_subprograma
%type <str> argumentos
%type <lid> lista_de_param
%type <str> clase_par
%type <str> resto_lis_de_param
%type <sen> lista_de_sentencias
%type <sen> sentencia
%type <str> variable //o tipo <expr>???
%type <expr> expresion
%type <number> M
%type <numlist> N

//Prioridad y asociatividad de los operadores
%left TOR
%left TAND
%left TNOT
%nonassoc TASSIG TNOTEQUAL TMENOR TMENOREQ TMAYOR TMAYOREQ
%left TPLUS TMINUS
%left TMUL TDIV

%start programa
%%

programa : RDEF RMAIN TPARENI TPAREND TDOSPUNTOS  
            {
               TablaSimbolos st;
               st.anadirVariable(*$1,"programa");
               stPila.empilar(st);

               codigo.anadirInstruccion("goto 5;");
               codigo.anadirInstruccion("Error en una división. No se puede dividir entre 0.;");
               codigo.anadirInstruccion("writeln;");
               codigo.anadirInstruccion("goto");
               codigo.anadirInstruccion("proc main");
            }
            bloque_ppl 
            {
               vector<int> tmp1; 
               tmp1.push_back(4);
               codigo.completarInstrucciones(tmp1, codigo.obtenRef());

               if(errores==false){
                  codigo.anadirInstruccion("halt");
                  codigo.escribir();
               }else{
                  YYABORT;
               }
               //stPila.tope().print();
               stPila.desempilar();
            }
         ;

bloque_ppl  :  decl_bl TLLAVEI
               decl_de_subprogs
               lista_de_sentencias
               TLLAVED
               {
			         if (!$4->exits.empty()) {
				         yyerror("Error semántico. Break fuera de un bucle");
				         errores=true;
			         }else if (!$4->continues.empty()) {
				         yyerror("Error semántico. Continue fuera de una estructura de control");
				         errores=true;;
			         }
               }
            ;

bloque : TLLAVEI
         lista_de_sentencias
         TLLAVED
         {
         $$ = new sentenciastruct;
         $$->exits = $2->exits;
         $$->continues = $2->continues;
         }
       ;

decl_bl : RLET declaraciones RIN
        | /* empty */
        ;

declaraciones :   declaraciones TSEMIC lista_de_ident TDOSPUNTOS tipo
                  {
                     for(vector<string>::iterator i = $3->begin(); i != $3->end(); i++){
                        if (!stPila.tope().existeId(*i)){
                           stPila.tope().anadirVariable(*i, *$5);
                        }else{
                           yyerror("Id duplicado.");
                           errores=true;;
                        }
                     }
                     codigo.anadirDeclaraciones(*$3, *$5);
                  }
              |   lista_de_ident TDOSPUNTOS tipo
                  {
                     for(vector<string>::iterator i = $1->begin(); i != $1->end(); i++){
                        if (!stPila.tope().existeId(*i)){
                           stPila.tope().anadirVariable(*i, *$3);
                        }else{
                           yyerror("Id duplicado.");
                           errores=true;;
                        }
                     }
                     codigo.anadirDeclaraciones(*$1, *$3);
                  }
              ;

lista_de_ident :  TIDENTIFIER resto_lista_id
                  {
                     $$ = new vector<string>;
                     $$ = $2; //añadir resto_lista_id
                     $$->insert($$->begin(), *$1); //añadir al principio id
                  }
                  
               ;

resto_lista_id :  TCOMA TIDENTIFIER resto_lista_id
                  {
                     $$  = new vector<string>(*$3);
                     $$->insert($$->begin(), *$2);
                  }
               |  /* empty */
                  {
                     $$ = new vector<string>;
                  }
               ;

tipo :   RINTEGER
         { 
         $$ = new std::string("int");
         }
      |  RFLOAT
         { 
         $$ = new std::string("real");
         }
     ;

decl_de_subprogs : decl_de_subprograma decl_de_subprogs
                 | /* empty */
                 ;

decl_de_subprograma : RDEF TIDENTIFIER 
                        {  
                           procedimiento= *$2;
                           if (!stPila.tope().existeId(*$2)){
							         stPila.tope().anadirProcedimiento(*$2);
                           }else{
                              yyerror("Id duplicado.");
                              errores=true;;
                           }
                           TablaSimbolos st; 
						         stPila.empilar(st); 

                           codigo.anadirInstruccion("proc " + *$2); 
                        } // Duda si hay que poner "proc" o "def"
                      argumentos TDOSPUNTOS bloque_ppl 
                        { 
                           //stPila.tope().print();
                           stPila.desempilar();
                           codigo.anadirInstruccion("endproc " + *$2); 
                        } // Duda si hay que poner en tokens.l o dejar asi
                    ;

argumentos : TPARENI lista_de_param TPAREND
           | /* empty */
           ;

lista_de_param : lista_de_ident TDOSPUNTOS clase_par tipo
                 { 
                    for(vector<string>::iterator i = $1->begin(); i != $1->end(); i++){
                       if (!stPila.tope().existeId(*i)){
                          stPila.anadirParametro(procedimiento, *i, *$3, *$4);
                       }else{
                           yyerror("Id duplicado.");
                           errores=true;;
                        }
                    }

                    codigo.anadirParametros(*$1, *$4, *$3);
                  }
                 resto_lis_de_param
               ;

clase_par : /* empty */
            {
               $$ = new std::string("val");
            }
          | TREF { $$ = new std::string("ref"); }
          ;

resto_lis_de_param : TSEMIC lista_de_ident TDOSPUNTOS clase_par tipo 
                     { 
                        for(vector<string>::iterator i = $2->begin(); i != $2->end(); i++){
                           if (!stPila.tope().existeId(*i)){
                              stPila.anadirParametro(procedimiento, *i, *$4, *$5);
                           }else{
                              yyerror("Id duplicado.");
                              errores=true;;
                           }
                        }
                        
                        codigo.anadirParametros(*$2, *$5, *$4);  
                     }

                     resto_lis_de_param
                     | /* empty */
                     ;

lista_de_sentencias : sentencia lista_de_sentencias 
                     {
                        $$ = new sentenciastruct;
                        $$->exits = *unir($1->exits, $2->exits);
                        $$->continues= *unir($1->continues, $2->continues);
                        delete $1; delete $2;
                     } 
                    | /* empty */ 
                     {  
                       $$ = new sentenciastruct;
                       $$->exits = * new vector<int>;
                       $$->continues = * new vector<int>;
                     }
                    ;

sentencia : variable TASSIG expresion TSEMIC
            {
               $$= new sentenciastruct;
               codigo.anadirInstruccion(*$1 + " := " + $3->str + ";") ; 
               $$->exits = * new vector<int>;
               $$->continues = * new vector<int>;
               $$->tipo= "asignacion";
               delete $1 ; delete $3;
            }
          | RIF expresion TDOSPUNTOS M bloque M
            {
               if ($2->tipo != "comparacion" && $2->tipo != "bool"){
                  yyerror("Error semántico en el if.");
                  errores=true;;
               }
               $$ = new sentenciastruct;
	      	   codigo.completarInstrucciones($2->trues,$4);
    	  	      codigo.completarInstrucciones($2->falses,$6);
	      	   $$->exits = $5->exits;
               $$->continues = $5->continues;
               //delete $2 ;
            }
          | RWHILE M expresion TDOSPUNTOS M bloque N RELSE TDOSPUNTOS M bloque M
            {
               if ($3->tipo != "comparacion" && $3->tipo != "bool"){
                  yyerror("Error semántico en el while.");
                  errores=true;;
               }
               $$ = new sentenciastruct;
               $$->exits = * new vector<int>;
               $$->continues = * new vector<int>;
               
	      	   codigo.completarInstrucciones($3->trues,$5);
    	  	      codigo.completarInstrucciones($3->falses,$10);
               codigo.completarInstrucciones(*$7,$2);
               codigo.completarInstrucciones($6->exits, $10);
               codigo.completarInstrucciones($6->continues, $2);
               codigo.completarInstrucciones($11->exits, $12);
               codigo.completarInstrucciones($11->continues, $2);
            }
          | RFOREVER TDOSPUNTOS M bloque N M 
            {
               $$ = new sentenciastruct;
               codigo.completarInstrucciones(*$5, $3);
               codigo.completarInstrucciones($4->exits, codigo.obtenRef());
               $$->exits = * new vector<int>;
               $$->continues = $4->continues;
            }
          | RBREAK RIF expresion TSEMIC
            {
               if ($3->tipo != "comparacion" && $3->tipo != "bool"){
                  yyerror("Error semántico en break.");
                  errores=true;;
               }
               $$ = new sentenciastruct;
               codigo.completarInstrucciones($3->falses, codigo.obtenRef());
               $$->exits =  * new vector<int>($3->trues);
               $$->continues = * new vector<int>;
               delete $2;
            }
          | RCONTINUE TSEMIC M
            {
               $$ = new sentenciastruct;
               codigo.anadirInstruccion("goto");
               $$->exits = * new vector<int>;
               
               vector<int> tmp1 ; tmp1.push_back($3) ;
               $$->continues = tmp1;
            }
          | RREAD TPARENI variable TPAREND TSEMIC
            {
               $$ = new sentenciastruct;
					$$->exits = * new vector<int>;
               $$->continues = * new vector<int>;
					codigo.anadirInstruccion("read "+ *$3 + ";");
            }
          | RPRINT TPARENI expresion TPAREND TSEMIC
            {
               $$ = new sentenciastruct;
					$$->exits = * new vector<int>;
               $$->continues = * new vector<int>;
					codigo.anadirInstruccion("write "+ $3->str + ";");
					codigo.anadirInstruccion("writeln;");
            }
          | TFOR TPARENI tipo TIDENTIFIER 
            {
               if (stPila.tope().existeId(*$4)){
						yyerror("Error en el for. El id ya existe.");
                  errores=true;
					}else{
                  stPila.tope().anadirVariable(*$4,*$3);
                  //stPila.tope().print();
                  /*TablaSimbolos st;
                  stPila.empilar(st);*/
                  
               }
               codigo.anadirInstruccion(*$3 + " "+ *$4 );
            }
          TASSIG expresion 
            {
               //Asignar la variable
               if ($7->tipo != "numero" && $7->tipo != "variable" && $7->tipo!= "operacion"){
                  yyerror("Error semántico en el for. La primera asignación expresiṕn no puede ser un booleano ni una comparación.");
                  errores=true;
               }
               codigo.anadirInstruccion(*$4 +*$6 + $7->str);
            }
          TSEMIC M expresion TSEMIC variable TASSIG expresion TPAREND TLLAVEI M lista_de_sentencias N TLLAVED M
            {
               if ($11->tipo != "comparacion" && $11->tipo != "bool"){
                  yyerror("Error semántico en el for. La expresiṕn no puede ser una operación.");
                  errores=true;
               }else if (*$4 != *$13) {
			         yyerror("Error semántico en el for. Se debe actualizar la variable de la expresión.");
                  errores=true;
               }
               if ( $15->tipo!= "operacion"){
                  yyerror("Error semántico en el for. La actualización de la variable debe ser una operación");
                  errores=true;
               }
               else{
                  codigo.completarInstrucciones($11->trues, $18);
                  codigo.completarInstrucciones($11->falses, $22);
                  //codigo.anadirInstruccion("goto" +$10);
                  codigo.completarInstrucciones(*$20, $10);
                  codigo.anadirInstruccion(*$13 +":=" +$15->str);

                  codigo.completarInstrucciones($19->exits, $22);
                  codigo.completarInstrucciones($19->continues, $10);

                  $$= new sentenciastruct;
                  $$->exits = * new vector<int>;
                  $$->continues = * new vector<int>;

               }                
            }
            | TIDENTIFIER TPARENI variable resto_lista_id TPAREND TSEMIC
               {  
                  //stPila.tope().print();
         
                  $$ = new sentenciastruct;
                  $$->exits = * new vector<int>;
                  $$->continues = * new vector<int>;
                  
                  vector<string> tmp1 ; 
                  tmp1.push_back(*$3) ;
                  if ($4->size() > 0){
                     tmp1 = *unirStrings(*$4,tmp1); 
                  }
                  
                  if (!stPila.tope().existeId(*$1)){
                     yyerror(" Error. No existe esa función");
                     errores=true;
                  }else{

                     bool argumentosIguales=stPila.verificarNumArgs(*$1,tmp1.size());
                     if(argumentosIguales==false){
                        yyerror(" Error. Número de argumentos diferente.");
                        errores=true;
                     }else{
                        //Declaraciones para el for
                        vector<string>::const_iterator iter;
                        int x;

                        for ( iter=tmp1.end()-1, x = 0; iter!=tmp1.begin()-1; iter--, x++) {
                           pair<string, string> tiposDoble;
                           string tipo=stPila.obtenerTipo(*iter);

                           tiposDoble = stPila.obtenerTiposParametro(*$1, x);
                           tipo = stPila.obtenerTipo(*iter);
                           if (tipo.compare(tiposDoble.second) != 0){
                              yyerror("Error semántico en la llamada a la función. Tipos incompatibles");
                              errores= true;
                           }else{
                              codigo.anadirInstruccion("param_" + tiposDoble.first + " " + *iter + ";");
                           }
                        }
                        codigo.anadirInstruccion("call "+*$1+";");
                     }
                  }
            }
          ;

M : /* empty */
   { $$ = codigo.obtenRef(); }
   ;
N : /* empty */ 
   { 
      $$ = new vector<int>;    
      vector<int> tmp1 ; tmp1.push_back(codigo.obtenRef()) ;
      *$$ = tmp1;
      codigo.anadirInstruccion("goto");
   }
   ;
variable : TIDENTIFIER
            {
               $$= $1;
            }
         ;

expresion : expresion TEQUAL expresion
            {
               if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }

               $$= new expresionstruct;
               $$->str= "";
               $$->trues = * new vector<int>(codigo.obtenRef());
               $$->falses = * new vector<int>(codigo.obtenRef()+1);
               *$$ = makecomparison($1->str,*$2,$3->str); 
               $$->tipo= "comparacion";

            }
          | expresion TMAYOR expresion
            {
               if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               $$= new expresionstruct;
               $$->str= "";
               $$->trues = * new vector<int>(codigo.obtenRef());
               $$->falses = * new vector<int>(codigo.obtenRef()+1);
               *$$ = makecomparison($1->str,*$2,$3->str); 
               $$->tipo= "comparacion";
            }
          | expresion TMENOR expresion
            {
                if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               $$= new expresionstruct;
               $$->str= "";
               $$->trues = * new vector<int>(codigo.obtenRef());
               $$->falses = * new vector<int>(codigo.obtenRef()+1);
               *$$ = makecomparison($1->str,*$2,$3->str);
               $$->tipo= "comparacion"; 
            }
          | expresion TMAYOREQ expresion
            {
                if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }

               $$= new expresionstruct;
               $$->str= "";
               $$->trues = * new vector<int>(codigo.obtenRef());
               $$->falses = * new vector<int>(codigo.obtenRef()+1);
               *$$ = makecomparison($1->str,*$2,$3->str); 
               $$->tipo= "comparacion"; 

            }
          | expresion TMENOREQ expresion
            {
                if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }

               $$= new expresionstruct;
               $$->str= "";
               $$->trues = * new vector<int>(codigo.obtenRef());
               $$->falses = * new vector<int>(codigo.obtenRef()+1);
               *$$ = makecomparison($1->str,*$2,$3->str);
               $$->tipo= "comparacion"; 

            }
          | expresion TNOTEQUAL expresion
            {
                if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }

               $$= new expresionstruct;
               $$->str= "";
               $$->trues = * new vector<int>(codigo.obtenRef());
               $$->falses = * new vector<int>(codigo.obtenRef()+1);
               *$$ = makecomparison($1->str,*$2,$3->str); 
               $$->tipo= "comparacion";

            }
          | expresion TPLUS expresion
            {
               if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               $$= new expresionstruct;
               $$->trues = * new vector<int>;
               $$->falses = * new vector<int>;
               *$$ = makearithmetic($1->str,*$2,$3->str);
               $$->tipo= "operacion"; 

            }
          | expresion TMINUS expresion
            {
                if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               $$= new expresionstruct;
               $$->trues = * new vector<int>;
               $$->falses = * new vector<int>;
               *$$ = makearithmetic($1->str,*$2,$3->str); 
               $$->tipo= "operacion";

            }
          | expresion TMUL expresion
            {
                if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               $$= new expresionstruct;
               $$->trues = * new vector<int>;
               $$->falses = * new vector<int>;
               *$$ = makearithmetic($1->str,*$2,$3->str);
               $$->tipo= "operacion";
            }
          | expresion TDIV expresion
            {
               if ($1->tipo== "bool" || $1->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($3->tipo== "bool" || $3->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               codigo.anadirInstruccion("if "+ $3->str + " = 0 goto 2;");
               $$= new expresionstruct;
               $$->trues = * new vector<int>;
               $$->falses = * new vector<int>;
               *$$ = makearithmetic($1->str,*$2,$3->str); 
               $$->tipo= "operacion";
            }
          | TIDENTIFIER

            {  if (!stPila.tope().existeId(*$1)){
               //stPila.tope().print();
						yyerror(" El id es inexistente.");
                  errores=true;
					}
               $$= new expresionstruct;
               $$->trues = * new vector<int>;
               $$->falses = * new vector<int>;
               $$->tipo = "variable";
               $$->str= *$1;
            }
          | TINTEGER
            {
               $$= new expresionstruct;
               $$->trues = * new vector<int>;
               $$->falses = * new vector<int>;
               $$->str = *$1;
               $$->tipo= "numero";
            }
          | TFLOAT
            {
               $$= new expresionstruct;
               $$->trues = * new vector<int>;
               $$->falses = * new vector<int>;
               $$->str = *$1;
               $$->tipo= "numero";
            }
          | TPARENI expresion TPAREND
            {
               $$= new expresionstruct;
               $$->trues = $2->trues;
               $$->falses = $2->falses;
               $$->str = $2->str;
               $$->tipo= $2->tipo;
            }
          | expresion TAND M expresion
            {
               if ($1->tipo!= "comparacion" && $1->tipo!="bool" ){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($4->tipo!= "comparacion" && $4->tipo!="bool"){
                  yyerror("Tipos incompatibles");
                 errores=true;
               }
               $$= new expresionstruct;
               codigo.completarInstrucciones($1->trues, $3);
               $$->trues = $4->trues;
               $$->falses = *unir($1->falses, $4->falses);
               $$->str= "";
               $$->tipo= "bool";
            }
          | expresion TOR M expresion
            {
               if ($1->tipo!= "comparacion" && $1->tipo!="bool"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ($4->tipo!= "comparacion" && $4->tipo!="bool"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               $$= new expresionstruct;
               codigo.completarInstrucciones($1->falses, $3);
               $$->trues = *unir($1->trues, $4->trues);
               $$->falses = $4->falses;
               $$->str= "";
               $$->tipo= "bool";
            }
          | TNOT expresion
            {
               if ($2->tipo!= "comparacion" && $2->tipo!="bool" ){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               $$= new expresionstruct;
               $$->trues = $2->falses;
               $$->falses = $2->trues;
               $$->str= "";
               $$->tipo= "bool";
            }
          ;
%%

expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 

  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1);
  codigo.anadirInstruccion("if " + s1 + " " + s2 + " " + s3 + " goto") ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}

expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 

  tmp.str = codigo.nuevoId() ;

  codigo.anadirInstruccion(tmp.str + " := " + s1 + " " +  s2 + " " +  s3 + ";") ;
  return tmp ;
}

vector<int> *unir(vector<int> lis1, vector<int> lis2){
        vector<int> *aux;
        aux = new vector<int>(lis1);

        aux->insert(aux->end(), lis2.begin(), lis2.end());
        return aux;
}
vector<string> *unirStrings (vector<string> lis1, vector<string> lis2){
        vector<string> *aux;
        aux = new vector<string>(lis1);

        aux->insert(aux->end(), lis2.begin(), lis2.end());
        return aux;
}
