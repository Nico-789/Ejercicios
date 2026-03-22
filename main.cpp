#include <iostream>
using namespace std;


const int especias = 12;
int cantidad = 0;
int cantidad_busquedas = 3;

string nombres[especias] = {"azafran", "canela", "pimienta", "curcuma", "cardamomo", "comino", "paprika", "nuez ", "oregano","ajo","tomillo","laurel"};
double precios[especias] = {3.80, 3.20, 3.40, 3.10, 3.60, 3.25, 3.15, 3.50,2.20,3.10,1.20,2.0};
int stock[especias]      = {500, 2000, 1500, 3000, 800, 2500, 3500, 1000,2500,3000,600,300};

string buscar_especia(string nombre) {

    string respuesta = "No encontrada.";
    int indice_busqueda = -1;

    for (int i = 0; i < especias; i++)
        if (nombres[i] == nombre)
            indice_busqueda = i;

    if (indice_busqueda != -1)
        respuesta = nombres[indice_busqueda] + " | $"+ std::to_string(precios[indice_busqueda]) +"/g | Stock: "+ std::to_string(stock[indice_busqueda])+" g";


    return respuesta;
}

double calcular_valor_total() {

    double acumulador_total = 0;

    for (int i = 0; i < cantidad; i++)
        acumulador_total =  acumulador_total + precios[i] * stock[i];

    return acumulador_total;
}

void generar_reporte() {

    cout<<"=== Reporte del Mercado ==="<<endl;
    cout<<"Valor total inventario:"+ std::to_string(calcular_valor_total()) +" "<<endl;
}



int main() {

    cout << "Bienvenido a su mercado de especias"<<endl;
    cout<<"Cuantas especias? (1-12):"<<endl;

    cin>>cantidad;

    if (cantidad < 0 || cantidad > especias) {
        cout<<"Ingresa un valor válido"<<endl;
    }

    for (int i = 0; i < cantidad; i++) {
        cout<<"Especia "+  std::to_string(i + 1) + " - Nombre: " + nombres[i]<<endl;
        cout<<"Especia "+  std::to_string(i + 1) + " Precio/g: " + std::to_string(precios[i])<<endl;
        cout<<"Especia "+  std::to_string(i + 1) + " Stock(g): " + std::to_string(stock[i])<<endl;
    }

    for (int i = 0; i < cantidad_busquedas; i++) {

        string valor_busqueda = "";

        cout<<"-- Busqueda "+ std::to_string(i + 1) +":"<<endl;
        cin>>valor_busqueda;
        cout<<buscar_especia(valor_busqueda)<<endl;
    }

    generar_reporte();

}

