//2 uzduotis. Marsaeigis
#include <iostream>
#include <fstream>
#include <iomanip>

struct Marsaeigis{
    int x{}; // dabartinis x ir y
    int y{};
    int komandu_skaicius{}; // max komandu (judesiu) skaicius
    int komandos_padarytos{}; // kiek veiksmu jau padareme
    int seka[30]{}; // saugome komandu, kurias padareme duomenis
    std::string stabdymo_priezastis{};
};

int main()
{
    std::ifstream fin;
    fin.open("U2.txt");

    int x0{}; // pradines koordinates
    int y0{};

    int x1{}; // tikslo koordinates
    int y1{};

    int n{}; // eiluciu (skirtingu seku) skaicius

    fin >> x0 >> y0 >> x1 >> y1 >> n; // pradiniai duomenys

    Marsaeigis marsaeigis[n]; // sukuriame n marsaeigiu

    for(int i = 0; i < n; ++i) // einam pro kiekviena marsaeigi
    {
        fin >> marsaeigis[n].komandu_skaicius;
        marsaeigis[i].x = x0;
        marsaeigis[i].y = y0;

        for(int j = 0; j < marsaeigis[n].komandu_skaicius; ++j) // einam pro kiekviena marsaeigio[n] komanda
        {
            int komanda{};
            fin >> komanda;
            switch(komanda) // papildom seku masyva duomenimis, pakeiciame koordinates, padidiname padarytu komandu skaiciu
            {
                case 1:
                    ++(marsaeigis[i].y);
                    ++(marsaeigis[i].komandos_padarytos);
                    marsaeigis[i].seka[j] = komanda;
                    break;
                case 2:
                    ++(marsaeigis[i].x);
                    ++(marsaeigis[i].komandos_padarytos);
                    marsaeigis[i].seka[j] = komanda;
                    break;
                case 3:
                    --(marsaeigis[i].y);
                    ++(marsaeigis[i].komandos_padarytos);
                    marsaeigis[i].seka[j] = komanda;
                    break;
                case 4:
                    --(marsaeigis[i].x);
                    ++(marsaeigis[i].komandos_padarytos);
                    marsaeigis[i].seka[j] = komanda;
                    break;
            }
            if( (x1 == marsaeigis[i].x) && (y1 == marsaeigis[i].y) ) // jeigu pasiekeme tiksla
            {
                marsaeigis[i].stabdymo_priezastis = "pasiektas tikslas";
                break;
            }
            else if(marsaeigis[i].komandu_skaicius == marsaeigis[n].komandos_padarytos) // jeigu nespejome pasiekti tikslo
            {
                marsaeigis[i].stabdymo_priezastis = "sekos pabaiga";
            }
        }
    }
    std::ofstream fout;
    fout.open("U2rez.txt");

    for(int i = 0; i < n; ++i) // einam pro kiekviena marsaeigi
        {
            fout << std::setw(20) << std::left <<marsaeigis[i].stabdymo_priezastis; // spausdiname marsaeigio[i] stabdymo priezasti
            for(int j = 0; j < marsaeigis[i].komandos_padarytos; ++j)
                {
                    fout << marsaeigis[i].seka[j]; //spausdiname marsaeigio[i] visa seka (kaip jis judejo)
                }
            fout << " " << marsaeigis[i].komandos_padarytos << '\n'; // spausdiname kiek komandu atliko marsaeigis[i]
        }

    return 0;
}
