

struct birth_date
{
    int day;
    int month;
    int year;
};

struct contact
{
    char fn[30];
    char ln[30];
    struct birth_date bd;
    char address[30];
    char email[30];
    char num[30];


}contact[100];

int i=0;

int day_valid(int d)
{
    if (d>=1 && d<=31)
        return 1;
    else return 0;
}

int month_valid(int m)
{
    if (m>=1 && m<=12)
        return 1;
    else return 0;

}

int year_valid(int y)
{
    if (y>=1900 && y<=2019)
        return 1;
    else return 0;
}

int email_valid(char s[])
{
    char temp[]=".com";
    int j;
    int n=1;
    int c=0;
    for (j=0;j<strlen(s);j++)
    {
        if (s[j]==64)
            c++;
    }


    for(j=0;j<strlen(s);j++)
    {
        if (s[j]==46)
        {
          n=strcmp(temp,s+j);
          if (n==0)
            break;
        }
    }

    if (c==1 && n==0)
        return 1;
        else return 0;
}

int num_valid(char s[])
{
    int j;
        if (s[0]!=48 || strlen(s)!=11 )
        return 0;
        for (j=0;j<strlen(s);j++)
        {
            if(!(48<=s[j] && s[j]<=57))
                return 0;
        }
     return 1;

}


void load()
{


    FILE* fp = fopen("test.txt","r");
    while(!feof(fp))
    {
     


        fscanf(fp,"%[^,],%[^,],%d-%d-%d,%[^,],%[^,],%[^\n]\n",contact[i].fn,contact[i].ln,&contact[i].bd.day,&contact[i].bd.month,&contact[i].bd.year,contact[i].address,contact[i].email,contact[i].num);


              i++;


    }


    fclose(fp);
}
void add()
{
    system("cls");
    struct contact con;
    printf("\t\t\tEnter valid data only\n\n");
    printf("Enter First name: ");

    scanf("%s",con.fn);
    printf("\nEnter Last name: ");
      scanf("%s",con.ln);
      printf("\nEnter day of birth: ");
        scanf("%d",&con.bd.day);
          while (day_valid(con.bd.day)==0)
   {
        printf("Invalid day of birth");
        printf("\nEnter a valid day of birth: ");
             scanf("%d",&con.bd.day);
   }

           printf("\nEnter month of birth: ");
        scanf("%d",&con.bd.month);
                while (month_valid(con.bd.month)==0)
   { printf("Invalid month of birth");
        printf("\nEnter a valid month of birth: ");
             scanf("%d",&con.bd.month);
   }
           printf("\nEnter year of birth: ");
        scanf("%d",&con.bd.year);
                while (year_valid(con.bd.year)==0)
   { printf("Invalid year of birth");
        printf("\nEnter a valid year of birth: ");
             scanf("%d",&con.bd.year);
   }

        getchar();
        printf("\nEnter Address: ");

   gets(con.address);

   printf("\nEnter E-mail: ");
             scanf("%s",con.email);
  while (email_valid(con.email)==0)
   { printf("Invalid E-mail");
        printf("\nEnter a valid E-mail: ");
             scanf("%s",con.email);
   }




  printf("\nEnter Phone number:");
            scanf("%s",con.num);
         do {  printf("Invalid Phone number");
             printf("\nEnter a valid Phone number: ");
            scanf("%s",con.num);
         }while (num_valid(con.num)==0);





   contact[i] = con;
    i++;
    printf("\nContact added successfully\n");
     printf("\nEnter any key\n");

   getch();
   menu();


}
void Query()
{
    system("cls");
    int r=0;
    int c=1;
    char lntemp[30];
    printf("Please Enter the last name of the contact you're searching for:\n");
    scanf("%s",lntemp);
    for (int k=0;k<i;k++)
    {
       if( strcasecmp(lntemp,contact[k].ln)==0)
            r++;
    }
    printf("%d contact(s) found\n",r);
    for(int j=0;j<i;j++)
    {
      if( strcasecmp(lntemp,contact[j].ln)==0)
      {
        printf("\ncontact(%d)\n***********\nFirst name:   %s\nLast name:   %s\nDate of birth:   %d-%d-%d\nAdress:   %s\nE-mail:   %s\nPhone number:   %s\n\n",c,contact[j].fn,contact[j].ln,contact[j].bd.day,contact[j].bd.month,contact[j].bd.year,contact[j].address,contact[j].email,contact[j].num);
        c++;
      }
    }
   printf("Enter any key");
   getch();
   menu();

}
void Delete()
{
    system("cls");
    char fntemp[30];
    char lntemp[30];
     int j;
     int r=0;

    printf("Please enter first name of the contact you want to delete:\n");
    scanf("%s",fntemp);
    printf("Please enter last name of the contact you want to delete:\n");
    scanf("%s",lntemp);

    for (j=0;j<i;j++)
    {
        if (strcasecmp(fntemp,contact[j].fn)==0 && strcasecmp(lntemp,contact[j].ln==0))
        {
            r++;
            break;
        }

    }
    if (r==0)
        printf("No contact found\n");
     if (r==1)
     {
     printf("Contact deleted successfully!\n");

    contact[j] = contact[i-1];
    i--;
     }
      printf("Enter any key");
   getch();
   menu();


}
void sortByLname()
{
    system("cls");
    struct contact temp;
    int j,k;
    for (j=0;j<i-1;j++)
    {
        for (k=0;k<i-j-1;k++)
        {
            if (strcasecmp(contact[k].ln,contact[k+1].ln)>0)
            {
               temp = contact[k];
               contact[k]=contact[k+1];
               contact[k+1]=temp;
            }

        }
    }
    for (j=0;j<i;j++)
    {
        printf("\ncontact(%d)\n***********\nFirst name:   %s\nLast name:   %s\nDate of birth:   %d-%d-%d\nAdress:   %s\nE-mail:   %s\nPhone number:   %s\n\n",j+1,contact[j].fn,contact[j].ln,contact[j].bd.day,contact[j].bd.month,contact[j].bd.year,contact[j].address,contact[j].email,contact[j].num);
    }
    if (i==0)
        printf("No contacts in the directory\n\n\n");
}
void sortByDOB()
{
    system("cls");
    struct contact temp;
    int j,k;
    for (j=0;j<i-1;j++)
    {
        for (k=0;k<i-j-1;k++)
        {
            if (contact[k].bd.year<contact[k+1].bd.year)
            {

               temp = contact[k];
               contact[k]=contact[k+1];
               contact[k+1]=temp;
            }
            if (contact[k].bd.year==contact[k+1].bd.year)
            {
                if (contact[k].bd.month<contact[k+1].bd.month)
                {
                temp = contact[k];
               contact[k]=contact[k+1];
               contact[k+1]=temp;
                }
                if (contact[k].bd.month==contact[k+1].bd.month)
                {
                    if (contact[k].bd.day<contact[k+1].bd.day)
                    {
                          temp = contact[k];
               contact[k]=contact[k+1];
               contact[k+1]=temp;
                    }
                }

            }


        }
    }
     for (j=0;j<i;j++)
    {
        printf("\ncontact(%d)\n***********\nFirst name:   %s\nLast name:   %s\nDate of birth:   %d-%d-%d\nAdress:   %s\nE-mail:   %s\nPhone number:   %s\n\n",j+1,contact[j].fn,contact[j].ln,contact[j].bd.day,contact[j].bd.month,contact[j].bd.year,contact[j].address,contact[j].email,contact[j].num);
    }
     if (i==0)
        printf("No contacts in the directory\n\n\n");
}
void Print()
{
    system("cls");
    printf("To sort contacts by last name enter (1)\nTo sort contacts by date of birth enter (2)\n");

    switch (getch())
    {
        case '1': sortByLname();
        break;
       case '2': sortByDOB();
        break;
    }
       printf("Enter any key");
   getch();
   menu();
}

void save()
{
      system("cls");
   FILE* fp =  fopen("test.txt","w");
   for (int k=0;k<i;k++)
   {
   fprintf(fp,"%s,%s,%d-%d-%d,%s,%s,%s\n",contact[k].fn,contact[k].ln,contact[k].bd.day,contact[k].bd.month,contact[k].bd.year,contact[k].address,contact[k].email,contact[k].num);
   }
   printf("\nContacts saved successfully\n");
   fclose(fp);


}
void quit()
{
  system("cls");
  printf("\nWarning modifications will NOT be saved\n");
  printf("\nPress (1) to return to menu or (2) to quit \n");
  if(getch()=='1')
    menu();
  else  exit(0);
}
void modify()
{
    system("cls");
    char lntemp[30];
    int r=0;
    int c=1;
    printf("Enter the last name of the contact you want to modify\n");
    scanf("%s",lntemp);
       for (int k=0;k<i;k++)
    {
       if( strcasecmp(lntemp,contact[k].ln)==0)
            r++;
    }
    printf("%d contact(s) found\n",r);
    for(int j=0;j<i;j++)
    {
      if( strcasecmp(lntemp,contact[j].ln)==0)
      {
      printf("\ncontact(%d)\n***********\n%s\n%s\n%d-%d-%d\n%s\n%s\n%s\n\n",c,contact[j].fn,contact[j].ln,contact[j].bd.day,contact[j].bd.month,contact[j].bd.year,contact[j].address,contact[j].email,contact[j].num);
      c++;
      }
    }

  printf("Enter the number of the contact you want to modify\n");
  int num;
  scanf("%d",&num);
   c=0;
int j;
  for(  j=0;j<i;j++)
    {

      if( strcasecmp(lntemp,contact[j].ln)==0)
      c++;

      if (c==num)
        break;
    }
    system("cls");
     printf("1-First name\n2-Last name\n3-Date of birth\n4-Address\n5-E-mail\n6-Phone number\n");
     printf("Enter the number of the field you want to edit\n");
     switch (getch())
     {
         case '1': {
                    system("cls");
                    printf("Enter the new First name: ");
                    scanf("%s",contact[j].fn);
                    }
                    break;
        case '2': {
                     system("cls");
                    printf("Enter the new Last name: ");
                    scanf("%s",contact[j].ln);
                    }
                    break;
         case '3': {
                     system("cls");
                    printf("Enter the new day of birth: ");
                    scanf("%d",&contact[j].bd.day);
                     printf("\nEnter the new month of birth: ");
                    scanf("%d",&contact[j].bd.month);
                     printf("\nEnter the new year of birth: ");
                    scanf("%d",&contact[j].bd.year);
                    }
                    break;

        case '4':   {
                      system("cls");
                    printf("Enter the new Address: ");
                    getchar();
                 gets(contact[j].address);
                    }
                    break;

        case '5':  {system("cls");
                    printf("Enter the new E-mail: ");
                    scanf("%s",contact[j].email);
                    }
                    break;
        case '6':{
                   system("cls");
                    printf("Enter the new Phone number: ");
                    scanf("%s",contact[j].num);
                    }
                    break;


     }
      printf("\n\nSuccessfully Modified\n\n");
      printf("\n\nEnter any key");
   getch();
   menu();
}

void menu()
{
     system("cls");
    printf("                    ******************Telephone Book******************             \n\n\n");
    printf("                   1.Query      2.Add      3.Delete      4.Modify                  \n");
    printf("                   5.Print      6.Save     7.quit                                  \n\n\n");
    printf("\n\n                                                           Developed by: Mohamed Fahmi");
    printf("\n\n                                                                         Mohamed Khallafalah");
    printf("\n\n                                                                         Mohamed Abdelaleem\n\n\n");

     switch(getch())
     {
         case '1':
                    Query();
                   break;
         case '2': add();
                   break;
          case '3': Delete();
                    break;
          case '4': modify();
                   break;
         case '5': Print();
                   break;
        case '6': save();
                  break;
        case '7': quit();
                break;


     }



}
