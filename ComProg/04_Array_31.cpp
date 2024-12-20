#include<iostream>
using namespace std;

#define ll long long
#define el cout<<'\n';

void print_number(ll &n)
{
    if(n == 1) cout << "one ";
    else if(n == 2) cout << "two ";
    else if(n == 3) cout << "three ";
    else if(n == 4) cout << "four ";
    else if(n == 5) cout << "five ";
    else if(n == 6) cout << "six ";
    else if(n == 7) cout << "seven ";
    else if(n == 8) cout << "eight ";
    else if(n == 9) cout << "nine ";
}

void print_tens(ll &a)
{
    ll n = a/10;
    if(n == 1)
    {
        ll x = ((ll)a)%10;
        if(x == 0) cout << "ten ";
        else if(x == 1) cout << "eleven ";
        else if(x == 2) cout << "twelve ";
        else if(x == 3) cout << "thirteen ";
        else if(x == 4) cout << "fourteen ";
        else if(x == 5) cout << "fifteen ";
        else if(x == 6) cout << "sixteen ";
        else if(x == 7) cout << "seventeen ";
        else if(x == 8) cout << "eighteen ";
        else if(x == 9) cout << "nineteen ";
    }
    else
    {
        if(n == 2) cout << "twenty ";
        else if(n == 3) cout << "thirty ";
        else if(n == 4) cout << "forty ";
        else if(n == 5) cout << "fifty ";
        else if(n == 6) cout << "sixty ";
        else if(n == 7) cout << "seventy ";
        else if(n == 8) cout << "eighty ";
        else if(n == 9) cout << "ninety ";
        a %= 10;
        print_number(a);
    }
}

void print_hundred(ll &n)
{
    ll hundred = n/100;
    if(hundred != 0)
    {
        print_number(hundred);
        cout << "hundred ";
        n %= 100;
    }
    // el;
    print_tens(n);
}

void print_thousand(ll &n)
{
    ll thousand = n/1000;
    if(thousand != 0)
    {
        print_number(thousand);
        cout << "thousand ";
    }
    n %= (ll)1e3;
    // el;
    print_hundred(n);
}

void print_amount(ll &n)
{
    if(n >= 1e3) print_thousand(n);
    else if(n >= 1e2) print_hundred(n);
    else if(n >= 10) print_tens(n);
    else print_number(n);
    // el;
}

void print_million(ll &n)
{
    ll ml = n/1e6;
    if(ml != 0)
    {
        print_amount(ml);
        cout << "million ";
    }
    // el;
    n %= (ll)1e6;
    if(n >= 1e4)
    {
        ll td = n/1000;
        print_amount(td);
        cout << "thousand ";
        n %= (ll)1e3;
        print_hundred(n);
    }
    else print_thousand(n);
}

void print_billion(ll &n)
{
    ll bl = n/1e9;
    if(bl != 0)
    {
        print_amount(bl);
        cout << "billion ";
    }
    // el;
    n %= (ll)1e9;
    print_million(n);
}

void print_trillion(ll &n)
{
    ll tl = n/1e12;
    if(tl != 0)
    {
        print_amount(tl);
        cout << "trillion ";
    }
    // el;
    n %= (ll)1e12;
    print_billion(n);
}

int main()
{
    ll n;
    cin >> n;
    if(n >= 1e12) print_trillion(n);
    else if(n >= 1e9) print_billion(n);
    else if(n >= 1e6) print_million(n);
    else if(n >= 1e4)
    {
        ll td = n/1000;
        print_amount(td);
        cout << "thousand ";
        n %= (ll)1e3;
        print_hundred(n);
    }
    else if(n >= 1e3) print_thousand(n);
    else if(n >= 1e2) print_hundred(n);
    else if(n >= 10) print_tens(n);
    else
    {
        if(n == 0) cout << "zero";
        else print_number(n);
    }
    // cout << '\n' << "n = " << n << '\n';
    return 0;
}