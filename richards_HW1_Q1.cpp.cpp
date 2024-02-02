#include <iostream>

using namespace std;

// should this have been located somewhere else or was this fine?
const int N = 5;

// Create check struct
struct Check{

    int CheckNum;
    string CheckMemo;
    float CheckAmount;
};

// Create checkbook class
class CheckBook{

public:

    //initialize variables
    float balance, lastDeposit;
    Check checkArray[N];
    int numOfChecks;

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
            cout << "\nCheck " << checkArray[i].CheckNum +1 << endl; // the +1 is just for readability because Check 0 sounds dumb
            cout << "Memo: " << checkArray[i].CheckMemo << endl;
            cout << "Amount: " << checkArray[i].CheckAmount << endl;
        }
    }

    // write check function
    bool writeCheck(float amount){
        if(amount <= balance){
                checkArray[numOfChecks].CheckAmount = amount;
                checkArray[numOfChecks].CheckNum = numOfChecks;
                checkArray[numOfChecks].CheckMemo = "For the purposes of testing checks!";

                balance -= amount;
                numOfChecks += 1;
        }else{
            return false;
        }
    }

};

int main(){
    CheckBook cb1; // create checkbook constructor

    cb1.deposit(500); // deposit 500

    // test checks
    cb1.writeCheck(30);
    cb1.writeCheck(60);
    cb1.writeCheck(100);

    // print all checks
    cb1.displayChecks();
}
