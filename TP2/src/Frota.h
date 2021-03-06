#ifndef FROTA_H_
#define FROTA_H_

#include <vector>
#include "Veiculo.h"

using namespace std;


class Frota {
	vector<Veiculo *> veiculos;
public:
	void adicionaVeiculo(Veiculo *v1);
	int numVeiculos() const;
	int menorAno() const;
	friend ostream & operator<<(ostream & o, const Frota & f);
	vector<Veiculo *> operator () (int anoM) const;
	float totalImposto() const;
};


#endif /*FROTA_H_*/
