#include <iostream>

using namespace std;


struct nodo {
    int tipo; 
    int movimientos; 
    nodo *sig; 
};

nodo *pilaCarros = NULL, *pilaMotos = NULL;


int totalDinero = 0;

void registrarVehiculo(int tipo) {
    nodo *nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->tipo = tipo;
    nuevo->movimientos = 0;
    nuevo->sig = NULL;

    if (tipo == 1) { 
        nuevo->sig = pilaCarros;
        pilaCarros = nuevo;
    } else if (tipo == 2) { 
        nuevo->sig = pilaMotos;
        pilaMotos = nuevo;
    }

    cout << "Vehiculo registrado: " << (tipo == 1 ? "Carro" : "Moto") << endl;
}

void retirarVehiculo(int tipo) {
    if ((tipo == 1 && pilaCarros == NULL) || (tipo == 2 && pilaMotos == NULL)) {
        cout << "No hay vehiculos del tipo " << (tipo == 1 ? "Carro" : "Moto") << " para retirar." <<endl;
        return;
    }

    nodo *aux;
    if (tipo == 1) { 
        aux = pilaCarros;
        pilaCarros = pilaCarros->sig;
        totalDinero += 2000 + aux->movimientos * 100;
    } else if (tipo == 2) { 
        aux = pilaMotos;
        pilaMotos = pilaMotos->sig;
        totalDinero += 1000 + aux->movimientos * 100;
    }

    cout << "Vehiculo retirado: " << (tipo == 1 ? "Carro" : "Moto") << endl;
    free(aux); 
}

void moverVehiculo(int tipo) {
    if (tipo == 1 && pilaCarros != NULL) {
        pilaCarros->movimientos++;
        cout << "Carro movido. Movimientos actuales: " << pilaCarros->movimientos << endl;
    } else if (tipo == 2 && pilaMotos != NULL) {
        pilaMotos->movimientos++;
        cout << "Moto movida. Movimientos actuales: " << pilaMotos->movimientos << endl;
    } else {
        cout << "No hay vehiculos del tipo " << (tipo == 1 ? "Carro" : "Moto") << " para mover." << endl;
    }
}

void mostrarDinero() {
    cout << "Total dinero generado: $" << totalDinero << endl;
}

int main() {
    int opcion, tipo;

    do {
        cout << "\n----------MENU----------"<<endl;
        cout << "1) Registrar vehiculo"<<endl;
        cout << "2) Retirar vehiculo"<<endl;
        cout << "3) Mover vehiculo"<<endl;
        cout << "4) Mostrar dinero generado"<<endl;
        cout << "5) Salir"<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese tipo de vehiculo (1 para carro, 2 para moto): ";
            cin >> tipo;
            if (tipo == 1 || tipo == 2) {
                registrarVehiculo(tipo);
            } else {
                cout << "Tipo de vehiculo invalido." << endl;
            }
            break;

        case 2:
            cout << "Ingrese tipo de vehiculo a retirar (1 para carro, 2 para moto): ";
            cin >> tipo;
            if (tipo == 1 || tipo == 2) {
                retirarVehiculo(tipo);
            } else {
                cout << "Tipo de vehiculo invalido." << endl;
            }
            break;

        case 3:
            cout << "Ingrese tipo de vehiculo a mover (1 para carro, 2 para moto): ";
            cin >> tipo;
            if (tipo == 1 || tipo == 2) {
                moverVehiculo(tipo);
            } else {
                cout << "Tipo de vehiculo invalido." << endl;
            }
            break;

        case 4:
            mostrarDinero();
            break;

        case 5:
            cout << "Saliendo del programa." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
