#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


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

    int njugadores;
    cout << "Ingrese el numero de jugadores: ";
    cin >> njugadores;

    string nombres[njugadores];
    for (int i = 0; i < njugadores; ++i)
    {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> nombres[i];
    }
}
