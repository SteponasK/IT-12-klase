#include <iostream>
#include <fstream>
#include <vector>
std::string skaiciuoti(int R, int G, int B) {
    int dec_num[6];
    dec_num[0] = R / 16; // surandam reiksmes pagal taisykle (salygoje)
    dec_num[1] = R % 16;
    dec_num[2] = G / 16;
    dec_num[3] = G % 16;
    dec_num[4] = B / 16;
    dec_num[5] = B % 16;

    char hex_num[6];
    std::string hex_chars = "0123456789ABCDEF"; // sukuriame visu sesioliktainiu skaitmenu stringa

    for (int i = 0; i < 6; ++i)
        hex_num[i] = hex_chars[dec_num[i]]; // pakeiciame is desimtainio i sesioliktaini skaiciu

    std::string skaicius(hex_num, 6); // sukuriame skaiciu is sesioliktainiu skaiciu masyvo
    return skaicius;
}
int main()
{
    int a;
    int b;
    std::ifstream fin;
    fin.open("U1.txt");
    fin >> a >> b;
    std::vector<std::string> skaiciai;
    for (int i = 0; i < a*b; ++i) // einam pro visa U1.txt faila
    {
        int R;
        int G;
        int B;
        fin >> R >> G >> B;
        std::string skaicius = skaiciuoti(R, G, B); // perskaiciuojam i sesioliktaini
        skaiciai.push_back(skaicius); // push_backinam ant skaiciu vektoriaus
    }

    std::ofstream fout;
    fout.open("U1rez.txt");
    for (int i = 0; i < a*b; ++i) // einam pro visus skaicius
    {
        if(i%b == 0 && i != 0) fout << std::endl; // spausdinam newline eilutes gale
        fout << skaiciai[i];
        if((i+1)%b != 0) fout << ';'; // spausdinam ; jeigu nepaskutinis skaicius

    }
    return 0;
}
