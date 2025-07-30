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

string tmembresia() {
    int opcion;
    cout << "Seleccione el tipo de membresia:\n";
    cout << "1. Mensual\n";
    cout << "2. Trimestral\n";
    cout << "3. Anual\n";
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: return "Mensual";
        case 2: return "Trimestral";
        case 3: return "Anual";
        default:
            cout << "Opcion no valida, asignado 'Mensual' por defecto.\n";
            return "Mensual";
    }
}

class ABB{

private:
 Cliente*raiz;

    //Crear un nuevo cliente
    bool insertar(Cliente*& raiz, int cedula, const string& nombreCompleto, const string& membresia) {
        if (raiz == nullptr) {
            raiz = new Cliente(cedula, nombreCompleto, membresia);
            return true;  //Se insertó exitosamente
        }

        if (cedula < raiz->cedula) {
            return insertar(raiz->izquierda, cedula, nombreCompleto, membresia);
        } else if (cedula > raiz->cedula) {
            return insertar(raiz->derecha, cedula, nombreCompleto, membresia);
        } else {
            return false; // La cédula ya existe
        }
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
// Mostrar cliente
void mcliente(Cliente* raiz) {
    if (raiz == nullptr) return;

    mcliente(raiz->izquierda);
    cout << "ID: " << raiz->cedula << ", Nombre: " << raiz->nombreCompleto
         << ", Membresia: " << raiz->membresia << '\n';
    mcliente(raiz->derecha);
}

public:

    ABB() {
        raiz = nullptr;
    }

    void insertarCliente(int cedula, const string& nombreCompleto, const string& membresia) {
    if (insertar(raiz, cedula, nombreCompleto, membresia)) {
        cout << "===Cliente agregado correctamente: " << nombreCompleto << ", Cédula: " << cedula << "===" << endl;
    } else {
        cout << "Error: La cédula ya existe. No se registró el cliente." << endl;
    }
}
    void mostrarClientes() {
    mcliente(raiz);
    }
    void buscarCliente(int cedula) {
        Cliente* encontrado = buscar(raiz, cedula);
        if (encontrado != nullptr) {
            cout << "===Cliente encontrado: " << encontrado->nombreCompleto << ", Membresía: " << encontrado->membresia<< "===" << endl;
        } else {
            cout << "Cliente no encontrado." << endl;
        }
    }
void cargarDesdeArchivo(const string& nombreArchivo = "clientes.txt") {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos1 = linea.find(';');
        size_t pos2 = linea.find(';', pos1 + 1);

        int id = stoi(linea.substr(0, pos1));
        string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
        string membresia = linea.substr(pos2 + 1);

        insertar(raiz, id, nombre, membresia);  // ← llamar a insertar desde dentro de la clase
    }
   archivo.close();
    cout << "Datos cargados desde archivo.\n";
}
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

    ABB arbol;
    int opcion, cedula;
    string nombreCompleto, membresia;

    do {
        menu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese la cédula del cliente: ";
                cin >> cedula;
                cin.ignore();
                cout << "Ingrese nombre del cliente: ";
                getline(cin, nombreCompleto);
                membresia = tmembresia();
                arbol.insertarCliente(cedula, nombreCompleto, membresia);
                break;

            case 2:
                cout << "Para buscar un cliente, ingrese la cédula: ";
                cin >> cedula;
                arbol.buscarCliente(cedula);
                break;

            case 3:
                cout << "Lista de clientes:\n";
                arbol.mostrarClientes();
                break;

            case 4:
                cout << "Para eliminar un cliente, ingrese la cédula: ";
                cin >> cedula;
                break;

            case 5:
             arbol.gdatos();
                cout << "Datos guardados en 'clientes.txt'.\n";
                break;

            case 6:
             cout << "Cerrando....\n";
             break;

            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6);

    return 0;
}
