// CryptoPract1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#define N 1000

using std::cin;
using std::cout;
using std::endl;

int Module(int, int); //функция нахождения модуля
int ModuleExp(int, int, int); //функция возведения в степень по модулю 
int Nsd(int, int); //функция нахождение найбольшего общего делителя
void Range(int, int); //функция нахождения простых чисел в интервале
int Phi(int); //функция Эйлера

int main()
{
    int a, b, m, x;
    
    
    
    int index = 1;
    while (index != 0)
    {
        cout << endl << "What do you want to do:" << endl;
        cout << "1 - a % m = x" << endl;
        cout << "2 - a^b % m = x" << endl;
        cout << "3 - a*x = b % m" << endl;
        cout << "4 - generate a prime in the range from A to B" << endl;
        cout << "0 - Exit" << endl;
        cin >> index;

        switch (index)
        {
        case 1:
            cout << "Please, input a" << endl;
            cin >> a;            
            cout << "Please, input m" << endl;
            cin >> m;
            cout << "a = " << a << endl;          
            cout << "m = " << m << endl;

            x = Module(a,m);
            cout << "x = " << x << endl;
            break;
        case 2:
            cout << "Please, input a" << endl;
            cin >> a;
            cout << "Please, input b" << endl;
            cin >> b;
            cout << "Please, input m" << endl;
            cin >> m;
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "m = " << m << endl;

            cout << "x = " << ModuleExp(a, b, m) << endl;
            break;
        case 3:
            cout << "Please, input a" << endl;
            cin >> a;
            cout << "Please, input b" << endl;
            cin >> b;
            cout << "Please, input m" << endl;
            cin >> m;
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "m = " << m << endl;

            if (Nsd(a, m) == 1)
            {                                      
                int p = Phi(m);
                x = (b * ModuleExp(a,p-1,m)) % m;
                cout << "x = " << x;
            }            
            break;
        case 4:           

            int A, B;
            cout << "Please, input A" << endl;
            cin >> A;
            cout << "Please, input B" << endl;
            cin >> B;
            cout << "A = " << A << endl;
            cout << "B = " << B << endl;                       
            Range(A, B);
            break;
        case 0:
            break;
        }
    }
}

int Module(int aa,int am) //"функция" нахождения модуля
{
    int x = aa % am;
    return x;
}

int ModuleExp(int aa, int ab, int am) //функция возведения в степень по модулю
{
   if (ab == 0) return 1;
    int x = ModuleExp(aa, ab / 2, am);
    if (ab % 2 == 0)
        return (x * x) % am;
    else
        return (aa * x * x) % am;
}

int Nsd(int aa, int ab) //функция нахождение найбольшего общего делителя
{
    if (aa == 0)
        return ab;
    while (ab != 0)
    {
        if (aa > ab)
            aa = aa - ab;
        else
            ab = ab - aa;
    }
    return aa;
}

void Range(int aA, int aB) //функция нахождения простых чисел в интервале
{
    int i = 0;
    int N1 = 1;
    int aA1 = aA;
    int aB1 = aB;
    
    for (aA; aA < aB; aA++)
    {
        for (int n = aA - 1; n > 1; n--)
        {
            if (aA % n == 0)
                break;
            if (n == 2)
            {
                
                N1++;
                
            }
        }
    }    

    int *mas = new int [N1];
    for (aA1; aA1 < aB1; aA1++)
    {
        for (int n = aA1 - 1; n > 1; n--)
        {
            if (aA1 % n == 0)
                break;
            if (n == 2)
            {
                              
                mas[i] = aA1;
                i++;
                

            }
        }
    }    
    cout << "1 - display whole massive" << endl;
    cout << "2 - display one random element" << endl;
    int index = 0;
    cin >> index;
    if (index == 1)
    {
        for (int i = 0; i < N1-1; i++)
            cout << mas[i] << " ";
        cout << endl;

    }
    else if (index == 2)
    {
        srand(time(NULL)); 

        int j = rand() % N1-1;
        cout << mas[j] << endl;
    }
   
    free(mas);
}

int Phi(int n)  //функция Эйлера
{
    int result = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}


