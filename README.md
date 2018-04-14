# C++ Bjorklund Algorithm



I'm Greatfull to Sergio Castro for his code

https://bitbucket.org/sjcastroe/bjorklunds-algorithm

I reimplement it to fit in a simple std::vector<int>

there is also a shift method

and a print vector

et voilà

```c++
int main() {

    auto kick = bjorklund(16, 4);      // the basic 4/4
    cout << kick << endl;     //1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0

    auto hh = shift(kick, 2);
    cout << hh << endl;     //0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0

    cout<< pressets["afro"] << endl;
    //1 0 1

    return 0;
}
```



Here is the genesis of this code

https://stimresp.wordpress.com/2014/10/18/bjorklund-the-algorithm-in-c/

And the research paper of course by Toussaint

http://cgm.cs.mcgill.ca/~godfried/publications/banff.pdf

