#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int SCarta() //randomizador de cartas
{
    return rand() % 10 + 1; 
}

void mCartas(const int c[], int n_cartas) //Repartidor de cartas
{
    for (int i = 0; i < n_cartas; ++i)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

int cPuntaje(const int c[], int n_cartas) //Contador del puntaje
{
    int total = 0;
    for (int i = 0; i < n_cartas; ++i)
    {
        total += c[i];
    }
    return total;
}

int main()
{
    srand(time(0)); //Para la obtencion de numero totalmente aleatorios siempre

    int njugadores; //numero de jugadores
    cout << "Ingrese el numero de jugadores: ";
    cin >> njugadores;

    string nombres[njugadores]; //nombre de cada uno de los jugadores
    for (int i = 0; i < njugadores; ++i)
    {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> nombres[i];
    }

    const int max_cartas = 10; //repartidor de las primeras 2 cartas
    int c[njugadores][max_cartas] = {0};
    int n_cartas[njugadores] = {0};

    for (int i = 0; i < njugadores; ++i)
    {
        c[i][n_cartas[i]++] = SCarta();
        c[i][n_cartas[i]++] = SCarta();
    }

    char opcion;
    bool Planta[njugadores] = {false};

    for (int i = 0; i < njugadores; ++i) //sistema base de 21
    {
        cout << "Turno de " << nombres[i] << ":" << endl;
        while (!Planta[i])
        {
            cout << "Tus c: ";
            mCartas(c[i], n_cartas[i]);

            cout << "Deseas pedir una carta (p) o plantarte (s)? ";
            cin >> opcion;

            if (opcion == 'p')
            {
                c[i][n_cartas[i]++] = SCarta();
                if (cPuntaje(c[i], n_cartas[i]) > 21)
                {
                    cout << "Te has pasado de 21. ¡Perdiste!" << endl;
                    Planta[i] = true;
                }
            }
            else if (opcion == 's')
            {
                Planta[i] = true;
            }
        }
    }

    cout << "Puntajes finales:" << endl; //Puntajes finales
    for (int i = 0; i < njugadores; ++i)
    {
        cout << nombres[i] << " - Cartas: ";
        mCartas(c[i], n_cartas[i]);
        cout << "Puntaje: " << cPuntaje(c[i], n_cartas[i]) << endl;
    }

    int mpuntaje = 0;
    string ganador = "Nadie";
    for (int i = 0; i < njugadores; ++i)
    {
        int puntaje = cPuntaje(c[i], n_cartas[i]);
        if (puntaje <= 21 && puntaje > mpuntaje)
        {
            mpuntaje = puntaje;
            ganador = nombres[i];
        }
    }

    cout << "El ganador es: " << ganador << " con " << mpuntaje << " puntos." << endl << endl; //Ganador

    cout << "Creadores: " << "Andre Vladimir Romero Puente - Carnet 00061624" << endl; //Creadores
    cout << "Creadores: " << "Axell Alejandro Giron Posada - Carnet 00134424" << endl;
    return 0;

}