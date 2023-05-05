#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char** Llenar_Matriz(int filas, int columnas) {
	char** matriz = new char* [filas];
	for (int i = 0; i < filas; i++) {
		matriz[i] = new char[columnas];
		for (int j = 0; j < columnas; j++) {
			matriz[i][j] = '-';
		}
	}
	return matriz;
}

int posicion_random(int n) {
	return rand() % n;
}

void agregar_obstaculos(char** matriz, int obstaculos, int filas, int columnas) {
	int obstaculos_insertados = 0;
	while (obstaculos_insertados < obstaculos) {
		int fila = posicion_random(filas);
		int columna = posicion_random(columnas);
		if (matriz[fila][columna] == '-') {
			matriz[fila][columna] = '#';
			obstaculos_insertados++;
		}
	}
}

void imprimir_matriz(char** matriz, int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		cout << "| ";
		for (int j = 0; j < columnas; j++) {
			cout << " '" << matriz[i][j] <<"' ";
		}
		cout << " |";
		cout << endl;
	}
}

int main() {
	int opcion = 0;
	int opcion2 = 0;
	int XOR[8];
	int disco1[8];
	int disco2[8];
	bool datosingresados = false;
	while (true) {
		cout << "MENU PRINCIPAL" << endl;
		cout << "1. Disco XOR\n2. Matriz con Obstaculos\n3. Salir\n Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1: {
			while (true) {
				cout << "DISCO XOR\n1. Guardar datos en disco XOR\n2. Obtener datos de disco 1\n3. Obtener datos de disco 2\n4. Salir\n Ingrese una opcion: ";
				cin >> opcion;
				system("cls");
				if (opcion == 1) {
					datosingresados = true;
					cout << "Ingrese los datos del disco 1:\n";
					for (int i = 0; i < 8; i++) {
						cout << "Disco 1[" << i << "]: ";
						cin >> disco1[i];
						while (disco1[i] != 0 && disco1[i] != 1) {
							cout << "Ingrese un valor entre 0 y 1\n";
							cout << "Disco 1[" << i << "]: ";
								cin >> disco1[i];
						}
					}
					cout << "Ingrese los datos del disco 2:\n";
					for (int i = 0; i < 8; i++) {
						cout << "Disco 2[" << i << "]: ";
						cin >> disco2[i];
						while (disco2[i] != 0 && disco2[i] != 1) {
							cout << "Ingrese un valor entre 0 y 1\n";
							cout << "Disco 2[" << i << "]: ";
							cin >> disco2[i];
						}
					}
					for (int i = 0; i < 8; i++) {
						if (disco1[i] == disco2[i])
							XOR[i] = 0;
						else
							XOR[i] = 1;
					}
					cout << "Disco XOR: [";
					for (int i = 0; i < 8; i++) {
						cout << " " << XOR[i] << " ";
					}
					cout << "]";
					system("pause");
					system("cls");
				}
				else if (opcion == 2) {
					if (!datosingresados) {
						cout << "Primero debe ingresar datos por medio de la opcion 1!\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "\nDisco XOR: [";
						for (int i = 0; i < 8; i++) {
							cout << " " << XOR[i] << " ";
						}
						cout << "]";
						cout << "\nDisco 2: [";
						for (int i = 0; i < 8; i++) {
							cout << " " << disco2[i] << " ";
						}
						cout << "]";
						cout << "\nDatos calculados del Disco 1: [";
						for (int i = 0; i < 8; i++) {
							if (XOR[i] == 0) {
								cout << " " << disco2[i] << " ";
							}
							else if (XOR[i] == 1) {
								if (disco2[i] == 1) {
									cout << " " << 0 << " ";
								}
								else if (disco2[i] == 00) {
									cout << " " << 1 << " ";
								}
							}
						}
						cout << "]\n";
						system("pause");
						system("cls");
					}
				}
				else if (opcion == 3) {
					if (!datosingresados) {
						cout << "Primero debe ingresar datos por medio de la opcion 1!\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "\nDisco XOR: [";
						for (int i = 0; i < 8; i++) {
							cout << " " << XOR[i] << " ";
						}
						cout << "]";
						cout << "\nDisco 1: [";
						for (int i = 0; i < 8; i++) {
							cout << " " << disco1[i] << " ";
						}
						cout << "]";
						cout << "\nDatos calculados del Disco 2: [";
						for (int i = 0; i < 8; i++) {
							if (XOR[i] == 0) {
								cout << " " << disco1[i] << " ";
							}
							else if (XOR[i] == 1) {
								if (disco1[i] == 1) {
									cout << " " << 0 << " ";
								}
								else if (disco1[i] == 00) {
									cout << " " << 1 << " ";
								}
							}
						}
						cout << "]\n";
						system("pause");
						system("cls");
					}
				}
				else if (opcion == 4) {
					datosingresados = false;
					for (int i = 0; i < 8; i++) {
						disco1[i] = NULL;
						disco2[i] = NULL;
					}
					break;
				}
			}
			break;
		}
		case 2: {
			cout << "Matriz con Obstaculos";
			srand(time(NULL));
			int filas, columnas, obstaculos;
			cout << "Ingrese la cantidad de filas (>= 5): ";
			cin >> filas;
			cout << "Ingrese la cantidad de columnas (>= 5): ";
			cin >> columnas;
			cout << "Ingrese la cantidad de obstaculos (>= 1 y < " << filas * columnas << "): ";
			cin >> obstaculos;
			char** matriz = Llenar_Matriz(filas, columnas);
			agregar_obstaculos(matriz, obstaculos, filas, columnas);
			imprimir_matriz(matriz, filas, columnas);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "Gracias por revisar el trabajo!\n";
			system("pause");
			return 0;
			break;
		}
		default:
			cout << "Opcion invalida!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}