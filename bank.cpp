#include<iostream>
#include<string>
using namespace std;

class Bank{
    private:
        string *name;
        string *address;
        float *amount;
        int *account_number;
    public:
        Bank(){
            name = new string;
            address = new string;
            amount = new float;
            account_number = new int;
        }
        void create_account();
        void withdraw_money();
        void deposit_money();
        void showDetails();
        int search(int account_number);
};

void Bank::create_account(){
    cout<<"Enter your account number :: "<<endl;
    cin>>*account_number;
    cout<<"Enter your name :: "<<endl;
    cin.ignore();
    getline(cin,*name);
    cout<<"Enter your Address :: "<<endl;
    getline(cin,*address);
    cout<<"Enter your amount :: "<<endl;
    cin>>*amount;
    cout<<"Account is Created successfully.";
}

void Bank :: withdraw_money(){
    float newMoney;
    cout<<"Enter Amount :: "<<endl;
    cin>>newMoney;
    if (newMoney <= *amount)
    {
        *amount -=  newMoney;
        cout<<"Amount withdraw successfully."<<endl;
        cout<<"Now your total Amount is :: "<<*amount;
    }else{
        cout<<"Your total is low can't withdraw now ::"<<endl;
    }

}

void Bank::deposit_money(){
    float newMoney;
    cout<<"Enter Amount :: "<<endl;
    cin>>newMoney;
    if(newMoney >= 0){
            cout<<"Amount Deposit Successfully."<<endl;
            *amount += newMoney;
    }else{
        cout<<"Can't deposit money"<<endl;
    }
}

void Bank :: showDetails(){
    cout<<"Account_number :: "<<*account_number<<endl;
    cout<<"Customer's name :: "<<*name<<endl;
    cout<<"Customer's Address :: "<<*address<<endl;   
}

int Bank :: search(int number){
    if(*account_number == number){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    Bank *B[20];
    int i=0,choice,number;
    while (1)
    {
        system("cls");
        cout<<"\n========================\n";
        cout<<" Bank Management System"; 
        cout<<"\n========================\n";
        cout<<"\n1.Create a new Account."<<endl;
        cout<<"\n2.Withdraw Money."<<endl;
        cout<<"\n3. Deposit Money."<<endl;
        cout<<"\n4. Display Detail."<<endl;
        cout<<"\n5. Exit()."<<endl;  
        cout<<"Please Enter your choice :: "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            B[i] = new Bank;
            B[i]->create_account();
            i++;
            break;
        case 2: 
            cout<<"Enter your account_number :: "<<endl;
            cin>>number;
            for (int t = 0; t < i; t++)
            {
                if (B[t]->search(number))
                {
                    B[t]->withdraw_money();
                }else{
                    cout<<"Invalid Account_number or account doeasn't exist"<<endl;
                }                  
            }
            break;
        case 3: 
            cout<<"Enter your accout_number :: "<<endl;
            cin>>number;   
            for (int t = 0; t < i; t++)
            {
                if (B[t]->search(number))
                {
                    B[t]->deposit_money();
                }else{
                    cout<<"Invalid Account_number or account doeasn't exist"<<endl;
                }     
            }
            break;
        case 4:
            cout<<"Enter your account_number :: "<<endl;
            cin>>number;
            for (int t = 0; t < i; t++)
            {
                if (B[t]->search(number))
                {
                    B[t]->showDetails();
                }else{
                    cout<<"Invalid Account_number or account doeasn't exist"<<endl;
                }     
            } 
            break;  
        case 5:
                exit(0);
                break;
        default:
            cout<<"Invalid choice";
            break;
        }
        cout<<endl;
        cout<<endl;
        cin.ignore();
        cin.get();
    }
    return 0;
}