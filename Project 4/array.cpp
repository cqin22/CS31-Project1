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
    if (n < 0)
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
    if(pos > n) return -1;
    string first = a[pos];
    for (int i = pos; i < n - 1; i++)
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
    string people[5] = {"boris", "gordon", "rishi", "liz", "john"};
        cerr << "appendToAll(people, -4, \"!!!\") = " << appendToAll(people, -4, "!!!") << endl; //test negative
        cerr << "appendToAll(people, 5, \"!!!\") = " << appendToAll(people, 5, "!!!") << endl; //test normal cases
        for (int i = 0; i < sizeof(people)/sizeof(string); i++) {
            cerr << people[i] << " ";
        }
        cerr << "\n\n";

        string people1[6] = {"boris", "gordon", "rishi", "liz", "john", "gordon"};
        cerr << "lookup(people1, 6, \"gordon\") = " << lookup(people1, 6, "gordon") << endl; //find earliest gordon
        cerr << "lookup(people1, 6, \"arthur\") = " << lookup(people1, 6, "arthur") << endl; //what if target string doesn't exist
        cerr << "\n";

        string pm[7] = {"david", "liz", "margaret", "tony", "gordon", "boris", "tony"};
        cerr << "positionOfMax(pm, 7) = " << positionOfMax(pm, 7) << endl; //finds first instance of alphabetically-last name
        string pm1[0] = {};
        cerr << "positionOfMax(pm1, 0) = " << positionOfMax(pm1, 0) << endl; //if no interesting elements
        cerr << "\n";

        string mp[5] = {"john", "david", "liz", "theresa", "margaret"};
        cerr << "rotateLeft(mp, 5, 1) = " << rotateLeft(mp, 5, 1) << endl; //tests a normal scenario
        for (int i = 0; i < sizeof(mp)/sizeof(string); i++) { //look at new array
            cerr << mp[i] << " ";
        }
        cerr << endl;
        string mp1[5] = {"john", "david", "liz", "theresa", "margaret"};
        cerr << "rotateLeft(mp1, 5, -4) = " << rotateLeft(mp1, 5, -4) << endl; //check out of bounds negative pos
        cerr << "rotateLeft(mp1, 5, 10) = " << rotateLeft(mp1, 5, 10) << endl; //check out of bounds out of bounds pos
        cerr << "rotateLeft(mp1, -5, 3) = " << rotateLeft(mp1, -5, 3) << endl; //negative n
        cerr << "\n";

        string d[9] = {"tony", "boris", "rishi", "rishi", "gordon", "gordon", "gordon", "rishi", "rishi"};
        cerr << "countRuns(d, 9) = " << countRuns(d, 9) << endl; //counts 5 sequences
        cerr << "countRuns(d, -9) = " << countRuns(d, -9) << endl; //tests negative
        cerr << "\n";

        string leader[6] = {"boris", "rishi", "xD", "tony", "theresa", "david"};
        cerr << "flip(leader, 4) = " << flip(leader, 4) << endl; //tests first 4 swap
        for (int i = 0; i < sizeof(leader)/sizeof(string); i++) { //look at new array
            cerr << leader[i] << " ";
        }
        cerr << endl;
        string leader1[7] = {"boris", "rishi", "xD", "tony", "theresa", "david", "arthur"};
        cerr << "flip(leader1, 7) = " << flip(leader1, 7) << endl; //tests an odd-numbered array flip
        for (int i = 0; i < sizeof(leader1)/sizeof(string); i++) { //look at new array
            cerr << leader1[i] << " ";
        }
        cerr << "\n\n";

        string leader2[6] = {"boris", "rishi", "", "tony", "theresa", "david"};
        string politician[5] = {"boris", "rishi", "david", "", "tony"};
        cerr << "differ(leader2, 6, politician, 5) = " << differ(leader2, 6, politician, 5) << endl; //normal test, should return index 2
        cerr << "differ(leader2, 2, politician, 1) = " << differ(leader2, 2, politician, 1) << endl; //when boths n's run out
        cerr << "differ(leader2, -3, politician, 1) = " << differ(leader2, -3, politician, 1) << endl; //check negative n
        cerr << "\n";

        string names[10] = {"john", "margaret", "theresa", "rishi", "boris", "liz"};
        string names1[10] = {"margaret", "theresa", "rishi"};
        string names2[10] = {"john", "rishi"};
        string names3[0] = {};
        string names4[0] = {};
        cerr << "subsequence(names, 6, names1, 3) = " << subsequence(names, 6, names1, 3) << endl; //normal test, found a subsequence at index 1
        cerr << "subsequence(names, 5, names2, 2) = " << subsequence(names, 5, names2, 2) << endl; //test w/ no subsequence in names
        cerr << "subsequence(names, 6, names3, 0) = " << subsequence(names, 6, names3, 0) << endl; //test with names3 as an empty array
        cerr << "subsequence(names3, 0, names4, 0) = " << subsequence(names3, 0, names4, 0) << endl; //2 empty subsequences, should still return 0
        cerr << "subsequence(names3, 0, names2, 6) = " << subsequence(names3, 0, names2, 6) << endl; //test an empty array as man sequence and an actual array as subsequence, should return -1
        cerr << "\n";

        string names5[10] = {"john", "margaret", "theresa", "rishi", "boris", "liz"};
        string set1[10] = {"david", "boris", "rishi", "margaret"};
        string set2[10] = {"tony", "gordon"};
        string set3[0] = {};
        cerr << "lookupAny(names5, 6, set1, 4) = " << lookupAny(names5, 6, set1, 4) << endl; //normal test, should return 1
        cerr << "lookupAny(names5, 6, set2, 2) = " << lookupAny(names5, 6, set2, 2) << endl; //what if nothing from set2 exists in names5, returns -1
        cerr << "lookupAny(names5, 6, set3, 0) = " << lookupAny(names5, 6, set3, 0) << endl; //empty set, should return -1
        cerr << "\n";

        string pm2[6] = {"david", "liz", "margaret", "tony", "gordon", "boris"};
        string pm3[4] = {"margaret", "theresa", "liz", "rishi"};
        cerr << "split(pm2, 6, \"john\") = " << split(pm2, 6, "john") << endl; //normal test
        for (int i = 0; i < sizeof(pm2)/sizeof(string); i++) {
            cerr << pm2[i] << " ";
        }
        cerr << endl;
        cerr << "split(pm3, 4, \"rishi\") = " << split(pm3, 4, "rishi") << endl; //includes the splitter itself in the string array
        for (int i = 0; i < sizeof(pm3)/sizeof(string); i++) {
            cerr << pm3[i] << " ";
        }
        cerr << "\n\n";
    
    return 0;
}
