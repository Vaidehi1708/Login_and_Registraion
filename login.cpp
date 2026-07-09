#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
 
vector<string> unames; //stores all usernames
vector<string> passwords; //stores all passwords
 
void load()
{
    ifstream f("users.txt");
    string a,b;
 
    while(f>>a>>b)
    {
        unames.push_back(a);
        passwords.push_back(b);
    }
 
    f.close();
}
 
int checkuser(string name)
{
    for(int i=0;i<unames.size();i++)
    {
        if(unames[i]==name)
            return 1;
    }
    return 0;
}
 
void reg()
{
    string name,pass;
    cout<<"Enter username : ";
    cin>>name;
 
    if(checkuser(name)==1)
    {
        cout<<"username already exist, try different one"<<endl;
        return;
    }
 
    cout<<"Enter password : ";
    cin>>pass;
 
    unames.push_back(name);
    passwords.push_back(pass);
 
    ofstream f("users.txt",ios::app);
    f<<name<<" "<<pass<<endl;
    f.close();
 
    cout<<"Registered successfully"<<endl;
}
 
void login()
{
    string name,pass;
    cout<<"Enter username : ";
    cin>>name;
    cout<<"Enter password : ";
    cin>>pass;
 
    for(int i=0;i<unames.size();i++)
    {
        if(unames[i]==name)
        {
            if(passwords[i]==pass)
            {
                cout<<"Login success, welcome "<<name<<endl;
                return;
            }
            else
            {
                cout<<"wrong password"<<endl;
                return;
            }
        }
    }
 
    cout<<"user not found"<<endl;
}
 
int main()
{
    load(); //load old users from file first
 
    int ch;
 
    while(1)
    {
        cout<<endl;
        cout<<"1.Register"<<endl;
        cout<<"2.Login"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"enter choice : ";
        cin>>ch;
 
        if(ch==1)
        {
            reg();
        }
        else if(ch==2)
        {
            login();
        }
        else if(ch==3)
        {
            break;
        }
        else
        {
            cout<<"wrong choice"<<endl;
        }
    }
 
    cout<<"program ended"<<endl;
 
    return 0;
}