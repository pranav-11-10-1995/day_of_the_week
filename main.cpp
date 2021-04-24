#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char date1[11]="03/11/1582",date2[11],copy1[11],copy2[11];
    int i;
    /*cout<<"enter the first date : ";
    cin.getline(date1,11);*/

    cout<<"DATE FORMAT : DD/MM/YYYY \n\n";
    cout<<"ENTER THE DATE TO FIND THE DAY OF THE WEEK: ";
    cin.getline(date2,11);

    for(i=0;i<11;i++)
    {
        copy1[i]=date1[i];
        copy2[i]=date2[i];
    }

    date1[0]='0';
    date1[1]='1';
    date1[3]='0';
    date1[4]='1';

    date2[0]='3';
    date2[1]='1';
    date2[3]='1';
    date2[4]='2';


    int year1=(date1[6]-48)*1000+(date1[7]-48)*100+(date1[8]-48)*10+(date1[9]-48)*1;
    int year2=(date2[6]-48)*1000+(date2[7]-48)*100+(date2[8]-48)*10+(date2[9]-48)*1;
    int daydiff1=365*(year2-year1)+365;
    if(year1 !=year2)
    {
     for(i=year1;i<=year2;i++)
     {
        if(i%4==0)
        {
            daydiff1++;
        }
     }
    }
   /*cout<<"\n"<<"maximum days : "<<daydiff1;*/
     //cout<<"\ncharacter size"<<sizeof(copy1[3])<<endl;
     // converting char to int

    int mon1=(copy1[3]-48)*10+(copy1[4]-48)*1;
    int mon2=(copy2[3]-48)*10+(copy2[4]-48)*1;


    if(year2==1582 && mon2==10)
    {
        cout<<"\n-------------------------------\n";
        cout<<"\nTHIS IS THE MONTH IN WHICH GREGORIAN CALENDER REPLACED JULIAN CALENDER";
        cout<<"\nENTER DATE FROM 01/11/1582";
        cout<<"\n-------------------------------\n";
        return 0;
    }
    if(year2==1582 && mon2<=9)
    {
        cout<<"\n-------------------------------\n";
        cout<<"\nJULIAN CALENDER WAS FOLLOWED";
        cout<<"\nENTER DATE FROM 01/11/1582";
        cout<<"\n-------------------------------\n";
        return 0;
    }
    if(year2<1582)
    {
        cout<<"\n-------------------------------\n";
        cout<<"\nJULIAN CALENDER WAS FOLLOWED";
        cout<<"\nENTER DATE FROM 01/11/1582";
        cout<<"\n-------------------------------\n";
        return 0;
    }


    int sum=0;
    for(i=1;i<mon1;i++)
    {
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
        {
            sum=sum+31;
        }
        if(i==2 /*&& year1%4 != 0 */)
        {
            sum=sum+28;
        }
        /*if(i==2 && year1%4 == 0)
        {
            sum=sum+29;
        }*/
        if(i==4 || i==6 || i==9 || i==11)
        {
            sum=sum+30;
        }
    }
    int month1=sum;
    /*cout<<"\nmonth1: "<<month1;*/

     sum=0;
    for(i=12;i>=mon2;i--)
    {
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
        {
            sum=sum+31;
        }
          if(i==2 /*&& year2%4 != 0 */)
        {
            sum=sum+28;
        }
        /*if(i==2 && year2%4 == 0)
        {
            sum=sum+29;
        }*/
        if(i==4 || i==6 || i==9 || i==11)
        {
            sum=sum+30;
        }
    }
    int month2=sum;

    /*cout<<"\nmonth2: "<<month2;*/



    int tot=daydiff1-month1-month2;

     if( (year1==year2) && (year1%4==0) && (mon1<3) && (mon2>=3))
    {
        tot=tot+1;
    }

    /*cout<<"\ntotal :"<<tot;*/




    int day1=(copy1[0]-48)*10+(copy1[1]-48)*1;
    int day2=(copy2[0]-48)*10+(copy2[1]-48)*1;

     if(year2 %4!=0 )
    {
        if(mon2==2)
        {
            if(day2>28)
            {
                cout<<"\n------------------------------------------------------------\n";
                cout<<"\nINVALID DATE ENTRY : NON-LEAP YEAR .....FEBRUARY HAS 28 DAYS\n";
                cout<<"\n------------------------------------------------------------\n";
                return 0;
            }
        }
    }

    if(year2 %4==0)
    {
        if(mon2==2)
        {
            if(day2>29)
            {
                cout<<"\n--------------------------------------------------------\n";
                cout<<"\nINVALID DATE ENTRY : LEAP YEAR .....FEBRUARY HAS 29 DAYS\n";
                cout<<"\n--------------------------------------------------------\n";
                return 0;
            }
        }
    }

    if(mon2==1 || mon2==3 || mon2==5 || mon2==7 || mon2==8 || mon2==10 || mon2==12)
    {
        if(day2>31)
        {
            cout<<"\n-----------------------------------------------------------------------------------------------\n";
            cout<<"\nINVALID DATE ENTRY : JANUARY, MARCH, MAY, JULY, AUGUST, OCTOBER, DECEMBER HAVE MAXIMUM 31 DAYS \n";
            cout<<"\n-----------------------------------------------------------------------------------------------\n";
            return 0;
        }
    }

       if(mon2==4 || mon2==6 || mon2==9 || mon2==11 )
    {
        if(day2>30)
        {
            cout<<"\n----------------------------------------------------------------------------\n";
            cout<<"\n INVALID DATE ENTRY : APRIL, JUNE, SEPTEMBER, NOVEMBER HAVE MAXIMUM 30 DAYS \n";
            cout<<"\n----------------------------------------------------------------------------\n";
            return 0;
        }
    }

     if(mon2>12)
    {
        cout<<"\n---------------------------------------------------------\n";
        cout<<"\n INVALID DATE ENTRY : NUMBER OF MONTHS IN A YEAR : 12 \n";
        cout<<"\n---------------------------------------------------------\n";
        return 0;
    }



    if(year2==1582 && mon2==11 && day2==1)
    {
        cout<<"\n***********";
        cout<<"\nSATURDAY\n";
        cout<<"\n***********\n";
        return 0;
    }
    if(year2==1582 && mon2==11 && day2==2)
    {
        cout<<"\n**********";
        cout<<"\nFRIDAY\n";
        cout<<"**********\n";
        return 0;
    }
    int tot1=tot-day1+day2+1;
    /*cout<<"\nday1 : "<<day1;
    cout<<"\nday2 : "<<day2;
    cout<<"\n"<<tot1;*/

    while(1)
    {

        if(tot1==1)
        {
            cout<<"\n**********";
            cout<<"\nSUNDAY\n";
            cout<<"**********\n";
            break;
        }
        else if(tot1==2)
        {
            cout<<"\n**********";
            cout<<"\nMONDAY\n";
            cout<<"**********\n";
            break;
        }
        else if(tot1==3)
        {
            cout<<"\n**********";
            cout<<"\nTUESDAY\n";
            cout<<"**********\n";
            break;
        }
        else if(tot1==4)
        {
            cout<<"\n**********";
            cout<<"\nWEDNESDAY\n";
            cout<<"**********\n";
            break;
        }
        else if(tot1==5)
        {
            cout<<"\n**********";
            cout<<"\nTHURSDAY\n";
            cout<<"**********\n";
            break;
        }
        else if(tot1==6)
        {
            cout<<"\n**********";
            cout<<"\nFRIDAY\n";
            cout<<"**********\n";
            break;
        }
        else if(tot1==0)
        {
            cout<<"\n**********";
            cout<<"\nSATURDAY\n";
            cout<<"**********\n";
            break;
        }
        else
        {
            tot1=tot1%7;
        }
    }
    return 0;
}
