#include <iostream>
using namespace std;

class Field
{
  public:
    Field();
    Field(wchar_t ident);
    void setIdentifier(wchar_t ident, int player);
    wchar_t getIdentifier();

  private:
    wchar_t identifier;
    int playerNumber;
};

Field::Field()
{
    identifier = 'x';
}

Field::Field(wchar_t ident)
{
    identifier = ident;
}

void Field::setIdentifier(wchar_t ident, int player)
{
    identifier = ident;
    playerNumber = player;
}

wchar_t Field::getIdentifier(){
    return identifier;
}