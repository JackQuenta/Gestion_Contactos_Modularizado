#include "Contactos.h"
#include <iostream>
using namespace std;

struct contactoEmail {
    string nombreCompleto;
    char sexo;
    int edad;
    string telefono;
    string email;
    string nacionalidad;
};

contactoEmail contactos[100];
int numContactos = 0;

void agregarContacto() {
    cout << "\n=== AGREGAR CONTACTO ===" << endl;
    cout << "Nombre completo: ";
    getline(cin, contactos[numContactos].nombreCompleto);
    
    cout << "Sexo (m para masculino/f para femenino): ";
    cin >> contactos[numContactos].sexo;
    while (contactos[numContactos].sexo != 'm' && contactos[numContactos].sexo != 'f') {
    	cout << "Opcion incorrecta, ingrese m o f: ";
    	cin >> contactos[numContactos].sexo;
	}
    cout << "Edad: ";
    cin >> contactos[numContactos].edad;
    while (contactos[numContactos].edad < 0 || contactos[numContactos].edad > 100) {
    	cout << "Ingrese una edad correcta (0-100): ";
    	cin >> contactos[numContactos].edad;
	}
    
    cout << "Telefono: ";
	cin.ignore();
	getline(cin, contactos[numContactos].telefono);

	while (contactos[numContactos].telefono.length() != 9 || contactos[numContactos].telefono[0] != '9') {
    	cout << "Ingrese un número válido de 9 dígitos que comience con 9: ";
    	getline(cin, contactos[numContactos].telefono);
	}
   
    cout << "Email: ";
    getline(cin, contactos[numContactos].email);
    
    cout << "Nacionalidad: ";
    getline(cin, contactos[numContactos].nacionalidad);
    
    numContactos++;
    cout << "Contacto agregado exitosamente!" << endl;
}

void eliminarContacto() {
    string nombreBuscar;
    cout << "\n=== ELIMINAR CONTACTO ===" << endl;
    cout << "Ingrese el nombre del contacto a eliminar: ";
    getline(cin, nombreBuscar);
    
	bool encontrado = false;
    for (int i = 0; i < numContactos; i++) {
        if (contactos[i].nombreCompleto == nombreBuscar) {
            for (int j = i; j < numContactos - 1; j++) {
                contactos[j] = contactos[j + 1];
        	}
            numContactos--;
			encontrado = true;
       		break;
        }
    }
    if (encontrado == true) {
    	cout << "Contacto Eliminado" << endl;
	} else {
    	cout << "Contacto no encontrado." << endl;
	}
}

void mostrarContactos() {
    cout << "\n=== CONTACTOS ===" << endl;
    for (int i = 0; i < numContactos; i++) {
        cout << "\nContacto " << (i+1) << ":" << endl;
        cout << "Nombre: " << contactos[i].nombreCompleto << endl;
        cout << "Sexo: " << contactos[i].sexo << endl;
        cout << "Edad: " << contactos[i].edad << endl;
        cout << "Telefono: " << contactos[i].telefono << endl;
        cout << "Email: " << contactos[i].email << endl;
        cout << "Nacionalidad: " << contactos[i].nacionalidad << endl;
    }
}

string extraerServidor(const string& email) {
    int posicion = email.find('@');
    string servidor;
    if (posicion >= 0) {
        servidor = email.substr(posicion + 1);
    }
    return servidor;
}

void mostrarContactosOrdenados() {
    cout << "\n=== CONTACTOS ORDENADOS POR CORREO ===" << endl;
        contactoEmail copia[100];
        for (int i = 0; i < numContactos; i++) {
            copia[i] = contactos[i];
        }
        for (int i = 0; i < numContactos - 1; i++) {
            for (int j = 0; j < numContactos - i - 1; j++) {
                string servidor1 = extraerServidor(copia[j].email);
                string servidor2 = extraerServidor(copia[j + 1].email);
                if (servidor1 > servidor2) {
                    contactoEmail temp = copia[j];
                    copia[j] = copia[j + 1];
                    copia[j + 1] = temp;
                }
            }
        }

        string servidorActual = "";
        for (int i = 0; i < numContactos; i++) {
            string servidor = extraerServidor(copia[i].email);
            if (servidor != servidorActual) {
                cout << "\n--- " << servidor << " ---" << endl;
                servidorActual = servidor;
            }
            cout << "Nombre: " << copia[i].nombreCompleto << endl;
    		cout << "Email : " << copia[i].email << endl;
    		cout << "Sexo  : " << copia[i].sexo << endl;
			cout << "Edad  : " << copia[i].edad << endl;
    		cout << "Tel.  : " << copia[i].telefono << endl;
        }
}

