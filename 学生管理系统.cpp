#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<cstring>
#include<iomanip> 
using namespace std;
class student {
private:
    char Name[4]; //姓名
    double Cpro;//C++
    double English;//英语
    double Math;//高数
    double Sport;//体育
    double Linemath;//线性代数
    double Allscore;//总分
    double Average;//平均分
    int Number; //学号  
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
int main()                                                                                        //主函数
{
    int x;
    double allscore;
    double average;
    system("cls");
    cout << "                         欢迎使用学生管理系统!                    " << endl;                  //标语
    cout << "                             指导老师: 崔慧娟                     " << endl;
    cout << "                      制作团队: 郭禺哲  张智皓                " << endl;
    for (x = 0; x < 80; x++)
        cout << "*";
    cout << "                        学 生 成 绩 管 理 系 统                   " << endl << endl;
    cout << "                0、输入学生成绩             1、增加学生成绩       " << endl;
    cout << "                2、修改学生成绩             3、删除学生的信息     " << endl;
    cout << "                4、按姓名查询               5、按学号查询         " << endl;
    cout << "                6、输出所有学生成绩         7、按总分高低排序     " << endl;
    cout << "                8、保存文件                 9、退出系统           " << endl;
    for (x; x > 0; x--)
        cout << "*";
    cout << "                       请输入0--9序号进行相对应的操作:";                                   //标语
    char p; char w;
    student s[60];        //指针对象，最多存60个学生数据
    ofstream* file[60];   //负责对文件插入操作
    int i = 0;
    int j = 0;
    int flag = 0;
    do//flag判断输入是否有效
    {
        cin >> p;
        if ((p >= '0' && p <= '9'))
            flag = 1;
        else
            cout << "                     指令错误！请重新输入：" << endl;
    } while (flag == 0);
    do {                                            //判断:0--9序号进行相对应的操作
        switch (p)                 //接收功能选项
        {
        case'0':                                                                                  //输入数据
        {
            char c;
            char name[4];
            int number;
            double cpro, english, math, sport, Linemath;
            do {
                cout << "            姓名  学号  C++  英语  高数  体育  线性代数\n"; //输入学生信息
                cout << "            ";
                cin >> name >> number >> cpro >> english >> math >> sport >> Linemath;
                {allscore = cpro + english + math + sport + Linemath; }
                {average = (cpro + english + math + sport + Linemath) / 5.0; }
                cout << "                     总成绩:" << allscore << "   平均成绩:" << average << endl << endl;  //计算成绩
                file[j] = new ofstream("D:\student.txt", ios::ate);
                *file[j] << "   姓名 " << name << " 学号 " << number << " C++成绩 " << cpro
                    << " 英语成绩 " << english << " 高数成绩 " << math << " 体育成绩 "
                    << sport << "线性代数成绩 " << Linemath << "总成绩" << allscore << "平均成绩" << average << endl;
                j++;
                s[i] = student(name, number, cpro, english, math, sport, Linemath, allscore, average);
                i++;
                cout << "                    数据输入成功，想继续输入吗?(y/n):";
                cin >> c;
                cout << endl;
                do {
                    if (c != 'y' && c != 'n')
                    {
                        cout << "                指令错误！请重新输入！" << endl << "     ";
                        cin >> c;
                    }
                    else
                        flag = 1;
                } while (flag == 0);
            } while (c == 'y');
            break; }
        case'1':                                                                                     //增加数据
        {
            char name[20];
            int number; double cpro, english, math, sport, Linemath;
            char c;
            do
            {
                cout << "                      请输入您要增加的学生的信息: " << endl;
                cout << "            姓名  学号  C++  英语  高数  体育  线性代数\n";//输入学生信息
                cout << "            ";
                cin >> name >> number >> cpro >> english >> math >> sport >> Linemath;
                {allscore = cpro + english + math + sport + Linemath; }
                {average = (cpro + english + math + sport + Linemath) / 5; }
                cout << "                     总成绩:" << allscore << "   平均成绩:" << average << endl << endl;  //计算成绩
                file[j] = new ofstream("D:\student.dat", ios::ate);
                *file[j] << "  姓名 " << name << " 学号  " << number << " C++成绩 " << cpro << " 英语成绩 "
                    << english << " 高数成绩 " << math << " 体育成绩 " << sport << " 线性代数成绩 " << Linemath
                    << " 总成绩 " << allscore << " 平均成绩 " << average << endl;
                j++;
                s[i] = student(name, number, cpro, english, math, sport, Linemath, allscore, average);
                i++;
                cout << "                     数据输入成功，想继续输入吗?(y/n):";
                cin >> c;
                cout << endl;
                if (c != 'y' && c != 'n')
                {
                    cout << "                        指令错误！请重新输入！" << endl << "     ";
                    cin >> c;
                }
            } while (c == 'y');
            break; }
        case'2':                                                                                //修改数据
        {
            char name[20]; int nu; double cc, eng, ma, sp, lmath, as, av;
            flag = 0;
            char c;
            if (i == 0)
            {
                cout << "                            系统中找不到这个学生！";
            }
            do
            {
                cout << "                     请输入您要修改的学生的姓名:";
                cin >> name;
                cout << endl;
                for (int h = 0; h < i; h++)         //h纪录要修改学生的位置
                {
                    if (strcmp(name, s[h].Name) == 0)
                    {
                        flag = 1;
                        cout << "                            请输入新数据:\n";
                        cout << "                学号  C++  英语  高数  体育  线性代数\n";
                        cout << "                ";
                        cin >> nu >> cc >> eng >> ma >> sp >> lmath;
                        {as = cc + eng + ma + sp + lmath; }
                        {av = as / 5; }
                        cout << "                          总成绩:" << as << "  平均成绩:" << av << endl << endl;

                        s[h].Cpro = cc;
                        s[h].English = eng;
                        s[h].Math = ma;
                        s[h].Sport = sp;
                        s[h].Number = nu;
                        s[h].Allscore = as;
                        s[h].Average = av;
                        cout << "                           数据修改成功！" << endl;
                    }
                }
                if (flag == 0)
                {
                    cout << "               您要修改的学生不存在！请检查重新输入！" << endl;
                }
                cout << "                      想继续修改吗?(y/n):";
                cin >> c;
                cout << endl;
                if (c != 'y' && c != 'n')
                {
                    cout << "                   指令错误！请重新输入！" << endl << "     ";
                    cin >> c;
                }
            } while (c == 'y');
            break; }
        case'3':                                                                                        //删除
        {
            cout << "                        请输入你要删除的姓名:";
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
                    cout << "                             删除成功！" << endl;
                }
            }
            break; }
        case'4':                                                                                   //按姓名查询
        {
            char n[20]; int j = 0; char c;
            if (i == 0)
            {
                cout << "                     管理系统中没有输入数据！" << endl; break;
            }
            do {
                int flag = 0;
                cout << "                    请输入你要查询的学生姓名:";
                cin >> n;
                cout << endl;
                for (int j = 0; j < i; j++)
                {
                    if (strcmp(n, (s[j]).Name) == 0)
                    {
                        flag = 1;
                        cout << "                          " << (s[j]).Name << "的成绩是:" << endl;
                        cout << "C++：" << (s[j]).Cpro << " 英语：" << (s[j]).English
                            << " 高数：" << (s[j]).Math << " 体育：" << (s[j]).Sport << " 线性代数: "
                            << (s[j]).Linemath << "总成绩:" << (s[j]).Allscore << "平均成绩:" << (s[j]).Average << endl;
                    }
                }
                if (flag == 0)
                    cout << "                   对不起!您要查询的学生不存在!" << endl;
                cout << "                        您想继续查询吗?(y/n):";
                cin >> c;
                cout << endl;
                if (c != 'y' && c != 'n')
                {
                    cout << "                       指令错误！请重新输入！" << endl;
                    cin >> c;
                }
            } while (c == 'y');
            break; }
        case'5':                                                                                   //按学号查询
        {
            int n, j = 0; char c;
            if (i == 0)
            {
                cout << "                        管理系统中没有输入数据！" << endl; break;
            }
            do {
                int flag = 0;
                cout << "                     请输入你要查询的学生的学号:";
                cin >> n;
                cout << endl;
                for (int j = 0; j < i; j++)
                {
                    if (s[j].Number == n)
                    {
                        flag = 1;
                        cout << "                          " << (s[j]).Name << "的成绩是:" << endl;
                        cout << "C++：" << (s[j]).Cpro << " 英语：" << (s[j]).English
                            << " 高数：" << (s[j]).Math << " 体育：" << (s[j]).Sport << " 线性代数: "
                            << (s[j]).Linemath << "总成绩:" << (s[j]).Allscore << "平均成绩:" << (s[j]).Average << endl;
                    }
                }
                if (flag == 0)
                    cout << "                    对不起!您要查询的学生不存在!" << endl;
                cout << "                        您想继续查询吗?(y/n):";
                cin >> c;
                cout << endl;
                if (c != 'y' && c != 'n')
                {
                    cout << "                       指令错误！请重新输入！" << endl;
                    cin >> c;
                }
            } while (c == 'y');
            break; }
        case'6':                                                                                         //输出
        {
            if (i == 0)
                cout << "                         管理系统中没有输入数据！" << endl;
            else
                cout << "          姓名  学号 c++ 英语 高数 体育 线性代数 总成绩 平均成绩   " << endl;
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
        {   //排序
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
                cout << "                     所有学生的成绩按总分从高到低的排名是：" << endl;
                if (i == 0)
                    cout << "                      管理系统中没有输入数据！" << endl;
                else
                    cout << "          姓名  学号 c++ 英语 高数 体育 线性代数 总成绩 平均成绩   " << endl;
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
        {     //保存
            cout << "                              保存成功!" << endl; break;
        }
        case'9':                                                                                         //退出
        {cout << "\n\n                             感谢您的使用，再见!!!\n\n\n" << endl;
        exit(0); }
        }
        cout << "                     您想继续进行其他操作吗?(y/n):";
        int flag = 0;
        do
        {
            cin >> w;
            cout << endl;
            if (w != 'y' && w != 'n')
                cout << "                   指令错误！请重新输入！" << endl;
            else
                flag = 1;
        } while (flag == 0);
        if (w == 'y')
            system("cls");
        cout << "                         欢迎使用学生管理系统!                    " << endl;                  //标语
        cout << "                             指导老师: 崔慧娟                       " << endl;
        cout << "                      制作团队: 郭禺哲 张智皓                " << endl;
        for (int x = 0; x < 80; x++)
            cout << "*";
        cout << "                        学 生 成 绩 管 理 系 统                   " << endl << endl;
        cout << "                0、输入学生成绩             1、增加学生成绩       " << endl;
        cout << "                2、修改学生成绩             3、删除学生的信息     " << endl;
        cout << "                4、按姓名查询               5、按学号查询         " << endl;
        cout << "                6、输出所有学生成绩         7、按总分高低排序     " << endl;
        cout << "                8、保存文件                 9、退出系统           " << endl;
        for (x = 79; x > 0; x--)
            cout << "*";
        cout << "                请输入0--9序号进行相对应的操作:";                  //标语
        cin >> p;
    } while (w == 'y');
    return 0;
}