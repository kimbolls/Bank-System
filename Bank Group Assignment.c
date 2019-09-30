#include <stdio.h>
#include<stdbool.h>
bool repeat();
bool quit = false;

main()
{
	char code;
	double balance = 500, deposit, withdraw;						//set starting account balance as 500
	printf("Welcome to myBank Berhad\n");							//interface , main menu for user
	printf("Your Account Balance is : RM %.2f\n", balance);
	printf("PLEASE CHOOSE ENTER TRANSACTION\n");
	printf("Cash Deposit : [1] \nCash Withdrawal : [2]\n");
	

	

	while (!quit)													//loop to repeat the entire transaction if user wants to
	{
		printf("Enter the Transaction code ([1],[2]) : ");			//user chooses to deposit or withdraw cash 
		scanf_s(" %c", &code);
		switch (code)
		{
		case '1':													//transaction code '1' to deposit cash
			printf("You Chose [%c] : Cash Deposit\n\n\n", code);
			printf("< Deposit Transaction >\n");
			printf("\nEnter amount you want to deposit : RM ");	    //user enter amount of cash to be deposited
			scanf_s("%lf", &deposit);			
			balance = balance + deposit;							//calculate cash deposited to be added to balance
			printf("\n\n\t\t.....PROCESSING.....\n");
			printf("\nYou deposited : RM %.2f", deposit);			//display amount cash deposited
			printf("\nYour balance is : RM %.2f", balance);			//display balance of cash in account
			repeat();												//user chooses to repeat transaction or to finish transaction
			break;
			

		case '2':													//transaction code '2' to deposit cash
			printf("You Chose [%c] : Cash Withdrawal\n\n\n", code);
			printf("< Withdrawal Transaction >\n");
			printf("\nEnter amount you want to withdraw : RM ");    //user enter amount of cash to be withdrawed
			scanf_s("%lf", &withdraw);

			printf("\n\n\t\t.....PROCESSING.....\n");

			if (withdraw > balance)								    //checks if user wanted to withdraw more than he have in balance , display an error message
			{
				printf("\nYour balance is insufficient to withdraw [RM %.2f] , \nYou only have [RM %.2f] in your account balance !!", withdraw, balance);
			}
			else													//else proceed transaction
			{
				balance = balance - withdraw;						//calculate cash deposited to be added to balance
				printf("\nYou withdrawed : RM %.2f", withdraw);		//display amount cash withdrawed
				printf("\nYour balance is : RM %.2f", balance);		//display balance of cash in account
			}
			repeat();												//user chooses to repeat transaction or to finish transaction
			break;

		default:													//if user enters any other value than '1' and '2' , display an error message
			printf("\n\nError ! Transaction Code is incorrect!\n");
			quit = false;											//set quit = false to repeat the transaction
			
			



		}
		
	}
	

}
bool repeat()
{
	char cont;
	printf("\nDo you want to continue transaction? [1] to Continue : "); //user chooses if they wanted to repeat the transaction or finish it
	scanf_s(" %c", &cont);
	switch (cont) {
	case '1':															//if user enters '1' , repeat the transaction
	{
		quit = false;													//set quit = false to repeat the transaction
		break;
	}

	default:															//if user enters other than '1' , finish the transaction
	{
		quit = true;													//set quit = true to finish the transaction
		printf("\n\n\n\t\t** Thank You **");
	}
	}

}