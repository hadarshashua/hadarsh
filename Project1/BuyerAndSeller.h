#ifndef BuyerAndSeller_H
#define BuyerAndSeller_H

#include "Buyer.h"
#include "Seller.h"

class BuyerAndSeller : public Buyer, public Seller
{
public:
	BuyerAndSeller( char* userName, char* password, Address* address);//constructor
	BuyerAndSeller(const BuyerAndSeller& other);//copy c'tor	
	BuyerAndSeller(BuyerAndSeller&& other);//move c'tor
	~BuyerAndSeller();	
};

#endif // ! BuyerAndSeller_H
