#include "players.h"
#include "carta.h"
#include <conio.h>
#include <windows.h>

players::players(){

    SetConsoleTitle("Blackjack");
}

int players::jugar(){

    char tecla;

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

void players::jugadorGana(int& dinero) {

    dinero = dinero + (dinero * 0.5);
    cout << "\nAhora tienes " << dinero << "$\n" << endl;
}

void players::jugadorPierde(int& dinero) {

    cout << "\nPierdes todo!" << endl;
    dinero = 0;
}

int players::ingresarTecla(char tecla, int dinero){

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

