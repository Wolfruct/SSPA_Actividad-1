#include <iostream>
#include "paqueteria.cpp"

using namespace std;

int menu();
void opc1(paqueteria *n_paqueteria);

int main()
{   
    bool ban = true;
    paqueteria *n_paqueteria = new paqueteria();

    while(ban)
    {
        switch (menu())
        {
        case 1:
            opc1(n_paqueteria);
            break;
        case 2:
            n_paqueteria->eliminar_inicio();
            break;
        case 3:
            n_paqueteria->mostrar();
            break;
        case 4:
            n_paqueteria->guardar();
            break;
        case 5:
            n_paqueteria->recuperar();
            break;
        case 6:
            ban = false;
            break;
        default:
        cout << "\n\n !Opcion no disponible!\n" << endl;
            break;
        }
    }

    cout << "\nexito final" << endl;
    system("pause");

    return 0;
}

int menu()
{
    int res;

    cout << "\n\n   -- Menu --   \n1.Agregar paquete\n2.Eliminar paquete\n3.Mostrar\n4.Guardar\n5.Recuperar\n6.Salir\n" << endl;
    cin >> res;

    return res;
}

void opc1(paqueteria *n_paqueteria)
{   int id;
    float peso;
    char origen[100], destino[100];

    cout << "\n\n   Ingresar Datos\n\nID: ";
    cin >> id;
    cout << "Peso: ";
    cin >> peso;
    cout << "Origen: ";
    cin.getline(origen,100);
    cin.getline(origen,100);
    cout << "Destino: ";
    cin.getline(destino,100);

    n_paqueteria->insertar_inicio(id,origen,destino,peso);

    return;
}
