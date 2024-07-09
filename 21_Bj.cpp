#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int SCarta()
{
    return rand() % 10 + 1;
}

void mCartas(const int c[], int n_cartas)
{
    for (int i = 0; i < n_cartas; ++i)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

int cPuntaje(const int c[], int n_cartas)
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
    srand(time(0));

    int njugadores;
    cout << "Ingrese el numero de jugadores: ";
    cin >> njugadores;

    string nombres[njugadores];
    for (int i = 0; i < njugadores; ++i)
    {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> nombres[i];
    }

    const int max_cartas = 10;
    int c[njugadores][max_cartas] = {0};
    int n_cartas[njugadores] = {0};

    for (int i = 0; i < njugadores; ++i)
    {
        c[i][n_cartas[i]++] = SCarta();
        c[i][n_cartas[i]++] = SCarta();
    }

    char opcion;
    bool Planta[njugadores] = {false};

    for (int i = 0; i < njugadores; ++i)
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

    cout << "Puntajes finales:" << endl;
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

    cout << "El ganador es: " << ganador << " con " << mpuntaje << " puntos." << endl << endl;

    cout << "Creadores: " << "Andre Vladimir Romero Puente - Carnet 00061624" << endl;
    cout << "Creadores: " << "Axell Alejandro Giron Posada - Carnet 00134424" << endl;
    return 0;

}