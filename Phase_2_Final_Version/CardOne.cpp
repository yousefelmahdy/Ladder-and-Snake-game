#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	pOut->PrintMessage("Enter the walletAmount of Decreaseing of the card ...");
	walletAmount=pIn->GetInteger(pOut);
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
}

void CardOne::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << walletAmount << endl;

}
void CardOne::Load(ifstream& Infile)
{
	Card::Load(Infile);
	Infile >> walletAmount;
}

void CardOne::setWalletAmount(Card* pCard)
{
	
	CardOne* ptr = dynamic_cast<CardOne*>(pCard);
	walletAmount = ptr->walletAmount;
}