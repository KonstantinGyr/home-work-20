#include <iostream>
#include <fstream>
#include <ctime>

int main() {
    int h,w;
    std::srand(std::time(nullptr));
    std::ofstream pic;
    std::string address;
    do{
        std::cout<<"Input address :";
        std::cin>>address;
        pic.open(address);
        if(!pic.is_open()) {
            std::cout << "Wrong address.";
        }
    }while(!pic.is_open());
    std::cout << "Input height picture :";
    std::cin>>h;
    std::cout << "Input wight picture :";
    std::cin>>w;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
               pic<<rand() %2<<" ";
            }
            pic<<std::endl;
        }
        pic.close();
    return 0;
}
