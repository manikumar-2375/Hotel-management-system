/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
struct date{
    int date;
    int month;
    int year;
}checkin_date,checkout_date;
typedef struct customer{
    char name[60];
    long long int phoneno;
    char address[100];
    char email[50];
    struct date cindate;
    struct date coutdate;
    int No_of_days;
    char roominfo[50];
    float restaurantbill;
    float roombill;
    float totalbill;
    char paymenttype[50];
    int no_of_rooms;
    int start;
    int end;
}customer;

void displaydate(struct date x){
    printf("%d-%d-%d\n",x.date,x.month,x.year);
}
int countLeapYears(struct date d);
int getDifference(struct date dt1, struct date dt2);
int z=0;


int restaurant(customer *c);
int datecalculation(customer *c);
float lunch();
float breakfast();
float dinner();
int roominformation(customer *c);
float Efficiencyrooms();
float Interconnectedrooms();
float Normalrooms();
float Presidentialsuitrooms();
int payment(customer *c);
void datastoring(customer *carray,customer c,int i);
void display(customer *carray,int i);
void booking(customer *customer1);
int displayf(int size,int i);




int main()
{
   customer c,*carray;
   int size=0;
   carray=(customer*)(malloc(1*sizeof(customer)));
    int choice,i=0,k=0;
    
    printf("\n\n\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*        WELCOME TO HOTEL ATULYA TAJ            *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n");
	do{
	size++;
	carray=(customer*)(realloc(carray,size*sizeof(customer)));
    booking(&c);
    datecalculation(&c);
    roominformation(&c);
    if(k==0)
    {
        carray[k].start=1;
        carray[k].end=z;
    }
    else
    {
        carray[k].start=carray[k-1].end+1;
        carray[k].end=carray[k-1].end+z;
    }

    carray[k].no_of_rooms=z;
    k++;
    restaurant(&c);
    c.totalbill=(c.No_of_days*c.roombill)+c.restaurantbill;
    
    payment(&c);
    datastoring(carray,c,i);
    display(carray,i);
    printf("\nDo you want to book another room\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2): ");
    
    scanf("%d",&choice);
    i++;
    }while(choice==1);
    FILE *f;
    f=fopen("DATA","wb");
    fwrite(carray,sizeof(customer),size,f);
    fclose(f);
    
    
    
    //FOR MANAGEMENT PURPOSE
    
    
    
    printf("Do you want to print our customers details?\n 1-yes \nPress any other keys to exit\n");
    int temp,x,y,p=0;
    
    scanf("%d", &temp);
    while(temp==1)
    {
    
        do
        {
        printf("\nWhich customer details do you want to print (Enter the number greater than 0 and less than or equal %d): ",size);
        scanf("%d",&x);
        if(x>=1&&x<=size)
        {
        displayf(size,x-1);
        p=0;
        }
        else
        {
         printf("Customer Detail not Found\n");
        p=1;
        }
        
        }while(p==1);
    printf("Do you want to print anymore customer details?\n 1-yes");
    scanf("%d", &temp);
    }
    
}
int displayf(int size,int i)
{
    customer carray[size];
    FILE *f;
    f=fopen("DATA","rb");
    fread(carray,sizeof(carray),1,f);
    fclose(f);
    printf("\n\n\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*       --------          *\n");
	printf("\t\t*        RECEIPT          *\n");
	printf("\t\t*       --------          *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n\n");
	printf("\tPERSONAL INFORMATION:\n");
	printf("\t\tName:%s\n",carray[i].name);
	printf("\t\tPhone no.:%lld\n",carray[i].phoneno);
	printf("\t\tAddress:%s\n",carray[i].address);
	printf("\t\tEmail:%s\n\n",carray[i].email);
	printf("\tCHECKIN AND CHECKOUT DATE:\n");
	printf("\t\tCheck_in date: ");
    displaydate(carray[i].cindate);
    printf("\t\tCheck_out date: ");
	displaydate(carray[i].coutdate);
	printf("\t\tNo Of Days of stay:%d",carray[i].No_of_days);
	printf("\n");
	printf("\tROOM:\n");
	printf("\t\tRoom Type:%s\n",carray[i].roominfo);
    if(carray[i].no_of_rooms==1)
        printf("\t\tRoom Number: %d\n",carray[i].end);
    else
        printf("\t\t Room Number: %d to %d\n",carray[i].start,carray[i].end);
	printf("\t\tRoom Bill:%.2f\n\n",carray[i].roombill);
	
	printf("\t\t\t************BILL*************\n");
	printf("\t\tRoom Bill:%.2f\n\n",carray[i].roombill);
	printf("\t\tNo Of Days of stay:%d",carray[i].No_of_days);
	printf("\t\tRestauran Bill:%.2f",carray[i].restaurantbill);
	printf("\n\n\t\tTotal Bill:%.2f",carray[i].totalbill);
	printf("\n\n\t\tAmount Paid:%.2f",carray[i].totalbill);
	printf("\n\t\tPayment type:%s",carray[i].paymenttype);
	
}






void datastoring(customer *carray,customer c,int i)
{   
    strcpy(carray[i].name,c.name);
    carray[i].phoneno=c.phoneno;
    strcpy(carray[i].email,c.email);
    strcpy(carray[i].address,c.address);
    carray[i].cindate.date=c.cindate.date;
    carray[i].cindate.month=c.cindate.month;
    carray[i].cindate.year=c.cindate.year;
    carray[i].coutdate.date=c.coutdate.date;
    carray[i].coutdate.month=c.coutdate.month;
    carray[i].coutdate.year=c.coutdate.year;
    carray[i].No_of_days=c.No_of_days;
    strcpy(carray[i].roominfo,c.roominfo);
    carray[i].restaurantbill=c.restaurantbill;
    carray[i].roombill=c.roombill;
    carray[i].totalbill=c.totalbill;
    strcpy(carray[i].paymenttype,c.paymenttype);
}


void booking(customer *customer1)
{
     char temp;
     long long int d;
     int count,j,flag;
    printf("Enter your details:\n");
    printf("Enter your name: ");
    do{
        j=0;
        flag=0;
        scanf("\n");
        scanf("%[^\n]%*c",customer1->name);
        while(customer1->name[j]!='\0')
        {
            if(isalpha(customer1->name[j])==0 && customer1->name[j]!=32)
            {
            	printf("INVALID NAME(ONLY ALPHABETS ALLOWED!)PLEASE ENTER AGAIN: ");
                flag=1;
                break;
            }
            j++;
        }
    }while(flag==1);

    // The format specifier "%[^\n]" tells to the compiler that read the characters until "\n" is not found.

    printf("Enter your Mobile number: ");
    
    do
    {
      scanf("%lld",&d);
      customer1->phoneno=d;
      count=0;
      while(d!=0)
       {
            d=d/10;
            count++;
       }
    
      if(count!=10)
      {
            printf("Enter a valid mobile no:");
            count=0;
      }
   
    }while(count!=10);
    
    printf("Enter your address: ");

    // temp statement to clear buffer
    
    scanf("%c",&temp);
    scanf("%[^\n]%*c",customer1->address);
    printf("Enter your email: ");
    scanf("%[^\n]%*c",customer1->email);
    printf("\n");
     printf("\n\n");
    printf("\t\t*       ------------------           *\n");
	printf("\t\t*        YOUR INFORMATION            *\n");
	printf("\t\t*       ------------------           *\n");
 
    printf("Name: %s\n",customer1->name);
    printf("Mobile Number: %lld\n",customer1->phoneno);
    printf("Address: %s\n",customer1->address);
    printf("Email Id: %s\n",customer1->email);   

}



int roominformation(customer *c)
{
    int choice,RoomBill,BillNorm, BillInter, BillSuit, BillEffi;
    char Roominfo[50];
    float Roombill;
    printf("\n\n");
    printf("\t\t\t\t\t\t\t Atulya Taj \n \t");
    for(int i=0;i<150;i++)
    printf("=");
    printf("\n");
    printf("\t\tChoose the type of room you want \n\n \t\t1. Normal rooms \t\tPrice: Contains four different types of rooms of range (999 rupees per day to 2999 rupees per day)  \n\n\t\t2. Interconnected rooms \t\t\t\t\tPrice: 2999 rupees per day.\n\n \t\tFeatures:Two seperate rooms,king sized bed and queen sized bed.\n\n");
    printf("\t\t3. Presidental suite rooms \t\t\t\t\tPrice: 49999 rupees per day.\n\n \t\tFeatures:SPA,clothes are provided.\n\n");
    printf("\t\t4. Efficiency rooms \t\t\t\t\t\tPrice: 5999 rupees per day.\n\n \t\tFeatures:A bed,one kitchen and one dinning table.\n\t");
    for(int i=0;i<150;i++)
    printf("=");
    printf("\nEnter any of the choice from 1 to 4.\n");
    printf(" ");
    do{
        printf("Enter  your choice: ");
        scanf("%d",&choice);
        if(choice >= 5)
        {
            printf("<<Please Enter Valid Input From 1 to 4>> \n");
        }
    }while(choice > 4);
    
    if(choice == 1)
    {
        printf("\n\nThank you. \nYou have choosen Normal rooms in our hotel. \n");
        strcpy(Roominfo,"Normal rooms");
        Roombill = Normalrooms();
    }
    else if(choice == 2)
        {
            printf("\n\nThank you. \nYou have choosen Interconnected rooms in our hotel. \n");
            strcpy(Roominfo,"Interconnected rooms");
            Roombill = Interconnectedrooms();
        }
        else if(choice == 3)
            {
                printf("\n\nThank you. \nYou have choosen Presidental suite rooms in our hotel. \n");
                strcpy(Roominfo,"Presidental suite rooms");
                Roombill = Presidentialsuitrooms();
            }
            else if(choice == 4)
                {
                    printf("\n\nThank you. \nYou have choosen Efficiency rooms in our hotel. \n");
                    strcpy(Roominfo,"Efficiency rooms");
                    Roombill = Efficiencyrooms();
                }
    strcpy(c->roominfo,Roominfo);
     printf("\n\n");
    
    printf("\t\t*       ----------           *\n");
	printf("\t\t*        ROOM BILL           *\n");
	printf("\t\t*       ----------           *\n");
 
    printf("Roomtype:%s\n",c->roominfo);
    c->roombill=Roombill;
    printf("Roombill:%.2f\n",c->roombill);
   
   
    return 0;
}



float Normalrooms()
{
    int choice;
    float BillNormal,b1=0,b2=0,b3=0,b4=0;
    char str;
    printf("\n\n");
    printf("\t\t\t\t\t\tAtulya Taj \n \t");
    for(int i=0;i<93;i++)
    printf("=");
    printf("\n");
    printf("\t\tChoose the type of room you want \n\n \t\t1. Single rooms \t\t\t\t\tPrice: 999 rupees per day.  \n\n\t\t2. Double rooms \t\t\t\t\tPrice: 1999 rupees per day.\n\n\t\t3. Triple rooms \t\t\t\t\tPrice: 2599 rupees per day.\n\n\t\t4. Quad rooms \t\t\t\t\t\tPrice: 2999 rupees per day.\n\n");
    printf("\t");
    for(int i=0;i<93;i++)
    printf("=");
    printf("\nEnter any of the choice from 1 to 4: ");

    do
    {
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("You have choosen Single room.\nPlease enter number of Single rooms that you wanted to book, n: ");
            scanf("%d",&z);
            b1 = b1+(999*z);
        }
        else if(choice == 2)
            {
                printf("You have choosen Double room.\nPlease enter number of Double rooms that you wanted to book, n: ");
                scanf("%d",&z);
                b2 = b2+(1999*z);
            }
            else if(choice == 3)
                {
                    printf("You have choosen Triple room.\nPlease enter number of Triple rooms that you wanted to book, n: ");
                    scanf("%d",&z);
                    b3 = b3+(2599*z);
                }
                else if(choice == 4)
                    {
                        printf("You have choosen Quad room.\nPlease enter number of Quad rooms that you wanted to book, n: ");
                        scanf("%d",&z);
                        b4 = b4+(2999*z);
                    }
                    else
                    {
                        printf("<<Please Enter Valid Input From 1 to 4>>\n");
                    }
    }while(choice > 4);

    BillNormal = b1+b2+b3+b4;

    return BillNormal;
}




float Interconnectedrooms()
{
    float BillInter;
    printf("Please enter number of Interconnected rooms that you wanted to book, n: ");
    scanf("%d",&z);
    BillInter =(2999*z);
    return BillInter;

}




float Presidentialsuitrooms()
{
    float BillSuit;
    printf("Please enter the number of Presidential suit rooms that you wanted to book, n: ");
    scanf("%d",&z);
    BillSuit = (49999*z);
    return BillSuit;
}




float Efficiencyrooms()
{
    float BillEffi;
    printf("Please enter how many Efficiency rooms that you wanted to book, n: ");
    scanf("%d",&z);
    BillEffi = (5999*z);
    return BillEffi;
}



int restaurant(customer *c)
{
         float total,breakfasttotal=0,lunchtotal=0,dinnertotal=0;
   //declaration
    
    char s1[4],s2[4],s3[4];
    int v,v1,v2,v3,v4,v5,count=0;
     printf("**** Enter the food you want until your stay in Atulyaa Taj Hotel ****\n\n");
     printf("Do You need BREAKFAST Give yes Otherwise No:\n");
     //validation
    do{
        if(count>0)
        printf("\nINVALID INPUT!!\nGive (yes or no):");
        scanf("%s",s1);
        v=strcmp(s1,"Yes");
        v1=strcmp(s1,"YES");
        v2=strcmp(s1,"yes");
        v3=strcmp(s1,"NO");
        v4=strcmp(s1,"No");
        v5=strcmp(s1,"no");
        count++;
    }while((v1) && (v2) && (v3) && (v4) && (v)&&(v5));
    //selecting
    v=strcmp(s1,"Yes");
    v1=strcmp(s1,"YES");
    v2=strcmp(s1,"yes");
    if(!v1 || !v2 || !v)
    {
        breakfasttotal=breakfast();
    }
    //validation
    count=0;
     printf("Do You need LUNCH Give yes Otherwise No:\n");
     do{
        if(count>0)
        printf("\nINVALID INPUT!!\n(Give yes or no):");
        scanf("%s",s2);
        v=strcmp(s2,"Yes");
        v1=strcmp(s2,"YES");
        v2=strcmp(s2,"yes");
        v3=strcmp(s2,"NO");
        v4=strcmp(s2,"No");
        v5=strcmp(s2,"no");
        count++;
    }while((v1) && (v2) && (v3) && (v4) && (v)&&(v5));
    //selecting
    if(!v1 || !v2 || !v)
    {
       lunchtotal=lunch();
    }
    count=0;
    //validation
    printf("Do You need DINNER Give yes Otherwise No:\n");
    do{
        if(count>0)
        printf("\nINVALID INPUT!!\n(Give yes or no):");
        scanf("%s",s3);
        v=strcmp(s3,"Yes");
        v1=strcmp(s3,"YES");
        v2=strcmp(s3,"yes");
        v3=strcmp(s3,"NO");
        v4=strcmp(s3,"No");
        v5=strcmp(s3,"no");
        count++;
    }while((v1) && (v2) && (v3) && (v4) && (v)&&(v5));
    //selecting
    if(!v1 || !v2 || !v)
    {
        dinnertotal=dinner();
    }
    total=breakfasttotal+lunchtotal+dinnertotal;
    printf("\nRestuarant bill is %.2f",total);
    total=total*c->No_of_days;
    //restaurantbill=total;
    printf("\nRestaurant bill for %d days:%.2f",c->No_of_days,total);
    c->restaurantbill=total;
    return 0;
}


float breakfast()
{
    int a1=0,a2=0,a3=0,a4=0;
    int q1=0,q2=0,q3=0,q4=0;
    int choice,quantity;
    float bill1=0;
    int num;
    do{
       printf("\t\t\t Atulya Taj Restaurant\n \t\t");
    for(int i=0;i<38;i++)
    printf("=");
    printf("\n");
    printf("\t\t\t\tBREAKFAST\n");
    printf("\t\t 1.IDLY price-RS.10 per one\n \t\t 2.SET DOSA price-RS.30\n \t\t 3.VADA Price -RS.10 per one\n \t\t 4.UPMA price-RS.30\n \t\t");
    for(int i=0;i<38;i++)
    printf("=");
    printf("\n");
    printf("Enter The Food Item From 1 to 4: ");
       scanf("%d",&choice);
       if(choice==1)
       {
           printf("You have choosen IDLY Please enter the quantity:");
           scanf("%d",&quantity);
           a1=a1+(10*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q1=q1+quantity;
       }
       else if(choice==2)
       {
           printf("You have choosen SET DOSA Please enter the quantity:");
           scanf("%d",&quantity);
           a2=a2+(30*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q2=q2+quantity;
       }
       else if(choice==3)
       {
           printf("You have choosen VADA Please enter the quantity:");
           scanf("%d",&quantity);
           a3=a3+(10*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q3=q3+quantity;
       }
       else if(choice==4)
       {
           printf("You have choosen UPMA Please enter the quantity:");
           scanf("%d",&quantity);
           a4=a4+(30*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q4=q4+quantity;
       }
       else
       {
           printf("<<Please Enter Valid Input From 1 to 4 >>\n\n");
           num=1;
       }
       
    }while(num==1); 
    printf("You have ordered\n%d IDLY\n%d SET DOSA\n%d VADA\n%d UPMA\n",q1,q2,q3,q4);
    bill1=a1+a2+a3+a4;
    printf(" BREAKFSAT Bill is %.2f\n",bill1);
    return bill1;
}



float lunch()
{
    int a1=0,a2=0,a3=0,a4=0;
    int q1=0,q2=0,q3=0,q4=0;
    int choice,quantity;
    float bill2=0;
    int num;
    do{
      printf("\t\t\t Atulya Taj Restaurant\n \t\t");
    for(int i=0;i<38;i++)
    printf("=");
    printf("\n");
    printf("\t\t\t\tLUNCH\n");
    printf("\t\t 1.CHICKEN BIRIYANI price-RS.200 per one\n \t\t 2.VEG BIRIYANI price-RS.100 per one\n \t\t 3.PLATE MEALS price -RS.80 per one\n \t\t 4.MANDI price-RS.350 per one\n \t\t");
    for(int i=0;i<38;i++)
    printf("=");
    printf("\n");
    printf("Enter The Food Item From 1 to 4: ");
       scanf("%d",&choice);
       if(choice==1)
       {
           printf("You have choosen CHICKEN BIRIYANI Please enter the quantity:");
           scanf("%d",&quantity);
           a1=a1+(200*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q1=q1+quantity;
       }
       else if(choice==2)
       {
           printf("You have choosen VEG BIRIYANI Please enter the quantity:");
           scanf("%d",&quantity);
           a2=a2+(100*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q2=q2+quantity;
       }
       else if(choice==3)
       {
           printf("You have choosen PLATE MEALS Please enter the quantity:");
           scanf("%d",&quantity);
           a3=a3+(80*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q3=q3+quantity;
       }
       else if(choice==4)
       {
           printf("You have choosen MANDI Please enter the quantity:");
           scanf("%d",&quantity);
           a4=a4+(350*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q4=q4+quantity;
       }
       else
       {
           printf("<<Please Enter Valid Input From 1 to 4 >>\n\n");
           num=1;
       }
       
    }while(num==1); 
    printf("You have ordered\n%d CHICKEN BIRIYANI\n%d VEG BIRIYANI\n%d PLATE MEALS\n%d MANDI\n",q1,q2,q3,q4);
    bill2=a1+a2+a3+a4;
    printf("LUNCH Bill is %.2f\n",bill2);
    return bill2;
}




float dinner()
{
    int a1=0,a2=0,a3=0,a4=0;
    int q1=0,q2=0,q3=0,q4=0;
    int choice,quantity;
    float bill3=0;
    int num;
    do{
    printf("\t\t\t Atulya Taj Restaurant\n \t\t");
    for(int i=0;i<38;i++)
    printf("=");
    printf("\n");
    printf("\t\t\t\tDINNER\n");
    printf("\t\t 1.ROTI price-RS.5 per one\n \t\t 2.PANNER BUTTER MASALA price-RS.100 per one\n \t\t 3.CHICKEN RICE price -RS.150 per one\n \t\t 4.THALI price-RS.200 per one\n \t\t");
    for(int i=0;i<38;i++)
    printf("=");
    printf("\n");
    printf("Enter The Food Item From 1 to 4:");
       scanf("%d",&choice);
       if(choice==1)
       {
           printf("You have choosen ROTI Please enter the quantity:");
           scanf("%d",&quantity);
           a1=a1+(5*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q1=q1+quantity;
       }
       else if(choice==2)
       {
           printf("You have choosen PANNER BUTTER MASALA Please enter the quantity:");
           scanf("%d",&quantity);
           a2=a2+(100*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q2=q2+quantity;
       }
       else if(choice==3)
       {
           printf("You have choosen CHICKEN RICE Please enter the quantity:");
           scanf("%d",&quantity);
           a3=a3+(150*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q3=q3+quantity;
       }
       else if(choice==4)
       {
           printf("You have choosen THALI Please enter the quantity:");
           scanf("%d",&quantity);
           a4=a4+(200*quantity);
           printf("Do you want to select another item\n 1-yes\n otherwise\n 2-no\n(Give 1 or 2):");
           scanf("%d",&num);
           q4=q4+quantity;
       }
       else
       {
           printf("<<Please Enter Valid Input From 1 to 4>>\n\n");
           num=1;
       }
       
    }while(num==1); 
    printf("You have ordered\n%d CHICKEN BIRIYANI\n%d VEG BIRIYANI\n%d PLATE MEALS\n%d MANDI\n",q1,q2,q3,q4);
    bill3=a1+a2+a3+a4;
    printf("DINNER Bill is %.2f\n",bill3);
    return bill3;
}
int datecalculation(customer *c)
{
    int no_of_days,dd,mm,yy;
    int str;
    
    do
    {
        str = -1;
        printf("Please enter the checkindate in the format of dd mm yy: ");
    
        scanf("%d%d%d",&dd,&mm,&yy);
        
        
        if(yy>=2021 && yy <= 2025)
        {
            //checkin month validation
            if(mm>=1 && mm<=12)
            {
                //checkin days validation
                if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                    printf("Checkin Date is valid.\n");
                else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                    printf("Checkin Date is valid.\n");
                else if((dd>=1 && dd<=28) && (mm==2))
                    printf("Checkin Date is valid.\n");
                else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                    printf("Checkin Date is valid.\n");
                else
                {
                    str=0;
                    printf("Checkin Day is invalid.\n");
                }
            }
            else
            {
                str = 0;
                printf("Checkin Month is not valid.\n");
            }
        }
        else
        {
            str = 0;
            printf("Checkin Year is not valid.\nPLease enter valid date \n ");
        }
    }while(str==0);
    c->cindate.date = dd;
    c->cindate.month = mm;
    c->cindate.year= yy;
    checkin_date.date = dd;
    checkin_date.month = mm;
    checkin_date.year = yy;
    
   do{
       str=-1;
       printf("Please enter the checkoutdate in the format of dd mm yy: ");
       scanf("%d%d%d",&dd,&mm,&yy);
        if(checkin_date.year==yy)
        {
            if(checkin_date.month==mm)
            {
                if(checkin_date.date<=dd)
                {
                        if(yy>=2021 && yy <= 2025 ) 
                        {
                            //checkout month validation
                            if(mm>=1 && mm<=12)
                            {
                                //checkout days validation
                                if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                                    printf("Checkout Date is valid.\n");
                                else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                                    printf("Checkout Date is valid.\n");
                                else if((dd>=1 && dd<=28) && (mm==2) )
                                    printf("Checkout Date is valid.\n");
                                else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                                    printf("Checkout Date is valid.\n");
                                else
                                {
                                    str = 0;
                                    printf("Checkout Day is invalid.\nPlease enter valid date: \n");
                                }
                            }
                            else
                            {
                                str = 0;
                                printf("Checkout Month is not valid.\nPlease enter valid date: \n");
                            }
                        }
                        else
                        {
                            str = 0;
                            printf("Checkout Year is not valid.\nPLease enter valid date: \n");
                        }  
                
                }
                else
                {
                    printf("Checkout Date is Invlaid\nPlease enter valid date: \n");
                    str=0;
                }
            }
            else if(checkin_date.month<mm)
            {
                        if(yy>=2021 && yy <= 2025 ) 
                        {
                            //checkout month validation
                            if(mm>=1 && mm<=12)
                            {
                                //checkout days validation
                                if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                                    printf("Checkout Date is valid.\n");
                                else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                                    printf("Checkout Date is valid.\n");
                                else if((dd>=1 && dd<=28) && (mm==2) )
                                    printf("Checkout Date is valid.\n");
                                else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                                    printf("Checkout Date is valid.\n");
                                else
                                {
                                    str = 0;
                                    printf("Checkout Day is invalid.\nPlease enter valid date: \n");
                                }
                            }
                            else
                            {
                                str = 0;
                                printf("Checkout Date is Invlaid\nPlease enter valid date: \n");
                            }
                        }
                        else
                        {
                            str = 0;
                            printf("Checkout Date is Invlaid\nPlease enter valid date: \n");
                        }  
                     
            }
            else
            {
                printf("Checkout Date is Invlaid\nPlease enter valid date: \n");
                str=0;
            }
        }
        else if(checkin_date.year<yy)
        {
                        if(yy>=2021 && yy <= 2025 ) 
                        {
                            //checkout month validation
                            if(mm>=1 && mm<=12)
                            {
                                //checkout days validation
                                if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                                    printf("Checkout Date is valid.\n");
                                else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                                    printf("Checkout Date is valid.\n");
                                else if((dd>=1 && dd<=28) && (mm==2) )
                                    printf("Checkout Date is valid.\n");
                                else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                                    printf("Checkout Date is valid.\n");
                                else
                                {
                                    str = 0;
                                    printf("Checkout Day is invalid.\nPlease enter valid date: \n");
                                }
                            }
                            else
                            {
                                str = 0;
                                printf("Checkout Month is not valid.\nPlease enter valid date: \n");
                            }
                        }
                        else
                        {
                            str = 0;
                            printf("Checkout Year is not valid.\nPLease enter valid date: \n");
                        }  

        }
        else
        {
            printf("Checkout Date is Invlaid\nPlease enter valid date: \n");
            str=0;
        }
    }while(str==0);
    c->coutdate.date = dd;
    c->coutdate.month = mm;
    c->coutdate.year= yy;
    checkout_date.date = dd;
    checkout_date.month = mm;
    checkout_date.year= yy;
    printf("Check_in date: ");
    displaydate(c->cindate);
    printf("Check_out date: ");
    displaydate(c->coutdate);
    no_of_days=getDifference(checkin_date, checkout_date);
    no_of_days=no_of_days+1;
    c->No_of_days=no_of_days;
    printf("\nno_of_days:%d",no_of_days);
    return 0;
    
}
const int monthDays[12]
	= { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31 };


int countLeapYears(struct date d)
{
	int years = d.year;
	if (d.month <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

int getDifference( struct date dt1, struct date dt2)
{

	long int n1 = dt1.year * 365 + dt1.date;
	for (int i = 0; i < dt1.month - 1; i++)
		n1 += monthDays[i];
    n1 += countLeapYears(dt1);
	long int n2 = dt2.year * 365 + dt2.date;
	for (int i = 0; i < dt2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);
	return (n2 - n1);
}
void display(customer *carray,int i)
{
     printf("\n\n\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*       --------          *\n");
	printf("\t\t*        RECEIPT          *\n");
	printf("\t\t*       --------          *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n\n");
	printf("\tPERSONAL INFORMATION:\n");
	printf("\t\tName:%s\n",carray[i].name);
	printf("\t\tPhone no.:%lld\n",carray[i].phoneno);
	printf("\t\tAddress:%s\n",carray[i].address);
	printf("\t\tEmail:%s\n\n",carray[i].email);
	printf("\tCHECKIN AND CHECKOUT DATE:\n");
	printf("\t\tCheck_in date: ");
    displaydate(carray[i].cindate);
    printf("\t\tCheck_out date: ");
	displaydate(carray[i].coutdate);
	printf("\t\tNo Of Days of stay:%d",carray[i].No_of_days);
	printf("\n");
	printf("\tROOM:\n");
	printf("\t\tRoom Type:%s\n",carray[i].roominfo);
    if(carray[i].no_of_rooms==1)
        printf("\t\tRoom Number: %d\n",carray[i].end);
    else
        printf("\t\t Room Number: %d to %d\n",carray[i].start,carray[i].end);
	printf("\t\tRoom Bill:%.2f\n\n",carray[i].roombill);
	
	printf("\t\t\t*****************BILL******************\n\n");
	printf("\t\t\tRoom Bill: %.2f\n",carray[i].roombill);
	printf("\t\t\tNo Of Days of stay: %d\n",carray[i].No_of_days);
	printf("\t\t\tRestauran Bill for %d days: %.2f",carray[i].No_of_days,carray[i].restaurantbill);
	printf("\n\n\t\t\tTotal Bill: %.2f",carray[i].totalbill);
	printf("\n\n\n\t\t\tAmount Paid: %.2f",carray[i].totalbill);
	printf("\n\t\t\tPayment type: %s",carray[i].paymenttype);
	printf("\n\t\t\t*****************BILL******************\n\n\n");

}
int payment(customer *c)
{
    printf("\n\n");   
    printf("\n\n\n\n\t\t\t*****************BILL******************\n\n");
	printf("\t\t\tRoom Bill: %.2f\n",c->roombill);
	printf("\t\t\tNo Of Days of stay: %d\n",c->No_of_days);
	printf("\t\t\tRestauran Bill for %d days: %.2f",c->No_of_days,c->restaurantbill);
	printf("\n\t\t\tTotal Bill: %.2f",c->totalbill);
	printf("\n\n\t\t\t*****************BILL******************\n\n");
   int payment_type,ch;
   ch=1;
   char ptype[50];
    while(ch)
    {
        printf("\t\t\t Atulya Taj Restaurant\n \t\t");
        for(int i=0;i<38;i++)
        printf("=");
        printf("\n");
        printf("\t\t\t\tPAYMENT\n");
        printf("\t\t 1.Debit\n \t\t 2.Credit\n \t\t 3.Cash\n \t\t 4.Onlinepayment\n \t\t");
        for(int i=0;i<38;i++)
        printf("=");
        printf("\n");
        printf("\nEnter your choice between 1-4: ");
        scanf("%d",&payment_type);
        
        if(payment_type>=1 && payment_type<=4)
        {
           
                if(payment_type==3)
                {
                    strcpy(ptype,"Cash\n");
                    printf("\npayment succesfull \n\n\nThankyou for visiting the hotel\n");
                }
                else if(payment_type==2)
                {
                    strcpy(ptype,"Credit Card\n");
                    printf("\npayment succesfull \n\n\nThankyou for visiting the hotel\n");
                }
                else if(payment_type==1)
                {
                    strcpy(ptype,"Debit Card\n");
                    printf("\npayment succesfull \n\n\nThankyou for visiting the hotel\n");
                }
                else if(payment_type==4)
                {
                    strcpy(ptype,"Onlinepayment\n");
                    printf("\npayment succesfull \n\n\nThankyou for visiting the hotel\n");
                }
                ch = 0;
        }
        else
        {
            printf("\n\tPlease choose valid payment method\n");
        }
    }
    strcpy(c->paymenttype,ptype);
    
    return 0;
}

