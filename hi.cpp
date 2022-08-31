#include <iostream>
#include <string>
using namespace std;
int s[10] = {2, 3, 6, 8,50,68,84, 92, 93,94};
int len = 10;
int max2()
{
    int a[5] = {2, 6, 20, 1, 20};
    int max = a[0];
    int nextmax = a[0];
    int i=1;
    while (i<5)
    {
        if (a[i] > max)
        {
            nextmax = max;
            max = a[i];
        }
        else if (a[i]<max && a[i] >= nextmax)
        {
            nextmax = a[i];
        }
        i = i+1;

    }
    if (nextmax == max)
    {
        nextmax = INT_MIN;
    }
    return nextmax; 
}

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n-1);
}

int findnum(int n, int a, int b)
{
    int mid = (a+b)/2;
    if (a == b)
    {
        return 0;
    }
    if (s[mid] == n)
    {
        return 1;
    }
    else if (s[(a+b)/2] > n)
    {
        return findnum(n, a, (a+b)/2 -1);
    }
    else 
    {
        return findnum(n, (a+b)/2 +1, b);
    }
}

int findnum2(int num)
{
    int start = 0, end = len-1;
    int mid = 0;
    while (1)
    {
        mid = (start+end)/2;
        if (s[mid] == num)
            return 1;

        if (start == end)
            return 0;

        if (s[mid] > num)
            end = mid-1;
        else 
            start = mid +1;
    }
}

void merge()
{
    int a1[5] = {1,3,5,7,9};
    int a2[5] = {1,2,4,6,8};
    int i=0;
    int j=0;
    while (i<5 , j<5)
    {
        if (a1[i] < a2[j])
        {
            cout <<a1[i];
            i++;
        }
        else if (a1[i] > a2[j])
        {
            cout <<a2[j];
            j++;
        }
        else
        {
            cout <<a1[i] <<a2[j];
            i++;
            j++;
        }
    }
}




int main() 
{
    int a1[] = {1,3,5,7,9,10,11};
    int a2[] = {78};
    int len1 = 7, len2 = 1;
    int i=0;
    int j=0;
    while (i<len1 && j<len2)
    {
        if (a1[i] < a2[j])
        {
            cout <<a1[i];
            i++;
        }
        else if (a1[i] > a2[j])
        {
            cout <<a2[j];
            j++;
        }
        else
        {
            cout <<a1[i] <<a2[j];
            i++;
            j++;
        }
    } 
    while (i < len1)
    {
        cout << a1[i];
        i++;
    }
    while (j < len2)
    {
        cout << a2[j];
        j++;
    }
    return 0;
}