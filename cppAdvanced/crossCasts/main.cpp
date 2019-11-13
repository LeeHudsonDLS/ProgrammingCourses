////////////////////////////////////////////////////////////
//
//		Cross Casts
//
////////////////////////////////////////////////////////////

#include <vector>
using namespace std;


struct Base             { virtual void f() {} };
struct LX : public Base { virtual void lf() {} };
struct LY : public LX   { virtual void lf() {} };
struct LZ : public LY   { virtual void lf() {} };
struct RX : public Base { virtual void rf() {} };
struct RY : public RX   { virtual void rf() {} };
struct RZ : public RY   { virtual void rf() {} };

//////

int main()
{
    vector<Base*> theList;

    theList.push_back(new Base);
    theList.push_back(new LX);
    theList.push_back(new LY);
    theList.push_back(new LZ);
    theList.push_back(new RX);
    theList.push_back(new RY);
    theList.push_back(new RZ);

    for(auto i = 0; i < theList.size(); i++)
    {
        // dynamic_cast acts as a filter
        LX* p = dynamic_cast<LX*>(theList[i]);
        if(p) p->lf();
    }
}

