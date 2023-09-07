#include <iostream>
#include <fstream> // std::ifstream std::ofstream
#include <vector> // std::vector
#include <iomanip> // std::fixed std::setprecision

void skaitytiFaila(unsigned int &n, std::vector <int> &sveikieji, std::vector <double> &realieji);
void rasytiFaila(std::ofstream &failasOUT, const int zs, const double kk);
int main()
{
    std::vector <int> sveikieji{};
    std::vector <double> realieji{};
    unsigned int n{}; // Seimu (eiluciu) skaicius
    skaitytiFaila(n, sveikieji, realieji); // Nuskaitome duomenis is failo

    std::ofstream failasOUT;
    failasOUT.open("Rezultatai.txt");

    for (size_t i = 0; i < n*2; i+=2){
        int s = sveikieji.at(i); // Suaugusiuju skaicius
        int v = sveikieji.at(i + 1); // Vaiku skaicius
        double sk = realieji.at(i); // Suaugusiojo bilieto kaina
        double vk = realieji.at(i + 1); // Vaiko bilieto kaina

        int zs = s + v; // Seimos nariu skaicius
        double kk = (static_cast<double>(s) * sk) + (static_cast<double>(v) * vk); // Keliones islaidos
        rasytiFaila(failasOUT, zs, kk); // Irasome duomenis i faila
    }
    return 0;
}
void skaitytiFaila(unsigned int &n, std::vector <int> &sveikieji, std::vector <double> &realieji) {
    std::ifstream failasIN;
    failasIN.open("Duomenys.txt");
    failasIN >> n; // Eiluciu skaicius

    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < 4; j++) { // 4 reiksmes eiluteje
            if (j < 2) { // Pirmas dvi reiksmes irasome i sveikuju skaiciu masyva
                int temp{};
                failasIN >> temp;
                sveikieji.push_back(temp);
            }
            else { // Dvi paskutines irasome i realiuju skaiciu masyva
                double temp{};
                failasIN >> temp;
                realieji.push_back(temp);
                std::cout << temp << std::endl;
            }
        }
    }
}
void rasytiFaila(std::ofstream &failasOUT, const int zs, const double kk) {
    failasOUT << zs << ' ' << std::fixed << std::setprecision(2) << kk << '\n'; // Irasome eilute i faila
}

