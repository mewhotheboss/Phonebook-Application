#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PhoneBook
{
    char Name[20];
    char Number[12];
    struct PhoneBook *next;

}*Head=NULL;

void Add()
{
    system("cls");
    struct PhoneBook *CurrNode, *NewNode;
    NewNode= (struct PhoneBook*)malloc(sizeof(struct PhoneBook));

    printf("Enter Name: \n");
    scanf("%s",&NewNode->Name);
    printf("Enter Number:\n");
    scanf("%s",&NewNode->Number);
    NewNode->next=NULL;

    if(Head==NULL)
    {
        Head=NewNode;
    }

    else
    {
        CurrNode=Head;
        while(CurrNode->next!=NULL)
        {
            CurrNode=CurrNode->next;
        }
        CurrNode->next=NewNode;
    }
}

void Search()
{
    struct PhoneBook *display=Head;
    int Count=0;
    char NAME[20],Number[15];

Start:

    system("cls");
    printf("\n\tHow can do you want to search?\n");
    printf("\n\t1. by Name\n\t2. by Number\n\t3. Main Menu\n");

    switch(getch())
    {
    case '1':
    {
        printf("\nEnter Name to search: \n");
        scanf("%s",&NAME);

        while(display!=NULL)
        {
            if(strcmp(display->Name,NAME)==0)
            {
                Count++;
                printf("%d.\n\tName: %s",Count,display->Name);
                printf("\n\tNumber: %s\n\n",display->Number);
            }
            display=display->next;
        }
        break;
    }

    case '2':
    {
        printf("\nEnter Number to search:\n");
        scanf("%s",&Number);

        while(display!=NULL)
        {
            if(strcmp(display->Number,Number)==0)
            {
                Count++;
                printf("%d.\n\tName: %s",Count,display->Name);
                printf("\n\tNumber: %s\n\n",display->Number);
            }
            display=display->next;
        }
        break;
    }

    case '3':
    {
        goto End;
        break;
    }

    default:
    {
        printf("Wrong Input !\n");
        goto Start;
        break;
    }
}

End:
    printf("\n\nPress any key for Main Menu.\n");
    getch();
}

void Delete(struct PhoneBook *CurrNode)
{
    system("cls");
    char Name[20];
    struct PhoneBook *Prev=NULL;
    printf("\nTo Delete a Contact Please enter Name:\n");
    scanf("%s",&Name);

    while(CurrNode!=NULL)
    {
        if(strcmp(CurrNode->Name,Name)==0)
        {
            break;
        }
        Prev=CurrNode;
        CurrNode=CurrNode->next;
    }

    if(CurrNode==NULL)
    {
        printf("\n\nNot Found!\n");
    }

    else if(Prev==NULL)
    {
        Head=CurrNode->next;
        free(CurrNode);
        printf("\n%s is deleted.\n",Name);
    }

    else
    {
        Prev->next=CurrNode->next;
        free(CurrNode);
        printf("\n%s is deleted.\n",Name);
    }

    printf("\n\nPress any key for Main Menu.\n");
    getch();
}

void ViewAll(struct PhoneBook *display)
{
    system("cls");
    int Count=0;

    printf("\t\tAll Contacts:\n\n");

    while(display!=NULL)
    {
        Count++;
        printf("%d.\n\tName: %s",Count,display->Name);
        printf("\n\tNumber: %s\n\n",display->Number);
        display=display->next;
    }

    if(Head==NULL)
    {
        printf("PhoneBook is Empty!");
    }

    printf("\n\nPress any key for Main Menu.\n");
    getch();
}

int main()
{
    system("COLOR 2f");
    char Pass[20],Hint[20];

    printf("\n\t\t\t\tWelcome to PhoneBook application.! (press any key to start)\n\t");
    getch();

Password:

    system("cls");
    printf("\n\t\t\t\t\tPhoneBook HOME\n\n\tEnter Your Choice:");
    printf("\n\t1. Create Password\t2. Forgot Password?\t3. Login\t4. Exit\n");

    switch(getch())
    {
    case '1':
    {
        printf("\nEnter New Password: \n");
        gets(Pass);
        printf("\nEnter Hints for Security: \n");
        gets(Hint);

        goto Password;
        break;
    }

    case '2':
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

    case '3':
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
            printf("Wrong Password!!! Retry again.");
            getch();
            goto Password;
        }
        break;
    }

    case '4':
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

Menu:

    system("cls");
    printf("\n\t\t\t\t\tPhoneBook Main MENU\n\n\tEnter Your Choice:");
    printf("\n\t1. Create\t2. Search\n\t3. Delete\t4. View All\n\t5. Exit \t6. LogOut\n");

    switch(getch())
    {
    case '1':
    {
        Add();
        goto Menu;
        break;
    }

    case '2':
    {
        Search();
        goto Menu;
        break;
    }

    case '3':
    {
        Delete(Head);
        goto Menu;
        break;
    }

    case '4':
    {
        ViewAll(Head);
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
    printf("@ Copyright 2022 || All Rights Reserved By SAKIBUL_HASAN_RAFI...!\n");
    return 0;
}
