/*
    在最后一次c语言考试中写过类似的题 但本题更加复杂 数据更大且测试点更严格
    分析:
    先根据分数加法的公式累加，后分离出整数部分和分数部分
    用int 存储后 会发现有个测试点过不去 估计是数值过大导致的 所以使用long long  并且用#define来减少代码量
    ⼀一开始⼀一直是浮点错误，按理理来说应该是出现了了/0或者%0的情况，但很难找到
    后来注意到应该在累加的时候考虑是否会超出long long的范围(这实在是巨大的数据...)，所以在累加每一步之前进行分子分⺟的约分处理(gcd)
    本题最后应该还要考虑整数和真分数部分分子都为0时候输出0的情况(最后一个测试点)
*/

#include<iostream>//分子:Numerator 分母:Denominator
#include<cstdio>
#define LL long long
using namespace std;


LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

int main(void)
{
    LL n, a, b, Numerator = 0, Denominator = 1, gcdvalue;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = (Numerator == 0 || Denominator == 0) ? 1 : gcd(abs(Numerator), abs(Denominator));
        Numerator /= gcdvalue;
        Denominator /= gcdvalue;
        gcdvalue = (a == 0 || b == 0) ? 1 : gcd(abs(a), abs(b));
        a /= gcdvalue;
        b /= gcdvalue;
        Numerator = Numerator * b + Denominator * a;
        Denominator = Denominator * b;
    }
    LL interger = Numerator / Denominator;
    Numerator -= interger * Denominator;
    gcdvalue = (Numerator == 0 || Denominator == 0) ? 1 : gcd(abs(Numerator), abs(Denominator));
    Numerator /= gcdvalue;
    Denominator /= gcdvalue;
    if (interger != 0)
    {
        cout << interger;
        if (Numerator != 0) cout << " ";
    }
    if (Numerator != 0)
        cout << Numerator << "/" << Denominator;
    if (interger == 0 && Numerator == 0)
        cout << "0";

    return 0;
}

/* //再贴一个ch写的代码 比我的简洁
    #include<iostream>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	int n,a,b;cin>>n;
	scanf("%d/%d",&a,&b);
	for(int i=1;i<n;i++)
	{	
        int c,d,t;
		scanf("%d/%d",&c,&d);
		a=a*d+b*c,b=d*b;
		if(a<0) t=gcd(-a,b);
		else if(a>0) t=gcd(a,b);
		else if(a==0) t=1;
		a/=t,b/=t; 
	}
	if(a==0){printf("0");return 0;}
	else if(b==1) printf("%d",a);
	else if(a/b!=0) printf("%d %d/%d",a/b,a-a/b*b,b);
	else if(a/b==0) printf("%d/%d",a,b);
}
*/