/*
 * Condominio.cpp
 */

#include "Condominio.h"

int nID=1;

int nID_I =1;


Imovel::Imovel(int areaH, string prop,int id): areaHabitacao(areaH), proprietario(prop), ID(nID_I)
{
	nID_I++;
}

int Imovel::getID() const
{ return ID; }

void Imovel::setID(int id)
{ ID=id; }

int Imovel::getAreaHabitacao() const
{ return areaHabitacao; }

string Imovel::getProprietario() const
{ return proprietario; }

float Imovel::mensalidade() const
{
	return 50 + 0.2*areaHabitacao;
}

Apartamento::Apartamento(int areaH, int anda, string prop, int id): Imovel(areaH,prop,id), andar(anda)
{}

float Apartamento::mensalidade() const
{
	return Imovel::mensalidade() + andar;
}

Vivenda::Vivenda(int areaH, int areaExt, bool pisc, string prop, int id):Imovel(areaH,prop,id), areaExterior(areaExt), piscina(pisc)
{}

float Vivenda::mensalidade() const
{
	if(piscina)
		return Imovel::mensalidade() + 0.1*areaExterior + 10;
	else
		return Imovel::mensalidade() + 0.1*areaExterior ;
}

int Vivenda::getAreaTotal() const
{
	return Imovel::getAreaTotal() + areaExterior;
}

Urbanizacao::Urbanizacao(string nm, int id): nome(nm), ID(id)
{}

Urbanizacao::Urbanizacao(string nm) : nome(nm),ID(nID)
{
	nID++;
	resetID_i();
}

void Urbanizacao::adicionaImovel(Imovel *im1)
{ imoveis.push_back(im1); }


vector<Imovel *> Urbanizacao::getImoveis() const
{ return imoveis; }

string Urbanizacao::getNome() const
{ return nome; }

int Urbanizacao::getID() const
{ return ID; }

void Urbanizacao::resetID()
{
	nID=1;
}
void Urbanizacao::resetID_i()
{
	nID_I=1;
}
vector<Imovel*> Urbanizacao::areaSuperiorA(int a1) const
{
	vector<Imovel*> im;
	for(size_t i=0;i<imoveis.size();i++)
	{
		if(imoveis[i]->getAreaTotal() > a1)
			im.push_back(imoveis[i]);
	}
	return im;
}

bool Urbanizacao::operator >(const Urbanizacao &u1)
{
	vector<string> difp1;
	vector<string> difp2;

	if(imoveis.size() ==0)
		return false;
	else if(u1.getImoveis().size() ==0)
		return true;
	for(size_t i =0; i<imoveis.size();i++)
	{
		bool found=false;
		for(size_t j=0;j<difp1.size();j++)
		{
			if(imoveis[i]->getProprietario() == difp1[j])
				found = true;
		}
		if(!found)
			difp1.push_back(imoveis[i]->getProprietario());
	}
	for(size_t i =0; i<u1.getImoveis().size();i++)
	{
		bool found=false;
		for(size_t j=0;j<difp2.size();j++)
		{
			if(u1.getImoveis()[i]->getProprietario() == difp2[j])
				found = true;
		}
		if(!found)
			difp2.push_back(u1.getImoveis()[i]->getProprietario());
	}
	float r1 = (float) (imoveis.size()/difp1.size());
	float r2 = (float) (u1.getImoveis().size() /difp2.size());
	return  r1 < r2 ;
}

void ECondominio::adicionaUrbanizacao(Urbanizacao urb1)
{ urbanizacoes.push_back(urb1); }

vector<Urbanizacao> ECondominio::getUrbanizacoes() const
{ return urbanizacoes; }

float ECondominio::mensalidadeDe(string nome) const
{
	float sum =0;
	for(size_t i =0; i <urbanizacoes.size();i++)
	{
		for(size_t j =0; j < urbanizacoes[i].getImoveis().size();j++)
		{
			if(urbanizacoes[i].getImoveis()[j]->getProprietario()==nome)
				sum += urbanizacoes[i].getImoveis()[j]->mensalidade();
		}
	}
	return sum;
}

vector<Urbanizacao> ECondominio::removeUrbanizacaoDe(string nome)
{
	vector<Urbanizacao> remov;
	for(size_t i =0;i<urbanizacoes.size();i++)
	{
		bool found=false;
		for(size_t j=0;j<urbanizacoes[i].getImoveis().size();j++)
		{
			if(urbanizacoes[i].getImoveis()[j]->getProprietario()==nome)
			{
				remov.push_back(urbanizacoes[i]);
				found = true;
				break;
			}
		}
		if(found)
		{
			urbanizacoes.erase(urbanizacoes.begin()+i);
			i--;
		}
	}
	return remov;
}

vector<Imovel*> ECondominio::operator ()(const string &s)
{
	vector<Imovel*> inex;
	for(size_t i=0; i<urbanizacoes.size();i++)
	{
		if(urbanizacoes[i].getNome()==s)
			return urbanizacoes[i].getImoveis();
	}
	return inex;
}





