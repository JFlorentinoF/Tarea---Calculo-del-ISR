#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double SalarioBruto, SueldoNetoGravableMensual, RentaNetaAnual;
    double ISRAnual = 0, ISRMensual = 0;

    cout << "BIENVENIDO AL BANCO YUNIPET.\nCalculadora del ISR.\n" << endl;
    cout << "Introduzca su salario bruto mensual: ";
    cin >> SalarioBruto;

    // Se descuenta el 5.91% de la TSS (2.87% AFP + 3.04% SFS)
    SueldoNetoGravableMensual = SalarioBruto - (SalarioBruto * 0.0591);
    RentaNetaAnual = SueldoNetoGravableMensual * 12;

    // Lógica con la escala de la DGII vigente
    if (RentaNetaAnual <= 416220.00) {
        ISRAnual = 0;
    }
    else if (RentaNetaAnual <= 624329.00) {
        ISRAnual = (RentaNetaAnual - 416220.00) * 0.15;
    }
    else if (RentaNetaAnual <= 867123.00) {
        ISRAnual = 31216.00 + ((RentaNetaAnual - 624329.00) * 0.20);
    }
    else { // Para rentas mayores a 867,123.01
        ISRAnual = 79776.00 + ((RentaNetaAnual - 867123.00) * 0.25);
    }

    // Se divide el ISR anual entre 12 para saber cuánto descontar cada mes
    ISRMensual = ISRAnual / 12;

    // Configuración para mostrar solo 2 lugares decimales
    cout << fixed << setprecision(2);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Tu salario bruto mensual es:RD$ " << SalarioBruto << endl;

    // Condición para mostrar 0 si no aplica para el impuesto.
    if (ISRMensual > 0) {
        cout << "Tu descuento mensual de ISR va a ser de:RD$ " << ISRMensual << endl;
    }
    else {
        cout << "Tu descuento mensual de ISR va a ser de:RD$ 0.00" << endl;
    }
}