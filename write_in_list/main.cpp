#include <iostream>
#include <fstream>
#include <string>

bool okDate(const std::string& date){
    int year = std::stoi(date.substr(6, 4));
    int month = std::stoi(date.substr(3, 2));
    int day = std::stoi(date.substr(0, 2));
    if (year < 2000 || year > 2022)return false;
    if (month < 1 || month > 12)return false;
    if (day < 0 || day > 31)return false;
    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))return false;
    if (day > 28 && month == 2 && year % 4 != 0)return false;
    if (day > 29 && month == 2 && year % 4 == 0)return false;
    return true;
    }

int main() {
    int salary;
    std::string date;
    std::string firstName;
    std::string secondName;
    std::string address;
    std::ofstream list;
    do{
        std::cout<<"Input file address: ";
        std::cin>>address;
        list.open(address,std::ios::app);
        if(!list.is_open()){
            std::cout<<"Wrong address"<<std::endl;
        }
    }while(!list.is_open());
    while(firstName!="stop"){
        std::cout << "Input first name :" << std::endl;
        std::cin>>firstName;
        if(firstName=="stop")break;
        list<<firstName<<" ";
        std::cout << "Input second name :" << std::endl;
        std::cin>>secondName;
        list<<secondName<<" : ";
        do {
            std::cout << "Input data :";
            std::cin >> date;
            if (!okDate(date)) {
                std::cout << "Wrong date!" << std::endl;
            }

        }while(!okDate(date));
        list<<date<<" ";
        std::cout<<"Input sum :";
        std::cin>>salary;
        list<<salary<<" rub."<<std::endl;
    }
    list.close();
    return 0;
}
