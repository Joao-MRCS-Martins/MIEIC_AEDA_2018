/*
 * Jogo.cpp
 *
 */

#include "Jogo.h"
#include <sstream>
using namespace std;


unsigned Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;
  int n=1;
  unsigned pos = frase.find(' ');
  while ( pos != string::npos ) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}


Jogo::Jogo()
{

}

Jogo::Jogo(list<Crianca>& lc2)
{
	criancas= lc2;
}

void Jogo::insereCrianca(const Crianca &c1)
{
	criancas.push_back(c1);
}

list<Crianca> Jogo::getCriancasJogo() const
{
	return criancas;
}


string Jogo::escreve() const
{
	ostringstream oss;

	for(list<Crianca>::const_iterator it = criancas.begin(); it != criancas.end();it++) {
		oss << it->escreve() << endl;
	}
	return oss.str();
}


Crianca& Jogo::perdeJogo(string frase)
{
	int num_jogadas = numPalavras(frase);
	int jogada = 0;
	list<Crianca>::iterator it;
	while(criancas.size() > 1) {
		while (jogada < num_jogadas)
		{
			if(it == criancas.end()) {
				it = criancas.begin();
				continue;
			}
			it++;
			jogada++;
		}
		cout << criancas.front().getNome();
		if(it == criancas.end())
			it = criancas.begin();
		criancas.erase(it);
		it = criancas.begin();
		jogada = 1;
	}

	return criancas.front();
}


list<Crianca>& Jogo::inverte()
{
	criancas.reverse();
	return criancas;
}


list<Crianca> Jogo::divide(unsigned id)
{
	list<Crianca> res;
	list<Crianca>::iterator it;
	list<Crianca>::iterator it_aux;
	for(it = criancas.begin(); it != criancas.end();) {
		if(it->getIdade()>id) {
			res.push_back(*it);
			it_aux = it;
			it_aux++;
			criancas.erase(it);
			it = it_aux;
		}
		else
			it++;
	}
	return res;
}


void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
	criancas = l1;
}


bool Jogo::operator==(Jogo& j2)
{
		list<Crianca> jo2 = j2.getCriancasJogo();
	if(this->criancas.size() != jo2.size())
		return false;
	list<Crianca>::iterator i1 = criancas.begin();
	list<Crianca>::iterator i2 = jo2.begin();
	while(i1 != criancas.end()) {
		if(*i1 == *i2) {
			i1++;
			i2++;
		}
		else
			return false;
	}
	return true;
}

int myrandom (int i) { return rand()%i;}

list<Crianca> Jogo::baralha() const
{
	vector<Crianca> vec;
	list<Crianca> lc = this->getCriancasJogo();
	list<Crianca>::iterator it;
	for(it = lc.begin(); it != lc.end();it++) {
		vec.push_back(*it);
	}
	random_shuffle(vec.begin(),vec.end(),myrandom);
	lc.clear();
	for(size_t i=0;i < vec.size(); i++) {
		lc.push_back(vec[i]);
	}
	return lc;
}
