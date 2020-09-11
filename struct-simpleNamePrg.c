// Einfaches Strukturen Program gemischt mit
// Low Level File Handling ...
// compile: gcc struct-simpleNamePrg.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h> // für file descriptoren
//////////////////////////////////////////////////////////
//	STRUCT´s					//
//////////////////////////////////////////////////////////
typedef struct _MetadatenPersonen_	// erstelle Struktur "_MetadatenPersonen_"
	{
		char Name[100];
		char FamName[100];
		int year;
		float great;
	} data;							// mit dem Deklarations namen "data"
//////////////////////////////////////////////////////////
//	Void´s						//
//////////////////////////////////////////////////////////
static void error_exit( char *errormessage )	// error handling function
	{
    fprintf (stderr, "\n %s ; %s \n", errormessage, strerror(errno));
    exit(EXIT_FAILURE);
	}
void fill(data *r)
	{
		strcpy(r->Name,"itsMe");
		strcpy(r->FamName,"secondName");
		r->year = 20;
		r->great = 1.78;
	}
void printdata(data r)
	{
		printf("\n - - - \n - name = %s\n - FamName = %s\n - year = %d \n - great = %2.2f\n\n",r.Name,r.FamName,r.year,r.great);
	}
void fillself(data *r)	// Zeiger auf Struktur "data" mit namen "r" wird übergeben
	{	// Fülle die struktur "data" mit namen "r" über die Tastatureingabe
		printf("\ntype in Name...\n");
		scanf("%s",&(r->Name));	// "&" Address Operator wird verlang von funktion scanf()
		printf("\ntype in FamName...\n");		//...nicht wegen der Referenzierung des Zeigers
		scanf("%s",&(r->FamName));
		printf("\ntype in year...\n");
        scanf("%d",&(r->year));
		printf("\ntype in great in 'cm'...\n");
        scanf("%f",&(r->great));
			r->great = r->great/100;
	}
//////////////////////////////////////////////////////////
//	MAIN						//
//////////////////////////////////////////////////////////
int main()
{//   MAIN START
	data person;		//deklarierung der Struktur "data" mit namen "person"
	system("clear");	// clear den Bildschirm (sieht schöner aus)
	printf("\n\n - Personen daten werden gefüllt\n");
	fill(&person);		//Addresse "&" von struktur "data" mit namen "person" weiter geben
	printdata(person);	//übergebe struktur "data" mit namen "person" an funktion printdata()

printf("\ngebe daten von selbst ein\n");
	fillself(&person);	// übergebe Addresse von struct "person" an funktion fillself()
	printdata(person);	// Daten von struct "person" an funktion printdata()

// Struktur in eine Datei schreiben!!!
// low level I/O file stream / mit File Deskriptoren !!!
printf("\nschreibe Personen Daten in Datei...\n");
	printf("Name der Datei = ");
	int fh;	// file descripor
	char filename[100]; //name der Datei
	char structbuff[512]; // buffer für zusammenfügen eines Strings ...siehe snprintf()
	scanf("%s",&filename);// Eingabe des Dateinamens an die Addresse "&" von filename

//füge struct daten in "structbuff" mit der größe von "structbuff" zusammen
	snprintf(structbuff,sizeof(structbuff),"\nName = %s\nFamName = %s\nyear = %d\ngreat = %2.2f \n",person.Name,person.FamName,person.year,person.great);
// Fehlerprüfende funktion zum öffnen einer Datei (filename) mit lese&schreibe funktion
// Falls Datei nicht existiert...erstelle sie (O_CREAT) mit lese&Schreibe&Execute Rechten
// für user,group und others (,0777) -> siehe Linux rechte verteilung....
	if ( (fh=open(filename,O_RDWR|O_CREAT,0777)) == -1) {
    perror("\n\n-FATAL--------------\n-Fehler beim öffnen der datei in funktion open()");
    return EXIT_FAILURE;
    }
// schreibe in die datei: strucbuf mit der String länge von structbuff
    if ( (write (fh,structbuff,strlen(structbuff) )) == -1) {
    perror("\n\n-FATAL-----------\n-Fehler beim schreiben in die datei\n");
    return EXIT_FAILURE;
    }
	close(fh);	// schließe den File Deskriptor wieder...

// Fehlerprüfende Funktion
// um zu Checken ob datei existiert/erstellt wurde...
	if ( (fh=open(filename,O_RDONLY)) == -1)	// öffne Datei (filename) mit Lese rechten (O_RDONLY)
		{
		perror("\n\n - - Fehler!! \n - - Datei nicht erstellt");
		return EXIT_FAILURE;
		exit(0);
		}
	if ((close(fh)) == -1)	// Fehlerprüfende funktion zum schliesen von File Deskriptor (close(fh) )
		perror("Fehler bei schließen des File Descriptors");
	printf("\n\n - Datei erfolgreich erstellt\n - Good Bye!!\n");
}//   MAIN END

