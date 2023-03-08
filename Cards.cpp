//Завдання 6. Написати функцію, що виводить на екран
//передану їй гральну карту.


#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;
enum suits { heart, diamond, club, spade };

void color(int suits)       
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (suits == heart || suits == diamond) SetConsoleTextAttribute(hConsole, 252); // червоний колір на білому тлі 
    else SetConsoleTextAttribute(hConsole, 240); // чорний колір на білому тлі 
}

void uncolor()       // колір за замовчуванням
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
}

void edge()  // рамочка праворуч
{
    cout << " ";
    uncolor();
    cout << "|\n";
}


void card(int s, int n)  // виводить на екран передану карту  (розраховано на колоду із 52 карт).
{

    char card[13] = { 'A','2','3','4','5','6','7','8','9','0','J','Q','K' }; // символи для відображення гідності карти
    string suit[4] = { "\u2665", "\u2666", "\u2663", "\u2660" };  //  символи мастей

    uncolor();
    cout << "\n " << setfill('_') << setw(20) << "_\n"; // верхня рамка

    cout << "| "; // 1-й рядок із гідністю карти 
    color(s);
    if (n != 10) cout << card[n - 1] << " ";
    else cout << 10;
    color(s);
    cout << setfill(' ') << setw(16);
    edge();

    cout << "| "; // 2-й рядок із символом масті
    color(s);
    cout << suit[s];
    cout << setfill(' ') << setw(17);
    edge();
    /*
    Далі малюємо візернуки (залежно від гідності)
    */

    cout << "| "; // 3-й рядок 
    if (n == 2 || n == 3)
    {
        cout << setw(11);
        color(s);
        cout << suit[s];
        cout << setw(9);
        edge();
    }
    else if (n >= 4 && n <= 10)
    {
        cout << setw(7);
        color(s);
        cout << suit[s] << setw(10) << suit[s];
        cout << setw(5);
        edge();
    }
    else
    {
        color(s);
        cout << setw(18);
        edge();
    }


    cout << "| "; // 4-й рядок 
    if (n == 9 || n == 10)
    {
        cout << setw(11);
        color(s);
        cout << suit[s];
        cout << setw(9);
        edge();
    }
    else
    {
        color(s);
        cout << setw(18);
        edge();
    }

    cout << "| "; // 5-й рядок 
    if (n == 7)
    {
        cout << setw(11);
        color(s);
        cout << suit[s];
        cout << setw(9);
        edge();
    }
    else if (n > 7 && n <= 10)
    {
        cout << setw(7);
        color(s);
        cout << suit[s] << setw(10) << suit[s];
        cout << setw(5);
        edge();
    }
    else
    {
        color(s);
        cout << setw(18);
        edge();
    }

    cout << "| "; // середина
    if (n == 2 || n == 4 || n >= 8 && n <= 10)
    {
        color(s);
        cout << setw(18);
        edge();
    }
    else if (n == 1 || n == 3 || n == 5)
    {
        cout << setw(11);
        color(s);
        cout << suit[s];
        cout << setw(9);
        edge();
    }
    else if (n == 6 || n == 7)
    {
        cout << setw(7);
        color(s);
        cout << suit[s] << setw(10) << suit[s];
        cout << setw(5);
        edge();
    }
    if (n > 10)  // для карт старше 10 просто пишемо слово. 
    {
        cout << setw(11);
        color(s);
        if (n == 11) cout << "JACK ";
        if (n == 12) cout << "QUEEN";
        if (n == 13) cout << "KING ";
        cout << setw(7);
        edge();
    }


    cout << "| "; // 5-й з кінця рядок 
    if (n > 7 && n <= 10)
    {
        cout << setw(7);
        color(s);
        cout << suit[s] << setw(10) << suit[s];
        cout << setw(5);
        edge();
    }
    else
    {
        color(s);
        cout << setw(18);
        edge();
    }

    cout << "| "; // 4-й з кінця рядок 
    if (n == 10)
    {
        color(s);
        cout << setw(11);
        cout << suit[s];
        cout << setw(9);
        edge();
    }
    else
    {
        color(s);
        cout << setw(18);
        edge();
    }


    cout << "| "; // 3-й з кінця рядок 
    if (n == 2 || n == 3)
    {
        cout << setw(11);
        color(s);
        cout << suit[s];
        cout << setw(9);
        edge();
    }
    else if (n > 3 && n <= 10)
    {
        cout << setw(7);
        color(s);
        cout << suit[s] << setw(10) << suit[s];
        cout << setw(5);
        edge();
    }
    else
    {
        color(s);
        cout << setw(18);
        edge();
    }

    cout << "| "; // передостанній рядок із гідністю карти 
    color(s);
    if (n != 10) cout << setfill(' ') << setw(17) << card[n - 1];
    else cout << setfill(' ') << setw(17) << 10;
    edge();

    cout << "| "; // останній рядок із символом масті
    color(s);
    cout << setfill(' ') << setw(19) << suit[s];
    edge();
        
    // нижня рамка
    cout << "|_"; 
    color(2);
    cout << setfill('_') << setw(18);
    edge(); 
}

int main()
{
    int n, s;

    do // вести карту
    {
        cout << "Enter card\n1 - Ace \n2 - Two\n3 - Three\n4 - Four\n5 - Five\n6 - Six\n7 - Seven\n8 - Eight\n9 - Nine\n10 - Ten\n11 - Jacket\n12 - Quin\n13 - King" << endl;
        cin >> n;
        if (n < 1 || n > 13) cout << "Incorrect number, try again\n";
    } while (n < 1 || n > 13);


    do  // вести масть
    {
        cout << "\n\t\t\tCard suits\n1. Heart.\n2. Diamond\n3. Club\n4. Spade\n";
        cout << "Input a card suit: \n";
        cin >> s;
        if (s < 1 || s > 4) cout << "Incorrect number, try again\n";
    } while (s < 1 || s > 4);
    s--;

    card(s, n); // виклик функції

    /*
    ТЕСТ : генерування усіх можливих карт. 

   for (int i=1; i<14; i++)
        for (int j=0; j < 4; j++)
            card(j, i);

    */

}