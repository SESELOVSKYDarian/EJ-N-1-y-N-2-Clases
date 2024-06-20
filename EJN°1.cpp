#include <iostream>
#include <string>
using namespace std;

class CCuenta{
	private:
    	string titular;
    	double cantidad;
    	double cantidadRetirar;

	public:
    	CCuenta(string, double, double);
    	string setTitular(string titu);
    	double setCantidad(double cant);
    	double setCantidadRetirar(double cantRet);
    	string getTitular();
    	double getCantidad();
    	double retirarCantidad();
};

CCuenta::CCuenta(string titu, double cant, double cantRet){
	titular = setTitular(titu);
	cantidad = setCantidad(cant);
	cantidadRetirar = setCantidadRetirar(cantRet);
}

string CCuenta::setTitular(string titu){
	titular = titu;
	return titular;
}

double CCuenta::setCantidad(double cant){
	if (cant >= 0){
		cantidad = cant;
	}
	return cantidad;
}

double CCuenta::setCantidadRetirar(double cantRet){
	cantidadRetirar = cantRet;
	return cantidadRetirar;
}

string CCuenta::getTitular(){
	return titular;
}

double CCuenta::getCantidad(){
	return cantidad;
}

double CCuenta::retirarCantidad()
{
	if (cantidadRetirar <= cantidad){
		cantidad = cantidad - cantidadRetirar;
	}
	return cantidad;
}

int main()
{
    string titular;
    double cantidad;
    double cantidadRetirar;
    
    cout << "Ingrese su nombre: ";
    getline(cin, titular);
    cout << "Ingrese la cantidad de la cuenta: ";
    cin >> cantidad;
    cout << "Ingrese la cantidad a retirar de la cuenta: ";
    cin >> cantidadRetirar;

    CCuenta cuenta(titular, cantidad, cantidadRetirar);

    cout << "Titular: " << cuenta.getTitular() << endl;
    cout << "Cantidad " << cuenta.getCantidad() << endl;
    cout << "Cantidad luego de retirar dinero: " << cuenta.retirarCantidad() << endl;

    return 0;
}
