#include <iostream>

using namespace std;
using std::string;

typedef struct SMS
{
    string wiadomosc;
    string tel;
    bool valid;
    bool read;
    void show();
    SMS() { autodestrukcja();}
    void autodestrukcja()
    {
        wiadomosc = "";
        tel = "";
        read = false;
        valid = false;
    }
}SMS;

typedef struct MBOX
{
    SMS *sms;
    int pojemnosc_skrzynki;
    void load_file();
    void receved(string wiadomosc, string tel);
    void show_all();
    void show_unread();
    void show_one(int i);
    void delete_one(int i);
    void delete_all();
    void search_by_number(string number);
    void search_by_text(string phrase);
    MBOX(int pojemnosc_skrzynki);
    ~MBOX();
}MBOX;
