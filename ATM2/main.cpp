#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void sort(int (&arr)[100]){
    for(int i=0; i < 100; i++){
        int maxInd=i;
        for(int j=i+1; j < 100; j++) {
            if (arr[j] > arr[maxInd]) {
                maxInd = j;
            }
        }
        std::swap(arr[i], arr[maxInd]);
    }
}

void fill(){
    int banknote[6]={100,200,500,1000,2000,5000};
   int arr[100];
    std::ofstream bank;
    for(int i=0;i<100;i++){
       arr[i]=banknote[rand() % 6];
    }
    sort(arr);
    bank.open("bank.bin",std::ios::binary);
    bank.write((char*)arr, sizeof (arr));
    bank.close();
}
void availability(int (&atm)[100]) {
    std::ifstream bank;
    bank.open("bank.bin",std::ios::binary);
    bank.read((char*)atm, sizeof (atm));
    bank.close();
}
bool extract(int (&atm)[100],int money){
    int sum=0;
    for(int i=0;i<100;i++) {
        if(atm[i]==0)continue;
        if (money-sum >= atm[i]) {
            sum+= atm[i];
            atm[i] = 0;
            if(money==sum){
                std::cout <<sum<<" ";
                return true;
            }
        }
    }
    return false;
}
void exchange (int (&atm)[100]){
    std::ofstream bank;
    bank.open("bank.bin",std::ios::binary);
    bank.write((char*)atm, sizeof (atm));
    bank.close();
}
int main() {
    int atm[100];
    char sign;
    int money;
    std::string address;
    std::cout << "Enter operation type :";
    std::cin>>sign;
    if(sign=='+'){
        fill();
        return 0;
    }
    else if(sign=='-'){
        availability(atm);
    } else return 0;
    std::cout <<"How much money do you want ? :";
    std::cin>>money;
    if(extract(atm,money)){
        std::cout<<"Money issued.";
        exchange(atm);
    } else{
        std::cout<<"This operation is not possible!";
    }
    return 0;
}
