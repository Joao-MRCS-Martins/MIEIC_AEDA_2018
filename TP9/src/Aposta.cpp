#include "Aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Aposta::contem(unsigned num) const
{
	return (numeros.find(num) != numeros.end());
}


void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
	for(int i =0;i<valores.size() && n>0;i++) {
		if (numeros.insert(valores[i]).second)
			n--;
	}

}
unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
	unsigned certos = 0;
	tabHInt::const_iterator it = numeros.begin();
	for(;it != numeros.end();it++) {
		if (sorteio.find(*it) != sorteio.end())
			certos++;
	}
	return certos;
}




