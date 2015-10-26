 /*        HOSPITAL MANAGEMENT SYSTEM           */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pro.h"

void menu()							/* Main menu*/
{

                int choice;
                printf("\t\t*************************************************");
                printf("\n\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
                printf("\n\t\t*************************************************");
                printf("\n\n\n\n\n\n\n");
                printf("\t\t1.PATIENT");
                printf("\n\t\t2.STAFF");
                printf("\n\t\t3.INVENTORY");
                printf("\n\t\t0.EXIT");
                printf("\n\n\tEnter your choice: ");
                scanf("%d", &choice);
                

                switch(choice)
                {
                                case 1:
                                                pat();
                                                break;
                                case 2:
                                                //emp();
                                                //break;
						exit(1);
                                case 3:
                                                //inv();
                                                //break;
                               			exit(1);
                                case 0:
                                                exit(1);
                }
}

void verification(){						

	char userp[] = {"passuser"};
	char adminp[] = {"passadmin"};
	char u[20];
	char a[20];
	int uchoice;
	int ucheck;
	printf("\nEnter choice\n 1 - Administrator\n 2 - User\n");
	scanf("%d" , &uchoice);
	if(uchoice == 1)		
		{
			printf("\nPlease enter the password\n");
			scanf("%s" , a);
			ucheck = strcmp(a , adminp);
			if(ucheck == 0)
				{
					printf("Welcome administrator\n");
					menu();
				}
			else
				{
					printf("\nEntered password is wrong.Try again\n");
					printf("\nPlease ensure that selected mode is correct\n");
					verification();
				}
		}
	if(uchoice == 2)
		{
			printf("\nPlease enter the password\n");
			scanf("%s" , u);
			ucheck = strcmp(u , userp);
			if(ucheck == 0)
				{
					printf("Welcome user\n");
					menu();
				}
			else
				{
					printf("\nEntered password is wrong.Try again\n");
					printf("\nPlease ensure that selected mode is correct\n");
					verification();
				}
		}
}



void pat()
{
				int ch;
			while(1){
				printf("\n\n\t\t\tPATIENT");
                                printf("\n\t\t1.Enter a New Entry");
                                printf("\n\t\t2.Modify Existing");
                                printf("\n\t\t3.Search an Entry");
                                printf("\n\t\t4.Listing of records");
                                printf("\n\t\t5.Delete an Entry");
                                printf("\n\t\t6.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                scanf("%d",&ch);
                                
				switch(ch){
                                
						 case 1:
                                                        add_pat(); 
							break;        
								 
                				 case 2:		 
							mod_pat();
							break;
						 case 3:
							search_pat();
							break;
						 case 4:
							list_pat();
							break;
                                		 case 5:
							delete_pat();
                                			break;
                                		 case 6:
							menu();
                                			break;
				}
			}

}
void add_pat(){
								
				FILE *fp;
                		long int recsize;
                		struct patient p;
		                recsize=sizeof(p);
				fp=fopen("pat.txt","a");
								if(fp==NULL){
                        						printf("\nSorry!! Cannot open file");
                                               
               							 }else{
               							 		printf("\nEnter the registration no. of the patient: ");
										scanf("%s",p.regn);
										printf("\nEnter the name of the patient: ");
										scanf("%s",p.name);
                                                                                printf("\nEnter the name of the Guardian: ");
										scanf("%s",p.fname);
                                                                   		printf("\nEnter the gender of the patient(M.male or F.female): ");
                                                                                scanf("%s",p.gender);
                                                                                printf("\nEnter the Blood group of the patient: ");
                                                                                scanf("%s",p.bg);
                                                                                printf("\nEnter the age of the patient: ");
                                                                                scanf("%d",&p.age);
                                                                                printf("\nEnter the address of the patient:\n");
                                                                                printf("\n\tEnter the house number: ");
                                                                                scanf("%d",&p.a.hno);
                                                                              	printf("\n\tEnter the street/colony: ");
                                                                                scanf("%s",p.a.street);
                                                                                printf("\n\tEnter the city: ");
                                                                                scanf("%s",p.a.city);
                                                                                printf("\n\tEnter the state: ");
                                                                                scanf("%s",p.a.state);
                                                                                printf("\nEnter the phone number of the patient: ");
                                                                                scanf("%s",p.ph);
                                                                                printf("\nEnter the Disease for which he/she wants treatment: ");
                                                                                scanf("%s",p.disease);
							    			printf("\nEnter the name of the Doctor to which he/she is being referred: ");
                                                                                scanf("%s",p.doc_name);
										printf("\nEnter the history, if any, related to treatment of the patient: ");
                                                                                scanf("%s",p.history);
					       					fwrite(&p,recsize,1,fp);
                                                                                printf("The record is sucessfully added\n");
                                                                }
						fclose(fp);
						return;
}						
						
void mod_pat(){
										long int recsize;
                								struct patient p;
		                						recsize=sizeof(p);
                                               					char reg[15];
                                                              			printf("\nEnter the Registration number of the patient to modify: ");
                                                                                scanf("%s",reg);
										FILE *fp;
                                                                                fp = fopen("pat.txt","r+");
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.regn,reg)==0)
                                                                                                {
                                                                                                               
														printf("\nEnter the new name of the patient: ");
														scanf("%s",p.name);
                                                                                                                fgets(p.name ,40, fp);
														printf("\nEnter the new name of the Guardian: ");
                                                                                                                scanf("%s",p.fname);
														fgets(p.fname,40, fp);
														printf("\nEnter the new Blood group of the patient: ");
                                                                                                                scanf("%s",p.bg);
														printf("\nEnter the new age of the patient: ");
                                                                                                                scanf("%d",&p.age);
														printf("\nEnter the new address of the patient:\n");
                                                                                                                printf("\n\tEnter the house number: ");
                                                                                                                scanf("%d",&p.a.hno);
                                                                                                               
                                                                                                                printf("\n\tEnter the street/colony: ");
                                                                                                                scanf("%s",p.a.street);
                                                                                                                printf("\n\tEnter the city: ");
                                                                                                                scanf("%s",p.a.city);
                                                                                                                printf("\n\tEnter the state: ");
                                                                                                                scanf("%s",p.a.state);
														printf("\nEnter the new phone number of the patient: ");
                                                                                                                scanf("%s",p.ph);
                                                                                                                
														printf("enter the date of treatment given: ");
														scanf("%s",p.date);
                                                                                                                fgets(p.date ,10, fp);
														printf("\nEnter the detail of treatment given:");
														scanf("%s",p.treatment);
                                                                                                                fgets(p.treatment ,40, fp);
                                                                                                                printf("\nEnter the medicines prescribed:");
														scanf("%s",p.med);
                                                                                                                fgets(p.med ,40, fp);

                                                                                                                fseek(fp,-recsize,SEEK_CUR);
                                                                                                                fwrite(&p,recsize,1,fp);
                                                                                                                break;
                                                                                                }
                                                                                }
								fclose(fp);
                                                                return;                 
}

void search_pat(){
										long int recsize;
                								struct patient p;
		                						recsize=sizeof(p);
                                            					char reg[15];
										int i = 0;
                                              					FILE *fp;
										fp=fopen("pat.txt","r+");
										printf("\nEnter registration no. of the patient to search: ");
										scanf("%s", reg);
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.regn,reg)==0){
														i = 1;
                                                                                                		break;
												}
										}
										if(i = 1){
														printf("\nRegistration Number of the Patient : %s" , p.regn);
                                                                                                                printf("\nName of the Patient : %s" , p.name);
                                                                                                                printf("\nName of the Guardian : %s" , p.fname);
                                                                                                                printf("\nAge : %d",p.age);
                                                                                                                printf("\nGender : %s",p.gender);
                                                                                                                printf("\nBlood group: %s",p.bg);
														printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                                                                                printf("\nphone number : +91-%s",p.ph);
                                                                                                                printf("\nDisease : %s",p.disease);
                                                                                                                printf("\nEarlier History : %s" , p.history);
                                                                                                               
														printf("\nDetails of treatment given and medicine prescribed:");
														printf("\nDATE\t\tTREATMENT GIVEN\t\tMEDICINE PRESCRIBED\n");
														printf("%s\t\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                                                                                printf("\nName of the Doctor : %s" , p.doc_name);
                                                                                                                

                                                                                }else{
												printf("Record not found\n");
												fclose(fp);
										}
                                                                return;
}

void list_pat(){

                                                
                                                                FILE *fp; 
                                                                fp=fopen("pat.txt","r+"); 
								long int recsize;
                						struct patient p;
		                				recsize=sizeof(p);
                                               			                                     
                                                                while(fread(&p,recsize,1,fp)==1)
                                                                {
                                                                                printf("\nRegistration Number of the Patient : %s" , p.regn);
                                                                                printf("\nName of the Patient : %s" , p.name);
                                                                                printf("\nAge : %d",p.age);
                                                                                printf("\nGender : %s",p.gender);
                                                                                printf("\nBlood group: %s",p.bg);
										printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                                                printf("\nphone number : +91-%s",p.ph);
                                                                                printf("\nDisease : %s",p.disease);
                                                                                printf("\nEarlier History :%s " , p.history);
                                                                                
										printf("\nDetails of treatment given and medicine prescribed:");
										printf("\nDATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                                                                                printf("%s\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                                                printf("\nName of the Doctor : %s" , p.doc_name);
                                                                                

                                                                                printf("\n----------------------------------------------------\n");

                                                                }
                              return;                                 
}

void delete_pat(){
										long int recsize;
                								struct patient p;
		                						recsize=sizeof(p);
                                               					char reg[15];
                               							FILE *fp, *ft;
										printf("\nEnter the Registration number of the Patient to be deleted: ");
                                                                                scanf("%s",reg);
										fp = fopen("pat.txt","r");
                                                                                ft=fopen("temp.txt","w+");
                                                                               
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.regn,reg)!=0)
                                                                                                fwrite(&p,recsize,1,ft);
                                                                                                else
												printf("\nThe Record has been Deleted Successfully.");
                                                                                }

                                                                                fclose(fp);
                                                                                fclose(ft);
                                                                                remove("pat.txt");
                                                                                rename("temp.txt","pat.txt");
                                                                                fp=fopen("pat.txt","r+");

                                                                                return;
}
/*void emp(){
	return;
}

void inv(){
	return;
}*/
