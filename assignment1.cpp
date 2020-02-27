#include <iostream>
#include <string>
#include "picosha2.h"

using namespace std;
using namespace picosha2;

class transaction {
    public:
        string payer;
        string payee;
        int amount;
};

class block {
    public:
        transaction t[5];
        char prev_hash[256];
        char cur_hash[256];
};

//initiates blockchain
string init_blockchain(){
    cout<< "Hello and welcome to Abhimanyu's cryptocoin :-)"<<endl;
    block curr;
    string hash_input, prev_hash;
    cout<< "please enter initial hash"<<endl;
    cin>>prev_hash;
    hash_input = prev_hash;
    string hash_hex_temp;
    for(int i=0;i<5;i++){
        cout<< "Please enter Payer string for transaction "<<i+1<<endl;
        cin>> curr.t[i].payer;
        
        hash256_hex_string(curr.t[i].payer, hash_hex_temp);
        hash_input += hash_hex_temp; 

        cout<< "Please enter Payee string for transaction "<<i+1<<endl;
        cin>> curr.t[i].payee;
        
        hash256_hex_string(curr.t[i].payee, hash_hex_temp);
        hash_input += hash_hex_temp; 

        cout<< "please enter amount to be transacted for transaction"<<i+1<<endl;
        cin>>curr.t[i].amount;
        hash_input += to_string(curr.t[i].amount); 
    }
    string curr_hash;
    hash256_hex_string(hash_input, curr_hash);
    return curr_hash;
}

int main()
{
    cout<< init_blockchain();
}