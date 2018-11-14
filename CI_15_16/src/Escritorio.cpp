#include "Escritorio.h"
#include <iostream>


//Documento
Documento::Documento(int nPag, float pP, float pA):
			numPaginas(nPag), pPreto(pP), pAmarelo(pA)
{ }
Documento::~Documento() {}

int Documento::getNumPaginas() const { return numPaginas; }

float Documento::getPercentagemPreto() const { return pPreto; }

float Documento::getPercentagemAmarelo() const { return pAmarelo; }

Documento Documento::operator +(const Documento &doc1)
{
	Documento doc(this->getNumPaginas() + doc1.getNumPaginas(),
			(this->getPercentagemPreto() * this->getNumPaginas() + doc1.getPercentagemPreto()*doc1.getNumPaginas()) / (this->getNumPaginas() + doc1.getNumPaginas()),
			(this->getPercentagemAmarelo() * this->getNumPaginas() + doc1.getPercentagemAmarelo()*doc1.getNumPaginas()) / (this->getNumPaginas() + doc1.getNumPaginas()));
	return doc;
}

//Impressora
Impressora::Impressora(string cod, int a): codigo(cod), ano(a)
{}
Impressora::~Impressora() {}

string Impressora::getCodigo() const
{ return codigo; }

int Impressora::getAno() const
{ return ano; }

vector<Documento> Impressora::getDocumentosImpressos() const
{ return docsImpressos; }

bool Impressora::imprime(Documento doc1) {return true;}

//ImpressoraPB
ImpressoraPB::ImpressoraPB(string cod, int a, int toner): Impressora(cod, a), numPagImprimir(toner)
{}

int ImpressoraPB::getNumPaginasImprimir() const
{ return numPagImprimir; }

bool ImpressoraPB::imprime(Documento doc1)
{
	if(numPagImprimir < doc1.getNumPaginas())
		return false;
	else
	{
		docsImpressos.push_back(doc1);
		numPagImprimir -= doc1.getNumPaginas();
		return true;
	}
}


//ImpressoraCores
ImpressoraCores::ImpressoraCores(string cod, int a, int toner): Impressora(cod, a),
		numPagImprimirPreto(toner), numPagImprimirAmarelo(toner)
{}

int ImpressoraCores::getNumPaginasImprimir() const {
	if (numPagImprimirPreto < numPagImprimirAmarelo) return (int)numPagImprimirPreto;
	return (int)numPagImprimirAmarelo;
}

bool ImpressoraCores::imprime(Documento doc1)
{
	if(numPagImprimirAmarelo < doc1.getNumPaginas() * doc1.getPercentagemAmarelo())
		return false;
	else if(numPagImprimirPreto < doc1.getNumPaginas() * doc1.getPercentagemPreto())
		return false;
	docsImpressos.push_back(doc1);
	numPagImprimirAmarelo -= doc1.getNumPaginas()* doc1.getPercentagemAmarelo();
	numPagImprimirPreto -= doc1.getNumPaginas() * doc1.getPercentagemPreto();
	return true;
}

//Funcionario
Funcionario::Funcionario(string cod): codigo(cod)
{}
Funcionario::~Funcionario() {}

void Funcionario::adicionaImpressora(Impressora *i1)
{ impressoras.push_back(i1); }

vector<Impressora *> Funcionario::getImpressoras() const
{ return impressoras; }

string Funcionario::getCodigo() const
{ return codigo; }



//Escritorio
Escritorio::Escritorio() {}
Escritorio::~Escritorio() {}

void Escritorio::adicionaImpressora(Impressora *i1)
{ impressoras.push_back(i1); }

void Escritorio::adicionaFuncionario(Funcionario f1)
{ funcionarios.push_back(f1); }

vector<Impressora *> Escritorio::getImpressoras() const
{ return impressoras; }

int Escritorio::numImpressorasSemResponsavel() const
{
	int n = 0;
	for(size_t i = 0; i <funcionarios.size();i++)
	{
		for(size_t j=0;j < funcionarios[i].getImpressoras().size();j++)
		{
			for(size_t k=0;k< impressoras.size();k++)
			{
				if(funcionarios[i].getImpressoras()[j]->getCodigo() == impressoras[k]->getCodigo())
					n++;
			}
		}
	}
	return impressoras.size() - n;
}

vector<Impressora*> Escritorio::retiraImpressoras(int ano1)
{
	vector<Impressora*> removed;
	for(size_t i =0;i<impressoras.size();i++)
	{
		if(impressoras[i]->getAno() < ano1)
		{
			removed.push_back(impressoras[i]);
			impressoras.erase(impressoras.begin()+i);
			i--;
		}
	}
	return removed;
}

Impressora* Escritorio::imprimeDoc(Documento doc1) const
{
	for(size_t i = 0; i < impressoras.size();i++)
	{
		if(impressoras[i]->imprime(doc1))
			return impressoras[i];
	}
	Impressora* inex = new Impressora("inexistente",0);
	return inex;
}
vector<Impressora*> Escritorio::tonerBaixo() const
{
	vector<Impressora*> tonerBaixo;
	for(size_t i =0; i< impressoras.size();i++)
	{
		if(impressoras[i]->eCores())
		{
			if(impressoras[i]->getNumPaginasImprimir() < 20)
				tonerBaixo.push_back(impressoras[i]);
		}
		else
		{
			if(impressoras[i]->getNumPaginasImprimir() < 30)
				tonerBaixo.push_back(impressoras[i]);
		}
	}
	return tonerBaixo;
}

string Escritorio::operator()(string cod)
{

	for(size_t i=0;i<funcionarios.size();i++)
	{
		for(size_t j=0;j<funcionarios[i].getImpressoras().size();j++)
		{
			if(funcionarios[i].getImpressoras()[j]->getCodigo()==cod)
				return funcionarios[i].getCodigo();
		}
	}
	return "nulo";
}










