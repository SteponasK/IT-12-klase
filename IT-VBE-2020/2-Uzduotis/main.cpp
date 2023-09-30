#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Zvejys
{
    std::string vardas{};
    int zuvu_skaicius{};
    std::vector<std::string> zuvies_vardas{};
    std::vector<int> zuvies_mase{};
    int taskai{};

};

struct Zuvis
{
    std::string vardas;
    int taskai{};
    int bendra_mase{};

};
void rikiuoti_sarasa(Zuvis zuvis[], int zuvu_skaicius, Zvejys zvejys[], int n);
int main()
{
    std::ifstream fin;
    fin.open("U2.txt");
    int n{};// zveju skaicius
    fin >> n;
    Zvejys zvejys[n];
    std::string temp{};
    std::getline(fin, temp); // perskaitome tuscia linija, kuri atsirado nuskaicius n kintamaji
    for(int i = 0; i < n; ++i)
    {
        std::string vardas{};
        std::getline(fin, vardas); // paemame texto linija
        int zuvu_skaicius = stoi(vardas.substr(21)); // surandame skaiciu (jis bus nuo 21 characterio)
        vardas.erase(vardas.begin()+20, vardas.end()); //  istrinam skaicius is vardo string
        zvejys[i].vardas = vardas;
        zvejys[i].zuvu_skaicius = zuvu_skaicius;
        for(int j = 0; j < zvejys[i].zuvu_skaicius; ++j)
        {
            std::string zuvies_vardas{};
            std::getline(fin, zuvies_vardas);
            std::string zuvies_mase = zuvies_vardas.substr(21);
            zvejys[i].zuvies_mase.push_back( stoi(zuvies_mase) );
            zuvies_vardas.erase(zuvies_vardas.begin()+20, zuvies_vardas.end());
            zvejys[i].zuvies_vardas.push_back( zuvies_vardas );

        }
    }
    int zuvu_skaicius;
    fin >> zuvu_skaicius;
    Zuvis zuvis[zuvu_skaicius];
    std::string temp2; // nuskaitom tuscia linija, kuri atsirado nuskaicius zuvu_skaicius kintamaji
    std::getline(fin, temp2);
    for(int i = 0; i < zuvu_skaicius; ++i)
    {
        std::string vardas{};
        std::getline(fin, vardas); // paemam visa line texto
        std::string taskai = vardas.substr(21);
        vardas.erase(vardas.begin()+20, vardas.end());
        zuvis[i].vardas = vardas;
        zuvis[i].taskai = stoi(taskai);
    }

    for(int i = 0; i < n; ++i) // einam pro kiekviena zveji
    {
        for(int j = 0; j < zvejys[i].zuvies_vardas.size(); ++j) // einam pro zvejo zuvis
        {
            for(int k = 0; k < zuvu_skaicius; ++k)
            { // skaiciuojam taskus
                if(zuvis[k].vardas.compare(zvejys[i].zuvies_vardas[j]) == 0)
                {
                    if(zvejys[i].zuvies_mase[j] >= 200)
                    {
                        zvejys[i].taskai+=30;
                    }
                    else
                    {
                        zvejys[i].taskai+=10;
                    }
                    zvejys[i].taskai+=zuvis[k].taskai;
                    zuvis[k].bendra_mase+=zvejys[i].zuvies_mase[j];
                }
            }

        }
    }
    rikiuoti_sarasa(zuvis, zuvu_skaicius, zvejys, n); // surikuojam abudu sarasus

    std::ofstream fout;
    fout.open("U2rez.txt");
    fout << "Dalyviai" << std::endl;
    for(int i = 0; i < n; ++i)
    {
        fout << zvejys[i].vardas << ' '<< zvejys[i].taskai << std::endl;
    }
    fout << "Laimikis" << std::endl;
    for(int i = 0; i < zuvu_skaicius; ++i)
    {
        fout << zuvis[i].vardas << ' '<< zuvis[i].bendra_mase << std::endl;
    }

    return 0;
}
void rikiuoti_sarasa(Zuvis zuvis[], int zuvu_skaicius, Zvejys zvejys[], int n)
{ // Bubble sort
    for(int i = 0; i < zuvu_skaicius; ++i)
    {
        for(int j = 0; j < zuvu_skaicius-1; ++j)
        {
            if(zuvis[j].bendra_mase < zuvis[j+1].bendra_mase)
            {
                std::swap(zuvis[j], zuvis[j+1]);
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n-1; ++j)
        {
            if(zvejys[j].taskai < zvejys[j+1].taskai)
            {
                std::swap(zvejys[j], zvejys[j+1]);
            }
        }
    }
}
