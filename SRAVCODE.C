#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
 int num2=101,num3=201;
struct node
{
 int d1;
 int d2;
 char d3[20];
 struct node *link;
}*first=NULL,*first1=NULL;
void add1(int n)
{
struct node *p,*t;
 int i;
 char k[20]="pk\0";
 for(i=0;i<n;i++)
 {
 p=(struct node*)malloc(sizeof(struct node));
 p->d1=num2;
 p->d2=0;
 strcpy(p->d3,k);
 num2++;
 p->link=NULL;
 t=first;
 if(first==NULL)
 {
  first=p;
 }
 else
 {
  while(t->link!=NULL)
  {
  t=t->link;
  }
  t->link=p;
  }
 }
}
 void dis1()
 {
  struct node *t;
  t=first;
  if(first==NULL)
  {
   printf("No homes booked!!\n");
  }
  else
  {
  printf("NUMBER OF 2BHK HOMES AVAILABLE ARE:\n");
   while(t!=NULL)
   {
   if(t->d2==0)
   {
    printf("%d  ",t->d1);
    }
    t=t->link;
   }
  }
 }


void add2(int n1)
{
struct node *p,*t;
 int i;
 for(i=0;i<n1;i++)
 {
 p=(struct node*)malloc(sizeof(struct node));
 p->d1=num3;
 p->d2=0;
 num3++;
 p->link=NULL;
 t=first1;
 if(first1==NULL)
 {
  first1=p;
 }
 else
 {
  while(t->link!=NULL)
  {
  t=t->link;
  }
  t->link=p;
  }
}
}
 void dis2()
 {
  struct node *t;
  t=first1;
  if(first1==NULL)
  {
   printf("No homes booked\n");
  }
  else
  {
  printf("NUMBER OF 3BHK HOMES AVAILABLE ARE:\n");
   while(t!=NULL)
   {
   if(t->d2==0)
   {
    printf("%d ",t->d1);
   }
   t=t->link;
   }
  }
 }


  void bookedhome1()
 {
 int c=0;
  struct node *t;
  t=first;
  if(first==NULL)
  {
   printf("No homes booked!!\n");
 }
  else
  {
   while(t!=NULL)
   {
   if(t->d2==1)
   {
    c++;
    printf("HOUSE NUM     NAME\n");
    printf(" %d          %s\n ",t->d1,t->d3);
    printf("------------------------------------------------------------------------\n");
    }
    t=t->link;
   }
  }
  if(c==0)
  printf("NO HOMES BOOKED\n");
  else
  printf("\Are the house details\n");
 }

 void bookedhome2()
 {
  int c=0;
  struct node *t;
  t=first1;
  if(first1==NULL)
  {
   printf("No homes booked\n");
  }
  else
  {
   while(t!=NULL)
   {
   if(t->d2==1)
   {
   c++;
   printf("HOUSE NUM      NAME\n");
    printf("%d            %s\n ",t->d1,t->d3);
    printf("--------------------------------------------------------------------------\n");
   }
   t=t->link;
   }
  }
  if(c==0)
  printf("NO HOMES BOOKED\n");
  else
  printf("Are the house numbers booked\n");
 }

 void show()
 {
   printf("VANDANA APARTMENTS ARE THE BEST PROVIDING TENANTS WITH BEST FURNISHED HOMES.\n");
   printf("ROOMS ARE APACTIOUSLY FILLED WITH MASTER BEDROOMS,AUTOMATE DOORS,CEILING TO ");
   printf("FLOOR MIRRORS.CLOSETS ARE WELL EQUIPPED WITH AMPLE LIGHTNING AND EARTHQUAKE ");
   printf("RESISTANT NOISE PROOF CEILINGS");
   printf("\n");
 }
 void search(char name[20])
 {
 struct node *t;
   int key,flag=0;
   printf("ENTER THE HOUSE NUMBER:");
   scanf("%d",&key);
      t=first;
      while(t!=NULL)
      {
       if(t->d1==key&&t->d2==0)
       {
       t->d2=1;
       strcpy(t->d3,name);
       flag=1;
       break;
       }
       if(t->d1==key&&t->d2==1)
       {
       flag=2;
       }
   t=t->link;
 }
   if(flag==1)
   {
   printf("HOUSE NUMBER %d BOOKED SUCCESSFULLY BY %s\n",t->d1,t->d3);
   printf("------------------------------------------------------------------\n");
   printf("ENJOY YOUR STAY HERE IN VANDANA APARTMENTS\n");
   }
   else if(flag==2)
   {
    printf("HOME ALREADY BOOKED\n");
    }

   else
   printf("INVALID HOUSE NUMBER\n");
 }

  void search1(char name[20])
 {
 struct node *t;
   int key,flag=0;
   printf("ENTER THE HOUSE NUMBER:");
   scanf("%d",&key);
      t=first1;
      while(t!=NULL)
      {
      if(t->d1==key&&t->d2==0)
       {
       t->d2=1;
       strcpy(t->d3,name);
       flag=1;
       break;
       }
       if(t->d1==key&&t->d2==1)
       {
	 flag=2;
       }
     t=t->link;
 }
   if(flag==1)
   {
     printf("HOUSE NUMBER %d BOOKED SUCCESSFULLY BY %s\n",t->d1,t->d3);
   printf("------------------------------------------------------------------\n");
   printf("ENJOY YOUR STAY HERE IN VANDANA APARTMENTS\n");
   }
   else if(flag==2)
   printf("HOME ALREADY BOOKED\n");
   else
   printf("INVALID HOUSE NUMBER\n");
 }
 void bookHome()
 {
 int d;
 struct node *cur,*cur1;
 char name[20];
 printf("ENTER YOUR NAME:");
 scanf("%s",name);
 printf("ENTER 2BHK OR 3BHK:");
 scanf("%d",&d);
 if(d==2)
 {
   cur=first;
   while(cur->link!=NULL)
   {
    if(cur->d2==0)
    {
    search(name);
    break;
    }
    else
    {
    cur=cur->link;
    }
   }
 }
 else if(d==3)
 {
   cur=first1;
   while(cur->link != NULL)
   {
    if(cur->d2==0)
    {
      search1(name);
      break;
    }
    else
    {
    cur=cur->link;
    }
   }
 }
 else
 printf("PLEASE ENTER VALID NUMBER\n");
 return;

 }
 void delhome()
 {
  struct node *t,*cur,*pre;
  int key;
  t=first;
  if(first==NULL)
  {
   printf("linked list empty\n");
  }
  else
  {
  printf("ENTER THE VALID HOUSE NUMBER TO BE DELETED:");
  scanf("%d",&key);
  while(t->d1!=key)
  {
   t=t->link;
   }
   if(t->d2==1)
   {
   printf("THE VACATED HOUSE NUMBER IS: %d\n BY- %s\n",t->d1,t->d3);
   t->d2=0;
  }

  else
  {
   printf("HOME NOT ALLOCATED\n");
 }
}
}

 void delhome1()
 {
  struct node *t,*cur,*pre;
  int key;
  t=first1;
  if(first1==NULL)
  {
   printf("linked list empty\n");
  }
  else
  {
  printf("ENTER THE VALID HOUSE NUMBER TO BE DELETED:");
  scanf("%d",&key);
  while(t->d1!=key)
  {
   t=t->link;
   }
   if(t->d2==1)
   {
   printf("THE VACATED HOUSE NUMBER IS: %d\nBY- %s\n",t->d1,t->d3);
   t->d2=0;
  }
  else
 printf("HOME NOT ALLOCATED\n");
}
}

void addhomes()
{
 char p[10],u[10],ch;
 int i,k,a,homes2,homes3;
 printf("ENTER YOUR NAME:");
 scanf("%s",&u);
 printf("ENTER THE PASSWORD:");
 for(i=0;i<6;i++)
 {
  ch = getch();
  p[i] = ch;
  ch=' ';
  printf("%c",ch);
  }
  p[i] = '\0';
k=strcmp(p,"sravan");
printf("\nCONFIRM PASSWORD:");
 for(i=0;i<6;i++)
 {
  ch = getch();
  p[i] = ch;
  ch=' ';
  printf("%c",ch);
  }
  p[i] = '\0';

k=strcmp(p,"sravan");
printf("\n");
if(k==0)
{

			 printf("ENTER 2BHK OR 3BHK :");
			 scanf("%d",&a);
			 if(a==2)
			 {
			 printf("ENTER THE NUMBER OF HOMES TO BE BUILT:");
			 scanf("%d",&homes2);
			 add1(homes2);
			 }
			 else if(a==3)
			 {
			   printf("ENTER THE NUMBER OF HOMES TO BE BUILT:");
			   scanf("%d",&homes3);
			   add2(homes3);
			 }
			 else
			 {
			   printf("ACCESS DENIED\n");
			 }
}
 else
 {
  printf("PLEASE ENTER CORRECT PASSWORD\n!!");
}
}

void homes_available()
{
int a;
	    printf("ENTER 2BHK OR 3BHK:");
	    scanf("%d",&a);
	    if(a==2)
	     dis1();
	     else if(a==3)
	     dis2();
	     else
	     printf("Invalid use of characters!!!\n");
}


 void main()
 {
   int pwd2,pwd3,c,d,e;
   int ch,maritalStatus,n=10;
   char user[20];
   clrscr();
    add1(n);
    add2(n);
    printf("=======================================================================\n");
    printf("WELCOME TO VANDANA APPARTMENTS !!!\n");

 prasan :


    while(1)
    { printf("========================================================================\n");
      printf("1.ADMIN\n2.USER\n3.EXIT\n");
      printf("===============================================================================\n");
      printf("ENTER YOUR CHOICE:");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1 : printf("THE LOGGED IN USER IS ADMIN!!!\n");
		 while(1){
		 printf("1.ADD HOME\n2.VACATE HOME\n3.BOOKED HOME\n4.MAIN MENU\n");
		 printf("---------------------------------------------------------\n");
		 printf("ENTER YOUR CHOICE:");
		 scanf("%d",&d);

		 switch(d)
		 {
		 case 1 : addhomes();
			  break;

		 case 2 : printf("ENTER YOUR PASSWORD:");
			 scanf("%d",&pwd2);
	    if(pwd2==22)
	    {
	     delhome();
	     printf("\n---------------------------------------------------------------------\n");
	    }
	    else if(pwd2==23)
	    {
	    delhome1();
	    printf("\n-------------------------------------------------------------------------\n");
	    }
	    else
	    {
	    printf("PLEASE ENTER CORRECT PASSWORD!!!\n");
	      }
	    break;

	   case 3: printf("ENTER THE PASSWORD:");
	   scanf("%d",&pwd3);
	   if(pwd3==24)
	   {
	   printf("ENTER 2BHK OR 3BHK:");
	   scanf("%d",&c);
	    if(c==2)
	     bookedhome1();
	     else  if(c==3)
	     bookedhome2();
	     else
	     printf("Please enter correct details\n");
	    }
	     else
	     printf("Please enter correct password!!!\n");
	     break;
	    case 4 :clrscr();
		   goto prasan;

		    // break;
	  default : printf("INVALID CHOICE!!!\n");
	}}
       //	break;


	case 2:printf("ENTER YOUR NAME :");
	       scanf("%s",&user);
	       printf("\n=============================================================\n");
	       printf("WELCOME TO VANDANA APARTMENTS  %s\n",user);
	       while(1)
	       {
	       printf("\n1.SHOW FEATURES\n2.HOMES AVAILABLE\n3.BOOK HOME\n4.MAIN MENU\n");
	       printf("-----------------------------------------------------------------\n");
	       printf("enter choice:");
	       scanf("%d",&e);
	       switch(e)
	       {
		  case 1:  show();
			    printf("\n----------------------------------------------------------------\n");
			   break;
		  case 2 : homes_available();
			    printf("\n-----------------------------------------------------------------\n");
			   break;
		  case 3 : printf("Please enter your marital status (Bachelor - 0  or FamilyMan - 1)\n");
	   scanf("%d",&maritalStatus);
	   if(maritalStatus == 0)
	  { printf("SORRY WE DON'T ACCOMODATE BACHELORS!!!");
	   printf("\n---------------------------------------------------------------------------\n"); }
	    else if(maritalStatus==1)
	    bookHome();
	    else
	    printf("ACCESS DENIED\n");
	    break;
	    case 4 : clrscr();
		     goto prasan;
		     // break;
	   default : printf("ENTER PROPER CHOICE!!!\n");
	   }}
	 //  break;
	   case 3 : exit(0);
		   // break;

	   default : printf("PLEASE ENTER VALID CHOICE\n");
	}
       }
     //  getch();
      }

































