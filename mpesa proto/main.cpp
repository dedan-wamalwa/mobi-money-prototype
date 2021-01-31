#include <iostream>
#include<string>
using namespace std;

class pesa
{
private:
    int bal=0,wfee,sfee;
public:
    void deposit();
    void withdraw();
    void send();
    void airtime();
    int balance();
};
int pesa::balance()
{
return bal;
}
void pesa::deposit()
{
int b1;
cout<<"Enter the amount you wish deposit"<<endl;
cin>>b1;
cout<<"You have deposited KES "<<b1<<",Transaction cost: 0.00";
bal=bal+b1;
cout<<".New M-Pesa balance is KES "<<bal;
}
void pesa::withdraw()
{
int a1;
cout<<"Enter the amount you wish to withdraw:"<<endl;
cin>>a1;
while(a1<=49 || a1>=70001)
    {
cout<<"Invalid amount,enter amount between 50 and 70000 only"<<endl;
cin>>a1;
    }
if (a1>=50 && a1<=100){wfee=10;}
else if (a1>=101 && a1<=500){wfee=27;}
else if (a1>=501 && a1<=1000){wfee=28;}
else if (a1>=1001 && a1<=3500){wfee=32;}
else if (a1>=3501 && a1<=5000){wfee=37;}
else if (a1>=5001 && a1<=10000){wfee=39;}
else if (a1>=10000 && a1<=15000){wfee=45;}
else if (a1>=15001 && a1<=30000){wfee=56;}
else if (a1>=30001 && a1<=70000){wfee=72;}
if (bal<(a1+wfee)){cout<<"You have insufficient funds to complete transaction\nYour M-Pesa balance is KES "<<bal;}
else{
cout<<"You have withdrawn KES "<<a1<<",transaction cost:"<<wfee;
bal=bal-(a1+wfee);
cout<<".New M-Pesa balance is "<<bal<<endl;}
}
void pesa::send()
{
string number;
int a2;
cout<<"Enter the number you wish to send to:"<<endl;
cin>>number;
cout<<"Enter the amount you wish to send:"<<endl;
cin>>a2;
while(a2<=0 || a2>=70001)
    {
cout<<"Invalid amount,enter amount between 0 and 70000 only"<<endl;
cin>>a2;
    }
if (a2>=0 && a2<=100){sfee=0;}
else if (a2>=101 && a2<=500){sfee=10;}
else if (a2>=501 && a2<=1000){sfee=13;}
else if (a2>=1001 && a2<=3500){sfee=19;}
else if (a2>=3501 && a2<=5000){sfee=30;}
else if (a2>=5001 && a2<=10000){sfee=35;}
else if (a2>=10000 && a2<=15000){sfee=42;}
else if (a2>=15001 && a2<=30000){sfee=50;}
else if (a2>=30001 && a2<=70000){sfee=65;}
if(bal<(a2+sfee)){cout<<"You have insufficient funds to complete the transaction\nYour M-Pesa balance is KES "<<bal<<endl;}
else{
bal=bal-(a2+sfee);
cout<<"KES "<<a2<<" has been sent to "<<number<<" Transaction cost:"<<sfee;
cout<<".New M-Pesa balance is KES "<<bal<<endl;}
}
void pesa::airtime()
{
int a3;
cout<<"Enter the amount you wish to buy airtime:";
cin>>a3;
if(a3>bal){cout<<"\nYou have insufficient funds to complete the transaction\n";
cout<<"Your M-Pesa balance is "<<bal;}
else{
bal=bal-a3;
cout<<"You have bought KES "<<a3<<" worth of airtime.New M-Pesa balance is KES "<<bal<<endl;
}
}
int main()
{
pesa pp;int op,y;
cout<<"Your opening M-Pesa balance is KES 0.00";
do{
cout<<"\nChoose an option below:"<<endl;
cout<<"1. DEPOSIT\n2.BUY AIRTIME\n3.SEND MONEY\n4.WITHDRAW CASH\n5.CHECK BALANCE\n";
cin>>op;
switch (op)
{
case 1:
    pp.deposit();
    break;
case 2:
    pp.airtime();
    break;
case 3:
    pp.send();
    break;
case 4:
    pp.withdraw();
    break;
case 5:
    cout<<"Your M-Pesa balance is KES "<<pp.balance()<<endl;
    break;
default:
    cout<<"\nInvalid choice!";
}
cout<<"\nPress 1 to continue,0 to exit!"<<endl;
cin>>y;
while(y>1 || y<0){cout<<"Invalid choice!\nPress 1 to continue,0 to exit!"<<endl;
cin>>y;}
}while(y==1);
return 0;
}
