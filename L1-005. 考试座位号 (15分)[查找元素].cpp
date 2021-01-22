/*
L1-005 考试座位号 (15分)
每个 PAT 考生在参加考试时都会被分配两个座位号，一个是试机座位，一个是考试座位。正常情况下，考生在入场时先得到试机座位号码，入座进入试机状态后，系统会显示该考生的考试座位号码，考试时考生需要换到考试座位就座。但有些考生迟到了，试机已经结束，他们只能拿着领到的试机座位号码求助于你，从后台查出他们的考试座位号码。

输入格式：
输入第一行给出一个正整数 N（≤1000），随后 N 行，每行给出一个考生的信息：准考证号 试机座位号 考试座位号。其中准考证号由 16 位数字组成，座位从 1 到 N 编号。输入保证每个人的准考证号都不同，并且任何时候都不会把两个人分配到同一个座位上。

考生信息之后，给出一个正整数 M（≤N），随后一行中给出 M 个待查询的试机座位号码，以空格分隔。

输出格式：
对应每个需要查询的试机座位号码，在一行中输出对应考生的准考证号和考试座位号码，中间用 1 个空格分隔。

输入样例：
4
3310120150912233 2 4
3310120150912119 4 1
3310120150912126 1 3
3310120150912002 3 2
2
3 4
输出样例：
3310120150912002 2
3310120150912119 1
*/


#include <iostream> //第一种 比较一般 就是 不停地输入三个数组  其中会遇到一个用double存那个变量的时候 输入很长的数字的时候 double就不够用了会转换成科学计数法 会导致答案精度要求不够
#include <string> 
using namespace std;

int main(void)
{
    int n, m, index;
    int j;
    double number[1000];
    int seat_1[1000], seat_2[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number[i] >> seat_1[i] >> seat_2[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> index;
        for (j = 0; j < n; j++)
            if (seat_1[j] == index)
                cout << (long long int)number[j] << " " << seat_2[j] << endl;
    }

    return 0;
}


#include <iostream> 
#include <vector> 
using namespace std; 
struct stu 
{
string s; 
int one, two;
};

int main(void) //像这种某个学生对应一系列东西 利用结构体是非常好的 然后再利用vector向量来替代数组
{
    int n, m, temp; 
    cin >> n;
    
    vector<stu> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i].s >> a[i].one >> a[i].two;
    }
    cin >> m;
    for (int i = 0; i < m; i++) 
    {
        cin >> temp;
        for (int j = 0; j < n; j++) 
        {
            if (a[j].one == temp) 
            {
                cout << a[j].s << " " << a[j].two << endl;
                break;
            }
        }
    }
    return 0;
}