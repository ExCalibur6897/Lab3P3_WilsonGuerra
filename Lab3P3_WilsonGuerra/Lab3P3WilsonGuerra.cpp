#include <iostream>

using namespace std;

int main() {
	int opcion = 0;
	int opcion2 = 0;
	int XOR[8];
	int disco1[8];
	int disco2[8];
	while (true) {
		cout << "MENU PRINCIPAL" << endl;
		cout << "1. Disco XOR\n2. Matriz con Obstaculos\n3. Salir\n Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1: {
			while (true) {
				cout << "DISCO XOR\n1. Guardar datos en disco XOR\n2. Obtener datos de disco 1\n3. Obtener datos de disco 2\n4. Salir";
				cin >> opcion;
				if (opcion == 1) {

				}
				else if (opcion == 2) {

				}
				else if (opcion == 3) {

				}
				else if (opcion == 4) {
					break;
				}
			}
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			cout << "Gracias por revisar el trabajo!";
			system("pause");
			return 0;
			break;
		}
		default:
			cout << "Opcion invalida!" << endl;
			break;
		}
	}
}