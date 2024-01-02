#include "carta.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>

carta::Carta() {
}

/**
 * @brief Funcion para tomar una carta en un turno del juego.
 *
 * Genera numeros al azar para representar el numero, letra y simbolo de cada una de las cartas.
 * Una carta para el jugador y otra para el dealer.
 *
 * @param jugadorSuma Puntos totales del jugador basados en las cartas que ha tomado, se actualiza cada vez que se llama a la funcion.
 * @param dealerSuma Puntos totales del dealer basados en las cartas que ha tomado, se actualiza cada vez que se llama a la funcion.
*/
void carta::tomarCartas(int& jugadorSuma, int& dealerSuma) {

    srand(time(0)); // Genera una nueva semilla random cada vez que se repita el loop
    int jugadorNumero = rand() % 11; // Numero random del 0 al 10
    int dealerNumero = rand() % 11;
    int jugadorSimbolo = rand() % 4; // Numero random del 0 al 3
    int dealerSimbolo = rand() % 4;

    //////CARTAS///////////

    // "letra[dealerSimbolo]" y "simbolo[jugadorSimbolo]" son diferentes para que no se repita siempre el mismo simbolo con la misma letra //

    // si el numero es 0 o 1, la carta será una carta con letra (A, Q, K, J)
    if (jugadorNumero == 0 || jugadorNumero == 1) {

        jugadorSuma = jugadorSuma + 10; // El valor de puntos de la letra es 10, se suma al total
        cout << "Tu: " << letra[dealerSimbolo] << simbolo[jugadorSimbolo] << " - " << jugadorSuma << " puntos";
    }

    // Numeros normales, usamos else if puesto que solo uno de los dos puede ser true
    else if (1 < jugadorNumero && jugadorNumero <= 10) {

        jugadorSuma = jugadorSuma + jugadorNumero;
        cout << "Tu: " << jugadorNumero << simbolo[jugadorSimbolo] << " - " << jugadorSuma << " puntos";
    }

    // si el numero es 0 o 1, la carta será una carta con letra (A, Q, K, J)
    if (dealerNumero == 0 || dealerNumero == 1) {

        dealerSuma = dealerSuma + 10; // El valor de puntos de la letra es 10, se suma al total
        cout << "\nDealer: " << letra[jugadorSimbolo] << simbolo[dealerSimbolo] << " - " << dealerSuma << " puntos";
    }

    // Numeros normales, usamos else if puesto que solo uno de los dos puede ser true
    else if (1 < dealerNumero && dealerNumero <= 10) {

        dealerSuma = dealerSuma + dealerNumero;
        cout << "\nDealer: " << dealerNumero << simbolo[dealerSimbolo] << " - " << dealerSuma << " puntos";
    }
}

/** @brief Muestra el resultado despues de un turno
 *
 * Muestra el resultado final del juego si ha finalizado.
 * Si el juego aun no ha finalizado, muestra el resultado del turno.
 *
 * @param jugadorSuma Puntos totales del jugador basados en las cartas que ha tomado.
 * @param dealerSuma Puntos totales del dealer basados en las cartas que ha tomado.
 * @param dinero Cantidad de dinero que se ha apostado.
 * @param tecla Tecla presionada para repetir o finalizar el juego.
 * @param finalizado Bool usado para saber si el juego ha finalizado.
*/

void carta::mostrarResultado(int jugadorSuma, int dealerSuma, int &dinero, char& tecla, bool& finalizado) {

    ////////RESULTADOS////////

    // 21 puntos JUGADOR
    if (jugadorSuma == 21) {

        cout << "\n\n21 puntos,  Ganador!!";
        jugadorGana(dinero);
        cout << "\nPresiona E para continuar o X para salir";
        tecla = getch();
        finalizado = true;
    }

    // Mas de 21 puntos JUGADOR
    else if (jugadorSuma > 21) {

        cout << "\n\nTienes mas de 21 puntos, perdedor!";
        jugadorPierde(dinero);
        cout << "\nPresiona E para continuar o X para salir";
        tecla = getch();
        finalizado = true;
    }

    // 21 puntos DEALER
    else if (dealerSuma == 21) {

        cout << "\n\nEl dealer tiene 21 puntos, el dealer gana!";
        jugadorPierde(dinero);
        cout << "\nPresiona E para continuar o X para salir";
        tecla = getch();
        finalizado = true;
    }

    // Mas de 21 puntos DEALER
    else if (dealerSuma > 21) {

        cout << "\n\nGanador!, el dealer tiene mas de 21 puntos";
        jugadorGana(dinero);
        cout << "\nPresiona E para continuar o X para salir";
        tecla = getch();
        finalizado = true;
    }

    // Fin de una ronda
    else {

        cout << "\n\nPresiona E para jugar otra vez o X para salir\n\n";
        tecla = getch();

        while(tecla != 'e'){
            if (tecla == 'x') {
                if (dealerSuma > jugadorSuma) {

                    cout << "\nEl dealer tiene mas puntos";
                    jugadorPierde(dinero);
                    cout << "Te vas con " << dinero << "$\n";
                    return;
                }
                else if (dealerSuma == jugadorSuma) {

                    cout << "\nEmpate! no puedes abandonar" << endl << "Presiona E para seguir jugando" << endl;
                    tecla = getch();
                }
                else {

                    cout << "\nTienes mas puntos que el dealer, ganaste!" << endl;
                    jugadorGana(dinero);
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
