// STRUCT deklarierung und verwendung mit pointern ....
// Compile: gcc struct.c 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
//////////////////////////////////////////////////////////
//      STRUCTS                                         //
//////////////////////////////////////////////////////////
typedef struct _lokations_
{
	int x;
	int y;
} coordinaten; // Datentyp ist "coordinaten" // deklarieren zb = "int somethinng" / "coordinaten something"
											// 1. Deklariert int namens "something"	// 2. Deklariert die Struktur _lokations_ namens "something"
typedef struct _rechteck_
{
	int hohe;
	int breite;
	char farbe[25];
} Rechteck;		// Datentyp ist "Rechteck" // deklarieren: Rechteck "objekt1"
											// deklariert die Struktur _rechteck_ namens "objekt1"
//////////////////////////////////////////////////////////
//	Void´s						//
//////////////////////////////////////////////////////////
static void error_exit( char *errormessage )	// FATAL HANDLING function
	{
		fprintf (stderr, "\n %s ; %s \n", errormessage, strerror(errno));
		exit(EXIT_FAILURE);
	}
void print(coordinaten input)   //	struktur coordinaten mit dem Namen "input" wird aufgenommen
	{	// Datentyp nicht int...sondern eben coordinaten
		printf("\n ( %d / %d ) \n",input.x,input.y);
	}
void rechtprint(Rechteck r)		// struktur Rechteck mit dem namen "r" wird aufgenommen
	{
		printf("\n hohe=%d breite=%d farbe=%s \n",r.hohe,r.breite,r.farbe);
	}
void del(coordinaten *input)	// Zeiger auf die struktur coordinaten mit namen "input" wird aufgenommen
	{							//werte auf NUL setzen mit pointern "*"
		input->x = 0;			// "->" weil wir mit pointern arbeiten
		input->y = 0;			// "." wenn wir ohne pointer arbeiten
	}

//3
void hzwei(Rechteck ***r)
    {
		(**r)->hohe = (**r)->hohe*2;    //(***r) dreifach referenziert....damit gehen wir
    }	//höhe verdoppeln				//"***"drei schritte zurück = "rechtdel()" // "->"damit gehen wir
                                        //den letzten schritt zurück zu "int main()"
//2
void verdoppel(Rechteck **r)			//"**"zwei pointer weil wir:
	{									// * = ein schritt zurück (void rechteck() )
		(*r)->breite = (*r)->breite*2;	// ** = zweiter schritt zurück ( int main )
		//verdoppel wert von Breite		// (*r) weil wir ihn erst einmal auflösen müssen
		hzwei(&r);	// Gebe Addresse von hier bearbeiteter Structur "Rechteck **r" an funktion hzwei() weiter...
	}

//1
void rechtdel(Rechteck *r)		//"*" pointer veränderung (bei address übergabe) // zeiger auf die übergebenen Daten
	{
		strcpy( (r->farbe),"schwarz"); // r->farbe weil wir mit pointern arbeitn // r.farbe = ohne pointer
		verdoppel(&r);			//addresse von r übergeben "&"
	}
//////////////////////////////////////////////////////////
//	MAIN						//
//////////////////////////////////////////////////////////
int main()
{//   MAIN START
	coordinaten point = {5, 8};
	print(point);
	del(&point);	//"&" übergibt die addresse von point
	print(point);	//damit es auch wirklich point überschreibt und
					//eine kopie oder so übergibt

	Rechteck r1 = {5, 10, "Rot"};	//werte initaliesieren in struct "Rechteck" mit namen r1

	Rechteck r2;					//uninitalised struct mit namen r2
	r2.hohe = 3;					// struct Rechteck mit namen r2 die hohe auf 3 setzen
	r2.breite = 2;					// r2: breite = 2
	strcpy(r2.farbe,"Gelb");		// r2: string farbe = "Gelb"
	rechtprint(r1);					// übergebe struct Rechteck r1 an funktion rechtprint()
	rechtdel(&r1);					// übergebe addresse (&) von struct Rechteck r1 an funktion rechtdel()
	rechtprint(r1);					// übergebe ganze struktur werte von r1 an rechtprint()
}//   MAIN END

	//INFOS\\
// und operator gibt addresse weiter , auf addresse wird mit *point zugegriffen
// und die darauf liegenden daten überschrieben
