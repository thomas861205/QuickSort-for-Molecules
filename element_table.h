#define H   1.00
#define He  4.00
#define Li  7.00
#define Be  9.00
#define B   11.00
#define C   12.00
#define N   14.00
#define O   16.00
#define F   19.00
#define Ne  20.00
#define Na  23.00
#define Mg  24.00
#define Al  27.00
#define Si  28.00
#define P   31.00
#define S   32.00
#define Cl  35.00
#define K   39.00
#define Ar  40.00
#define Ca  40.00
#define Sc  45.00
#define Ti  48.00
#define V   51.00
#define Cr  52.00
#define Mn  55.00
#define Fe  56.00
#define Co  59.00
#define Ni  59.00
#define Cu  64.00
#define Zn  65.00
#define Ga  70.00
#define Ge  73.00
#define As  75.00
#define Se  79.00
#define Br  80.00
#define Kr  84.00
#define Rb  85.00
#define Sr  88.00
#define Y   89.00
#define Zr  91.00
#define Nb  93.00
#define Mo  96.00
#define Tc  97.00
#define Ru  101.00
#define Rh  103.00
#define Pd  106.00
#define Ag  108.00
#define Cd  112.00
#define In  115.00
#define Sn  119.00
#define Sb  122.00
#define Te  128.00
#define I   127.00
#define Xe  131.00
#define Cs  133.00
#define Ba  137.00
#define La  139.00
#define Ce  140.00
#define Pr  141.00
#define Nd  144.00
#define Pm  145.00
#define Sm  150.00
#define Eu  152.00
#define Gd  157.00
#define Tb  159.00
#define Dy  163.00
#define Ho  165.00
#define Er  167.00
#define Tm  169.00
#define Yb  173.00
#define Lu  175.00
#define Hf  178.00
#define Ta  181.00
#define W   184.00
#define Re  186.00
#define Os  190.00
#define Ir  192.00
#define Pt  195.00
#define Au  197.00
#define Hg  201.00
#define Tl  204.00
#define Pb  207.00
#define Bi  209.00
#define Po  209.00
#define At  210.00
#define Rn  222.00
#define Fr  223.00
#define Ra  226.00
#define Ac  227.00
#define Th  232.00
#define Pa  231.00
#define U   238.00
#define Np  237.00
#define Pu  244.00
#define Am  243.00
#define Cm  247.00
#define Bk  247.00
#define Cf  251.00
#define Es  252.00
#define Fm  257.00
#define Md  258.00
#define No  259.00
#define Lr  262.00
#define Rf  267.00
#define Db  270.00
#define Sg  269.00
#define Bh  270.00
#define Hs  270.00
#define Mt  278.00
#define Ds  281.00
#define Rg  281.00
#define Cn  285.00
#define Nh  286.00
#define Fl  289.00
#define Mc  289.00
#define Lv  293.00
#define Ts  293.00
#define Og  294.00

#include <map>
#include <string>

using namespace std;

map<string, double> elementTable = {
    {"H", 1.00},
    {"He", 4.00},
    {"Li", 7.00},
    {"Be", 9.00},
    {"B", 11.00},
    {"C", 12.00},
    {"N", 14.00},
    {"O", 16.00},
    {"F", 19.00},
    {"Ne", 20.00},
    {"Na", 23.00},
    {"Mg", 24.00},
    {"Al", 27.00},
    {"Si", 28.00},
    {"P", 31.00},
    {"S", 32.00},
    {"Cl", 35.00},
    {"Ar", 40.00},
    {"K", 39.00},
    {"Ca", 40.00},
    {"Sc", 45.00},
    {"Ti", 48.00},
    {"V", 51.00},
    {"Cr", 52.00},
    {"Mn", 55.00},
    {"Fe", 56.00},
    {"Co", 59.00},
    {"Ni", 59.00},
    {"Cu", 64.00},
    {"Zn", 65.00},
    {"Ga", 70.00},
    {"Ge", 73.00},
    {"As", 75.00},
    {"Se", 79.00},
    {"Br", 80.00},
    {"Kr", 84.00},
    {"Rb", 85.00},
    {"Sr", 88.00},
    {"Y", 89.00},
    {"Zr", 91.00},
    {"Nb", 93.00},
    {"Mo", 96.00},
    {"Tc", 97.00},
    {"Ru", 101.00},
    {"Rh", 103.00},
    {"Pd", 106.00},
    {"Ag", 108.00},
    {"Cd", 112.00},
    {"In", 115.00},
    {"Sn", 119.00},
    {"Sb", 122.00},
    {"Te", 128.00},
    {"I", 127.00},
    {"Xe", 131.00},
    {"Cs", 133.00},
    {"Ba", 137.00},
    {"La", 139.00},
    {"Ce", 140.00},
    {"Pr", 141.00},
    {"Nd", 144.00},
    {"Pm", 145.00},
    {"Sm", 150.00},
    {"Eu", 152.00},
    {"Gd", 157.00},
    {"Tb", 159.00},
    {"Dy", 163.00},
    {"Ho", 165.00},
    {"Er", 167.00},
    {"Tm", 169.00},
    {"Yb", 173.00},
    {"Lu", 175.00},
    {"Hf", 178.00},
    {"Ta", 181.00},
    {"W", 184.00},
    {"Re", 186.00},
    {"Os", 190.00},
    {"Ir", 192.00},
    {"Pt", 195.00},
    {"Au", 197.00},
    {"Hg", 201.00},
    {"Tl", 204.00},
    {"Pb", 207.00},
    {"Bi", 209.00},
    {"Po", 209.00},
    {"At", 210.00},
    {"Rn", 222.00},
    {"Fr", 223.00},
    {"Ra", 226.00},
    {"Ac", 227.00},
    {"Th", 232.00},
    {"Pa", 231.00},
    {"U", 238.00},
    {"Np", 237.00},
    {"Pu", 244.00},
    {"Am", 243.00},
    {"Cm", 247.00},
    {"Bk", 247.00},
    {"Cf", 251.00},
    {"Es", 252.00},
    {"Fm", 257.00},
    {"Md", 258.00},
    {"No", 259.00},
    {"Lr", 262.00},
    {"Rf", 267.00},
    {"Db", 270.00},
    {"Sg", 269.00},
    {"Bh", 270.00},
    {"Hs", 270.00},
    {"Mt", 278.00},
    {"Ds", 281.00},
    {"Rg", 281.00},
    {"Cn", 285.00},
    {"Nh", 286.00},
    {"Fl", 289.00},
    {"Mc", 289.00},
    {"Lv", 293.00},
    {"Ts", 293.00},
    {"Og", 294.00}
};