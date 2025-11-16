#include <string>

using std::string;

class Zmogus {
    protected:
        string vardas_;
        string pavarde_;
    public:
        Zmogus() = default;
        Zmogus(string v, string p) : vardas_{v}, pavarde_{p} {};
        virtual inline string vardas() const = 0;
        virtual inline string pavarde() const = 0;
        virtual ~Zmogus() {};
};