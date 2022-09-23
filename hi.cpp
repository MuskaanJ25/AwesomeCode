#include <iostream>
#include <climits>
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;

int max(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    else return b;
}

int min(int a, int b)
{
    if (a<b)
    {
        return a;
    }
    else return b;
}

void swapnum1(int& i, int& j)
{
    int c= i;
    i=j;
    j=c;
}

void swapnum2(int& i, int& j)
{
    i = i+j;
    j = i-j;
    i = i-j;
}

int max2(int a[], int len)
{
    int max = a[0];
    int nextmax = a[0];

    int i = 1;
    while (i < len)
    {
        if (a[i] > max)
        {
            nextmax = max;
            max = a[i];
        }
        else if (a[i] < max && a[i] >= nextmax)
        {
            nextmax = a[i];
        }
        i = i + 1;
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

    return n * fact(n - 1);
}

int findnum1(int n, int a, int b, int s[])
{
    int mid = (a + b) / 2;

    if (a == b)
    {
        return 0;
    }

    if (s[mid] == n)
    {
        return 1;
    }
    else if (s[(a + b) / 2] > n)
    {
        return findnum1(n, a, (a + b) / 2 - 1, s);
    }
    else
    {
        return findnum1(n, (a + b) / 2 + 1, b, s);
    }
}

int findnum2(int num, int a[], int len)
{
    int start = 0, end = len - 1;
    int mid = 0;

    while (1)
    {
        mid = (start + end) / 2;
        if (a[mid] == num)
        {
            return 1;
        }

        if (start == end)
        {
            return 0;
        }
        if (a[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}

void merge(int a1[], int a2[], int len1, int len2, int mergedarr[])
{
    int i = 0;
    int j = 0;
    int n = 0;

    while (i < len1 && j < len2)
    {
        if (a1[i] < a2[j])
        {
            mergedarr[n] = a1[i];
            i++;
        }
        else
        {
            mergedarr[n] = a2[j];
            j++;
        }
        n++;
    }

    while (i < len1)
    {
        mergedarr[n] = a1[i];
        i++;
        n++;
    }

    while (j < len2)
    {
        mergedarr[n] = a2[j];
        j++;
        n++;
    }

}

int arraysum(int start, int end, int a[])
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum = sum + a[i];
    }
    return sum;
}

bool comparearray(int a1[], int a2[], int len, int starta1)
{
    for (int i = 0; i < len; i++)
    {
        if (a1[i + starta1] != a2[i])
        {
            return false;
        }
    }

    return true;
}

bool findsubstring(int a1[], int a2[], int len1, int len2)
{
    int findsum = arraysum(0, len2 - 1, a2);
    int i = 0;
    int sum1 = arraysum(0, len2 - 1, a1);
    if (len1 == len2)
    {
        if (comparearray(a1, a2, len2, 0))
        {
            return true;
        }
    }
    while (i < len1 - len2 + 1)
    {
        if (sum1 == findsum)
        {
            if (comparearray(a1, a2, len2, i))
            {
                return true;
            }
        }
        else if (i < len1 - len2)
        {
            sum1 = sum1 - a1[i] + a1[i + len2];
        }
        i++;
    }
    return false;
}

bool checkmiddle(int a[], int len, int checknum)
{
    int above = 0;
    int below = 0;

    for (int i = 0; i < len; i++)
    {
        if (a[i] < checknum)
        {
            below++;
        }
        else if (a[i] > checknum)
        {
            above++;
        }
    }

    if (above == below)
    {
        return true;
    }
    return false;
}

int maxforindex(int a[], int start, int len)
{
    int sum = 0;
    int max = 0;
    for (int i = start; i < len; i++)
    {
        sum = sum + a[i];
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}

int maxsumsubarray1(int a[], int len)
{
    int maxsum = 0;

    for (int i = 0; i < len; i++)
    {
        int maxfori = maxforindex(a, i, len);
        if (maxfori > maxsum)
        {
            maxsum = maxfori;
        }
    }
    return maxsum;
}

int maxsumsubarray2(int a[], int len)
{
    int sumtillnow = 0;
    int maxsum = INT16_MIN;
    for (int i = 0; i < len; i++)
    {
        sumtillnow = sumtillnow + a[i];  
        if (sumtillnow > maxsum)
        {
            maxsum = sumtillnow;
        }
        if (sumtillnow < 0)
        {
            sumtillnow = 0;
        }
    }
    return maxsum;
}

void bubblesort(int a[], int len)
{
    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i < len - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
        }
    }
}

void mergesort(int a[], int len)
{
    if (len == 1)
    {
        return;
    }

    int l1 = len / 2;
    int l2 = len - len / 2;

    int leftarr[l1];
    int rightarr[l2];

    for (int i = 0; i < len / 2; i++)
    {
        leftarr[i] = a[i];
    }
    for (int i = len / 2; i < len; i++)
    {
        rightarr[i - len/2] = a[i];
    }
   
    mergesort(leftarr, l1);
    mergesort(rightarr, l2);
    merge(leftarr, rightarr, l1, l2, a);
}

void printarr(int a[], int len)
{
    for (int i=0; i<len; i++)
    {
        cout << a[i]<< " ";
    }
}

int ksmallest(int a[], int len, int k)
{
    bubblesort(a, len);
    
    int i = 0;
    int n = 0;
    int ksmallest = INT8_MAX;
    while (n<k)
    {
        if (a[i] != a[i + 1])
        {
        
            n++;
        }
        i++;
    }
   // 2,2,4,5,7,7,56,63
    return a[i-1];
}

void sort012(int a[], int len)
{
    int num0 = 0;
    int num1 = 0;
    int num2 = 0;
    for (int i=0; i<len; i++ )
    {
        if (a[i] == 0)
        {
            num0 ++;
        }
        else if (a[i] == 1)
        {
            num1++;
        }
        else if(a[i] == 2)
        {
            num2++;
        }   
    }
    for (int i=0; i<num0; i++)
    {
        a[i] = 0;
    }
    for (int i=num0; i<num0+num1; i++)
    {
        a[i] = 1;
    }
    for (int i= num1+num2; i<len; i++)
    {
        a[i] = 2;
    }
}

void sepnums1(int a[], int len)
{
    int i=0;
    int j=len-1;

    while (1)
    {
        if (j == i)
        {
            return;
        }
        while (a[i]<0 && j != i)
        {
            i++;
        }
        while (a[j] >=0 && j != i)
        {
            j--;
        }

        swapnum1(a[i],a[j]);
    }   
}

void sepnums2(int a[], int len)
{
    int j=0;
    for (int i=0; i<len; i++)
    {
        if (a[i]<0)
        {
            swapnum1(a[i],a[j]);
            j++;
        }
    }
}

bool checksum(int a[], int len, int findsum)
{
    int start = 0;
    int end = 0;
    int sum = 0;

    while (end<len)
    {
        if(sum < findsum)
        {
            sum = sum + a[end];
            end++;
        }
        else if(sum>findsum)
        {
            sum = sum - a[start];
            start++;
        }
        else if (sum == findsum)
        {
            return true;
        }
    }
    return false;
}

int arrintersec(int a1[], int a2[], int len1, int len2)
{
    int i=0;
    int j=0;
    int intersection =0;
    while (i<len1 && j<len2)
    {
        if (a1[i] == a2[j])
        {
            intersection++;
            i++; 
            j++;
        }
        else if (a1[i]<a2[j])
        {
            i++;
        }
        else if (a1[i]>a2[j])
        {
            j++;
        }
        
    }
    return intersection;
}

int arrunion1(int a1[], int a2[], int len1, int len2)
{
    int i=0;
    int j=0;
    int numunion =0;
    while (i<len1 && j<len2)
    {
        if (a1[i] == a2[j])
        {
            numunion++;
            i++; 
            j++;
        }
        else if (a1[i]<a2[j])
        {
            numunion++;
            i++;
        }
        else if (a1[i]>a2[j])
        {
            numunion++;
            j++;
        }
    }
    if (i<len1)
    {
        numunion = numunion + len1- i;
    }
    if (j<len2)
    {
        numunion = numunion + len2- j;
    }
    return numunion;
}

int arrunion2(int a1[], int a2[], int len1, int len2)
{
    int numunion = len1 + len2 - arrintersec(a1, a2, len1, len2);
    return numunion;
}

void rotatearr(int a[], int len)
{
    int c = a[len-1];
    for (int i=len-1; i>=0; i--)
    {
        a[i]=a[i-1];
    }
    a[0] = c;
}

int missingnum(int a[], int len)
{
    int sum = arraysum(0, len-1, a);
    int idealsum = (len+1)*(len+2)/2;
    int miss = idealsum - sum;
    return miss;
}

int paircountsorted(int a[], int len, int findsum)
{
    int i=0;
    int j=len-1;
    int count =0;
    while (i<j)
    {
        if (a[i]+a[j] == findsum)
        {
            count++;
            i++;
            j--;
        }
        else if (a[i]+a[j] < findsum)
        {
            i++;
        }
        else if (a[i]+a[j] > findsum)
        {
            j--;
        }
    }
    return count;
}

int paircount1(int a[], int len, int findsum)
{
    int doublepair = 0;
    int count =0;
    for (int i=0; i<len; i++)
    {
        for (int j=0; j<len; j++)
        {
            if (a[i]+a[j] == findsum)
            {
                doublepair++;
            }
        }
    }
    count = doublepair/2;
    return count;
}

int paircount2(int a[], int len, int findsum)
{
    mergesort(a, len);
    int count = 0;
    count = paircountsorted(a, len, findsum);
    return count;
}

void duplicates1(int a[], int len)
{
    mergesort(a, len);
    for (int i=0; i<len-1; i++)
    {
        if(a[i] == a[i+1])
        {
            cout << a[i] << " ";
        }
    }
}

void duplicates2(int a[], int len)
{
    for(int i=0; i<len; i++)
    {
        int num = a[i] % len;
        a[num] = a[num] + len;
    }

    for(int i=0; i<len; i++)
    {
        if ((a[i]/len) >= 2)
        cout << i << " ";
    }
}

int maxof3(int a, int b, int c)
{
    if(a>=b && a>=c)
    {
        return a;
    }
    else if(b>=a && b>=c)
    {
        return b;
    }
    else return c;
}

int minof3(int a, int b, int c)
{
    if(a<=b && a<=c)
    {
        return a;
    }
    else if(b<=a && b<=c)
    {
        return b;
    }
    else return c;   
}

void reps3arr(int a1[], int len1, int a2[], int len2, int a3[], int len3)
{
    int i= 0;
    int j= 0;
    int k= 0;
    while (i<len1 && j<len2 && k<len3)
    {
        if(a1[i] == a2[j] && a2[j] == a3[k])
        {
            cout << a1[i] << " ";
            i++;
            j++;
            k++;
        }
        else if (a1[i]< a2[j])
        {
            i++;
        }
        else if (a2[j]< a3[k])
        {
            j++;
        }
        else 
        {
            k++;
        }
    }
}

int firstrep(int a[], int len)
{
    bool done = false;
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(a[i] == a[j])
            {
                return i;
                done = true;
            }
            if (done == true) break; 
        }
        if (done == true) break;
    }
    
}

void subarrequal01(int a[], int len)
{
    for (int i=0; i<len; i++)
    {
        if (a[i]==0)
        {
            a[i] = -1;
        }
    }
    for (int i=0; i<len; i++)
    {
        for (int j=i+1; j<len; j++)
        {
            if (arraysum(i,j,a) == 0)
            {
                cout << "(" << i << "," << j << ")" ;
            }
        }
    }
}

void altnums(int a[], int len)
{
    int i=0;
    int j=1;
    while (i<len && j<len)
    {
        if (a[i] >=0) 
        {
            i = i+2;
        }
        if (a[j] < 0)
        {
            j = j+2;
        }
        if (a[i] < 0 && a[j] >=0)
        {
            swapnum1(a[i], a[j]);
        }
    }
}

bool check0sum(int a[], int len)
{
    bool sum0 = false;
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if (arraysum(i,j,a) == 0)
            {
                sum0 = true;
            }
        }
    }
    return sum0;
}

int maxprdno0(int a[], int start, int end)
{
    int product =1;
    int countneg =0;
    int firstneg =-1;
    int lastneg =-1;


    for (int i=start +1; i<end; i++)
    {
        if(a[i]<0)
        {
            countneg++;
            lastneg = i;
            if(firstneg < 0)
            {
                firstneg = i;
            }
        }
    }

    if ((countneg%2) == 0)
    {
        for (int i=start+1; i<end; i++)
        {
            product = product*a[i];
        }
    }

    else
    {
        int pleft =1;
        int pryt =1;
        for (int i=start+1; i<lastneg; i++)
        {
            pleft = pleft*a[i];
        }
        for (int i=firstneg+1; i<end; i++)
        {
            pryt = pryt*a[i];
        }

        if(pleft > pryt)
        {
            product = pleft;
        }
        else 
            product = pryt;
    }
    return product;
}

int maxprd1(int a[], int len)
{
    int count0 = 0;
    for (int i=0; i<len; i++)
    {
        if (a[i] == 0)
        {
            count0++;
        }
    }
    int b[count0+2];
    b[0] = -1;            
    b[count0+1] = len;
    int j=1;
    for (int i=0; i<len; i++)
    {
        if (a[i]==0)
        {
            b[j] = i;
            j++;
        }
    }
    
    int i=0;
    int max =1;
    while (i<count0+2)
    {
        int product = maxprdno0(a, b[i], b[i+1]);
        if (product > max)
        {
            max = product;
        }
        i++;
    }
    return max;
}

int maxprd2(int a[], int len)
{
    int maxprd = 1;
    int minprd = 1;
   
    for (int i=0; i<len; i++)
    {
        if (a[i] < 0)
        {
            swapnum1 (minprd, maxprd);
        }
        minprd = min (minprd*a[i], a[i]);
        maxprd = max (maxprd*a[i], a[i]);
    }
    return maxprd;
}

int numswitchfox(char a[], int len)
{
    int change = 0;
    int hand = -1;
    for (int i=0; i<len; i++)
    {
        if (a[i] != 'f' && hand == -1)
        {
            if (a[i] == 'o')
            {
                hand = 0;
            }
            else hand = 1;
        }
        if (a[i] == 'x' && hand == 0)
        {
            change++;
            hand = 1;
        }
        if (a[i] == 'o' && hand == 1)
        {
            change++;
            hand = 0;
        }   
    }
    return change;
}

int longestsubseq(int a[], int len)
{
    mergesort(a, len);
    int length = 1;
    int maxlen = 1;
    for (int i=1; i<len; i++)
    {
        if (a[i] == a[i-1]+1)
        {
            length++;
        }
        else if (a[i] == a[i-1])
        {
            continue;
        }
        else length = 1;

        if (length > maxlen)
        {
            maxlen = length;
        }
    }
    return maxlen;
}

int rotarrmin(int a[], int len)
{
    int start = 0;
    int end = len-1;
    int mid = 0;
    while (1)
    {
        mid = (start + end)/2;    

        if (mid == 0)
        {
            return min(a[0],a[1]);
        }    
       
        if (end == start)
        {
            return a[end];
        }
        if (a[mid] < a[mid - 1])
        {
            return a[mid];
        }

        if (a[mid] > a[end])
        {
            start = mid+1;
        }
        else end = mid-1; 
    }
}

int maxsumrot(int a[], int len)
{
    int totsum = arraysum(0, len-1, a);
    int sumnow = 0;
    int nextsum = 0;
    for (int i=0; i<len; i++)
    {
        sumnow = sumnow + i*a[i];
    }
 
    int maxsum = sumnow;
    for (int i=1; i<len; i++)
    {
        nextsum = sumnow - totsum + len*a[i-1];
        sumnow = nextsum; 

        if (nextsum > maxsum)
        {
            maxsum = nextsum;
        }
    }
    return maxsum;
}

int minplatforms(int arr[], int dep[], int len)
{
    int platreq = 1;
    mergesort (arr, len);
    mergesort (dep , len);
    int final[2*len] = {};
    int i = 0;
    int j = 0;
    int n = 0;

    while (i < len && j < len)
    {
        if (arr[i] < dep[j])
        {
            final[n] = 1;
            i++;
        }
        else
        {
            final[n] = -1;
            j++;
        }
        n++;
    }

    int sum = final[0];
    for (int i=1; i<2*len; i++)
    {
        sum = sum + final[i];
        platreq = max(sum, platreq);
    }
    return platreq;
}

class Pet
{
    private:
        string pet_type;
        string pet_name;
        int* pet_age = NULL;

    public:
        Pet(string type, string name, int age)
        {
            pet_type = type;
            pet_name = name;
            pet_age = new int;
            *pet_age = age;
            cout << "const done" <<endl;
        }

        ~Pet()
        {
            delete pet_age;
            cout << "dest done" <<endl;
        }

        void showdata()
        {
            cout << "Pet (" << this << ") [Type : " << pet_type << " Name : " << pet_name << " age : " << *pet_age << " ]"<<endl;
        }

        Pet& set_type(string pet_type)
        {
            this->pet_type = pet_type;
            return *this;
        }

        Pet& set_name(string pet_name)
        {
            this->pet_name = pet_name;
            return *this;
        }

        Pet& set_age(int age)
        {
            *(this->pet_age) = age;
            return *this;    
        } 
};

class node
{
    public:
        int data;
        node* pnext;
};

class linked_list
{
    private:
        node* phead = NULL;
        int size = 0;

    public:

        int get_size()
        {
            return size;
        }

        bool is_empty()
        {
            if(size == 0)
            return true;
            else
            return false;
        }

        void print()
        {
            node* pnode = phead;
            while (pnode != NULL)
            {
                cout << pnode->data << " ";
                pnode = pnode->pnext;
            }
            cout << endl;
        }

        void push_back(int data)
        {
            node* pnode = phead;
            while(pnode != NULL)
            {
                if(pnode->pnext != NULL)
                {
                    pnode = pnode->pnext;
                }
                else 
                    break;
            }
            node* pnew = new node();
            pnew->data = data;
            pnew->pnext = NULL;
            if(pnode == NULL)
            {
                phead = pnew;
            }
            else
                pnode->pnext = pnew;

            size++;
        }

        void push_ahead(int data)
        {
            node* pnew = new node();
            pnew->pnext = phead;
            pnew->data = data;
            phead = pnew;
            size++;
        }

        node* search(int data)
        {
            node* pnode = phead;
            while(pnode != NULL)
            {
                if(pnode->data != data && pnode->pnext != NULL)
                {
                    pnode = pnode->pnext;
                }
                else if(pnode->data == data)
                {
                    return pnode;
                }
                else 
                    return NULL;
            }
            return NULL;
        }

        void remove(int data)
        {
            node* pnode = phead;
            if(phead->data == data)
            {
                phead = phead->pnext;
                delete pnode;
            }
            else
            {
                while(pnode != NULL)
                {
                    if (pnode->pnext != NULL && pnode->pnext->data == data)
                    {
                        node* pdel = pnode->pnext;
                        pnode->pnext = pnode->pnext->pnext;
                        delete pdel;
                        break;
                    }
                    else if(pnode->pnext != NULL && pnode->pnext->data != data)
                    {
                        pnode = pnode->pnext;    
                    }
                }
            }
            size--;
        }
};

class circ_ll
{
private:
    node* phead= NULL;
    node* plast= NULL;
    int size;

public:
    int get_size()
    {
        return size;
    }

    bool is_empty()
    {
        if(size == 0)
        return true;
        else
        return false;
    }

    void push_back(int data)
    {
        node* pnew = new node();
        pnew->data = data;
        if(plast == NULL)
        {
            phead = pnew;
            plast = pnew;
        }
        else
        {
            plast->pnext = pnew;
            plast = pnew;
        }
        plast->pnext = phead;
        size++;
    }

    void print()
    {
        node* pnode = phead;
        cout << pnode->data << " ";
        pnode = phead->pnext;
        while(pnode != phead)
        {
            cout << pnode->data << " ";
            pnode = pnode->pnext;
        }
        cout << endl;
    }

    void push_ahead(int data)
    {
        node* pnew = new node();
        pnew->data = data;
        if(plast == NULL)
        {
            phead = pnew;
            plast = pnew;
            plast->pnext = phead;
        }
        else
        {
            plast->pnext = pnew;
            pnew->pnext = phead;
            phead = pnew;
        }
        
        size++;
    }

    node* search(int data)
    {
        node* pnode = phead;
        if (pnode->data == data)
        {
            return phead;
        }
        pnode = pnode->pnext;
        {
            while(pnode != phead)
            {
                if (pnode->data == data)
                {
                    return pnode;
                }
                else 
                    pnode = pnode->pnext;
            }
            return NULL;
        }
    }

    void remove(int data)
    { 
        if(phead->pnext->data == data)
        {
            node* pdel = phead->pnext;
            phead->pnext = phead->pnext->pnext;
            delete pdel;
        }
        else
        {
            node* pnode = phead->pnext;
            while(pnode != phead)
            {
                if(pnode->pnext->data == data)
                {
                    node* pdel = pnode->pnext;
                    if(pdel == plast)
                    {
                        plast = pnode;
                        pnode->pnext = pnode->pnext->pnext;
                        delete pdel;
                    }
                    else if (pdel == phead)
                    {
                        plast->pnext = plast->pnext->pnext;
                        phead = phead->pnext;
                        delete pdel;
                    }
                    else
                    {
                        pnode->pnext = pnode->pnext->pnext;
                        delete pdel;
                    }
                }
                else 
                    pnode = pnode->pnext;
            }
        }
        size--;
    }
};

class Person
{
    friend ostream& operator<<(ostream& out, const Person& person)
    { 
        out << "Person [Full name :" << person.get_full_name() << ", Age:" << person.get_age() << ", Address:" << person.get_address() << "]";
        return out;
    }
public:
    Person() = default;

    Person(string_view fullname, int age, string_view address)
    {
        m_full_name = fullname;
        m_age = age;
        m_address = address;
        cout << "const for person called " << endl;
    }

    Person(const Person& source) : m_full_name(source.m_full_name), m_age(source.m_age), m_address(source.m_address)
    {
        cout << "custom copy const for person called" <<endl;
    }

    ~Person()
    {
        cout << "dest for person called" << endl;
    }
    
    string get_full_name() const
    {
        return m_full_name;
    }
    
    int get_age()const
    {
        return m_age;
    }
    
    string get_address() const
    {
        return m_address;
    }

public:
    string m_full_name = "None";

protected: 
    int m_age = 0;

private : 
    string m_address = "None";
};

class Player : public Person
{
    friend ostream& operator<<(ostream& out, const Player& player)
    {
        out << "Player [Full name : " << player.get_full_name() << ",age : " << player.get_age() << ",address : " << player.get_address() << "]";
        return out;
    }
public:
    Player() = default;
    ~Player()
    {
    }
    
    void play()
    {
        m_full_name = "Stef Curry"; 
        m_age = 32; 
    }
private : 
    int m_career_start_year = 0;
    double m_salary = 0.0;
    int health_factor = 0;

};

class Nurse : protected Person
{
	friend ostream& operator<<(ostream& out, const Nurse& operand)
    {
        out << "Nurse [Full name : " << operand.get_full_name() << ",age : " << operand.get_age() << ",address : " << operand.get_address() << ",practice certificate id : " << operand.practice_certificate_id << "]";
        return out;
    }

public:
	Nurse() = default;
	~Nurse()
    {
    }
	
    void treat_unwell_person()
    {
        m_full_name = "Sick Man"; 
        m_age = 28; 
    }
    
private : 
    int practice_certificate_id = 0;
};

class Engineer : public Person
{
    friend ostream& operator<<(ostream& out , const Engineer& operand)
    {
        out << "Engineer [Full name : " << operand.get_full_name() << ",age : " << operand.get_age() << ",address : " << operand.get_address() << ",contract_count : " << operand.contract_count << "]";
        return out;   
    }
public:
    Engineer() = default;
    Engineer(string_view fullname, int age, string_view address, int contract_count_param) : Person(fullname, age, address), contract_count(contract_count_param)
    {
        cout << "const for engg called " << endl;
    }

    Engineer(const Engineer& source) : Person(source), contract_count(source.contract_count)
    {
        cout << "custom copy const for eng called" << endl;
    }

    ~Engineer()
    {
        cout << "dest for engg called " << endl;
    }

    void build_something()
    {
        m_full_name = "mr. X";
        m_age = 43; 
    }
    
protected:
    using Person::get_full_name;
    using Person::get_age;
    using Person:: get_address;

    
    int get_contract_count() const
    {
        return contract_count;
    }

private: 
    int contract_count = 0;
};

class CivilEngineer : public Engineer
{
    friend ostream& operator<<(ostream& out, const CivilEngineer& operand)
    {
        out << "CivilEngineer [Full name : " << operand.get_full_name() << ",age : " << operand.get_age() << ",address : " << operand.get_address() << ",contract_count : " << operand.get_contract_count() << ",speciality : " << operand.m_speciality << "]";
        return out;
    }
public:
    CivilEngineer()= default;
    CivilEngineer(string_view fullname, int age, string_view address, int contract_count, string_view speciality) : Engineer(fullname, age, address, contract_count), m_speciality(speciality)
    {
        cout << "const for civil engg called " << endl;
    }
    CivilEngineer(const CivilEngineer& source) : Engineer(source), m_speciality(source.m_speciality)
    {
        cout << "custom copy const called for civil eng called" << endl;
    }
    ~CivilEngineer()
    {
        cout << "dest for civil engg called " << endl;
    }
    
    void build_road()
    {
    }
	
private : 
    string m_speciality{"None"};
};

class stack
{
private:
    int* arr = NULL;
    int capacity = 5;
    int size = 0;
    bool auto_resize = true;

public:
    stack(int cap, bool resize = true)
    {
        capacity = cap;
        arr = new int(capacity);
        auto_resize = resize;
    }

    stack(bool resize = true)
    {
        arr = new int(capacity);
        auto_resize = resize;
    }

    ~stack()
    {
        if (arr)
            delete arr;
    }

    int get_cap()
    {
        return capacity;
    }

    bool push(int data)
    {
        if (size<capacity)
        {
            arr[size] = data;
            size++;
        }
        else
        {
            if (auto_resize == 0)
                return 0;
            else
            {
                capacity = capacity*2;
                int* arr2 = arr;
                arr = new(nothrow) int(capacity);
                if(!arr)
                    return 0;
                for(int i=0; i<size; i++)
                {
                    arr[i] = arr2[i];
                }
                arr[size] = data;
                size++;
                delete arr2;
                arr2 = NULL;
            }
        }
        return 1;
    }

    int pop()
    {
        if(is_empty())
        {
            return INT_MIN;
        }
        size--;
        return arr[size];
    }

    void print()
    {
        for(int i=0; i<size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool is_empty()
    {
        if(size == 0)
            return true;
        else return false;
    }

    int peek()
    {
        if(is_empty())
        {
            return INT_MIN;
        }
        return arr[size-1];
    }
};

class queue
{
private:
    int* arr = NULL;
    int capacity = 5;
    int size = 0;
    int index_pop = 0;
    int index_push = -1;
    bool auto_resize = true;

public:
    queue(int cap, bool resize = true) 
    {                                           
        auto_resize = resize;
        capacity = cap;
        arr = new int(capacity);
    }

    queue(bool resize = true)
    {
        arr = new int(capacity);
        auto_resize = resize;
    }

    ~queue()
    {
        if(arr)
            delete arr;
    }

    int get_capacity()
    {
        return capacity;
    }

    int get_size()
    {
        return size;
    }

    bool push(int data)
    {
        if (size >= capacity)
        {
            if(auto_resize == false)
                return 0;
            else 
            {   
                capacity = 2*capacity;
                int* arr2 = arr;
                arr = new(nothrow) int(capacity);
                if(!arr) 
                    return 0;
                for(int i=index_pop; i<index_pop+size; i++)
                {
                    arr[i-index_pop] = arr2[i%capacity];
                }
                index_push=size;
                index_pop=0;
                arr[size] = data;
                size++;
                delete arr2;
                arr2 = NULL;
            }
        }
        else
        {
            index_push = (index_push+1)%capacity;
            arr[index_push] = data;
            size++;
        }
        return 1;
    }

    int pop()
    {
        if(is_empty())
            return INT_MIN;

        int num_pop = arr[index_pop];
        index_pop = (index_pop+1)%capacity;
        size--;
        return num_pop;
    }

    void print()
    {
        for(int i=index_pop; i<index_pop+size; i++)
        {
            cout << arr[i%capacity] << " ";
        }
        cout << endl;
    }

    bool is_empty()
    {
        if(size == 0)
            return true;
        else return false;
    }    

    int peek()
    {
        if(is_empty())
        {
            return INT_MIN;
        }
        return arr[index_pop];
    }
};

template <typename T>
class queue_generic
{
private:
    T* arr = NULL;
    int capacity = 5;
    int size = 0;
    int index_pop = 0;
    int index_push = -1;
    bool auto_resize = true;

public:
    queue_generic(int cap, bool resize = true) 
    {                                           
        auto_resize = resize;
        capacity = cap;
        arr = new T[capacity];
    }

    queue_generic(bool resize = true)
    {
        arr = new T[capacity];
        auto_resize = resize;
    }

    ~queue_generic()
    {
        if(arr)
            delete[] arr;
    }

    int get_capacity()
    {
        return capacity;
    }

    int get_size()
    {
        return size;
    }

//Returns true if push succeds else returns false
    bool push(T data)
    {
        if (size >= capacity)
        {
            if(auto_resize == false)
                return 0;
            else 
            {   
                capacity = 2*capacity;
                T* arr2 = arr;
                arr = new(nothrow) T[capacity];
                if(!arr) 
                    return 0;
                for(int i=index_pop; i<index_pop+size; i++)
                {
                    arr[i-index_pop] = arr2[i%capacity];
                }
                index_push=size;
                index_pop=0;
                arr[size] = data;
                size++;
                delete[] arr2;
                arr2 = NULL;
            }
        }
        else
        {
            index_push = (index_push+1)%capacity;
            arr[index_push] = data;
            size++;
        }
        return 1;
    }

//Throw exception if the queue is empty
    T pop()
    {
        if(is_empty())
            throw;

        T num_pop = arr[index_pop];
        index_pop = (index_pop+1)%capacity;
        size--;
        return num_pop;
    }

    void print()
    {
        for(int i=index_pop; i<index_pop+size; i++)
        {
            cout << arr[i%capacity] << " ";
        }
        cout << endl;
    }

    bool is_empty()
    {
        if(size == 0)
            return true;
        else return false;
    }    

//Throw exception if the queue is empty
    T peek()
    {
        if(is_empty())
        {
            throw;
        }
        return arr[index_pop];
    }
};



