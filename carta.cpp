#include "carta.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>

carta::Carta() {
    srand(time(0));
}

void carta::tomarCartas(int& suma, int& dealerSuma) {

    srand(time(0));
    int numero = rand() % 11;
    int dealerNumero = rand() % 11;
    int randomJ = rand() % 4;
    int randomD = rand() % 4;

    suma = suma + numero;
    dealerSuma = dealerSuma + dealerNumero;

    //////CARTAS///////////
    // 0 y 1 para usar letras
    if (numero == 0 || numero == 1) {

        suma = suma + 10;
        cout << "Tu: " << letra[randomJ] << simbolo[randomJ] << " - " << suma << " puntos";
    }

    // Numeros normales
    if (1 < numero && numero <= 10) {

        cout << "Tu: " << numero << simbolo[randomJ] << " - " << suma << " puntos";
    }

    // Numeros normales
    if (1 < dealerNumero && dealerNumero <= 10) {

        cout << "\nDealer: " << dealerNumero << simbolo[randomD] << " - " << dealerSuma << " puntos";
    }

    // 0 y 1 para usar letras
    if (dealerNumero == 0 || dealerNumero == 1) {

        dealerSuma = dealerSuma + 10;
        cout << "\nDealer: " << letra[randomD] << simbolo[randomD] << " - " << dealerSuma << " puntos";
    }
}

void carta::mostrarResultado(int& suma, int& dealerSuma, int& dinero, char& tecla, bool& finalizado) {

    ////////RESULTADOS////////
    // 21 puntos JUGADOR
    if (suma == 21) {

        cout << "\n\n21 puntos,  Ganador!!";
        jugadorGana(dinero, suma);
        cout << "\nPresiona E para continuar o X para salir";
        tecla = getch();
        finalizado = true;
    }

    // Mas de 21 puntos JUGADOR
    else if (suma > 21) {

        cout << "\n\nTienes mas de 21 puntos, perdedor!";
        jugadorPierde(dinero, suma);
        cout << "\nPresiona E para continuar o X para salir";
        tecla = getch();
        finalizado = true;
    }

    // 21 puntos DEALER
    else if (dealerSuma == 21) {

        cout << "\n\nEl dealer tiene 21 puntos, el dealer gana!";
        jugadorPierde(dinero, suma);
        cout << "\nPresiona E para continuar o X para salir";
        tecla = getch();
        finalizado = true;
    }

    // Mas de 21 puntos DEALER
    else if (dealerSuma > 21) {

        cout << "\n\nGanador!, el dealer tiene mas de 21 puntos";
        jugadorGana(dinero, suma);
        cout << "\nPresiona E para continuar o X para salir";
        tecla = getch();
        finalizado = true;
    }

    // Fin del juego
    else {

        cout << "\n\nPresiona E para jugar otra vez o X para salir\n\n";
        tecla = getch();

        while(tecla != 'e'){
            if (tecla == 'x') {
                if (dealerSuma > suma) {

                    cout << "\nEl dealer tiene mas puntos";
                    jugadorPierde(dinero, suma);
                    cout << "Te vas con " << dinero << "$\n";
                    return;
                }
                else if (dealerSuma == suma) {

                    cout << "\nEmpate! no puedes abandonar" << endl << "Presiona E para seguir jugando" << endl;
                    tecla = getch();
                }
                else {

                    cout << "\nTienes mas puntos que el dealer, ganaste!" << endl;
                    jugadorGana(dinero, suma);
                    return;
                }
            }
            else {
                    cout << "Porfavor presiona una tecla valida\n\n";
                    tecla = getch();
            }
        }
    }
}

