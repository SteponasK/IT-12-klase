#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
void getData();
void getDarzoves();
void getParduotuves();
void getLowestPrices();
bool printSum();
void surastiPrintEilutes();
void surikiuotiPrintEilutes();
void printEilutesFNC();
 int p{}; // darzoviu skaicius
 int s{};// pinigu suma
 float sum = 0; // pigiausiu prekiu suma
 std::ifstream fin;
 std::ofstream fout;
 struct Parduotuve{
     std::string pavadinimas{};
     std::vector<float> darzoves_kaina{};
 };
 std::vector<Parduotuve> parduotuves;
 std::vector<std::string> darzoves_pavadinimai{};
 std::vector<float> maziausios_kainos{};
int main()
{
    getData();
    getLowestPrices();
    fout.open("U2.txt");
    if(!printSum()) return 0;
    surastiPrintEilutes();
    surikiuotiPrintEilutes();
    printEilutesFNC();
    return 0;
}
void getData(){
   fin.open("U1.txt");
    fin >> p;
    fin >> s;
    getDarzoves();
    getParduotuves();
}
void getParduotuves(){
    for(int i = 0; i < 5; ++i){
        std::string temp{}; // gaunam parduotuves pavadinima
        fin >> temp;
        Parduotuve temp_parduotuve;
        temp_parduotuve.pavadinimas = temp;
        for (int j = 0; j < p; ++j){
            float temp_kaina{};
            fin >> temp_kaina;
            temp_parduotuve.darzoves_kaina.push_back(temp_kaina);
        }
        parduotuves.push_back(temp_parduotuve);
    }
}
void getDarzoves(){
    for (int i = 0; i < p; ++i){
        std::string temp{};
        fin >> temp;
        darzoves_pavadinimai.push_back(temp);
    }
}
void getLowestPrices(){
    // jeigu kaina 0, tada nera parduotuveje

    for(int i = 0; i < p; ++i){ // einame pro kiekviena darzove
            float min_kaina  = s+1; // virs biudzeto
       for(int j = 0; j < 5; ++j){ // einame pro parduotuve
            if (parduotuves[j].darzoves_kaina[i] < min_kaina
                &&  parduotuves[j].darzoves_kaina[i] != 0){
                    min_kaina = parduotuves[j].darzoves_kaina[i];
                }
        }
        maziausios_kainos.push_back(min_kaina);
    }
    for(int i = 0; i < p; ++i){
        sum+= maziausios_kainos[i];
    }
}
bool printSum(){
    if(sum > s){
        std::cout << "Nepavyks nusipirkti";// EDGE CASE DAUGIAU KAINA
        return false;
    }
    fout << sum << std::endl;
    return true;

}
std::vector<std::vector<std::string>> printEilutes;

void surastiPrintEilutes(){
    for (int i = 0; i < 5; ++i){
            bool cheap = false;
            std::vector<std::string> cheapest_darzoves;
        for (int j = 0; j < p; ++j){
            if(parduotuves[i].darzoves_kaina[j]
                == maziausios_kainos[j]){
                    if(!cheap)
                    {
                        cheapest_darzoves.push_back(parduotuves[i].pavadinimas);
                    }
                    cheap = true;
                    cheapest_darzoves.push_back(darzoves_pavadinimai[j]);
                }
        }
    if (cheap){
            printEilutes.push_back(cheapest_darzoves);
        }
    }
}
bool compare(std::vector<std::string>& vec1, std::vector<std::string>& vec2){
    return vec1.size() > vec2.size();
}
void surikiuotiPrintEilutes(){
    std::sort(printEilutes.begin(), printEilutes.end(), compare);
}
void printEilutesFNC(){
    for(const auto& eilute: printEilutes){
        for(const auto& zodis: eilute){
            fout << zodis;
            if(zodis.length() < 10){
                int truksta = 10- zodis.length();
                while(truksta){
                    fout << ' ';
                    --truksta;
                }
            }
        }
        fout << std::endl;
    }
}
