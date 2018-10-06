#include "Frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1) {
	veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
	return veiculos.size();
}

int Frota::menorAno() const {
	if (veiculos.empty())
		return 0;
	int x, m = veiculos.at(0)->getAno();
	for (size_t i = 1; i< veiculos.size(); i++) {
		x = veiculos.at(i)->getAno();
		if(m > x)
			m = x;
	}
	return m;
}

ostream & operator<<(ostream &o, const Frota &f) {
	for (size_t i = 0; i < f.veiculos.size(); i++) {
		cout << "O veiculo " << i+1 << " tem os seguintes atributos: " << endl;
		f.veiculos.at(i)->info();
		cout << endl;
	}
	return o;
}

vector<Veiculo *> Frota::operator () (int anoM) const {
	vector<Veiculo *> v1;
	for (size_t i = 0; i < veiculos.size(); i++) {
		if (veiculos.at(i)->getAno() == anoM)
			v1.push_back(veiculos.at(i));
	}
	return v1;
}

float Frota::totalImposto() const {
	float sum = 0;
	if (veiculos.empty())
		return sum;
	for (size_t i = 0; i < veiculos.size(); i++) {
		sum += veiculos.at(i)->calcImposto();
	}
	return sum;
}

















