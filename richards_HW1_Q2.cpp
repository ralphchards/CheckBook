#include <iostream>

using namespace std;

// should this have been located somewhere else or was this fine?
const int N = 5;

// Create check class
class Check{
    int CheckNum;
    string CheckMemo;
    float CheckAmount;

public:
    Check(): CheckNum(0), CheckMemo(""), CheckAmount(0){
    }

    int getNum(){
        return CheckNum;
    }
    string getMemo(){
        return CheckMemo;
    }
    float getAmount(){
        return CheckAmount;
    }

    void setNum(int x){
        CheckNum = x;
    }
    void setMemo(string x){
        CheckMemo = x;
    }
    void setAmount(float x){
        CheckAmount = x;
    }
};

// Create checkbook class
class CheckBook{
public:

    static int allChecks;

    //initialize variables
    float balance, lastDeposit;
    Check checkArray[N];
    int numOfChecks;

    int getAllChecks(){
       return allChecks;
    }

    // Constructors to create with either 0 or a desired balance
    CheckBook(): balance(0), numOfChecks(0) {}
    CheckBook(float balance_amount): balance(balance_amount), numOfChecks(0) {}

    // deposit function to add to balance
    void deposit(float amount){
        balance += amount;
    }

    // display all checks
    void displayChecks(){
        for(int i = numOfChecks-1; i >= 0; i--){
            cout << "\nCheck " << checkArray[i].getNum() + 1 << endl; // the +1 is just for readability because Check 0 sounds dumb
            cout << "Memo: " << checkArray[i].getMemo() << endl;
            cout << "Amount: " << checkArray[i].getAmount() << endl;
        }
    }

    // write check function
    bool writeCheck(float amount){
        if(amount <= balance && numOfChecks < N && allChecks < 10){
                checkArray[numOfChecks].setAmount(amount);
                checkArray[numOfChecks].setNum(numOfChecks);

                cout << "memo?: " << endl;
                string memoinput;
                cin >> memoinput;
                checkArray[numOfChecks].setMemo(memoinput);

                balance -= amount;

                allChecks +=1;
                numOfChecks += 1;
        }else{
            return false;
        }
    }

};

int CheckBook::allChecks = 0; // I cant get anything to run without doing this and it's making me insane trying different things but I figure this is
                             //wrong since it doesnt say to do this in the homework?

int main(){
    CheckBook cb1(1000), cb2(500); // create checkbook constructors

    // test checks
    for(int i=0;i<10;i++){
    cb1.writeCheck(150);
    cb2.writeCheck(130);
    }

    // print all checks
    cout<<"\nCB1 Checks"<<endl;
    cb1.displayChecks();
    cout<<"\nCB2 Checks"<<endl;
    cb2.displayChecks();
    cout<<"\n" << cb1.getAllChecks()<<endl;
    cout<<cb2.getAllChecks()<<endl;
}
