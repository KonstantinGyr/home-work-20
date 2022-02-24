#include <iostream>
#include <fstream>

int main() {
    std::ifstream river;
    std::ofstream basket;
    std::string rivAddr;
    std::string baskAddr;
    do{
        std::cout<<"Input address river :";
        std::cin>>rivAddr;
        river.open(rivAddr);
        if(!river.is_open()) {
            std::cout << "Wrong address."<<std::endl;
        }
    }while(!river.is_open());
    do{
        std::cout<<"Input address basket :";
        std::cin>>baskAddr;
        basket.open(baskAddr,std::ios::app);
        if(!basket.is_open()) {
            std::cout << "Wrong address."<<std::endl;
        }
    }while(!basket.is_open());
    std::string fish;
    std::string fish_inRiv;
    int n=0;
    do {
        std::cout << "Input name of fish :";
        std::cin >> fish;
        river.seekg(0);
        while (!river.eof()) {
         river>>fish_inRiv ;
         if(fish_inRiv==fish){
             basket<<fish_inRiv<<std::endl;
             n++;
             std::cout<<"You caught "<<fish<<std::endl;
         }
        }
    }while(fish!="stop");
    std::cout<<"Ñaught fish : "<<n;
    return 0;
}
