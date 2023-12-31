#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include "carta.h"
using namespace std;

void jugadorGana(int& dinero, int& suma);
void jugadorPierde(int& dinero, int& suma);
int ingresarTecla(char tecla, int dinero);

int main(){


    char tecla;
    //Inicio del juego
    do{

        system("cls");
        int suma = 0;
        int dealerSuma = 0;
        int dinero = 0;
        string letra[4] {"A", "J", "Q", "K"};
        string simbolo[4] {" de diamantes", " de corazones", " de trebol", " de picas"};
        bool finalizado = false;
        carta blackjack;

        cout << "Escribe la cantidad de dinero que usaras"  << endl;
        cin >> dinero;

        while(cin.fail()) {

            cout << "Ingrese un numero adecuado" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> dinero;
        }

        cout << "\n";

        //Tomar cartas
        do{

            system("cls");

            if(!finalizado){

                blackjack.tomarCartas(suma, dealerSuma);
                blackjack.mostrarResultado(suma, dealerSuma, dinero, tecla, finalizado);
            }

            else{

                cout << "Tu saldo es de $" << dinero << endl;
                cout << "\nPresiona E para jugar otra vez o X para salir\n\n";

                tecla = getch();
                ingresarTecla(tecla, dinero);
                break;
            }

            if(tecla == 'x'){

                system("cls");
                cout << "Te vas con $" << dinero << endl << endl;
                return 0;
            }

            while(tecla != 'e'){

                cout << "\n\nPorfavor presiona una tecla valida\n\n";
                tecla = getch();
            }
        }while(tecla == 'e');
    }while(tecla == 'e');
}

void jugadorGana(int& dinero, int& suma) {

    dinero = dinero + (dinero * 0.5);
    cout << "\nAhora tienes " << dinero << "$\n" << endl;
    suma = 0;
}

void jugadorPierde(int& dinero, int& suma) {

    cout << "\nPierdes todo!" << endl;
    dinero = 0;
    suma = 0;
}

int ingresarTecla(char tecla, int dinero){

    while(tecla != 'e'){

        if(tecla == 'x'){

            system("cls");
            cout << "Te vas con $" << dinero << "\n";
            return 0;
        }

        else{

        cout << "\nPorfavor presiona una tecla valida\n\n";
            tecla = getch();
        }
    }
}
