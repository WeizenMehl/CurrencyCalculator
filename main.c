#include <stdio.h>
#define swiss 1.08
#define dollar 1.21
#define tuerk 9.01

void info();
float conversions_factor_to_Euro(int);
float conversion(float, int,int);
void output(int, int, float, float);
int is_Euro(int);
int is_not_Euro(int);

int main() {
    int zielwaehrung = 0;
    float betrag = 0;
    int ausgangswaehrung = 0;
    float ergebnis = 0;
    float zwischenbetrag = 0;

    do {
        info();

        printf("\nWaehlen Sie eine Ausgangswaehrung aus: ");
        scanf("%i", &ausgangswaehrung);

        printf("\nWaehlen Sie den Betrag aus: ");
        scanf("%f", &betrag);

        printf("\nWaehlen Sie eine Zielwaehrung aus: ");
        scanf("%i", &zielwaehrung);

        if(is_Euro(ausgangswaehrung) == 1 && is_not_Euro(zielwaehrung) ==1){    //if Schleifen die prüfen ob in was in wasumgerechnet werden und rechnungsweg festlegen
            ergebnis = conversion(betrag,zielwaehrung,0);
            output(ausgangswaehrung, zielwaehrung, betrag, ergebnis);
        }

        if(is_Euro(zielwaehrung) == 1 && is_not_Euro(ausgangswaehrung) == 1){
            ergebnis = conversion(betrag,ausgangswaehrung,1);
            output(ausgangswaehrung, zielwaehrung, betrag, ergebnis);
        }

        if(is_not_Euro(zielwaehrung) == 1 && is_not_Euro(ausgangswaehrung) == 1){
            zwischenbetrag = conversion(betrag,ausgangswaehrung,1);
            ergebnis = conversion(zwischenbetrag,zielwaehrung,0);
            output(ausgangswaehrung, zielwaehrung, betrag, ergebnis);
        }


    }while(zielwaehrung != 0 && ausgangswaehrung != 0 );



    return 0;
}
void info(void){
    printf("Euro = 1\nSchweizer Franken = 2\nDollar = 3\ntuerk Lira = 4\nBeenden = 0\n");   //Funktion für die Ausgabe von Info Daten

}
float conversions_factor_to_Euro(int waehrung){ //Funktion für die Ausgabe eines faktors für die Umrechnung

    switch(waehrung){
        case 1 : return 1;break;            //Euro
        case 2 : return 1/swiss;break;      //Franken auf Euro
        case 3 : return 1/dollar;break;     //Dollar auf Euro
        case 4 : return 1/tuerk;break;      //Lira auf Euro
        default: ;
    }

}
float conversion(float betrag, int weahrung,int richtung){  //Funktion für die Umrechnung
    float faktor;

    switch(richtung){
        case 0 : {  //Euro -> andere Währung

            switch(weahrung){
                case 1 : faktor = 1;break;
                case 2 : faktor = swiss;break;
                case 3 : faktor = dollar;break;
                case 4 : faktor = tuerk;break;
                default: ;
            }
            return betrag * faktor;break;
        }
        case 1 : return betrag * conversions_factor_to_Euro(weahrung);  //andere Währung -> Euro
        default: ;
    }
}

void output(int ausgangswaehrung, int zielwaehrung, float betrag_Ausgangwaehrung, float betrag_Zielwaehrung ){      // Funktion für die Ausgabe
    char* text_ausgangswaehrung;
    char* text_zielwaehrung;

    switch(ausgangswaehrung){
        case 1 : text_ausgangswaehrung = "Euro";break;
        case 2 : text_ausgangswaehrung = "Schweizer Franken";break;
        case 3 : text_ausgangswaehrung = "Doller";break;
        case 4 : text_ausgangswaehrung = "Tuerkische Liar";break;

    }

    switch(zielwaehrung){
        case 1 : text_zielwaehrung = "Euro";break;
        case 2 : text_zielwaehrung = "Schweizer Franken";break;
        case 3 : text_zielwaehrung = "Doller";break;
        case 5 : text_zielwaehrung = "Tuerkische Liar";break;

    }

    printf("\nDie Ausgangwaehrung ist: %i", ausgangswaehrung);
    printf("\nDie Zielwaehrung ist: %i ",zielwaehrung);
    printf("\nDer Betrag der Ausgangswaehrung ist: %.2f ",betrag_Ausgangwaehrung);
    printf("\nDer Betrag der Zielwaehrung ist: %.2f\n\n ",betrag_Zielwaehrung);
}
int is_Euro(int weahrung){  //Funktion zur bestätigung das Währung Euro ist
    if(weahrung == 1)
        return 1;

    else
        return 0;
}

int is_not_Euro(int weahrung){                  //Funktion zur bestätigung das Währung nicht Euro ist
    if (weahrung > 1 && weahrung < 5)
        return 1;
    else
        return 0;
}
