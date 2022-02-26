#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>


void sort(std::vector<int>&vec){
    for(int i=0; i < vec.size(); i++){
        int maxInd=i;
        for(int j=i+1; j < vec.size(); j++) {
            if (vec[j] > vec[maxInd]) {
                maxInd = j;
            }
        }
        std::swap(vec[i], vec[maxInd]);
    }
}
    void fill(){
        std::vector<int>vec;
        std::string address;
        std::ofstream bank;
        do {
            std::cout << "Input bank address :";
            std::cin >> address;
            bank.open(address);
            if(!bank.is_open()){
                std::cout << "Wrong address :";
            }
        }while(!bank.is_open());
        std::srand(std::time(nullptr));
        for (int i = 0; i < 1000; i++) {
            int n = rand() % 6;
            if (n == 0)vec.push_back(100);
            else if (n == 1)vec.push_back(200);
            else if (n == 2)vec.push_back(500);
            else if (n == 3)vec.push_back(1000);
            else if (n == 4)vec.push_back(2000);
            else if (n == 5)vec.push_back(5000);
        }
        sort(vec);
        for(int i=0; i < vec.size(); i++){
              bank << vec[i];
              if((i+1)>=20&&(i+1)%20==0&&i+1 != vec.size()){
                  bank<<std::endl;
              }
              else if(i+1 != vec.size()){
                  bank<<" ";
              }
        }
    bank.close();
    }
void availability(std::vector<int>&atm,std::string &address) {
    std::ifstream bank;
    bank.open(address);
    while (!bank.is_open()) {
        std::cout << "Wrong address :"<<std::endl;
        std::cout << "Input bank address :";
        std::cin >> address;
        bank.open(address);
    }
    int money;
     do{
        bank >> money;
        atm.push_back(money);
        if(bank.eof())break;
    }while (!bank.eof());
    bank.close();
}
bool extract(std::vector<int>&atm,int money){
    int sum=0;
    for(int i=0;i<atm.size();i++) {
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
void exchange (std::vector<int>&atm,std::string address){
    std::ofstream bank;
    bank.open(address);
    for(int i=0;i<atm.size();i++){
        bank<<atm[i];
        if((i+1)>=20&&(i+1)%20==0&&i+1!=atm.size()){
            bank<<std::endl;
        }
        else if(i+1!=atm.size()){
            bank<<" ";
        }
    }
    bank.close();
}
int main() {
    std::vector<int>atm;
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
        std::cout << "Input bank address :";
        std::cin >> address;
        availability(atm,address);
    }
    std::cout <<"How much money do you want ? :";
    std::cin>>money;
    if(extract(atm,money)){
        std::cout<<"Money issued.";
        exchange(atm,address);
    } else{
        std::cout<<"This operation is not possible!";
    }
    return 0;
}