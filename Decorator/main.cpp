#include <iostream>
#include "Decorator.h"
int main(int argc, char** argv)
{
    int c;
    do
    {
        cout << "**Choose your pizza**\n";
        cout << "1* Base Pizza\n2* With chees\n3* With Mahsroom and chees\n4* With "
                "tomato and chees\n5* With chees, tomato and mashroom\n0* Exit"
             << endl;
        cin >> c;
        Pizza* p = PizzaFactory::getMyPizza(c);
        if (p)
        {
            cout << "Your order: " << p->getDesc() << "\nPrice: " << p->getCost();
            cout << "\n**************************************************************"
                    "**"
                    "*****\n";
            delete (p);
        }

    } while (c != 0);
}