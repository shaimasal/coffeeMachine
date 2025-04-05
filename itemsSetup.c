#include <stdio.h>
#include <stdbool.h>

//set max ammount of coffee 
int coffeeAmount(int amount){
	return amount;
}

//set max ammount of espresso 
int espressoAmount(int amount){
	return amount;
}

//set max ammount of hot chocolate
int hotChocolateAmount(int amount){
	return amount;
}

//set max ammount of macchiato
int macchiatoAmount(int amount){
	return amount;
}

//set max ammount of cappuccino
int cappuccinoAmount(int amount){
	return amount;
}

//set max ammount of 1 KM coins that are in machine
int oneCoinAmount(int km){
	return km;
}

//set max ammount of 0,5 KM coins that are in machine
double halfCoinsAmount(double coin){ 
	return coin / 2;
}


//function to checks if there is a drink of chosen type or not
bool soldOut(int amount){
	
	if(amount == 0){//if this drink is sold out already, then give true back!
		printf("This item is sold out\n");
		return true;
	}
	
	return false;
}

//function checks if customer has paid enough money to buy drink or not
bool notEnoughMoney(double paid, double price){
	
	if(paid < price){//if customer payed less than drink's price --> return true;
		return true;
	}
	
	return false;
}


