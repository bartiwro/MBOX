#include "box.h"

int main()
{
    MBOX nowy(10);
    nowy.receved("tekst1","100300200");
    nowy.receved("tekst2","200300200");
    nowy.receved("mydlo 3","300300200");
    nowy.receved("tekst4","400300200");
    nowy.receved("5mydlo 5","500300200");
    nowy.receved("tekst6","600300200");
    nowy.receved("mydlok7","700300200");
    nowy.receved("tekst8","800300200");
    nowy.search_by_number("600300200");
    cout << endl;
    nowy.search_by_text("mydlo");
    cout << endl;
    nowy.show_unread();
    cout << endl;
    nowy.show_unread();
    cout << endl;
    nowy.delete_one(6);
    cout << endl;
    nowy.show_all();
    cout << endl;
    nowy.show_one(5);
    cout << endl;
    nowy.delete_all();
    cout << endl;
    nowy.show_all();
    nowy.receved("tekst8","800300200");
    cout << endl;
    nowy.show_all();

    return 0;
}
