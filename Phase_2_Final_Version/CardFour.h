#pragma once

#include "Card.h"

class CardFour : public Card
{
	// CardFour Parameters:
	int walletAmount;

public:
	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFour which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

	void Save(ofstream& Outfile, int Type);


	virtual ~CardFour(); // A Virtual Destructor
};
