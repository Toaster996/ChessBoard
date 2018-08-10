#include <iostream>
using namespace std;

class Field
{
  public:
    Field();
    Field(char ident);
    void setIdentifier(char ident, int player);
    char getIdentifier();

  private:
    char identifier;
    int playerNumber;
};

Field::Field()
{
    identifier = 'x';
}

Field::Field(char ident)
{
    identifier = ident;
}

void Field::setIdentifier(char ident, int player)
{
    identifier = ident;
    playerNumber = player;
}

char Field::getIdentifier(){
    return identifier;
}