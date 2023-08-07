#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;
bool isPrime(long long num) {
    if (num < 2)
        return false;
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
// 判断数组是否全部为质数
bool allPrimes(std::vector<long long>& arr) {
    for (long long num : arr) {
        if (!isPrime(num))
            return false;
    }
    return true;
}
long long sumarr(vector<long long>& arr)
{
    long long sum = 0;
    for (long long i = 0;i < arr.size();i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main() {
    vector<long long> arr;
    long long n;
    cin >> n;
    for (long long i = 0;i < n;i++)
    {
        long long a;
        cin >> a;
        arr.push_back(a);
    }
        if (n == 1)
        {
            if (isPrime(arr[0]))
                cout << "Yes";
            else cout << "No";
        }
        else if (n == 2)
        {
            if (sumarr(arr) % 2 == 1 && isPrime(arr[0] + arr[1] - 2))
                cout << "Yes";
            else if (sumarr(arr) % 2 == 0 && sumarr(arr) >= 4)
                cout << "Yes";
            else
                cout << "No";
        }
        else if (n > 2) {
            if (sumarr(arr) >= 2 * n)
                cout << "Yes";
            else
                cout << "No";
        }
    return 0;
}