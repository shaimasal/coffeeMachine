#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "itemsSetup.c"

const double COFFEE_PRICE = 1.0;
const double ESPRESSO_PRICE = 1.5;
const double HOTCHOCOLATE_PRICE = 2.5;
const double MACCHIATO_PRICE = 3;
const double CAPPUCCINO_PRICE = 3.5;
const double HALF_COIN = 0.5;

int main(){
	bool flag = false; //checks if that drink is sold out 
	double changeTarget = 0;
	double cMoney; //customer's money
	bool target = false; //to check if change has been paid back corectly

	int coffee = coffeeAmount(10); //setup coffee max to 10
	int espresso = espressoAmount(5); //setup espresso max to 5
	int hotChocolate = hotChocolateAmount(3); //setup hotChocolate max to 3
	int macchiato = macchiatoAmount(2); //setup macchiato max to 2
	int cappuccino = cappuccinoAmount(7); //setup cappuccino max to 7
	
	int oneCoin = oneCoinAmount(15); //max one coin ammount is 15 KM from type 1 KM   
	double halfCoin = halfCoinsAmount(5);//max half coin ammount is 2.50 KM from type 0.50 KM,  0.50 0.50 0.50 0.50 0.50
	
	FILE *infile, *outfile;
	infile = fopen("money.txt", "r");
	outfile = fopen("money.txt", "w");

	if(infile == NULL){
    printf("Sorry file not found!\n");
	exit(1);
	}
	fprintf(outfile, "This is a record of money in the machine. \n");
	fprintf(outfile, "There is money of onecoin %d \n", oneCoin);
	fprintf(outfile, "There is money of halfcoin %.2f \n", halfCoin);

	printf("\nWelcome to Coffee Machine!\n");
	printf("You have to enter your money first then choose the drink that you want to buy.\n\n");
	
	printf("Please enter your money in KM or 0 to Exit: ");
	scanf("%lf", &cMoney);
	int option; //customer's option to buy
	while(cMoney != 0 ){
		printf("\n\nPlease choose number of drink that you want to buy or 0 to Exit:\n");
		printf("\n1- Coffee, price: 1 KM, %d left.\n", coffee);
		printf("2- Espresso, price: 1.5 KM, %d left.\n", espresso);
		printf("3- Hot Chocolate, price: 2.50 KM, %d left.\n", hotChocolate);
		printf("4- Macchiato, price: 3 KM, %d left.\n", macchiato);
		printf("5- Cappuccino, price: 3.50 KM, %d left.\n", cappuccino);
		printf("\nnumber: ");
		scanf("%d", &option);
		while(option != 0){
			if(option == 1){
				if(soldOut(coffee)){
					flag = true;
					break;
				}
				if(notEnoughMoney(cMoney, COFFEE_PRICE)){
					printf("You didn't pay enough money for this drink!\n try again and be sure that you have paid enough for that drink!\n");
					exit(1);
				}else{
					changeTarget = cMoney - COFFEE_PRICE;
					if(changeTarget > (oneCoin + halfCoin)){
						printf("Sorry we dont have change to pay back!\n we can't take your order.\n");
						printf("Your money %.2f KM has been returned!\n", cMoney);
						exit(1);
					}else{
						cMoney = cMoney - COFFEE_PRICE;
						while(target == false){
							if(oneCoin != 0 && changeTarget >= 1){ 
								changeTarget--;
								oneCoin--; 
								fprintf(outfile, "The current VALUE is %d KM of oneCoin \n", oneCoin);
							}else if((oneCoin == 0 || changeTarget > 0) && halfCoin != 0){ 
								changeTarget = changeTarget - HALF_COIN; 
								halfCoin = halfCoin - 0.5; 
								fprintf(outfile, "The current VALUE is %.2f KM of halfCoin \n", halfCoin);
							}
							if(changeTarget == 0){
								target = true;
							}
							
						}
					}
				}
				coffee--;
				printf("Enjoy with your coffee!\n");
				printf("Your rest money is %.2f KM\n", cMoney);
				break;
			}else if(option == 2){
				if(soldOut(espresso)){
					flag = true;
					break;
				}
				if(notEnoughMoney(cMoney, ESPRESSO_PRICE)){
					printf("You didn't pay enough money for this drink!\n try again and be sure that you have paid enough for that drink!\n");
					exit(1);
				}else{
					changeTarget = cMoney - ESPRESSO_PRICE;
					if(changeTarget > (oneCoin + halfCoin)){
						printf("Sorry we dont have change to pay back!\n we can't take your order.\n");
						printf("Your money %.2f KM has been returned!\n", cMoney);
						exit(1);
					}else{
						cMoney = cMoney - ESPRESSO_PRICE;
						while(target == false){
							if(oneCoin != 0 && changeTarget >= 1){
								changeTarget--;
								oneCoin--;
								fprintf(outfile, "The current VALUE is %d KM of oneCoin \n", oneCoin);
							}else if((oneCoin == 0 || changeTarget > 0) && halfCoin != 0){
								changeTarget = changeTarget - HALF_COIN;
								halfCoin = halfCoin - 0.5;
								fprintf(outfile, "The current VALUE is %.2f KM of halfCoin \n", halfCoin);
							}
							
							if(changeTarget == 0){
								target = true;
							}
							
						}
					}
				}
				espresso--;
				printf("Enjoy with your espresso!\n");
				printf("Your rest money is %.2f KM\n", cMoney);
				break;
			}else if(option == 3){
				if(soldOut(hotChocolate)){
					flag = true;
					break;
				}
				if(notEnoughMoney(cMoney, HOTCHOCOLATE_PRICE)){
					printf("You didn't pay enough money for this drink!\n try again and be sure that you have paid enough for that drink!\n");
					exit(1);
				}else{
					changeTarget = cMoney - HOTCHOCOLATE_PRICE;
					if(changeTarget > (oneCoin + halfCoin)){
						printf("Sorry we dont have change to pay back!\n we can't take your order.\n");
						printf("Your money %.2f KM has been returned!\n", cMoney);
						exit(1);
					}else{
						cMoney = cMoney - HOTCHOCOLATE_PRICE;
						while(target == false){
							if(oneCoin != 0 && changeTarget >= 1){
								changeTarget--;
								oneCoin--;
								fprintf(outfile, "The current VALUE is %d KM of oneCoin \n", oneCoin);
							}else if((oneCoin == 0 || changeTarget > 0) && halfCoin != 0){
								changeTarget = changeTarget - HALF_COIN;
								halfCoin = halfCoin - 0.5;
								fprintf(outfile, "The current VALUE is %.2f KM of halfCoin \n", halfCoin);
							}
							
							if(changeTarget == 0){
								target = true;
							}
							
						}
					}
				}
				hotChocolate--;
				printf("Enjoy with your Hot Chocolate!\n");
				printf("Your rest money is %.2f KM\n", cMoney);
				break;
			}else if(option == 4){
				if(soldOut(macchiato)){
					flag = true;
					break;
				}
				if(notEnoughMoney(cMoney, MACCHIATO_PRICE)){
					printf("You didn't pay enough money for this drink!\n try again and be sure that you have paid enough for that drink!\n");
					exit(1);
				}else{
					changeTarget = cMoney - MACCHIATO_PRICE;
					if(changeTarget > (oneCoin + halfCoin)){
						printf("Sorry we dont have change to pay back!\n we can't take your order.\n");
						printf("Your money %.2f KM has been returned!\n", cMoney);
						exit(1);
					}else{
						cMoney = cMoney - MACCHIATO_PRICE;
						while(target == false){
							if(oneCoin != 0 && changeTarget >= 1){
								changeTarget--;
								oneCoin--;
								fprintf(outfile, "The current VALUE is %d KM of oneCoin \n", oneCoin);
							}else if((oneCoin == 0 || changeTarget > 0) && halfCoin != 0){
								changeTarget = changeTarget - HALF_COIN;
								halfCoin = halfCoin - 0.5;
								fprintf(outfile, "The current VALUE is %.2f KM of halfCoin \n", halfCoin);
							}
							
							if(changeTarget == 0){
								target = true;
							}
							
						}
					}
				}
				macchiato--;
				printf("Enjoy with your Macchiato!\n");
				printf("Your rest money is %.2f KM\n", cMoney);
				break;
			}else if(option == 5){
				if(soldOut(cappuccino)){
					flag = true;
					break;
				}
				if(notEnoughMoney(cMoney, CAPPUCCINO_PRICE)){
					printf("You didn't pay enough money for this drink!\n try again and be sure that you have paid enough for that drink!\n");
					exit(1);
				}else{
					changeTarget = cMoney - CAPPUCCINO_PRICE;
					if(changeTarget > (oneCoin + halfCoin)){
						printf("Sorry we dont have change to pay back!\n we can't take your order.\n");
						printf("Your money %.2f KM has been returned!\n", cMoney);
						exit(1);
					}else{
						cMoney = cMoney - CAPPUCCINO_PRICE;
						while(target == false){
							if(oneCoin != 0 && changeTarget >= 1){
								changeTarget--;
								oneCoin--;
								fprintf(outfile, "The current VALUE is %d KM of oneCoin \n", oneCoin);
							}else if((oneCoin == 0 || changeTarget > 0)&& halfCoin != 0){
								changeTarget = changeTarget - HALF_COIN;
								halfCoin = halfCoin - 0.5;
								fprintf(outfile, "The current VALUE is %.2f KM of halfCoin \n", halfCoin);
							}
							
							if(changeTarget == 0){
								target = true;
							}
							
						}
					}
				}
				cappuccino--;
				printf("Enjoy with your Cappuccino!\n");
				printf("Your rest money is %.2f KM\n", cMoney);
				break;
			}
		}
		if(option == 0 && cMoney != 0){
			flag = true;
			break;
		}
	}
	

	if(flag){ 
		printf("Your money %.2f KM has been returned! Have a Nice Day!\n", cMoney);
	}
	
	fclose(infile);
	fclose(outfile);
	return 0;
}