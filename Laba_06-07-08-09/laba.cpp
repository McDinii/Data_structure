#include "Header.h"

using namespace Struct;

job* arr = new job;

int main()
{
    int select, len = 0;
    bool Exit = true;

    while (Exit)
    {
        system("cls");
        cout << "0)exit\n"
            << "1)push to array\n"
            << "2)output array \n"
            << "3)file menu \n"
            << "4)delete\n"//laba06
            << "5)edit\n"//laba06
            << "6)sort menu \n"//laba07
            << "7) find surline\n"//laba08
            << "8)search menu\n";//laba09

        cin >> select;
        system("cls");
        switch (select)
        {
        case 0:
            Exit = false;
            break;
        case 1:
            Add(arr, len);
            break;
        case 2:
            Print(arr, len);
            break;
        case 3:
            filePrint(arr, len);
            break;
        case 4:
            Delete(arr, len);
            break;
        case 5:
            Change(arr, len);
            break;
        case 6:
            Sort(arr, len);
            break;
        case 7:
            FindStr(arr, len);
            break;
        case 8:
            FoundAlg(arr, len);
            break;
        default:
            break;
        }
    }
}