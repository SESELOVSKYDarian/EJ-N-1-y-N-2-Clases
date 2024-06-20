#include <iostream>
#include <string>
using namespace std;

class CPersona{
    private:
        string nombre;
        int edad;
        int dni;
        string genero;
        double peso;
        double altura;

    public:
        CPersona(string, int, int, string, double, double);
        string setNombre(string nom);
        int setEdad(int ed);
        int setDNI(int documento);
        string setGenero(string gen);
        double setPeso(double pes);
        double setAltura(double alt);
        string getNombre();
        int getEdad();
        int getDNI();
        string getGenero();
        double getPeso();
        double getAltura();
        int calcularIMC();
        string comprobarGenero(string gen);
        bool esMayorDeEdad();
};


CPersona::CPersona(string nom, int ed, int documento, string gen, double pes, double alt){
    nombre = setNombre(nom);
    edad = setEdad(ed); 
    dni = setDNI(documento);
    genero = setGenero(gen);
    peso = setPeso(pes);
    altura = setAltura(alt);
}

string CPersona::setNombre(string nom){
    nombre = nom;
    return nombre;
}

int CPersona::setEdad(int ed){
    if (ed >= 0){
        edad = ed;
    }
    return edad;
}

int CPersona::setDNI(int documento){
    dni = documento;
    return dni;
}

string CPersona::setGenero(string gen){
    genero = comprobarGenero(gen);
    return genero;
}

double CPersona::setPeso(double pes){
    peso = pes;
    return peso;
}

double CPersona::setAltura(double alt){
    altura = alt;
    return altura;
}


string CPersona::getNombre(){
    return nombre;
}

int CPersona::getEdad(){
    return edad;
}

int CPersona::getDNI(){
    return dni;
}

string CPersona::getGenero(){
    return genero;
}

double CPersona::getPeso(){
    return peso;
}

double CPersona::getAltura(){
    return altura;
}


int CPersona::calcularIMC(){
	int bajoPeso = -1;
    int pesoIdeal = 0;
    int sobrepeso = 1;

    double imc = peso / (altura * altura);
    
    if (imc < 20){
		return bajoPeso;	
	}
	if (imc >= 20 && imc <= 25){
		return pesoIdeal;
	}
	return sobrepeso;
}

bool CPersona::esMayorDeEdad(){
	bool flag = false;
	if (edad >= 18){
		flag = true;
	}
    return flag;
}

string CPersona::comprobarGenero(string gen){
    if (gen == "H" || gen == "M"){
		return gen;	
	}
    return "H";
}

int main()
{
    string nombre;
    int edad;
    int dni;
    string genero;
    double peso;
    double altura;
    string msg = "Es menor de edad.";
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Ingrese su edad: ";
    cin >> edad;
    cout << "Ingrese su DNI: ";
    cin >> dni;
    cout << "Ingrese su genero (H/M): ";
    cin >> genero;
    cout << "Ingrese su peso (kg): ";
    cin >> peso;
    cout << "Ingrese su altura (m): ";
    cin >> altura;

    CPersona persona(nombre, edad, dni, genero, peso, altura);

    cout << "Nombre: " << persona.getNombre() << endl;
    cout << "Edad: " << persona.getEdad() << endl;
    cout << "DNI: " << persona.getDNI() << endl;
    cout << "Genero: " << persona.getGenero() << endl;
    cout << "Peso: " << persona.getPeso() << endl;
    cout << "Altura: " << persona.getAltura() << endl;

    int imc = persona.calcularIMC();
    if (imc == -1){
    	cout << "Esta por debajo de su peso ideal." << endl;
	}
    if (imc == 0){
		cout << "Esta en su peso ideal." << endl;	
	}
	if (imc == 1){
		cout << "Tiene sobrepeso." << endl;
	}
	if (persona.esMayorDeEdad()){
		msg = "Es mayor de edad.";
	}
	cout << msg << endl;
    return 0;
}
