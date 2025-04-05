# coffeeMachine
# Overview
This project simulates a coffee vending machine where customers can select drinks, make payments, and receive change. The machine supports drinks like coffee, espresso, hot chocolate, macchiato, and cappuccino, and ensures proper validation for item availability and sufficient funds for transactions.

# Features
Drink Selection: Customers can choose from a variety of drinks (e.g., Coffee, Espresso, Hot Chocolate, Macchiato, Cappuccino).

Payment Handling: The machine validates whether the customer has inserted enough money for the selected drink.

Change Return: The machine provides change using coins (1 KM and 0.50 KM), prioritizing 1 KM coins for return.

Item Availability: The machine checks the stock for each item, and if an item is out of stock, it will notify the customer.

Persistent Money Tracking: A file (money.txt) tracks the machine's current balance.

# Structure
The project is split into two C files:

itemsSetup.c: Contains functions for checking the maximum quantity of each drink and coin.

machine.c: Contains the main logic for the coffee machine's operations, including customer interactions and money management.

money.txt: A text file that tracks the machine's current balance and changes after each transaction.

# Key Functions:
itemsSetup.c:

Functions for tracking available drink stock and coin amounts.

soldOut() function that checks if an item is sold out.

notEnoughMoney() function to check if the customer has enough funds for the selected drink.

machine.c:

The main function that handles customer interactions.

Asks the customer for their payment and drink selection.

Handles drink selection, payment validation, and change return.

If the customer doesn't choose anything, the machine returns their money.

# Installation
To compile and run the Coffee Machine project:

Clone the repository or download the project files.

Navigate to the project directory.

# Compile the C files:

bash
Copy
Edit
gcc machine.c itemsSetup.c -o coffee_machine
Run the executable:

bash
Copy
Edit
./coffee_machine
# How to Use
When prompted, input the amount of money you're inserting into the machine (or enter 0 to exit).

The machine will display available drink options.

Choose a drink by entering its number.

If the selection is valid and the machine has enough funds for change, it will process the order, deduct the price from your balance, and return any change.

If there is an issue (e.g., insufficient funds or sold-out drinks), the machine will notify you.

You can exit by choosing 0 and getting your money back.

Example Output
bash
Copy
Edit
Welcome to the Coffee Machine!

Please insert money (or 0 to exit): 5
Available drinks:
1. Coffee (3 KM)
2. Espresso (2 KM)
3. Hot Chocolate (4 KM)
4. Macchiato (3.5 KM)
5. Cappuccino (3.2 KM)

Please choose a drink: 1
You selected Coffee. Please wait...

Change to be returned: 2 KM
Thank you for using the Coffee Machine!
Problems Encountered
The main challenge was implementing the change-return logic. Initially, I tried using a for loop to return change, but it became complicated due to edge cases (e.g., when the machine can't return the exact change).

A while loop was used to improve the logic, allowing for more flexible handling of change return scenarios.

# Contributions
This project was developed as part of the CS103 course at the International University of Sarajevo. Special thanks to my brother for helping me solve the change-return issue by explaining the use of the while loop.
