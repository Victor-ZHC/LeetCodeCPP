#include <iostream>
using namespace std;

const int PRIMENUM = 25;
const int MAX = 100000;


int large_mutl(int a, int *output, int &b) 
{
    int carry = 0;
    for (int i = 0; i < b; i++)
    {
        int result = *(output + i) * a + carry;
        *(output + i) = result % 10;
        carry = result / 10;
    }
    
    while (carry)
    {
        *(output + b) = carry % 10;
        carry = carry / 10;
        b++;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int b = 1;
    int sieve[PRIMENUM] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int slot[PRIMENUM] = {0};
    int output[MAX];
    output[0] = 1;

    while (cin >> n)
    {
        for (int i = 2; i <= n; i++)
        {
            int s = 0;
            int temp = i;
            while (temp > 1)
            {
                int t = 0;
                while (temp % sieve[s] == 0)
                {
                    t++;
                    temp = temp / sieve[s];
                }
                if (t > slot[s])
                {
                    slot[s] = t;
                }
                s++;
            }
            
        }

        for (int i = 0; i < PRIMENUM; i++)
        {
            for (int j = 0; j < slot[i]; j++)
            {
                large_mutl(sieve[i], output, b);
            }
        }
        

        for (int i = b - 1; i >= 0; i--)
        {
            cout << output[i];
        }
        cout << endl;

        for (int i = 0; i < PRIMENUM; i++)
            slot[i] = 0;
        b = 1;
        output[0] = 1;
    }
    

    return 0;
}
