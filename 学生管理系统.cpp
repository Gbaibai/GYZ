#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<cstring>
#include<iomanip> 
using namespace std;
class student {
private:
    char Name[4]; //����
    double Cpro;//C++
    double English;//Ӣ��
    double Math;//����
    double Sport;//����
    double Linemath;//���Դ���
    double Allscore;//�ܷ�
    double Average;//ƽ����
    int Number; //ѧ��  
public:
    student() {}
    student(char name[4], int number, double cc, double english,
        double math, double sport, double lmath, double as, double av)
    {
        strcpy_s(Name, name);
        Number = number;
        Cpro = cc;
        English = english;
        Math = math;
        Sport = sport;
        Linemath = lmath;
        Allscore = as;
        Average = av;
    }
    friend int main();
};
int main()                                                                                        //������
{
    int x;
    double allscore;
    double average;
    system("cls");
    cout << "                         ��ӭʹ��ѧ������ϵͳ!                    " << endl;                  //����
    cout << "                             ָ����ʦ: �޻۾�                     " << endl;
    cout << "                      �����Ŷ�: ��خ��  �����                " << endl;
    for (x = 0; x < 80; x++)
        cout << "*";
    cout << "                        ѧ �� �� �� �� �� ϵ ͳ                   " << endl << endl;
    cout << "                0������ѧ���ɼ�             1������ѧ���ɼ�       " << endl;
    cout << "                2���޸�ѧ���ɼ�             3��ɾ��ѧ������Ϣ     " << endl;
    cout << "                4����������ѯ               5����ѧ�Ų�ѯ         " << endl;
    cout << "                6���������ѧ���ɼ�         7�����ָܷߵ�����     " << endl;
    cout << "                8�������ļ�                 9���˳�ϵͳ           " << endl;
    for (x; x > 0; x--)
        cout << "*";
    cout << "                       ������0--9��Ž������Ӧ�Ĳ���:";                                   //����
    char p; char w;
    student s[60];        //ָ���������60��ѧ������
    ofstream* file[60];   //������ļ��������
    int i = 0;
    int j = 0;
    int flag = 0;
    do//flag�ж������Ƿ���Ч
    {
        cin >> p;
        if ((p >= '0' && p <= '9'))
            flag = 1;
        else
            cout << "                     ָ��������������룺" << endl;
    } while (flag == 0);
    do {                                            //�ж�:0--9��Ž������Ӧ�Ĳ���
        switch (p)                 //���չ���ѡ��
        {
        case'0':                                                                                  //��������
        {
            char c;
            char name[4];
            int number;
            double cpro, english, math, sport, Linemath;
            do {
                cout << "            ����  ѧ��  C++  Ӣ��  ����  ����  ���Դ���\n"; //����ѧ����Ϣ
                cout << "            ";
                cin >> name >> number >> cpro >> english >> math >> sport >> Linemath;
                {allscore = cpro + english + math + sport + Linemath; }
                {average = (cpro + english + math + sport + Linemath) / 5.0; }
                cout << "                     �ܳɼ�:" << allscore << "   ƽ���ɼ�:" << average << endl << endl;  //����ɼ�
                file[j] = new ofstream("D:\student.txt", ios::ate);
                *file[j] << "   ���� " << name << " ѧ�� " << number << " C++�ɼ� " << cpro
                    << " Ӣ��ɼ� " << english << " �����ɼ� " << math << " �����ɼ� "
                    << sport << "���Դ����ɼ� " << Linemath << "�ܳɼ�" << allscore << "ƽ���ɼ�" << average << endl;
                j++;
                s[i] = student(name, number, cpro, english, math, sport, Linemath, allscore, average);
                i++;
                cout << "                    ��������ɹ��������������?(y/n):";
                cin >> c;
                cout << endl;
                do {
                    if (c != 'y' && c != 'n')
                    {
                        cout << "                ָ��������������룡" << endl << "     ";
                        cin >> c;
                    }
                    else
                        flag = 1;
                } while (flag == 0);
            } while (c == 'y');
            break; }
        case'1':                                                                                     //��������
        {
            char name[20];
            int number; double cpro, english, math, sport, Linemath;
            char c;
            do
            {
                cout << "                      ��������Ҫ���ӵ�ѧ������Ϣ: " << endl;
                cout << "            ����  ѧ��  C++  Ӣ��  ����  ����  ���Դ���\n";//����ѧ����Ϣ
                cout << "            ";
                cin >> name >> number >> cpro >> english >> math >> sport >> Linemath;
                {allscore = cpro + english + math + sport + Linemath; }
                {average = (cpro + english + math + sport + Linemath) / 5; }
                cout << "                     �ܳɼ�:" << allscore << "   ƽ���ɼ�:" << average << endl << endl;  //����ɼ�
                file[j] = new ofstream("D:\student.dat", ios::ate);
                *file[j] << "  ���� " << name << " ѧ��  " << number << " C++�ɼ� " << cpro << " Ӣ��ɼ� "
                    << english << " �����ɼ� " << math << " �����ɼ� " << sport << " ���Դ����ɼ� " << Linemath
                    << " �ܳɼ� " << allscore << " ƽ���ɼ� " << average << endl;
                j++;
                s[i] = student(name, number, cpro, english, math, sport, Linemath, allscore, average);
                i++;
                cout << "                     ��������ɹ��������������?(y/n):";
                cin >> c;
                cout << endl;
                if (c != 'y' && c != 'n')
                {
                    cout << "                        ָ��������������룡" << endl << "     ";
                    cin >> c;
                }
            } while (c == 'y');
            break; }
        case'2':                                                                                //�޸�����
        {
            char name[20]; int nu; double cc, eng, ma, sp, lmath, as, av;
            flag = 0;
            char c;
            if (i == 0)
            {
                cout << "                            ϵͳ���Ҳ������ѧ����";
            }
            do
            {
                cout << "                     ��������Ҫ�޸ĵ�ѧ��������:";
                cin >> name;
                cout << endl;
                for (int h = 0; h < i; h++)         //h��¼Ҫ�޸�ѧ����λ��
                {
                    if (strcmp(name, s[h].Name) == 0)
                    {
                        flag = 1;
                        cout << "                            ������������:\n";
                        cout << "                ѧ��  C++  Ӣ��  ����  ����  ���Դ���\n";
                        cout << "                ";
                        cin >> nu >> cc >> eng >> ma >> sp >> lmath;
                        {as = cc + eng + ma + sp + lmath; }
                        {av = as / 5; }
                        cout << "                          �ܳɼ�:" << as << "  ƽ���ɼ�:" << av << endl << endl;

                        s[h].Cpro = cc;
                        s[h].English = eng;
                        s[h].Math = ma;
                        s[h].Sport = sp;
                        s[h].Number = nu;
                        s[h].Allscore = as;
                        s[h].Average = av;
                        cout << "                           �����޸ĳɹ���" << endl;
                    }
                }
                if (flag == 0)
                {
                    cout << "               ��Ҫ�޸ĵ�ѧ�������ڣ������������룡" << endl;
                }
                cout << "                      ������޸���?(y/n):";
                cin >> c;
                cout << endl;
                if (c != 'y' && c != 'n')
                {
                    cout << "                   ָ��������������룡" << endl << "     ";
                    cin >> c;
                }
            } while (c == 'y');
            break; }
        case'3':                                                                                        //ɾ��
        {
            cout << "                        ��������Ҫɾ��������:";
            char m[20];
            cin >> m;
            for (int a = 0; a < i; a++)
            {
                if (strcmp(s[a].Name, m) == 0)
                {
                    int w;
                    w = a;
                    for (w; w < i; w++)
                    {
                        s[w] = s[w + 1];
                        i = i - 1;
                    }
                    cout << "                             ɾ���ɹ���" << endl;
                }
            }
            break; }
        case'4':                                                                                   //��������ѯ
        {
            char n[20]; int j = 0; char c;
            if (i == 0)
            {
                cout << "                     ����ϵͳ��û���������ݣ�" << endl; break;
            }
            do {
                int flag = 0;
                cout << "                    ��������Ҫ��ѯ��ѧ������:";
                cin >> n;
                cout << endl;
                for (int j = 0; j < i; j++)
                {
                    if (strcmp(n, (s[j]).Name) == 0)
                    {
                        flag = 1;
                        cout << "                          " << (s[j]).Name << "�ĳɼ���:" << endl;
                        cout << "C++��" << (s[j]).Cpro << " Ӣ�" << (s[j]).English
                            << " ������" << (s[j]).Math << " ������" << (s[j]).Sport << " ���Դ���: "
                            << (s[j]).Linemath << "�ܳɼ�:" << (s[j]).Allscore << "ƽ���ɼ�:" << (s[j]).Average << endl;
                    }
                }
                if (flag == 0)
                    cout << "                   �Բ���!��Ҫ��ѯ��ѧ��������!" << endl;
                cout << "                        ���������ѯ��?(y/n):";
                cin >> c;
                cout << endl;
                if (c != 'y' && c != 'n')
                {
                    cout << "                       ָ��������������룡" << endl;
                    cin >> c;
                }
            } while (c == 'y');
            break; }
        case'5':                                                                                   //��ѧ�Ų�ѯ
        {
            int n, j = 0; char c;
            if (i == 0)
            {
                cout << "                        ����ϵͳ��û���������ݣ�" << endl; break;
            }
            do {
                int flag = 0;
                cout << "                     ��������Ҫ��ѯ��ѧ����ѧ��:";
                cin >> n;
                cout << endl;
                for (int j = 0; j < i; j++)
                {
                    if (s[j].Number == n)
                    {
                        flag = 1;
                        cout << "                          " << (s[j]).Name << "�ĳɼ���:" << endl;
                        cout << "C++��" << (s[j]).Cpro << " Ӣ�" << (s[j]).English
                            << " ������" << (s[j]).Math << " ������" << (s[j]).Sport << " ���Դ���: "
                            << (s[j]).Linemath << "�ܳɼ�:" << (s[j]).Allscore << "ƽ���ɼ�:" << (s[j]).Average << endl;
                    }
                }
                if (flag == 0)
                    cout << "                    �Բ���!��Ҫ��ѯ��ѧ��������!" << endl;
                cout << "                        ���������ѯ��?(y/n):";
                cin >> c;
                cout << endl;
                if (c != 'y' && c != 'n')
                {
                    cout << "                       ָ��������������룡" << endl;
                    cin >> c;
                }
            } while (c == 'y');
            break; }
        case'6':                                                                                         //���
        {
            if (i == 0)
                cout << "                         ����ϵͳ��û���������ݣ�" << endl;
            else
                cout << "          ����  ѧ�� c++ Ӣ�� ���� ���� ���Դ��� �ܳɼ� ƽ���ɼ�   " << endl;
            for (int k = 0; k < i; k++)
            {
                cout << "          " << s[k].Name << setw(6) << s[k].Number << setw(5)
                    << (s[k]).Cpro << setw(5) << (s[k]).English << setw(5) << (s[k]).Math
                    << setw(5) << (s[k]).Sport << setw(9) << (s[k]).Linemath << setw(10)
                    << s[k].Allscore << setw(8) << (s[k]).Average << endl;
            }
            break;
        }
        case'7':
        {   //����
            student temp;
            for (int t = 0; t < i; t++)
                for (int k = t + 1; k < i; k++)
                    while (s[t].Allscore < s[k].Allscore)
                    {
                        temp = s[t];
                        s[t] = s[k];
                        s[k] = temp;
                    }
            if (true)
            {
                cout << "                     ����ѧ���ĳɼ����ִܷӸߵ��͵������ǣ�" << endl;
                if (i == 0)
                    cout << "                      ����ϵͳ��û���������ݣ�" << endl;
                else
                    cout << "          ����  ѧ�� c++ Ӣ�� ���� ���� ���Դ��� �ܳɼ� ƽ���ɼ�   " << endl;
                for (int k = 0; k < i; k++)
                {
                    cout << "          " << s[k].Name << setw(6) << s[k].Number << setw(5)
                        << (s[k]).Cpro << setw(5) << (s[k]).English << setw(5) << (s[k]).Math
                        << setw(5) << (s[k]).Sport << setw(9) << (s[k]).Linemath << setw(10)
                        << s[k].Allscore << setw(8) << (s[k]).Average << endl;
                }
            }
            break; }
        case'8':
        {     //����
            cout << "                              ����ɹ�!" << endl; break;
        }
        case'9':                                                                                         //�˳�
        {cout << "\n\n                             ��л����ʹ�ã��ټ�!!!\n\n\n" << endl;
        exit(0); }
        }
        cout << "                     ���������������������?(y/n):";
        int flag = 0;
        do
        {
            cin >> w;
            cout << endl;
            if (w != 'y' && w != 'n')
                cout << "                   ָ��������������룡" << endl;
            else
                flag = 1;
        } while (flag == 0);
        if (w == 'y')
            system("cls");
        cout << "                         ��ӭʹ��ѧ������ϵͳ!                    " << endl;                  //����
        cout << "                             ָ����ʦ: �޻۾�                       " << endl;
        cout << "                      �����Ŷ�: ��خ�� �����                " << endl;
        for (int x = 0; x < 80; x++)
            cout << "*";
        cout << "                        ѧ �� �� �� �� �� ϵ ͳ                   " << endl << endl;
        cout << "                0������ѧ���ɼ�             1������ѧ���ɼ�       " << endl;
        cout << "                2���޸�ѧ���ɼ�             3��ɾ��ѧ������Ϣ     " << endl;
        cout << "                4����������ѯ               5����ѧ�Ų�ѯ         " << endl;
        cout << "                6���������ѧ���ɼ�         7�����ָܷߵ�����     " << endl;
        cout << "                8�������ļ�                 9���˳�ϵͳ           " << endl;
        for (x = 79; x > 0; x--)
            cout << "*";
        cout << "                ������0--9��Ž������Ӧ�Ĳ���:";                  //����
        cin >> p;
    } while (w == 'y');
    return 0;
}