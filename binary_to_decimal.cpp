#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class binary{
    string s;
public:
void read(void);
void chk_binary(void);
void decimal(void);


};
void binary :: read(void){
    cout<<"enter a binary number"<<endl;
    cin>>s;

}
void binary :: chk_binary(void){
    for (int  i = 0; i < s.length() ; i++)
    {
        if(s.at(i)!='0' && s.at(i)!='1'){
            cout<<"incorrect binary format"<<endl;
            exit(0);
        }
    }
    
}
void binary :: decimal(void){
    int num=stoi(s);
    int sum=0,i=0;
    while(num){
       sum=sum+pow(2,i)*(num%10); 
       num=num/10;
       i++;
    }
cout<<sum;
}
int main(int argc, char const *argv[])
{binary b;
b.read();
b.chk_binary();
b.decimal();   
    return 0;
}
