#include <iostream>

void convertirSegundos(double totalSegundos, int& horas, int& minutos, int& segundos) {
    horas = totalSegundos / 3600;
    totalSegundos %= 3600;
    minutos = totalSegundos / 60;
    segundos = totalSegundos % 60;
}

int main() {
    int totalSegundos, horas, minutos, segundos;
	double total;
    std::cout << "Ingrese la cantidad de segundos: ";
    std::cin >> total;

    convertirSegundos(total, horas, minutos, segundos);

    std::cout << totalSegundos << " segundos equivale a " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." << std::endl;

    return 0;
}
