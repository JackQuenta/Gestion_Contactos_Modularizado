/*1. Gestión de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes características: nombres completos, sexo, edad,
teléfono, email, nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com, outlook.com,
yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del mismo*/

#include <iostream>
#include "Contactos.h"
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_CTYPE, "");
	int salir = 0;
    do {
        cout << "\n=== GESTION DE CONTACTOS ===" << endl;
        cout << "a) Agregar un contacto" << endl;
        cout << "b) Eliminar un contacto" << endl;
        cout << "c) Mostrar listado general de contactos registrados hasta ese momento." << endl;
        cout << "d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com, outlook.com, yahoo.com, etc.)" << endl;
        cout << "e) Salir del programa" << endl;
		char op;
        cin >> op;
        cin.ignore();
        
        switch(op) {
            case 'a':
                agregarContacto();
                break;
            case 'b':
                eliminarContacto();
                break;  
			case 'c':
                mostrarContactos();
                break;
			case 'd':
                mostrarContactosOrdenados();
                break;   
            case 'e':
                salir = 1;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while(salir == 0);
    
    return 0;
}
