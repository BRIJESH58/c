#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int main()
{
    int number, cnt, i, k = 0;
    long long octal, temp_Octal, binary, place;
    int test[32];
    char test1[32];
    char hexa;
    int OCTALVALUES[] = {0, 1, 10, 11, 100, 101, 110, 111};
    int conve_system;
    char test2[65];
    int L = 1, rem = 0;
    int octal_num = 0;
    int binary_num = 0;
    int hex_num = 0;
    int octaln, rev = 0, remm, chk = 0, hex = 0, mul = 1, u = 0;
    char binaryNum[40] = "", hexnum[40];
    int decimalNum = 0, octalNum[30], len = 0;
    char hexDecNum[10];
    char hexaDecNum[20];
    cout << "PRESS 1 FOR DECIMAL TO BINARY CONVERSION: " << endl;
    cout << "PRESS 2 FOR DECIMAL TO OCTAL CONVERSION: " << endl;
    cout << "PRESS 3 FOR DECIMAL TO HEXADECIMAL CONVERSION: " << endl;
    cout << "PRESS 4 FOR BINARY TO DECIMAL CONVERSION: " << endl;
    cout << "PRESS 5 FOR OCTAL TO DECIMAL CONVERSION: " << endl;
    cout << "PRESS 6 FOR OCTAL TO HEXADECIMAL CONVERSION: " << endl;
    cout << "PRESS 7 FOR BINARY TO OCTAL CONVERSION:" << endl;
    cout << "PRESS 8 FOR BINARY TO HEXADECIMAL CONVERSION: " << endl;
    cout << "PRESS 9 FOR OCTAL TO BINARY CONVERSION: " << endl;
    cout << "PRESS 10 FOR HEXADECIMAL TO BINARY CONVERSION: " << endl;
    cout << "PRESS 11 FOR HEXADECIMAL TO OCTAL CONVERSION: " << endl;
    cout << "PRESS 12 FOR HEXADECIMAL TO DECIMAL CONVERSION: " << endl;
    cin >> conve_system;
    switch (conve_system)
    {
    case 1:
        cout << "ENTER DECIMAL NUMBER: ";
        cin >> number;
        cnt = 0;
        while (number > 0)
        {
            test[cnt] = number % 2;
            number = number / 2;
            cnt++;
        }
        cout << "BINARY VALUE IS: ";
        for (i = (cnt - 1); i >= 0; i--)
            cout << test[i];
        break;

    case 2:
        cout << "ENTER DECIMAL NUMBER: ";
        cin >> number;
        cnt = 0;
        while (number > 0)
        {
            test[cnt] = number % 8;
            number = number / 8;
            cnt++;
        }
        cout << "OCTAL VALUE IS: ";
        for (i = (cnt - 1); i >= 0; i--)
            cout << test[i];
        break;

    case 3:
        cout << "ENTER DECIMAL NUMBER: ";
        cin >> number;
        cnt = 0;
        while (number > 0)
        {
            switch (number % 16)
            {
            case 1:
                test1[cnt] = 'A';
                break;
            case 2:
                test1[cnt] = 'B';
                break;
            case 3:
                test1[cnt] = 'C';
                break;
            case 4:
                test1[cnt] = 'D';
                break;
            case 5:
                test1[cnt] = 'E';
                break;
            case 6:
                test1[cnt] = 'F';
                break;
            default:
                test1[cnt] = (number % 16) + 0x30;
            }
            number = number / 16;
            cnt++;
        }
        cout << "HEXADECIMAL VALUE IS: ";
        for (i = (cnt - 1); i >= 0; i--)
            cout << test1[i];
        break;

    case 4:
        cout << "ENTER BINARY NUMBER: ";
        cin >> test1;
        cnt = 0;
        number = 0;
        for (i = (strlen(test1) - 1); i >= 0; i--)
        {
            number = number + (test1[i] - 0x30) * pow((double)2, (double)cnt);
            cnt++;
        }
        cout << "DECIMAL VALUE IS: " << number;
        break;

    case 5:
        cout << "ENTER OCTAL NUMBER: ";
        cin >> test1;
        cnt = 0;
        number = 0;
        for (i = (strlen(test1) - 1); i >= 0; i--)
        {
            number = number + (test1[i] - 0x30) * pow((double)8, (double)cnt);
            cnt++;
        }
        cout << "DECIMAL VALUE IS: " << number;
        break;

    case 6:
        cout << "ENTER OCTAL NUMBER: ";
        cin >> octaln;
        while (octaln != 0)
        {
            rem = octaln % 10;
            if (rem > 7)
            {
                chk++;
                break;
            }
            rev = (rev * 10) + rem;
            octaln = octaln / 10;
        }
        if (chk == 0)
        {
            octaln = rev;
            while (octaln != 0)
            {
                rem = octaln % 10;
                switch (rem)
                {
                case 0:
                    strcat(binaryNum, "000");
                    break;
                case 1:
                    strcat(binaryNum, "001");
                    break;
                case 2:
                    strcat(binaryNum, "010");
                    break;
                case 3:
                    strcat(binaryNum, "011");
                    break;
                case 4:
                    strcat(binaryNum, "100");
                    break;
                case 5:
                    strcat(binaryNum, "101");
                    break;
                case 6:
                    strcat(binaryNum, "110");
                    break;
                case 7:
                    strcat(binaryNum, "111");
                    break;
                }
                octaln = octaln / 10;
            }
            while (binaryNum[k] != '\0')
                k++;
            chk = 1;
            k--;
            while (k >= 0)
            {
                if (binaryNum[k] == '0')
                    rem = 0;
                else
                    rem = 1;
                hex = hex + (rem * mul);
                if (chk % 4 == 0)
                {
                    if (hex < 10)
                        hexnum[i] = hex + 48;
                    else
                        hexnum[i] = hex + 55;
                    mul = 1;
                    hex = 0;
                    chk = 1;
                    i++;
                }
                else
                {
                    mul = mul * 2;
                    chk++;
                }
                k--;
            }
            if (chk != 1)
                hexnum[i] = hex + 48;
            if (chk == 1)
                i--;
            cout << "HEXADECIMAL VALUE IS: ";
            chk = 0;
            for (i = i; i >= 0; i--)
            {
                if (hexnum[i] == '0' && chk == 0)
                {
                    chk++;
                    continue;
                }
                else
                    cout << hexnum[i];
            }
        }
        else
            cout << "INVALID OCTAL NUMBER. " << rem;
        cout << endl;
        break;

    case 7:
        cout << "ENTER BINARY NUMBER: ";
        cin >> binary_num;
        while (binary_num != 0)
        {
            rem = binary_num % 10;
            octal_num = octal_num + rem * L;
            L = L * 2;
            binary_num = binary_num / 10;
        }
        cout << "OCTAL VALUE IS: " << octal_num;
        break;

    case 8:
        cout << "ENTER BINARY NUMBER: ";
        cin >> binary_num;
        while (binary_num != 0)
        {
            rem = binary_num % 10;
            hex_num = hex_num + rem * L;
            L = L * 2;
            binary_num = binary_num / 10;
        }
        cout << "HEXADECIMAL VALUE IS: " << hex_num;
        break;

    case 9:
        cout << "ENTER OCTAL NUMBER: ";
        cin >> test1;
        cout << "BINARY VALUE IS:";
        while (test1[k])
        {
            switch (test1[k])
            {
            case '0':
                cout << "000";
                break;
            case '1':
                cout << "001";
                break;
            case '2':
                cout << "010";
                break;
            case '3':
                cout << "011";
                break;
            case '4':
                cout << "100";
                break;
            case '5':
                cout << "101";
                break;
            case '6':
                cout << "110";
                break;
            case '7':
                cout << "111";
                break;
            default:
                cout << "INVALID OCTAL NUMBER.";
            }
            k++;
        }
        break;

    case 10:
        cout << "ENTER HEXADECIMAL NUMBER: ";
        cin >> test1;
        cout << "BINARY VALUE IS: ";
        while (test1[k])
        {
            switch (test1[k])
            {
            case '0':
                cout << "0000";
                break;
            case '1':
                cout << "0001";
                break;
            case '2':
                cout << "0010";
                break;
            case '3':
                cout << "0011";
                break;
            case '4':
                cout << "0100";
                break;
            case '5':
                cout << "0101";
                break;
            case '6':
                cout << "0110";
                break;
            case '7':
                cout << "0111";
                break;
            case '8':
                cout << "1000";
                break;
            case '9':
                cout << "1001";
                break;
            case 'a':
            case 'A':
                cout << "1010";
                break;
            case 'b':
            case 'B':
                cout << "1011";
                break;
            case 'c':
            case 'C':
                cout << "1100";
                break;
            case 'd':
            case 'D':
                cout << "1101";
                break;
            case 'e':
            case 'E':
                cout << "1110";
                break;
            case 'f':
            case 'F':
                cout << "1111";
                break;
            default:
                cout << "HEXADECIMAL" << test1[k];
            }
            k++;
        }
        break;

    case 11:
        cout << "ENTER HEXADECIMAL NUMBER: ";
        cin >> hexDecNum;
        while (hexDecNum[i] != '\0')
        {
            len++;
            i++;
        }
        len--;
        i = 0;
        while (len >= 0)
        {
            rem = hexDecNum[len];
            if (rem >= 48 && rem <= 57)
                rem = rem - 48;
            else if (rem >= 65 && rem <= 70)
                rem = rem - 55;
            else if (rem >= 97 && rem <= 102)
                rem = rem - 87;
            else
            {
                cout << "INVALID HEXADECIMAL NUMBER.";
                cout << endl;
                return 0;
            }
            decimalNum = decimalNum + (rem * pow(16, i));
            len--;
            i++;
        }
        i = 0;
        while (decimalNum != 0)
        {
            octalNum[i] = decimalNum % 8;
            i++;
            decimalNum = decimalNum / 8;
        }
        cout << "OCTAL VALUE IS: ";
        for (i = (i - 1); i >= 0; i--)
            cout << octalNum[i];
        cout << endl;
        break;

    case 12:
        cout << "ENTER HEXADECIMAL NUMBER: ";
        cin >> hexaDecNum;
        while (hexaDecNum[i] != '\0')
        {
            len++;
            i++;
        }
        len--;
        i = 0;
        while (len >= 0)
        {
            rem = hexaDecNum[len];
            if (rem >= 48 && rem <= 57)
                rem = rem - 48;
            else if (rem >= 65 && rem <= 70)
                rem = rem - 55;
            else if (rem >= 97 && rem <= 102)
                rem = rem - 87;
            else
            {
                cout << "INVALID HEXADECIMAL NUMBER.";
                cout << endl;
            }
            decimalNum = decimalNum + (rem * pow(16, i));
            len--;
            i++;
        }
        cout << "DECIMAL VALUE IS: " << decimalNum;
        cout << endl;
    default:
        cout << "INVALID HEXADECIMAL NUMBER.";
        return 0;
    }
}