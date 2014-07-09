#include "box.h"

MBOX::MBOX(int pojemnosc_skrzynki)
{
    this->pojemnosc_skrzynki = pojemnosc_skrzynki;
    sms = new SMS[pojemnosc_skrzynki];
}
MBOX::~MBOX()
{
    delete [] sms;
}
void SMS::show()
{
    cout << "Wiadomosc od: " << tel << " o tresci: " << wiadomosc << endl;
}
void load_file()
{

}
void MBOX::receved(string wiadomosc, string tel)
{
    for(int i = 1; i<pojemnosc_skrzynki; i++)
        if(sms[i].valid == false)
        {
            sms[i].wiadomosc = wiadomosc;
            sms[i].tel = tel;
            sms[i].read = false;
            sms[i].valid = true;
            return;
        }
}
void MBOX::show_all()
{
    bool check = false;
    for(int i = 1; i<pojemnosc_skrzynki; i++)
    {
        if(sms[i].valid)
        {
            sms[i].show();
            sms[i].read = true;
            check = true;
        }
    }
    if(check == false)
        cout << "Nie masz zadnych wiadomosci" << endl;

}
void MBOX::show_unread()
{
    bool check = false;
    for(int i = 1; i<pojemnosc_skrzynki; i++)
    {
        if((sms[i].valid)&&!(sms[i].read))
        {
            sms[i].show();
            sms[i].read = true;
            check = true;
        }
    }
    if(check == false)
        cout << "Nie masz nieprzeczytanych wiadomosci" << endl;
}
void MBOX::show_one(int i)
{
    if((i >= 1) && sms[i].valid)
    {
        sms[i].show();
        sms[i].read = true;
    }
    else cout << "Nie ma takiej wiadomosci" << endl;
}
void MBOX::delete_one(int i)
{
    if(i >= 1)
    {
        cout << "Wiadomosc nr " << i << " zostala usunieta" << endl;
        sms[i].wiadomosc = "";
        sms[i].tel = "";
        sms[i].read = false;
        sms[i].valid = false;
        return;
    }
    else
        cout << "Blad. Wprowadz poprawnie nr wiadomosci, ktora chcesz usunac " << endl;
}
void MBOX::delete_all()
{
    for(int i = 1; i<pojemnosc_skrzynki; i++)
    {
        if(sms[i].valid)
            sms[i].valid = false;
    }
    cout << "Wszystkie wiadomosci zostaly usuniete" << endl;
}
void MBOX::search_by_number(string number)
{
    bool check = false;
    for(int i=1; i<pojemnosc_skrzynki; i++)
    {
        if((sms[i].valid) && (sms[i].tel == number))
        {
            sms[i].show();
            sms[i].read = true;
            check = true;
        }
    }
    if(check == false)
        cout << "Nie ma wiadomosci od tego nadawcy" << endl;
}
void MBOX::search_by_text(string phrase)
{
    bool check = false;
    for(int i=1; i<pojemnosc_skrzynki; i++)
    {
        size_t found = (sms[i].wiadomosc).find(phrase);
        if((sms[i].valid) && found!=string::npos)
        {
                sms[i].show();
                sms[i].read = true;
                check = true;
        }
    }
    if(check == false)
        cout << "Nie ma wiadomosci o takiej tresci" << endl;
}
