#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Salis
{
    std::string salis1;
    //int gauti_taskai = 0;
    std::string salis2;
    int salis2taskai;
    bool uzpildyta = false;
};
struct Salies_Rezultatai
{
    std::string vardas;
    int taskai;
};
std::vector<Salis> salis(2500);
std::ifstream fin;
int size = 2500;
void skaityti()
{
    fin.open("Eurovizija.csv");

    std::string salis1;
    std::string salis2;
    std::string taskai;

    int count = 0;
    while(std::getline(fin, salis1, ';')){
        std::getline(fin, salis2, ';');
        std::getline(fin , taskai);
        int taskai_int = stoi(taskai);
         salis[count].salis1 = salis1;
         salis[count].salis2 = salis2;
         salis[count].salis2taskai = taskai_int;
         salis[count].uzpildyta = true;
        ++count;
    }
    for(int i = 0; i < salis.size(); ++i){
            if(!salis[i].uzpildyta){
                size = i;
                break;
            }
        }
}
bool palyginti(Salis& a, Salis& b)
{
    if(a.salis1 != b.salis1)
        return a.salis1 < b.salis1;

    return a.salis2taskai > b.salis2taskai;
}
void rikiuoti()
{
    std::sort(salis.begin(), salis.begin() + size, palyginti);

}
std::vector<Salies_Rezultatai> salies_rez;
void papildyti()
{


    for(int i = 0; i < size; ++i)
    {
        if() // cia padaryt logika
    struct Salies_Rezultatai tempRez;
    tempRez.taskai = salis[i].salis2taskai;
    tempRez.vardas  = salis[i].salis2;
    salies_rez.push_back(tempRez);
    }
}
int main()
{
    skaityti();
    rikiuoti();
    for(int i = 0; i < size; ++i)
    {
        std::cout << salis[i].salis1 << ' ' <<
        salis[i].salis2 << ' ' << salis[i].salis2taskai << '\n';
    }
    /*std::cout << salis[0].salis1 << ' ' <<
        salis[0].salis2 << ' ' << salis[0].salis2taskai << '\n';*/
    std::cout << "size : " << size;
    return 0;
}
