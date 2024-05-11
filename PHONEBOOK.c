#include<stdio.h>
#include<string.h>

//Add contact function

void add_contact()
{
    char name[20],mob[20];

    FILE *fp;
    fp=fopen("contact.txt","a+");

    system("cls");

    printf("\t*****ADD CONTACT*****\n");
    printf("\n\tEnter your name  : ");
    scanf("%s",name);

    printf("\n\tEnter your number: ");
    scanf("%s",mob);

    fprintf(fp,"%s %s\n",name,mob);
    fclose(fp);

    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
}

//View contact function

void view_all_contact()
{
    char name1[20],mob[20];

    FILE *fp;
    fp=fopen("contact.txt","r");

    system("cls");

    printf("\t*****ALL CONTACTS*****\n");

    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        printf("\n\t NAME  : %s",name1);
        printf("\n\t Number: %s",mob);
        printf("\n");
    }
    fclose(fp);

    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
}

//Delete contact function

void delete_contact()
{
    char name[20],name1[20],mob[20];

    FILE *fp,*fp1;
    fp=fopen("contact.txt","r+");
    fp1=fopen("temp.txt","w");

    system("cls");

    printf("\t*****DELETE CONTACT*****\n");
    printf("\n\tEnter name: ");
    scanf("%s",name);

    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        if(strcmp(name,name1)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s\n",name1,mob);
    }
    fclose(fp);
    fclose(fp1);

    fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");

    while(fscanf(fp1,"%s %s",name1,mob)!=EOF)
    {
        fprintf(fp,"%s %s\n",name1,mob);
    }
    fclose(fp);
    fclose(fp1);

    remove("temp.txt");

    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
}

//Search contact function

void search_contact()
{
    char name[20],name1[20],mob[20];

    FILE *fp;
    fp=fopen("contact.txt","r");

    system("cls");

    printf("\t*****SEARCH CONTACT*****\n");
    printf("\n\t Enter Name :-");
    scanf("%s",name);

    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        if(strcmp(name,name1)==0)
        {
            printf("\n\tNAME  : %s\n",name1);
            printf("\n\tNumber: %s\n",mob);
        }
    }
    fclose(fp);

    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
}

//Main function  //PHONEBOOK HOME

int main()
{
    system("COLOR 5f");

    char Pass[20],Hint[20];

    printf("\n\tPhoneBook Application By SAKIBUL HASAN RAFI! (Press any key to Start)\n\t");
    getch();

Password:

    system("cls");

    printf("\n\tPhoneBook Application By SAKIBUL HASAN RAFI!\n\n\tEnter Your Choice: \n");
    printf("\n\t1. Create Password\t2. Forgot Password?\t3. Login\t4. Exit\n");

    switch(getch())
    {
    case '1'://Create password
    {
        printf("\nEnter New Password:\n");
        gets(Pass);

        printf("\nEnter Hints for Security:\n");
        gets(Hint);

        goto Password;
        break;
    }
    case '2'://Forgot password
    {
        char Reset[20];

        printf("\nEnter Hints for Reset Password:\n");
        gets(Reset);

        if(strcmp(Hint,Reset)==0)
        {
            printf("\nEnter New Password:\n");
            gets(Pass);

            printf("\nPassword has been Changed Successfully.\n");
        }
        else
        {
            printf("\nYou Need to Remember Hints For Reseting Password!\n");
            getch();
        }
        goto Password;
        break;
    }
    case '3'://Login
    {
        char Login[20];

        printf("\nEnter Password to Login:\n");
        gets(Login);

        if(strcmp(Pass,Login)==0)
        {
            goto Menu;
        }
        else
        {
            goto Password;
        }
        break;

    }
    case '4'://Exit
    {
        goto End;
        break;
    }
    default:
    {
        goto Password;
        break;
    }

    }

Menu://PHONEBOOK MAIN MENU

    system("cls");

    printf("\n\tPhoneBook Application By SAKIBUL HASAN RAFI!\n\n\tEnter Your Choice: ");
    printf("\n\t1. Create\t2. Search\n\t3. Delete\t4. View All\n\t5. Exit \t6. LogOut\n");

    switch(getch())
    {
    case '1':
    {
        add_contact();
        goto Menu;
        break;
    }
    case '2':
    {
        search_contact();
        goto Menu;
        break;
    }
    case '3':
    {
        delete_contact();
        goto Menu;
        break;
    }
    case '4':
    {
        view_all_contact();
        goto Menu;
        break;
    }
    case '5':
    {
        goto End;
        break;
    }
    case '6':
    {
        goto Password;
        break;
    }
    default:
    {
        goto Menu;
        break;
    }
    }

End:

    system("cls");

    printf("\n\t\t\tThank you for reviewing my Application.");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
    printf("@ Copyright 2022 || All Rights Reserved By SAKIBUL HASAN RAFI\n");

    return 0;
}
//END OF PHONEBOOK
