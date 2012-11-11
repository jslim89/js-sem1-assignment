/***** KTAR_LRT Program-2 *****/
/*******************************
Created by: Lim Jeong Sheng
			Tan Keong Ghee
			Yoong Keat Wei

Tutorial Class: Y1 M45
*******************************/

#include <stdio.h>
#include <math.h>			// Math Function

// Function Declaration

void destinationMenu();		
void ticketType();
void passagerType();
void continueMenu();

// Variables
double price, tax, charge, final_charge;
int way;
int type;
char stat_1, stat_2, y_n;

void main()					// Function Definition
{
	printf("-----------------------KTAR LRT station--------------------\n\n");
	printf(">> A << ---- >> B << ---- >> C << ---- >> D << ---- >> E <<\n");
	printf("----------------------Ticket price (RM)--------------------\n");
	printf("~~~~~~~ 1.10 ~~~~~~~ 0.80 ~~~~~~~ 1.70 ~~~~~~~ 1.40 ~~~~~~~\n");
	destinationMenu();		// Function Call
}

void destinationMenu()		// Function Definition
{
	fflush(stdin);
	printf("\n\n");		// Print some blank lines
	printf("***********************************************************\n");
	// Input

	printf("Destination from (A,B,C,D,E): ");
	scanf("%c",&stat_1);


	switch(stat_1)
	{
	case 'A': case 'a':
	case 'B': case 'b':
	case 'C': case 'c':
	case 'D': case 'd':
	case 'E': case 'e':

		printf("To destination (A,B,C,D,E): ");
		fflush(stdin);
		scanf("%c",&stat_2);
		printf("***********************************************************\n\n\n");
		
		if(stat_1 == stat_2)
		{
			printf("You have entered same destination. Please re-enter...\n\n");
			destinationMenu();
			return;
		}

		switch(stat_2)
		{
			case 'A': case 'a':
			case 'B': case 'b':
			case 'C': case 'c':
			case 'D': case 'd':
			case 'E': case 'e':
				break;
			default:
				printf("Invalid! Please re-enter...\n\n");
				destinationMenu();
				return;
				break;
		}
		break;

	default:
		printf("Invalid! Please re-enter...\n\n");
		destinationMenu();
		return;
		break;
	}

	
		switch(stat_1)		// Switch statement
		{
		case 'A': case 'a':
			
			switch(stat_2)
			{
			case 'B': case 'b':
				price = 1.10;
				break;
			case 'C': case 'c':
				price = 1.90;
				break;
			case 'D': case 'd':
				price = 3.60;
				break;
			case 'E': case 'e':
				price = 5.00;
				break;
			default:
			;}
			break;

		case 'B': case 'b':
			
			switch(stat_2)
			{
			case 'A': case 'a':
				price = 1.10;
				break;
			case 'C': case 'c':
				price = 0.80;
				break;
			case 'D': case 'd':
				price = 2.50;
				break;
			case 'E': case 'e':
				price = 3.90;
				break;
			default:
			;}
			break;

		case 'C': case 'c':
			
			switch(stat_2)
			{
			case 'A': case 'a':
				price = 1.90;
				break;
			case 'B': case 'b':
				price = 0.80;
				break;
			case 'D': case 'd':
				price = 1.70;
				break;
			case 'E': case 'e':
				price = 3.10;
				break;
			default:
			;}
			break;

		case 'D': case 'd':
			
			switch(stat_2)
			{
			case 'A': case 'a':
				price = 3.60;
				break;
			case 'B': case 'b':
				price = 2.50;
				break;
			case 'C': case 'c':
				price = 1.70;
				break;
			case 'E': case 'e':
				price = 1.40;
				break;
			default:
			;}
			break;

		case 'E': case 'e':
			
			switch(stat_2)
			{
			case 'A': case 'a':
				price = 5.00;
				break;
			case 'B': case 'b':
				price = 3.90;
				break;
			case 'C': case 'c':
				price = 3.10;
				break;
			case 'D': case 'd':
				price = 1.40;
				break;
			default:
			;}
			break;
		default:
	;}	
		// Output
		printf("-----------------------------------------------------------\n");
		printf("The station from %c to %c.\n",stat_1,stat_2);
		printf("Ticket price is RM %.2f\n",price);
		printf("-----------------------------------------------------------\n\n\n\n");
	
	
	ticketType(); // Function Call
}
	
void ticketType()		// Function Definition
{
	do
	{
		printf("***********************************************************\n");
		printf("(1) 1 way\n");
		printf("(2) 2 ways\n");
		printf("(3) Back\n");
		printf("***********************************************************\n");
	
			// Input
			printf("Please choose the selection : ");
			scanf("%d",&way);
			printf("***********************************************************\n\n");

			if(way == 1)
				price *= 1;
			else if(way == 2)
				price *= 2;
			else if(way == 3)
			{
				destinationMenu();
				return;
			}
			else
				printf("Invalid! Please re-enter...\n\n ");


		}while(way<1 || way>3);
		// Output
		printf("\n-----------------------------------------------------------\n");
		printf("The total of ticket price is RM %.2f\n",price);
		printf("-----------------------------------------------------------\n\n");
	
	passagerType();		// Function Call 
	
	return;
}

void passagerType()		// Function Definition
{
	int i;

	for(i=0 ; type<1 || type>3 ; i++)
	{
		printf("***********************************************************\n");
		printf("(1) Kid\n");
		printf("(2) Adult\n");
		printf("(3) Senior Citizen\n");
		printf("***********************************************************\n");

		// Input
		printf("Please choose the selection : ");
		scanf("%d",&type);
		printf("***********************************************************\n\n\n");

		if(type == 1)
		{
			tax = 0.1;
		}
		else if(type == 2)
		{
			tax = 0.2;
		}
		else if(type == 3)
		{
			tax = 0;
		}
		else
		{
			printf("\nInvalid! Please re-enter...\n\n");
		}
	}

	charge = ceil((price * tax) * 10)/10;
	final_charge = price + charge;

	// Output
	printf("-----------------------------------------------------------\n");
	printf("You have charged by RM %.2f\n",charge);
	printf("The final charge is RM %.2f\n",final_charge);
	printf("-----------------------------------------------------------\n\n");

	continueMenu();		// Function Call
}

void continueMenu()		// Function Definition
{
		// Input
		printf("Do you want buy ticket again? (Y/N): ");
		scanf(" %c",&y_n);
	
		if(y_n == 'Y' || y_n == 'y')
		{
			printf("\n\n\n\n");
			main();
			return;
		}
		else if(y_n == 'N' || y_n == 'n')
		{
			return;
		}
		else
		{
			printf("\nInvalid! Please re-enter...\n\n");
			continueMenu();			// Function Call
			return;
		}
}
