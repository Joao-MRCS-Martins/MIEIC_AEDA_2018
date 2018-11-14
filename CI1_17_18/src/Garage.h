/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include "Car.h"

class Garage {
	std::vector<Car *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Car *> getVehicles() const;
	void setVehicles(std::vector<Car *> vehicles);
	int getCapacity() const;
	bool addVehicle(Car *vehicle);
	Car* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

Garage::Garage(int size) : capacity(size) {
}

Garage::~Garage() {
	typename std::vector<Car *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

std::vector<Car *> Garage::getVehicles() const {
	return vehicles;
}

void Garage::setVehicles(std::vector<Car*> vehicles) {
	this->vehicles = vehicles;
}

int Garage::getCapacity() const {
	return capacity;
}

//ALINEA D
bool Garage::addVehicle(Car* vehicle)
{
	if(this->vehicles.size() == getCapacity())
		return false;
	else
	{
		for (size_t i = 0; i < this->vehicles.size(); i++)
		{
			if(*this->vehicles[i] == *vehicle)
			{
				return false;
			}
		}
	}
	this->vehicles.push_back(vehicle);
	return true;
}

//ALINEA E
bool compareCar (Car* c1,Car* c2)
{
	if(c1->getBrand() == c2->getBrand())
		return c1->getPrice() > c2->getPrice();
	else
		return (c1->getBrand() < c2->getBrand());
}

void Garage::sortVehicles()
{
	sort(vehicles.begin(),vehicles.end(),compareCar);
}

//ALINEA F
Car* Garage::removeVehicle(std::string brand,std::string model)
{
	for(size_t i =0;i<vehicles.size();i++)
	{
		if(vehicles[i]->getBrand() == brand && vehicles[i]->getModel() == model)
		{
			Car* c1 = vehicles[i];
			vehicles.erase(vehicles.begin() + i);
			return c1;
		}
	}
	throw NoSuchVehicleException();
}

//ALINEA G
class NoSuchBrandException
{
private:
	std::string brand;
public:
	NoSuchBrandException(std::string brand) {this->brand = brand;}
	std::string getBrand() {return brand;}
};

float Garage::avgPrice(std::string brand) const
{
	int n =0;
	float totalprice =0;
	bool nobrand=true;
	for(size_t i = 0;i<vehicles.size();i++)
	{
		if(vehicles[i]->getBrand() == brand)
		{
			nobrand = false;
			n++;
			totalprice += vehicles[i]->getPrice();
		}
	}
	if(nobrand)
		throw NoSuchBrandException(brand);
	else
		return totalprice /n;
}



#endif /* SRC_GARAGE_H_ */
