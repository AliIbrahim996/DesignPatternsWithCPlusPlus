#include <List>
#include <iostream>
using namespace std;
class Pizza;
class Component;

class Pizza {
public:
  virtual double getCost() = 0;
  virtual string getDesc() = 0;
};

class Decorator : public Pizza {
protected:
  Pizza *p;

public:
  Decorator(Pizza *p) : p(move(p)){};
  virtual string getDesc() {
    if (p)
      return p->getDesc();
  }
  virtual double getCost() {
    if (p)
      return p->getCost();
  }
  ~Decorator() { delete (p); }
};

class BasePizza : public Pizza {
  string getDesc() override { return "Base pizza "; }
  double getCost() override { return 1.0; }
};

class WithTomato : public Decorator {
public:
  WithTomato(Pizza *base) : Decorator(base){};
  string getDesc() override {
    return Decorator::getDesc().append(" with tomato");
  }
  double getCost() override { return Decorator::getCost() + 2.5; }
};

class WithChees : public Decorator {
public:
  WithChees(Pizza *base) : Decorator(base){};
  string getDesc() override {
    return Decorator::getDesc().append(" with chees");
  }
  double getCost() override { return Decorator::getCost() + 3.5; }
};

class WithMashroom : public Decorator {
public:
  WithMashroom(Pizza *base) : Decorator(base){};
  string getDesc() override {
    return Decorator::getDesc().append(" with mashroom");
  }
  double getCost() override { return Decorator::getCost() + 2.0; }
};
class PizzaFactory {
public:
  static Pizza *getMyPizza(int c) {
    switch (c) {
    case 1:
      return new BasePizza();
      break;
    case 2:
      return new WithChees(new BasePizza());
      break;
    case 3:
      return new WithMashroom(new WithChees(new BasePizza()));
      break;
    case 4:
      new WithTomato(new WithChees(new BasePizza()));
      break;
    case 5:
      new WithMashroom(new WithChees(new WithTomato(new BasePizza())));
      break;
    default:
      return nullptr;
      break;
    }
  }
};
int main(int argc, char **argv) {
  cout << "**Choose your pizza**\n";
  cout << "1* Base Pizza\n2* With chees\n3* With Mahsroom and chees\n4* With "
          "tomato and chees\n5* With chees, tomato and mashroom\n0* Exit"
       << endl;
  int c;
  while (cin >> c) {
    Pizza *p = PizzaFactory::getMyPizza(c);
    if (p) {
      cout << "Your order: " << p->getDesc() << "\nPrice: " << p->getCost();
      cout << "\n**************************************************************"
              "**"
              "*****\n";
      delete (p);
    }
    cout << "**Choose your pizza**\n";
    cout << "1* Base Pizza\n2* With chees\n3* With Mahsroom and chees\n4* With "
            "tomato and chees\n5* With chees, tomato and mashroom\n0* Exit"
         << endl;
  }
}
