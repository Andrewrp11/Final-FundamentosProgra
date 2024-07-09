#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int njugadores;


    cout << "Ingrese el número de jugadores: ";
    cin >> njugadores;
    string* n = new string[njugadores];

    for (int i = 0; i < njugadores; ++i) {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> n[i];
    }

    cout << "Los jugadores son:" << endl;
    for (int i = 0; i < njugadores; ++i) {
        cout << "Jugador " << i + 1 << ": " << n[i] << endl;
    }

    return 0;
}