#include <iostream>
#include <string>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include <stdexcept>

void sortSelect(std::vector<double> &data);
void printData(std::vector<double> &data);

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wcout << L"Ordenar numeros mediante el algoritmo de ordenamiento por selección.\n";
    std::wcout << L"Ingresa los números, para finalizar escribe \"fin\"." << std::endl;

    std::wstring dataIn;
    std::vector<double> data;
    double num;
    int counter = 0;

    while(true) {
        std::wcout << L"[" << counter << L"]> ";
        std::wcin >> dataIn;
        if (dataIn == L"fin")
            break;
        try {
            num = std::stod(dataIn);
            data.push_back(num);
            counter++;
        } catch(std::invalid_argument &exp) {
            std::wcout << L"No se guardo \"" << dataIn << L"\" porque no es un numero." << std::endl;
        } catch(std::out_of_range &exp){
            std::wcout << L"No se guardo \"" << dataIn << L"\", porque es demasiado grande para ser almacenado."
                << std::endl;
        }
    }
    if(data.empty()) {
        std::wcout << L"No se ingresaron datos" << std::endl;
        return 0;
    }
    std::wcout << L"Numeros ingresados...\n";
    printData(data);
    sortSelect(data);
    std::wcout << L"Después de aplicar el algoritmo de ordenamiento por selección..." << std::endl;
    printData(data);
}

void exchangeValue(double &a, double &b) {
    double aux = a;
    a = b;
    b = aux;
}

/**
* Ordenar un vector de n elementos de tipo double
* utilizando el algoritmo de ordenación por selección.
*/
void sortSelect(std::vector<double> &data) {
    int indexLower;

    /*
    * Ordenar data[0]...a[n-2] y a[n-1] en cada pasada
    */
    for(unsigned i = 0; i < data.size() - 1; i++) {
        indexLower = i;
        // j explora la sublista data[i+1]...data[n-1]
        for(unsigned j = i + 1; j < data.size(); j++)
            if(data[j] < data[indexLower])
                indexLower = j;
        // sitúa el elemento mas pequeño en data[i]
        if(i != indexLower)
            exchangeValue(data[i], data[indexLower]);
    }
}

/**
* Imprimir los valores del vector
*/
void printData(std::vector<double> &data) {
    for(unsigned i = 0; i < data.size(); i++) {
        std::wcout << L"[" << i << L"]-> " << data[i] << std::endl;
    }
}
