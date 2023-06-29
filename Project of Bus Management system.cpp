#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<conio.h>
#include<stdlib.h>
//The variable are global variable 
int i,p,rate,Z,j,k,l,age,phone_number;
char email[20], name[8], name1[8];
char bus, root;
int bus_sit, time;

 	struct login//it is structure for login and registration function 
 	{
 		char first_name[20];
 		char last_name[20];
 		char user_name[20];
 		char password[20];
 	};
 	
 	void registration()//this function is working for the registration 
 	{
 		system("color 1f");
 		printf("\n__________\n");
		printf("REGISTER:");
		printf("\n----------\n");
 		
 		FILE *information;//here we are using file handling
 		information = fopen("information.txt", "a");//here we are open the file as well as we give the name of the file in the append mode
 		
 		struct login k;// here we are using structure for taking information for the registration of any person
 		printf("Enter first name: ");
		scanf("%s", k.first_name);
 		printf("Enter Last name: ");
		scanf("%s", k.last_name);
		
		printf("username: ");
		scanf("%s", k.user_name);
		printf("Password: ");
		scanf("%s", k.password);
		
		printf("\nThanks for Registering!, %s", k.user_name);
		printf("\n______________________________________\n");

	 	fwrite(&k, sizeof(k), 1, information);
 		fclose(information);//here we are close the file
 	}
 	
	void login()// this funtion is working for the login 
	{
		system("color 1f");
		printf("\n_______\n");
		printf("LOGIN:");
		printf("\n-------\n");
		
 		char  user_name[20],password[20];// here we are taking information for the person because here we are checking ,is it registration or not??? 
 		for(int i=0; i<3; i++)
 		{	
 			FILE *information; //here we are using again file handling 
 			information=fopen("information.txt", "r");//here we are again open the file but in this time it is in the read mode 
 			
 			struct login k;//here are we again using structure
 			printf("user_id: ");//taking user id
 			scanf("%s", &user_name);
 			printf("password: ");//taking password
 			scanf("%s", &password);
 		
 			int n=0;
 			while(fread(&k, sizeof(k), 1, information))//here we are using login for checking
 			{
 				if((strcmp(user_name,k.user_name)==0) && (strcmp(password,k.password)==0))//here we are checking ,is it register or not if he registration 
 				{//the program going forword otherwise program going to be end!!
 					printf("Welcome, %s!\n", &user_name);// if he give right password and and id then we are welcome them 
 					n++;// here we are increment the "n"
 					break;
    			}
    		}
    		if (n == 0){
    			printf("Credentials did not matched.\n\n");//if they enter wrong password then it written in the screen
			}
			
			else if (n==1){
    			break;
			}
			
			if (i == 2){
				printf("\nError: Retry Limit exceeded %d", i);
				exit(0);//every person can try only 3 time afterthat program going to be at end
			}
			fclose(information);//here we are closing the file
		}
	
	}
void bus_type()//it is working for the asking bus condition!!!
{
	system("color f0");
	printf("\t\t|||***WELCOME TO OUR APP***||\t\t\n");
	printf("\t\t______________________________\t\t\n");
	system("color 4f");
	
	printf("\nPlease Enter the bus catgory:\n");
	printf("---------------------------------\n");
	printf("Enter A: for Higher condition, 8$ per km\n");
	printf("Enter B: for Medium condition, 5$ per km\n");
	printf("Enter C: for Lower  condition, 2$ per km\n");
	printf("\nBus type: ");
	scanf("%s", &bus);//here we are asking the bus condition
	switch(bus)
	{
		case 'A':
			{
			printf("Welcome to Higher condition\n");
			rate=8;
			break;
		    }
		case 'B':
			{
			printf("Welcome to Medium condition\n");
			rate=5;
			break;
		    }
		case 'C':
			{
			printf("Welcome to Lower condition\n");
			rate=2;
			break;
		    }
	    default:
	    	{
			printf("Invalid Bus category\n");
			exit(0);// the user enter wrong category the program ended !! 
			break;
		    }
	}
}
void seat()//it is asking for the seat number
{
	system("color 4f");
	printf("\nSeat Selection\n");
	printf("----------------");
	printf("\nSeat available in the bus: 10\n");
    printf("Which seat number do you want\n");
    printf("Seat number: ");
    scanf("%d", &bus_sit);//here we are asking the sit number
    if (bus_sit < 10)
    	printf("your seat number is %d\n", bus_sit);
    else{
    	printf("Seat not available");
		exit(0);	
	}
}
void route()//it is asking for the route
{
	system("color 4f");
	printf("\nWhich route do you want to go ?\n");
    printf("-------------------------------------\n");
	printf("Enter A: Defence to Gulshan lqbal\n");
	printf("Enter B: Shanti Nagar to Model Colony\n");
	printf("Enter C: Dalmia to Liyar\n");
	printf("Enter D: Urdu university to Nipa chowrangi\n");
	printf("Enter E: North Karachi to Nazimabad\n");
	printf("\nRoute: ");
	scanf("%s", &root);//asking the root
	printf("\n");
}
void route_switch()// here we are telling total rent
{
	system("color 4f");
	switch(root)
	{
		case 'A':
			{
				printf("Route: Defence to Gulshan lqbal\n");
				printf("Distance: 20km\n");
				printf("Fare: %d$\n", rate*20);
				break;
			}    
		case 'B':
			{
				printf("Route: Shanti Nagar to Model Colony\n");
				printf("Distance: 12km\n");
				printf("Fare: %d$\n", rate*12);
				break;
			}
		case 'C':
			{
				printf("Route: Dalmia to Liyar\n");
				printf("Distance: 14km\n");
				printf("Fare: %d$\n", rate*14);
				break;
			}
		case 'D':
			{
				printf("Route: Urdu university to Nepa chowragi\n");
				printf("Distance: 3km\n");
				printf("Fare: %d$\n", rate*3);
				break;
			}
		case 'E':
			{
				printf("Route: North Karachi to Nazimabad\n");
				printf("Distance: 10 km\n");
				printf("Fare: %d$\n", rate*10);
				break;
			}	
	    default:
	    	{
				printf("INVAID BUS CATORGORY\n");
				exit(0);
				break;
			}
	}
	
}



int main()
{
	system("color 1f");
	int i,p,rate,Z,j,k,l,age,phone_number;
    char email[20], name[8], name1[8];
    char bus, root;
    int bus_sit, time;
    	int choice;
	printf("---------------------------------------------\n");
	printf("Enter 1 for Registration\nEnter 2 for Login\n");
	printf("---------------------------------------------\n\nEnter(1 or 2): ");
	scanf("%d", &choice);
	
	if(choice == 1)//if the user enter the  1 then registration function start the work
	{
		int s;
		registration();
		
		printf("\nWould you like to sign-in ?\n");
		printf("press 2 to sign in: ");
		scanf("%d", &s);
		if (s == 2){
			login();
			
		}
	}
	
	else if(choice == 2)//if the user enter the  2 then login function starting the work
	{
		login();
	}
	else
	{
		exit(0);// if they enter the wrong number then function going to  be at ended 
	}
    bus_type();
    seat();
	route();
	printf("24 hour clock format\n");
	printf("At what time do you want the Bus: ");
	scanf("%d", &time);//here we are asking bus timing 
	printf("Please reach the stop at %d sharp.\n\n\n", time);
	route_switch(); 
	printf("\nYour journey is completed!\n");
	printf("Thanks for travelling with us!\n");
	return(0);		
}
