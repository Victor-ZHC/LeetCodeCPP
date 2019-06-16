#include <iostream>
#include <cstdint>
#include <math.h>
#include <bitset>
using namespace std;

const int MAX = 10000000;

int BitCount(uint16_t n)
{
    int c;
    for (c = 0; n; c++)
    {
        n &= (n - 1); // 清除最低位的1
    }
    return 16 - c;
}

int main(int argc, char const *argv[])
{
    uint16_t *prime = new uint16_t[MAX];
    int n;

    cin >> n;
    if (n < 3)
    {
        cout << 0 << endl;
        return 0;
    }

    int square = (int) sqrt(n) + 1;

    int index;
    uint16_t mask;

    for (int i = 2; i < square; i++)
    {
        index = i / 16;
        mask = 1 << (i % 16);
        if ((prime[index] & mask) == 0)
        {
            int j = 2;
            int temp = j * i;
            while (temp < n)
            {
                index = temp / 16;
                mask = 1 << (temp % 16);
                prime[index] = prime[index] | mask;
                // cout << temp << " " << bitset<16>(prime[index]) << endl;
                temp = ++j * i;
            }
        }
        
    }
    int count = 0;

    for (int i = 0; i * 16 < n; i++)
    {
        count += BitCount(prime[i]);
        // cout << bitset<16>(prime[i]) << endl;
    }
    if (n % 16)
        count -= 16 - (n % 16);
    count -= 2;

    cout << count << endl;

    return 0;
}

