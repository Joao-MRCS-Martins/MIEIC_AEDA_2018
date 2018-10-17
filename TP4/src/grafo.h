#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;
//definicao template da class Nó
template <class N, class A>
class No {
public:
	N info; //informacao do Nó
	vector< Aresta<N,A> > arestas; //vetor das arestas associadas ao nó
	int getNumArestas() const {  //retorna o numero de arestas associadas
		return arestas.size();	// ao nó
	}
	No(N inf) {			//construtor do Nó
		info = inf;
	}
};

//definicao template da classe Aresta
template <class N, class A>
class Aresta {
public:
	A valor; 	//valor atribuido à aresta
	No<N,A> *destino;  // pointer para o nó que está a apontar
	Aresta(No<N,A> *dest, A val) {	//construtor da aresta
		valor = val;
		destino = dest;
	}
};

//definicao template da classe Grafo
template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos; //vetor dos nós pertencentes ao grafo
  public: 
    Grafo(); //construtor e destrutor pré-definidos
    ~Grafo(); 
    Grafo & inserirNo(const N &dados); //insere nó no grafo se possivel, retorna apontador para o grafo
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val); //insere aresta num nó se possível, retorna apontador para o grafo
    Grafo & eliminarAresta(const N &inicio, const N &fim);  //elimina aresta num nó se possível, retorna apontador para o garfo
    A & valorAresta(const N &inicio, const N &fim); //retorna valor de uma aresta que faz parte de um nó "inicio" e aponta para o no "fim", se possível
    int numArestas(void) const;  // retorna o numero de arestas no grafo
    int numNos(void) const ;	//retorna o numero de nós no grafo
    void imprimir(std::ostream &os) const; //imprime o grafo num formato especifico (ver teste unitario, alinea f)
};


template <class N,class A>
Grafo<N,A>::Grafo() {

}

template <class N, class A>
Grafo<N,A>::~Grafo() {
for (size_t i=0; i<nos.size();i++) {
	delete nos.at(i);
	}
}

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);


// excecao  NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }



// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

//excecao ArestaRepetida
template<class N>
class ArestaRepetida {
public:
	N n1;
	N n2;
	ArestaRepetida(N n1,N n2) {
		this->n1 = n1;
		this->n2 = n2;
	}
};
template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<N> &ar)
{ out << "Aresta repetida: " << ar.n1 << " , " << ar.n2 ; return out; }

//excecao ArestaInexistente
template<class N>
class ArestaInexistente {
public:
	N n1;
	N n2;
	ArestaInexistente(N n1,N n2) {
		this->n1 = n1;
		this->n2 = n2;
	}
};
template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaInexistente<N> &ar)
{ out << "Aresta inexistente: " << ar.n1 << " , " << ar.n2 ; return out; }

template<class N, class A>
int Grafo<N,A>::numArestas(void) const {
    	int nA=0;
    	for (size_t i = 0; i<nos.size();i++) {
    		nA += nos.at(i)->getNumArestas();
    	}
    	return nA;
    }
template<class N, class A>
int Grafo<N,A>::numNos(void) const {
    	return nos.size();
    }

template<class N,class A>
Grafo<N,A>& Grafo<N,A>::inserirNo(const N &dados) {
    	for (size_t i=0; i < nos.size();i++) {
    			if (nos.at(i)->info == dados)
    				throw NoRepetido<N>(dados);
   		}
    	nos.push_back(new No<N,A>(dados));
    	return *this;
}

template<class N,class A>
Grafo<N,A>& Grafo<N,A>::inserirAresta(const N &inicio, const N &fim,const A &val) {
	bool flag1= true, flag2 = true;
	No<N,A>* noinit,*nofinal;
	for (size_t i=0;i < nos.size(); i++) {
		if(nos.at(i)->info == inicio) {
			noinit = nos.at(i);
			flag1 = false;
		}
		else if (nos.at(i)->info == fim) {
			nofinal = nos.at(i);
			flag2 = false;
		}
	}
	if(flag1)
		throw NoInexistente<N>(inicio);
	else if (flag2)
		throw NoInexistente<N>(fim);
	for (size_t i2 = 0; i2 < noinit->getNumArestas();i2++) {
		if (nofinal == noinit->arestas.at(i2).destino)
			throw ArestaRepetida<N>(inicio,fim);
	}
	noinit->arestas.push_back(Aresta<N,A>(nofinal,val));
	return *this;
}

template<class N,class A>
A& Grafo<N,A>::valorAresta(const N &inicio,const N&fim) {
	bool flag1= true, flag2 = true;
		No<N,A>* noinit,*nofinal;
		for (size_t i=0;i < nos.size(); i++) {
			if(nos.at(i)->info == inicio) {
				noinit = nos.at(i);
				flag1 = false;
			}
			if (nos.at(i)->info == fim) {
				nofinal = nos.at(i);
				flag2 = false;
			}
		}
		if(flag1)
			throw NoInexistente<N>(inicio);
		else if (flag2)
			throw NoInexistente<N>(fim);
		bool arestafound=false;
		size_t i = 0;
		for (; i < noinit->getNumArestas();i++) {
			if (noinit->arestas.at(i).destino->info == fim) {
				arestafound=true;
				break;
			}
		}
		if (!arestafound)
			throw ArestaInexistente<N>(inicio,fim);
		else
			return noinit->arestas.at(i).valor;
}

template<class N,class A>
Grafo<N,A>& Grafo<N,A>::eliminarAresta(const N &inicio,const N &fim) {
	bool flag1= true, flag2 = true;
			No<N,A>* noinit,*nofinal;
			size_t i=0;
			for (;i < nos.size(); i++) {
				if(nos.at(i)->info == inicio) {
					noinit = nos.at(i);
					flag1 = false;
				}
				if (nos.at(i)->info == fim) {
					nofinal = nos.at(i);
					flag2 = false;
				}
			}
			if(flag1)
				throw NoInexistente<N>(inicio);
			else if (flag2)
				throw NoInexistente<N>(fim);
			bool arestafound=false;
			size_t i2 = 0;
			for (; i2 < noinit->getNumArestas();i2++) {
				if (noinit->arestas.at(i2).destino->info == fim) {
					arestafound=true;
					break;
				}
			}
			if (!arestafound)
				throw ArestaInexistente<N>(inicio,fim);
			else
				noinit->arestas.erase(noinit->arestas.begin() + i2);
			return *this;

}

template<class N,class A>
void Grafo<N,A>::imprimir(std::ostream &os) const {
	for (size_t i = 0 ; i <nos.size();i++) {
		os << "( " << nos.at(i)->info;
		for (size_t i2=0; i2<nos.at(i)->arestas.size();i2++) {
			os << "[ " << nos.at(i)->arestas.at(i2).destino->info << " "
			<< nos.at(i)->arestas.at(i2).valor << "] ";
		}
		os << ") " ;
	}
}

template<class N,class A>
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &G) {
	G.imprimir(out);
	return out;
}
