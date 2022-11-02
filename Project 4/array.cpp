#include <iostream>
#include <string>
using namespace std;

int appendToAll(string a[], int n, string value)
{
    // Appends given value to each n of the array
    if (n < 0)
        return -1;
    for (int i = 0; i < n; i++)
        a[i] += value;
    return n;
}

int lookup(const string a[], int n, string target)
{
    // Return the position of a string in the array that is equal to target
    if (n < 0)
        return -1;
    for (int i = 0; i < n; i++)
        if (a[i] == target)
            return i;
    return -1;
}

int positionOfMax(const string a[], int n)
{
    // Return the position of a string in the array such that that string is >= every string in the array
    if (n <= 0)
        return -1;
    string max = a[0];

    int i = 0;
    int c = 0;
    while (i < n)
    {
        if (a[i] > max)
        {
            max = a[i];
            c = i; // test if there is a same string that shows up later
        }
        i++;
    }

    return c;
}

int rotateLeft(string a[], int n, int pos)
{
    // Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array. Return the original position of the item that was moved to the end.
    if (n < 0)
        return -1;
    if (pos < 0)
        return -1;
    if (pos > n)
        return -1;
    string first = a[pos];
    for (int i = pos; i < (n - 1); i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = first;
    return pos;
}

int countRuns(const string a[], int n)
{
    // Return the number of sequences of one or more consecutive identical items in a.
    if (n < 0)
        return -1;

    int count = 0;
    for (int i = -1; i < n - 1;)
    {
        do
        {
            i++;
        } while (a[i] == a[i + 1]);

        count++;
    }
    return count;
}

int flip(string a[], int n)
{
    // Reverse the order of the elements of the array and return n.
    if (n <= 0)
        return -1;
    int z = n - 1;
    string temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[z];
        a[z] = temp;
        z--;
    }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    // Return the position of the first corresponding elements of a1 and a2 that are not equal.
    if (n1 < 0 || n2 < 0)
        return -1;
    int smaller;
    if (n1 < n2)
        smaller = n1;
    else
        smaller = n2;

    int i = 0;
    while (i < smaller)
    {
        if (i == smaller)
            return smaller;
        if (a1[i] == a2[i])
            i++;
        else
            return i;
    }
    return i;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    // If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning position in the array.
    if (n1 < 0 || n2 < 0)
        return -1;
    if (n1 == 0 && n2 == 0)
        return 0;
    int i = 0;
    bool ans = false;
    while (i < n1) // loops through sequence comparing the subsequence through iteration i
    {
        if (a2[0] == a1[i])
        {
            for (int a = 0; a < n2; a++)
            {
                if (a1[a + i] == a2[a])
                    ans = true;
                else
                    ans = false;
            }
            if (ans == true)
                return i;
        }
        i++;
    }
    return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    // Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2. Return −1 if no element of a1 is equal to any element of a2. For example,
    if (n1 < 0 || n2 < 0)
        return -1;

    int i = 0;
    while (i < n1)
    {
        for (int a = 0; a < n2; a++)
        {
            if (a1[i] == a2[a])
                return i;
        }
        i++;
    }
    return -1;
}

int split(string a[], int n, string splitter)
{
    // Rearrange the elements of the array so that all the elements whose value is < splitter come before all the other elements, and all the elements whose value is > splitter come after all the other elements.
    if (n < 0)
        return -1;

    int ans = 0;

    int smallest;
    int j;
    string temp;
    for (int i = 0; i < n - 1; i++) // first alphabet-order all elements
    {
        smallest = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[smallest])
            {
                smallest = j;
            }
        }
        temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
    }

    for (j = 0; j < n; j++) // find first instance of splitter
    {
        if (a[j] < splitter)
        {
            ans++;
        }
    }

    return ans;
}
// shift elements forward
// for (int i = n; i >= 0; i--)
//     newa[i] = newa[i - 1];

// // insert x at pos
// newa[0] = "test";
int main()
{

    return 0;
}
