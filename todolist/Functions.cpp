#include "Functions.h"

bool check_date(Dela p)
{
    int d = p.mday;
    int m = p.mon;
    switch (m)
    {
    case 1:
        if ((d < 1 || d > 31)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 2:
        if ((d < 1 || d > 28)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 3:
        if ((d < 1 || d > 31)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 4:
        if ((d < 1 || d > 30)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 5:
        if ((d < 1 || d > 31)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 6:
        if ((d < 1 || d > 30)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 7:
        if ((d < 1 || d > 31)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 8:
        if ((d < 1 || d > 31)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 9:
        if ((d < 1 || d > 30)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 10:
        if ((d < 1 || d > 31)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 11:
        if ((d < 1 || d > 30)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    case 12:
        if ((d < 1 || d > 31)) {
            cout << INCORRECT_INPUT << endl << endl;
            return false;
        }
        else
            return true;
    default:
        cout << INCORRECT_INPUT << endl << endl;
        return false;
    }
}

bool check_time(Dela p)
{
    int h = p.hour;
    int m = p.min;
    if (h < 0 || h > 23) {
        cout << INCORRECT_INPUT << endl << endl;
        return false;
    }
    else if (m < 0 || m > 60) {
        cout << INCORRECT_INPUT << endl << endl;
        return false;
    }
    else
        return true;
}

int week(Dela p)
{
    int d = p.mday;
    int m = p.mon;
    float res;
    int days = 0;
    switch (m)
    {
    case 12:
        days += 31;
        if (m == 12)
            days += (d - 31);
    case 11:
        days += 30;
        if (m == 11)
            days += (d - 30);
    case 10:
        days += 31;
        if (m == 10)
            days += (d - 31);
    case 9:
        days += 30;
        if (m == 9)
            days += (d - 30);
    case 8:
        days += 31;
        if (m == 8)
            days += (d - 31);
    case 7:
        days += 31;
        if (m == 7)
            days += (d - 31);
    case 6:
        days += 30;
        if (m == 6)
            days += (d - 30);
    case 5:
        days += 31;
        if (m == 5)
            days += (d - 31);
    case 4:
        days += 30;
        if (m == 4)
            days += (d - 30);
    case 3:
        days += 31;
        if (m == 3)
            days += (d - 31);
    case 2:
        days += 28;
        if (m == 2)
            days += (d - 28);
    case 1:
        days += 31;
        if (m == 1)
            days += (d - 31);
    }
    res = ceil((float)(days - 2) / 7);
    return abs(res);
}

void start(Dela* p, int k)
{
    cout << endl << "��������� ������ ���." << endl << endl;;
    string s;
    for (int i = 0; i < k; i++) {
        getline(cin, s);
        cout << "���� �" << i + 1 << endl << endl;
        cout << "������� ��������: ";
        gets_s(p[i].name);
        do
        {
            cout << "������� ���������(�� 1 �� 10): ";
            cin >> p[i].priority;
        } while (p[i].priority < 1 || p[i].priority > 10);
        getline(cin, s);
        cout << "������� ��������: ";
        gets_s(p[i].description);
        cout << "������� �������(��/��/��:��) " << endl;
        do
        {
            cout << "����: ";
            cin >> p[i].mday;
            cout << "�����: ";
            cin >> p[i].mon;
            cout << "����: ";
            cin >> p[i].hour;
            cout << "������: ";
            cin >> p[i].min;
            cout << endl;
        } while (!(check_date(p[i]) && check_time(p[i])));
        p[i].week = week(p[i]);
    }
}

void menu(Dela* dela, int k)
{
    int n;
    do
    {
        system("pause");
        system("cls");
        print_all(dela, k);
        cout << "�������� �������:" << endl
            << "0 - ����� �� ���������" << endl
            << "1 - �������� ����" << endl
            << "2 - ������� ����" << endl
            << "3 - ������������� ����" << endl
            << "4 - ����� ���" << endl
            << "5 - ����������� ������ ���" << endl;
        cin >> n;
        cout << endl;
        switch (n)
        {
        case 0:
            break;
        case 1:
            add_delo(dela, k);
            break;
        case 2:
            del_delo(dela, k);
            break;
        case 3:
            edit(dela, k);
            break;
        case 4:
            search(dela, k);
        case 5:
            list_del(dela, k);
            break;
        default:
            cout << INCORRECT_CASE << endl << endl;
            break;
        }
    } while (n != 0);
}

void print2()
{
    cout << setw(78) << "���������� ������ ���" << endl << endl;
    cout << setw(30) << "��������" << setw(20) << "���������" << setw(28) << "��������" << setw(20) << "�������" << setw(20) << "� ������" << endl << endl;
}

void print(Dela p)
{
    cout << setw(28) << p.name << setw(17) << p.priority << "\t" << setw(30) << p.description << "\t\t ";
    printf("%02d/%02d/%02d:%02d\t\t%02d", p.mday, p.mon, p.hour, p.min, p.week);
    cout << endl << endl;
}

void print_all(Dela* p, int k)
{
    cout << setw(78) << "���������� ������ ���" << endl << endl;
    cout << setw(10) << "�����" << setw(20) << "��������" << setw(20) << "���������" << setw(28) << "��������" << setw(20) << "�������" << setw(20) << "� ������" << endl << endl;
    for (int i = 0; i < k; i++) {
        cout << setw(7) << i + 1 << setw(21) << p[i].name << setw(17) << p[i].priority << "\t" << setw(30) << p[i].description << "\t\t ";
        printf("%02d/%02d/%02d:%02d\t\t%02d", p[i].mday, p[i].mon, p[i].hour, p[i].min, p[i].week);
        cout << endl << endl;
    }
    cout << endl;
}

void add_delo(Dela* (&p), int& k)
{
    string s;
    getline(cin, s);
    Dela* buf = new Dela[k];
    copy(buf, p, k);
    k++;
    p = new Dela[k];
    copy(p, buf, k - 1);
    k--;
    cout << "������� ��������: ";
    gets_s(p[k].name);
    do
    {
        cout << "������� ���������(�� 1 �� 10): ";
        cin >> p[k].priority;
    } while (p[k].priority < 1 || p[k].priority > 10);
    getline(cin, s);
    cout << "������� ��������: ";
    gets_s(p[k].description);
    cout << "������� �������(��/��/��:��): " << endl;
    do
    {
        cout << "����: ";
        cin >> p[k].mday;
        cout << "�����: ";
        cin >> p[k].mon;
        cout << "����: ";
        cin >> p[k].hour;
        cout << "������: ";
        cin >> p[k].min;
        cout << endl;
    } while (!(check_date(p[k]) && check_time(p[k])));
    p[k].week = week(p[k]);
    k++;
    delete[] buf;
}

void copy(Dela* (&p_new), Dela* (&p), int k)
{
    for (int i = 0; i < k; i++)
        p_new[i] = p[i];
}

void copy_Dela(Dela& p_new, Dela& p)
{
    p_new.priority = p.priority;
    strcpy(p_new.description, p.description);
    strcpy(p_new.name, p.name);
    p_new.min = p.min;
    p_new.hour = p.hour;
    p_new.mday = p.mday;
    p_new.mon = p.mon;
    p_new.week = p.week;
}

int list_number(int k)
{
    int n;
    cout << "�������� ����� ���� �� ������: " << endl;
    while (!(cin >> n) || (cin.peek() != '\n') || (n < 1 || n > k))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << INCORRECT_INPUT << endl;
    }
    return n;
}

void del_delo(Dela* (&p), int& k)
{
    int n;
    string s;
    getline(cin, s);
    int temp = 0;
    n = list_number(k);
    n--;
    Dela* buf = new Dela[k];
    copy(buf, p, k);
    k--;
    p = new Dela[k];
    for (int i = 0;i <= k;i++)
        if (i != n) {
            p[temp] = buf[i];
            temp++;
        }
    if (temp == 0)
        cout << INCORRECT_INPUT << endl;
    cout << endl;
    delete[] buf;
}

void edit(Dela* p, int k)
{
    int n, n2;
    char new_str[255];
    int new_p, new_d, new_mon, new_h, new_min;
    string s;
    n = list_number(k);
    n--;
    do
    {
        system("pause");
        system("cls");
        print2();
        print(p[n]);
        cout << "����� ��������� ��������� ������?" << endl
            << "0 - ����� � ������� ����" << endl
            << "1 - ��������" << endl
            << "2 - ���������" << endl
            << "3 - ��������" << endl
            << "4 - �������" << endl;
        cin >> n2;
        getline(cin, s);
        cout << endl;
        switch (n2)
        {
        case 0:
            break;
        case 1:
            cout << "������� ����� ��������: ";
            gets_s(new_str);
            cout << endl;
            for (int i = 0; i < k; i++)
                if (n == i)
                    (strcpy(p[i].name, new_str));
            break;
        case 2:
            cout << "������� ����� ���������(�� 1 �� 10): ";
            while (!(cin >> new_p) || (cin.peek() != '\n') || (new_p < 1 || new_p > 10))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << INCORRECT_INPUT << endl;
            }
            for (int i = 0; i < k; i++)
                if (n == i)
                    p[i].priority = new_p;
            cout << endl;
            break;
        case 3:
            cout << "������� ����� ��������: ";
            gets_s(new_str);
            cout << endl;
            for (int i = 0; i < k; i++)
                if (n == i)
                    (strcpy(p[i].description, new_str));
            break;
        case 4:
            cout << "������� ����� �������(��/��/��:��): " << endl;
            for (int i = n; i <= n; i++) {
                do
                {
                    cout << "����: ";
                    cin >> new_d;
                    cout << "�����: ";
                    cin >> new_mon;
                    cout << "����: ";
                    cin >> new_h;
                    cout << "������: ";
                    cin >> new_min;
                    cout << endl;
                    p[i].mday = new_d;
                    p[i].mon = new_mon;
                    p[i].hour = new_h;
                    p[i].min = new_min;
                } while (!(check_date(p[i]) && check_time(p[i])));
                p[i].week = week(p[i]);
            }
            break;
        default:
            cout << INCORRECT_CASE << endl << endl;
            break;
        }
    } while (n2 != 0);
}

void search(Dela* p, int k)
{
    int n, n2;
    char str[155];
    int new_p, new_d, new_mon, new_h, new_min;
    string s;
    do
    {
        int temp = 0;
        system("pause");
        system("cls");
        print_all(p, k);
        cout << "�������� ������ ������:" << endl
            << "0 - ����� � ������� ����" << endl
            << "1 - �� ��������" << endl
            << "2 - �� ����������" << endl
            << "3 - �� ��������" << endl
            << "4 - �� ��������" << endl;
        cin >> n2;
        getline(cin, s);
        cout << endl;
        switch (n2)
        {
        case 0:
            break;
        case 1:
            cout << "������� ��������: " << endl;
            gets_s(str);
            cout << endl;
            for (int i = 0; i < k; i++)
                if (strcmp(p[i].name, str) == 0) {
                    print(p[i]);
                    temp++;
                }
            if (temp == 0)
                cout << NOT_FOUND << endl;
            cout << endl;
            break;
        case 2:
            cout << "������� ���������(�� 1 �� 10): " << endl;
            while (!(cin >> new_p) || (cin.peek() != '\n') || (new_p < 1 || new_p > 10))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << INCORRECT_INPUT << endl;
            }
            for (int i = 0; i < k; i++)
                if (p[i].priority == new_p) {
                    print(p[i]);
                    temp++;
                }
            if (temp == 0)
                cout << NOT_FOUND << endl;
            cout << endl;
            break;
        case 3:
            cout << "������� ��������: ";
            gets_s(str);
            cout << endl;
            for (int i = 0; i < k; i++)
                if (strcmp(p[i].description, str) == 0) {
                    print(p[i]);
                    temp++;
                }
            if (temp == 0)
                cout << NOT_FOUND << endl;
            cout << endl;
            break;
        case 4:
            cout << "������� �������(��/��/��:��): " << endl;
            cout << "����: ";
            cin >> new_d;
            cout << "�����: ";
            cin >> new_mon;
            cout << "����: ";
            cin >> new_h;
            cout << "������: ";
            cin >> new_min;
            cout << endl;
            for (int i = 0; i < k; i++)
                if ((p[i].mday == new_d) && (p[i].mon == new_mon) && (p[i].hour == new_h) && (p[i].min == new_min)) {
                    print(p[i]);
                    temp++;
                }
            if (temp == 0)
                cout << NOT_FOUND << endl;
            cout << endl;
            break;
        default:
            cout << INCORRECT_CASE << endl << endl;
            break;
        }

    } while (n2 != 0);
}

int sum(Dela& p, int k)
{
    int sum = p.mday * 1440 + (p.hour * 60) + p.min;
    return sum;
}

void sort(Dela* p, int k)
{
    Dela buf;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++)
            if (p[i].priority < p[j].priority) {
                copy_Dela(buf, p[j]);
                copy_Dela(p[j], p[i]);
                copy_Dela(p[i], buf);
            }
            else if ((p[i].priority == p[j].priority) && (sum(p[i], k) > sum(p[j], k) && (p[i].mday >= p[j].mday))) {
                copy_Dela(buf, p[j]);
                copy_Dela(p[j], p[i]);
                copy_Dela(p[i], buf);
            }
    }
}

void sort2(Dela* p, int k)
{
    Dela buf;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++)
            if (sum(p[i], k) > sum(p[j], k)) {
                copy_Dela(buf, p[j]);
                copy_Dela(p[j], p[i]);
                copy_Dela(p[i], buf);
            }
    }
}

void select_date(Dela* p, int k, int n2)
{
    int new_d, new_mon, new_w, temp = 0;
    switch (n2)
    {
    case 0:
        break;
    case 1:
        cout << "������� ����(��/��): " << endl;
        cout << "����: ";
        cin >> new_d;
        cout << "�����: ";
        cin >> new_mon;
        cout << endl << "��� ������ ��� �� ����: " << endl;
        for (int i = 0; i < k; i++)
            if ((p[i].mday == new_d) && (p[i].mon == new_mon)) {
                temp++;
                cout << temp << " - " << p[i].description << endl;
            }
        if (temp == 0)
            cout << endl << NOT_FOUND << endl;
        cout << endl;
        break;
    case 2:
        cout << "������� ����� ������: " << endl;
        cin >> new_w;
        cout << endl << "��� ������ ��� �� ������: " << endl;;
        for (int i = 0; i < k; i++)
            if (p[i].week == new_w) {
                temp++;
                cout << temp << " - " << p[i].description << endl;
            }
        if (temp == 0)
            cout << endl << NOT_FOUND << endl;
        cout << endl;
        break;
    case 3:
        cout << "������� ����� ������: " << endl;
        cin >> new_mon;
        cout << endl << "��� ������ ��� �� �����: " << endl;
        for (int i = 0; i < k; i++)
            if (p[i].mon == new_mon) {
                temp++;
                cout << temp << " - " << p[i].description << endl;
            }
        if (temp == 0)
            cout << endl << NOT_FOUND << endl;
        cout << endl;
        break;
    default:
        cout << INCORRECT_CASE << endl << endl;
        break;
    }
}

void list_del(Dela* (&p), int& k)
{
    int n, n2;
    Dela* buf = new Dela[k];
    do
    {

        copy(buf, p, k);
        system("pause");
        system("cls");
        print_all(p, k);
        cout << "�������� ����������:" << endl
            << "0 - ����� � ������� ����" << endl
            << "1 - �� ����������" << endl
            << "2 - �� ��������" << endl;
        cin >> n;
        if (n == 0)
            break;
        cout << "������� ������ �������:" << endl
            << "0 - �����" << endl
            << "1 - �� ����" << endl
            << "2 - �� ������" << endl
            << "3 - �� �����" << endl;
        cin >> n2;
        switch (n)
        {
        case 0:
            break;
        case 1:
            sort(buf, k);
            select_date(buf, k, n2);
            break;
        case 2:
            sort2(buf, k);
            select_date(buf, k, n2);
            break;
        default:
            cout << INCORRECT_CASE << endl << endl;
            break;
        }

    } while (n2 != 0);
    delete[] buf;
}
