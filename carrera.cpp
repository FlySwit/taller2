
#include <iostream>
#include <malloc.h>
#include <cstdlib>

using namespace std;

struct datos
{
    char n[10];
    float v;
};

struct nodos
{
    struct datos entrada;
    char k;
    int val = 0;
    nodos *sig, *ok;
};

nodos *cab, *aux, *aux2;

char j;
float c = 1;
int can;
float promedio = 0, suma = 0;
void lista();

void inicio()
{

    cout << "¿cuantos corredores hay en el maraton?: ";
    cin >> can;
    do
    {

        if (cab == NULL)
        {

            cab = (struct nodos *)malloc(sizeof(struct nodos));
            cout << "ingrese el nombre: ";
            cin >> cab->entrada.n;
            cab->sig = NULL;
            cout << "ingrese el numero de documento: ";
            cin >> suma;
            cab->entrada.v = suma;
            cab->sig = NULL;
        }
        else
        {
            c++;
            aux = (struct nodos *)malloc(sizeof(struct nodos));
            cout << "ingrese el nombre: ";
            cin >> aux->entrada.n;
            aux->sig = NULL;
            aux2 = cab;
            while (aux2->sig != NULL)
                aux2 = aux2->sig;
            aux2->sig = aux;

            cout << "ingrese el tiempo del corredor ";
            cin >> promedio;
            aux->entrada.v = promedio;
            suma = suma + promedio;

            if ((aux->entrada.v) < cab->entrada.v)
            {
                cout << "El tiempo del corredor debe ser mayor";
                return;
            }

            aux->sig = NULL;
            aux2 = aux = NULL;

            free(aux);
            free(aux2);
        }

    } while (c < can);
    lista();
    suma = suma / c;
    cout << "el promedio de los corredores es: " << suma << "\n";
}

void lista()
{
    int p = 0, i = 1;
    aux = cab;
    while (aux != NULL)
    {

        cout << "nombre del corredor " << aux->entrada.n << i++ << " : ";
        cin >> p;
        aux->entrada.v = p + aux->entrada.v;
        cout << aux->entrada.v << endl;
        aux = aux->sig;
        
    }
}

void inicio();

int main()
{

    inicio();
}
