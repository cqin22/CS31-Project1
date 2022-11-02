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
    string first = a[pos];
    for (int i = pos; i < n - 2; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = first;
    return pos;
}

// likely wrong
int countRuns(const string a[], int n)
{
    //Return the number of sequences of one or more consecutive identical items in a.
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
    if (n < 0)
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
    if ((n1 == 0 && n2 == 0) || n2 == 0)
        return 0;
    int i = 0;
    bool ans = false;
    while (i < n1)
    {
        if (a2[0] == a1[i])
        {
            for (int a = 0; a < n2; a++)
            {
                if (a1[i] == a2[a])
                    ans = true;
            }
            if (ans == true)
                return i;
        }
        else
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
    int element = 0;
    int j;
    string newa[n];
    int ans = 0;

    for (j = 0; j < n; j++)
    {
        if (a[j] < splitter)
        {
            newa[element] = a[j];
            element++;
            ans++;
        }
    }

    for (j = 0; j < n; j++)
    {
        if (a[j] == splitter)
        {
            newa[element] = a[j];
            element++;
        }
    }

    for (j = 0; j < n; j++)
    {
        if (a[j] > splitter)
        {
            newa[element] = a[j];
            element++;
        }
    }

    for (j = 0; j < n; j++)
        a[j] = newa[j];
    return ans;
}

// shift elements forward
// for (int i = n; i >= 0; i--)
//     newa[i] = newa[i - 1];

// // insert x at pos
// newa[0] = "test";
int main()
{
    string h[7] = {"rishi", "margaret", "gordon", "tony", "", "john", "liz"};
    assert(lookup(h, 7, "john") == 5);
    assert(lookup(h, 7, "gordon") == 2);
    assert(lookup(h, 2, "gordon") == -1);
    assert(positionOfMax(h, 7) == 3);

    string g[4] = {"rishi", "margaret", "liz", "theresa"};
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "rishi?" && g[3] == "theresa?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "liz?" && g[3] == "margaret?");

    string mp[5] = {"john", "david", "liz", "theresa", "margaret"};
    int m = rotateLeft(mp, 5, 1); // returns 1
                                  // mp now contains:  "john", "liz", "theresa", "margaret", "david"
    for (int i = 0; i < 5; i++)
    {
        cout << mp[i];
    }

    string d[5] = {"margaret", "margaret", "margaret", "tony", "tony"};
    assert(countRuns(d, 5) == 2);

    string z[9] = {
        "tony", "boris", "rishi", "rishi", "gordon", "gordon", "gordon", "rishi", "rishi"};
    int p = countRuns(z, 9); //  returns 5
    assert(p == 5);
    
    string charles[10] = {"tony", "boris", "rishi", "rishi", "gordon", "gordon", "gordon", "rishi", "rishi", "alien"};
    p = countRuns(z, 10); // another normal test case that returns 6
    assert(p == 6);


    string f[3] = {"liz", "gordon", "tony"};
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "tony" && f[2] == "liz");

    string leader[6] = {"boris", "rishi", "", "tony", "theresa", "david"};
    string politician[5] = {"boris", "rishi", "david", "", "tony"};
    int r = differ(leader, 6, politician, 5); //  returns 2
    int s = differ(leader, 2, politician, 1); //  returns 1
    assert(r == 2);
    assert(s == 1);

    string e[4] = {"gordon", "tony", "", "john"};
    assert(subsequence(h, 7, e, 4) == 2);
    cout << "All tests succeeded" << endl;

    string names[10] = {"john", "margaret", "theresa", "rishi", "boris", "liz"};
    string names1[10] = {"margaret", "theresa", "rishi"};
    int t = subsequence(names, 6, names1, 3); // returns 1
    assert(t = 1);

    string names2[10] = {"john", "rishi"};
    int u = subsequence(names, 5, names2, 2); // returns -1
    assert(u = -1);

    string ga[10] = {"john", "margaret", "theresa", "rishi", "boris", "liz"};
    string set1[10] = {"david", "boris", "rishi", "margaret"};
    int v = lookupAny(ga, 6, set1, 4); // returns 1 (a1 has "margaret" there)
    assert(v == 1);

    string set2[10] = {"tony", "gordon"};
    int w = lookupAny(ga, 6, set2, 2); // returns -1 (a1 has none)
    assert(w == -1);

    string pm2[4] = {"margaret", "theresa", "liz", "rishi"};
    int y = split(pm2, 4, "rishi"); //  returns 2

    for (int j = 0; j < 4; j++)
        cout << pm2[j] << " ";
    cout << endl;
    assert(y == 2);

    // pm2 must now be either
    //      "margaret"  "liz"  "rishi"  "theresa"
    // or   "liz"  "margaret"  "rishi"  "theresa"
    // All elements < "rishi" (i.e., "liz" and "margaret") come
    // before all others.
    // All elements > "rishi" (i.e., "theresa") come after all others.

    string pm[6] = {"david", "liz", "margaret", "tony", "gordon", "boris"};
    int x = split(pm, 6, "john"); //  returns 3
    assert(x == 3);

    for (int j = 0; j < 6; j++)
        cout << pm[j] << " ";
    cout << endl;

    // pm must now be
    //      "david"  "gordon"  "boris"  "liz"  "tony"  "margaret"
    // or   "gordon"  "boris"  "david"  "margaret"  "liz"  "tony"
    // or one of several other orderings.
    // All elements < "john" (i.e., "gordon", "boris", and "david")
    //   come before all others
    // All elements > "john" (i.e., "tony", "liz", and "margaret")
    //   come after all others

    
    
    return 0;
}
