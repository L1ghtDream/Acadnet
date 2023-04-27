#include <bits/stdc++.h>

// Absolut (1L) pattern
// Hai noroc!
// Understand how this class is used.
// Hint: Order a single Absolut.
class GigelAbsolut {
private:
    GigelAbsolut() : m_count(0) {}
public:
    ~GigelAbsolut() {}
    GigelAbsolut(const GigelAbsolut&) = delete;
    GigelAbsolut(GigelAbsolut&&) = delete;
    GigelAbsolut& operator=(const GigelAbsolut&) = delete;
    GigelAbsolut& operator=(GigelAbsolut&&) = delete;

    void update() { ++m_count; }
    int get_count() { return m_count; }

    static GigelAbsolut& getUniqueGigel();

private:
    int m_count;
};

int read_input()
{
    int n;
    std::cin >> n;
    return n;
}

void write_output(int n)
{
    std::cout << n << "\n";
}

int main()
{
    // read input
    int n = read_input();

    for (int i = 0; i < n; ++i) {
        // I want a GigelAbsolut, give me one
        GigelAbsolut& gigelAbsolut = GigelAbsolut::getUniqueGigel();
        // apply an update
        gigelAbsolut.update();
    }

    // get the number of updates and save it to a file
    GigelAbsolut& gigelAbsolut = GigelAbsolut::getUniqueGigel();
    write_output(gigelAbsolut.get_count());

    return 0;
}

// This is a function which always returns the same GigelAbsolut
// object. Is this the effect of the alcohol? Maybe, who knows...
GigelAbsolut& GigelAbsolut::getUniqueGigel()
{
    static GigelAbsolut g = GigelAbsolut();
    return g;
}
