
#ifndef ZOO_H_
#define ZOO_H_

#include "animal.h"
#include <vector>
#include <iostream>
#include <istream>

class Zoo {
	vector<Animal *> animais;
	vector<Veterinario *> veterinarios;
public:
	/**
	 * Returns the number of animals living on the zoo at that moment.
	 */
	int numAnimais() const;
	/**
	 * Returns the number of veterinaries working on the zoo at that moment.
	 */
	int numVeterinarios() const;
	/**
	 * Adds a new animal to the zoo.
	 * @param a1 , the pointer to the animal object to be added to the zoo.
	 */
	void adicionaAnimal (Animal * a1);
	/**
	 * Returns the information about the animals living on the zoo at that moment.
	 */
	string getInformacao() const;
	/**
	 * Searches for an animal with the name passed in the argument and returns true if its young.
	 * Returns false if he isn't or doesn't exist on the zoo.
	 * @param nomeA , name of the animal to be searched.
	 */
	bool animalJovem(string nomeA);
	/**
	 * Assigns vets from a istream to the animals in the zoo, distributing them properly.
	 * @param isV , stream from where the vets information will be withdrawn.
	 */
	void alocaVeterinarios(istream &isV);
	/**
	 * Searches for Vet with the name passed in the argument and removes him/her from the zoo's Vets and unassigns them
	 * from their animals, and are replaced for another Vet. Returns true in case he/she is found and removed,
	 * returns false otherwise.
	 * @param nomeV , name of the Vet to be removed.
	 */
	bool removeVeterinario(string nomeV);
	/**
	 * Compares the sum of ages of the animals in each zoo, returns true if the first has a smaller sum than the zoo's passed by argument.
	 * @param zoo2 , the reference to the zoo to be compared with.
	 */
	bool operator <(Zoo & zoo2) const;
	/**
	 * Returns the sum of the ages of the animals living in the zoo, at that moment.
	 */
	int sumIdade () const;
};


#endif /* ZOO_H_ */
