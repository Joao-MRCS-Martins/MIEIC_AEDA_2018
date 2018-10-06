#include "Veiculo.h"

using namespace std;

Veiculo::Veiculo(string mc, int m,int a) {
	marca = mc;
	mes = m;
	ano = a;
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil): Veiculo(mc,m,a) , combustivel(c),cilindrada(cil){

}

Automovel::Automovel(string mc, int m, int a, string c, int cil) : Motorizado(mc,m,a,c,cil) {

}

Camiao::Camiao(string mc,int m,int a, string c, int cil,int cm) : Motorizado(mc,m,a,c,cil), carga_maxima(cm) {

}

Bicicleta::Bicicleta(string mc,int m,int a,string t) : Veiculo(mc,m,a), tipo(t) {

}

string Motorizado::getCombustivel() const {
	return combustivel;
}

int Motorizado::getCilindrada() const {
	return cilindrada;
}

int Camiao::getCargaMax() const {
	return carga_maxima;
}

string Bicicleta::getTipo() const {
	return tipo;
}

string Veiculo::getMarca() const {
	return marca;
}

int Veiculo::getAno() const {
	return ano;
}

int Veiculo::getMes() const {
	return mes;
}

int Veiculo::info() const {
	cout << "A marca do veiculo e: " << this->getMarca() << endl;
	cout << "O ano do veiculo e: " << this->getAno() << endl;
	cout << "O mes do veiculo e: " << this->getMes() << endl;
	return 3;
}

int Motorizado::info() const {
	int x = Veiculo::info();
	cout << "O combustivel do veiculo e: " << this->getCombustivel() << endl;
	cout << "A cilindrada do veiculo e: " << this->getCilindrada() << endl;
	return (x+2);
}

int Automovel::info() const {
	return Motorizado::info();
}

int Camiao::info() const {
	int x = Motorizado::info();
	cout << "A carga maxima do veiculo e: " << this->getCargaMax() << endl;
	return ++x;
}

int Bicicleta::info() const {
	int x = Veiculo::info();
	cout << "O tipo de veiculo e: " << this->getTipo() << endl;
	return ++x;
}

bool Veiculo::operator <(const Veiculo & v) const {
	if (this->getAno() < v.getAno())
		return true;
	else if (this->getAno() == v.getAno()) {
		if (this->getMes() < v.getMes())
			return true;
		else return false;
	}
	else return false;
}

float Bicicleta::calcImposto() const {
	return 0;
}

float Motorizado::calcImposto() const {
	if (combustivel == "gasolina")
	{
		if (cilindrada <= 1000)
		{
			if (ano > 1995)
				return 14.56;
			else
				return 8.10;
		}
		else if ((cilindrada > 1000) && (cilindrada <= 1300))
		{
			if (ano > 1995)
				return 29.06;
			else return 14.56;
		}
		else if ((cilindrada > 1300) && (cilindrada <= 1750 ))
		{
			if (ano > 1995)
				return 45.15;
			else
				return 22.65;
		}
		else if ((cilindrada > 1750) && (cilindrada <= 2600))
		{
			if (ano > 1995)
				return 113.98;
			else
				return 54.89;
		}
		else if ((cilindrada > 2600) && (cilindrada <= 3500))
		{
			if (ano > 1995)
				return 181.17;
			else
				return 87.13;
		}
		else {
			if (ano > 1995)
				return 320.89;
			else
				return 148.37;
		}
	}
	else {
		if (cilindrada <= 1500)
		{
			if (ano > 1995)
				return 14.56;
			else
				return 8.10;
		}
		else if ((cilindrada > 1500) && (cilindrada <= 2000))
		{
			if(ano > 1995)
				return 29.06;
			else
				return 14.56;
		}
		else if ((cilindrada > 2000) && (cilindrada <= 3000))
		{
			if (ano > 1995)
				return 45.15;
			else
				return 22.65;
		}
		else {
			if (ano > 1995)
				return 113.98;
			else
				return 54.89;
		}
	}
}











