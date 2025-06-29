#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 Árboles Binarios 
 Definir clientes: ID(cédula), nombre completo y tipo de membresia (mensual, trimestral, anual) >> guardar en árbol binario
 Funciones: agregar, buscar, mostrar y eliminar 
 Guardar y recuperar info usando archivo de texto
 */

//Estructura de cliente
struct Cliente {
    int cedula;
    string nombreCompleto;
    string membresia;
    Cliente* izquierda;
    Cliente* derecha;


    //Constructor - inicializa Cliente
    public:
    //parámetros iniciales + lista de atributos + inicializa punteros
    Cliente(int cedula, const string& nombreCompleto, const string& membresia): cedula(cedula), nombreCompleto(nombreCompleto), membresia(membresia), izquierda(nullptr), derecha(nullptr){}
};



class ABB{

private:
 Cliente*raiz;

//Crear un nuevo cliente
Cliente* insertar(Cliente* raiz, int cedula, const string& nombreCompleto, const string& membresia) {
    if (raiz == nullptr) {
        return new Cliente(cedula, nombreCompleto, membresia);
    }
    if (cedula < raiz->cedula) {
        raiz->izquierda = insertar(raiz->izquierda, cedula, nombreCompleto, membresia);
    } else if (cedula > raiz->cedula) {
        raiz->derecha = insertar(raiz->derecha, cedula, nombreCompleto, membresia);
    } else {
        cout << "La cedula ya existe.\n";
    }
    return raiz;
}

//Buscar un cliente por cédula - ID
Cliente* buscar(Cliente* raiz, int cedula){

        if (raiz == nullptr)
            return nullptr; //no encuentra la cedula

        if (cedula == raiz->cedula)
            return raiz; //encuentra cedula
        else if (cedula < raiz->cedula)
            return buscar(raiz->izquierda, cedula); //búsqueda a la izquierda
        else
            return buscar(raiz->derecha, cedula); //búsqueda a la derecha 


}

};


// Ver cliente
//Eliminar cliente
//Guardar en archivo


//Menú de Opciones 
void menu() {
    cout << "\n Menú Principal del Gimnasio \n";
    cout << "1. Agregar nuevo cliente\n";
    cout << "2. Buscar cliente\n";
    cout << "3. Mostrar clientes\n";
    cout << "4. Eliminar cliente\n";
    cout << "5. Guardar datos en archivo\n";
    cout << "6. Salir\n";
    cout << "Ingrese una opción: ";
}


int main() {


    int opcion, cedula;
    string nombre, membresia;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la cédula del cliente: ";
                cin >> cedula;
                cin.ignore();
                cout << "Ingrese nombre del cliente: ";
                getline(cin, nombre);
                cout << "Ingrese el tipo de membresia [Mensual, Trimestral, Anual]: ";
                getline(cin, membresia);
                break;

            case 2:
                cout << "Para buscar un cliente, ingrese la cédula: ";
                cin >> cedula;
                break;

            case 3:
                cout << "Lista de clientes:\n";
                break;

            case 4:
                cout << "Para eliminar un cliente, ingrese la cédula: ";
                cin >> cedula;
                break;

            case 5:

                break;

            case 6:

                break;

            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6);

    return 0;
}
