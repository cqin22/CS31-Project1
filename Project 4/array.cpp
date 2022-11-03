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
    if (pos >= n)
        return -1;
    string first = a[pos];
    for (int i = pos; i < (n - 1); i++) // rotates left
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
    if (n < 0)
        return -1;
    int z = n - 1;
    string temp;
    for (int i = 0; i < n / 2; i++) // reverses order by switching the frist and last element
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
            return smaller; // checks if the smaller of n1 and n2 gets hit first
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
    for (int i = 0; i < n - 1; i++) // firstly, alphabet-order all elements
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

int main()
{
    // for appendToAll
    string people[5] = {"boris", "gordon", "rishi", "liz", "john"};
    assert(appendToAll(people, -1, "!!!") == -1); // negative size
    assert(appendToAll(people, 5, "!!!") == 5);   // ensure it works properly
    assert(people[0] == "boris!!!" && people[1] == "gordon!!!" && people[4] == "john!!!");
    assert(appendToAll(people, 0, "!!!") == 0); // empty array

    // for lookup
    string Peoples[5] = {"boris", "gordon", "rishi", "liz", "john"};
    assert(lookup(Peoples, -2, "boris") == -1); // negative size
    assert(lookup(Peoples, 5, "boris") == 0);   // found at position 0
    assert(lookup(Peoples, 1, "rishi") == -1);  // target is in array, but not within the size we search in
    assert(lookup(Peoples, 5, "Boris") == -1);  // capital letters matter
    assert(lookup(Peoples, 0, "boris") == -1);  // no string is found since it searched for size 0
    assert(lookup(Peoples, 0, "") == -1);       // array does not contain the empty string as an element
    Peoples[2] = "";
    assert(lookup(Peoples, 5, "") == 2); // now there is an empty string at position 2

    // for positionOfMax
    string pm[6] = {"david", "liz", "margaret", "tony", "gordon", "boris"};
    assert(positionOfMax(pm, 6) == 3);   // check that it works properly
    assert(positionOfMax(pm, 0) == -1);  // empty array, no interesting elements
    assert(positionOfMax(pm, -5) == -1); // negative size

    // for rotateLeft
    string mp[5] = {"john", "david", "liz", "theresa", "margaret"};
    assert(rotateLeft(mp, -5, -6) == -1); // negative size
    assert(rotateLeft(mp, 0, 0) == -1);   // both size 0
    assert(rotateLeft(mp, 3, 4) == -1);   // pos is out of range of the indicated array
    assert(rotateLeft(mp, 3, 3) == -1);   // pos is out of range of the indicated array
    assert(rotateLeft(mp, 5, 1) == 1);    // checks that function works properly
    assert(mp[0] == "john" && mp[1] == "liz" && mp[2] == "theresa" && mp[3] == "margaret" && mp[4] == "david");

    // for countRuns
    string d[9] = {"tony", "boris", "rishi", "rishi", "gordon", "gordon", "gordon", "rishi", "rishi"};
    assert(countRuns(d, 9) == 5); // checks that it works porperly
    assert(countRuns(d, 5) == 4); // checks that it works porperly
    assert(countRuns(d, 0) == 0); // if no elements, there are 0 sequences
    string k[9] = {"tony", "boris", "tony", "boris", "boris"};
    assert(countRuns(k, 5) == 4); // nonconsecutive identical items

    // for flip
    string leader[6] = {"boris", "rishi", "", "tony", "theresa", "david"};
    assert(flip(leader, -5) == -1); // negative size
    assert(flip(leader, 0) == 0);   // size 0
    assert(flip(leader, 4) == 4);   // checks that it works properly
    assert(leader[0] == "tony" && leader[1] == "" && leader[2] == "rishi");
    assert(leader[3] == "boris" && leader[4] == "theresa" && leader[5] == "david");

    // for differ
    string Leader[6] = {"boris", "rishi", "", "tony", "theresa", "david"};
    string politician[5] = {"boris", "rishi", "david", "", "tony"};
    assert(differ(Leader, 6, politician, 5) == 2);   // checks that it works correctly
    assert(differ(Leader, 2, politician, 1) == 1);   // checks that it works correctly
    assert(differ(Leader, 6, Leader, 6) == 6);       // return size of arrays, when they're exact same
    assert(differ(Leader, -5, politician, 5) == -1); // negative size
    assert(differ(Leader, 0, politician, 5) == 0);   // one empty array
    assert(differ(Leader, 0, politician, 0) == 0);   // both empty arrays

    // for subsequence
    string names[10] = {"john", "margaret", "theresa", "rishi", "boris", "liz"};
    string names1[10] = {"margaret", "theresa", "rishi"};
    assert(subsequence(names, 6, names1, 3) == 1); // a2 is found in a1
    string names2[10] = {"john", "rishi"};
    assert(subsequence(names, 5, names2, 2) == -1);  // a2 is not in a1
    assert(subsequence(names, 0, names2, 2) == -1);  // a1 empty array -> subsequence not found
    assert(subsequence(names, 5, names2, 0) == 0);   // a2 empty array is valid
    assert(subsequence(names, 0, names2, 0) == 0);   // Both empty arrays is valid
    assert(subsequence(names, 5, names2, -5) == -1); // negative size is invalid

    // for lookupAny
    string set1[10] = {"david", "boris", "rishi", "margaret"};
    assert(lookupAny(names, 6, set1, 4) == 1); // matching element at position 1
    string set2[10] = {"tony", "gordon"};
    assert(lookupAny(names, 6, set2, 2) == -1);  // no common elements
    assert(lookupAny(names, 6, set2, -5) == -1); // negative size
    assert(lookupAny(names, 6, set2, 0) == -1);  // a2 has 0 elements, no matches found
    assert(lookupAny(names, 0, set2, 2) == -1);  // a1 has 0 elements, no matches
    assert(lookupAny(names, 0, set2, 0) == -1);  // neither array has elements, no matches

    // for split
    assert(split(pm, 6, "john") == 3); // checks that it works properly
    string pm2[4] = {"margaret", "theresa", "liz", "rishi"};
    assert(split(pm2, 4, "rishi") == 2);   // checks that it works properly
    assert(split(pm2, -5, "rishi") == -1); // negative size
    assert(split(pm2, 0, "rishi") == 0);   // size 0
    string pm3[5] = {"margaret", "theresa", "theresa", "liz", "liz"};
    assert(split(pm3, 5, "theresa") == 3); // two consecutive identical strings

    // More Test Cases to checks that functions work properly
    string h[7] = {"rishi", "margaret", "gordon", "tony", "", "john", "liz"};
    assert(lookup(h, 7, "john") == 5);    // check that correct position is returned
    assert(lookup(h, 7, "gordon") == 2);  // check that correct position is returned
    assert(lookup(h, 2, "gordon") == -1); // not found in indicated index
    assert(positionOfMax(h, 7) == 3);

    string g[4] = {"rishi", "margaret", "liz", "theresa"};
    assert(differ(h, 4, g, 4) == 2);                                               // ensures correct position is returned
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "rishi?" && g[3] == "theresa?"); // checks random elements
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "liz?" && g[3] == "margaret?");     // elements should still be changed from above

    string e[4] = {"gordon", "tony", "", "john"};
    assert(subsequence(h, 7, e, 4) == 2); // ensures correct position is returned

    string D[5] = {"margaret", "margaret", "margaret", "tony", "tony"};
    assert(countRuns(D, 5) == 2); // ensures consecutive repeats count as one sequence

    string f[3] = {"liz", "gordon", "tony"};
    assert(lookupAny(h, 7, f, 3) == 2);                         // checks that the earliest position is returned
    assert(flip(f, 3) == 3 && f[0] == "tony" && f[2] == "liz"); // ensures positions are flipped properly

    assert(split(h, 7, "liz") == 3); // checks for the proper value

    string z[1] = {};
    assert(appendToAll(z, 1, "!") == 1 && z[0] == "!"); // Append to empty string
    z[0] = "";
    assert(lookup(z, 1, "") == 0);    // check if empty string works
    assert(positionOfMax(z, 1) == 0); // check if empty string works
    assert(rotateLeft(z, 1, 0) == 0); // check if empty string works
    assert(countRuns(z, 1) == 1);     // check if empty string works
    assert(flip(z, 1) == 1);          // check if empty string works
    assert(split(z, 1, "") == 0);     // empty string found at position
    assert(split(z, 1, "hi") == 1);   // When all elements are < splitter, return n

    string Z[1] = {""};
    assert(differ(z, 1, Z, 1) == 1);       // identical strings
    assert(subsequence(z, 0, Z, 1) == -1); // a2 is larger than a1
    assert(subsequence(z, 0, Z, 0) == 0);  // both size 0, valid

    assert(lookupAny(z, 1, Z, 0) == -1); // a1 can't have common elements w/ a2 bc it has none
    assert(lookupAny(z, 0, Z, 1) == -1); // a1 can't have common elements w/ a2 bc it has none

    cout << "all passed :D";
    return 0;
}
