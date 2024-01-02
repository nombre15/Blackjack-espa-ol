#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "carta.h"
using namespace std;

void jugadorGana(int& dinero);
void jugadorPierde(int& dinero);
int ingresarTecla(char tecla, int dinero);

int main(){

    char tecla;
    SetConsoleTitle("Blackjack");

    //Inicio del juego
    do{

        system("cls");
        int jugadorSuma = 0;
        int dealerSuma = 0;
        int dinero = 0;
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

            // Si aun no ha finalizado, jugar una ronda
            if(!finalizado){

                blackjack.tomarCartas(jugadorSuma, dealerSuma);
                blackjack.mostrarResultado(jugadorSuma, dealerSuma, dinero, tecla, finalizado);
            }

            // Si el juego ha finalizado
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

/** El jugador ha ganado el juego
 *
 * @param dinero Cantidad de dinero que sera aumentada
*/
void jugadorGana(int& dinero) {

    dinero = dinero + (dinero * 0.5);
    cout << "\nAhora tienes " << dinero << "$\n" << endl;
}

/** El jugador ha perdido el juego
 *
 * @param dinero Cantidad de dinero que sera cambiada a 0
*/
void jugadorPierde(int& dinero) {

    cout << "\nPierdes todo!" << endl;
    dinero = 0;
}

/** Funcion para ingresar una tecla
 *
 * @param tecla Valor de tecla que fue ingresado
 * @param dinero Cantidad de dinero que sera mostrada si se abandona el juego
*/
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

    // No hay return intencionalmente, puesto que la funcion jamas deberia llegar hasta aqui y no hay nada para retornar
}
