#ifndef decorator_h
#define decorator_h
#include <List>
#include <iostream>
using namespace std;


/**
 * @brief Pizza Interface
 */
class Pizza
{
public:
    /*!
     *  Returns the pizza's cost.
     *
     *      @return The cost.
     */
    virtual double getCost() = 0;

    /*!
     *  Returns the pizza's Description.
     *
     *      @return The description.
     */
    virtual string getDesc() = 0;
};

/**
 * @brief Decorator abstract class inorder to inheriht pizza kinds
 */
class Decorator : public Pizza
{
protected:
    Pizza* p;


public:
    /*!
     *  Constructor.
     *
     *      @param [in] p , refers to The Pizza type
     */
    explicit Decorator(Pizza* p);
    /*!
     *  Returns the decorated pizza's cost.
     *
     *      @return The cost.
     */
    virtual string getDesc();
    /*!
     *  Returns the decorated pizza's Description.
     *
     *      @return The description.
     */
    virtual double getCost();
    ~Decorator();
};

/**
 * @brief BasePizza class to make a base pizza without Ingredients .
 */

class BasePizza : public Pizza
{
    /*!
     *  Returns the base pizza's desc.
     *
     *      @return The desc.
     */
    string getDesc() override;
    /*!
     *  Returns the base pizza's cost.
     *
     *      @return The cost.
     */
    double getCost() override;
};

/**
 * @brief WithTomato class to add tomato to pizza Ingredients .
 */
class WithTomato : public Decorator
{
public:
    /*!
     *  Constructor.
     *
     *      @param [in] base
     */
    explicit WithTomato(Pizza* base);
    /*!
     *  Returns pizza with tomato desc.
     *
     *      @return The desc.
     */
    string getDesc() override;
    /*!
     *  Returns the feature cost
     *
     *      @return The cost.
     */
    double getCost() override;
};
/**
 * @brief WithChees class to add chees to pizza Ingredients .
 */
class WithChees : public Decorator
{
public:
    /*!
     *  Constructor.
     *
     *      @param [in] base
     */
    WithChees(Pizza* base);
    /*!
     *  Returns pizza with Chees desc.
     *
     *      @return The desc.
     */
    string getDesc() override;
    /*!
     *  Returns the feature cost
     *
     *      @return The cost.
     */
    double getCost() override;
};
/**
 * @brief WithMashroom class to add mashroom to pizza Ingredients .
 */
class WithMashroom : public Decorator
{
public:
    /*!
     *  Constructor.
     *
     *      @param [in] base
     */
    WithMashroom(Pizza* base);
    /*!
     *  Returns pizza with Mashroom desc.
     *
     *      @return The desc.
     */
    string getDesc();
    /*!
     *  Returns the feature cost
     *
     *      @return The cost.
     */
    double getCost() override;
};
/**
 * @brief A Factory class to generate Pizza accourding to user input.
 */

class PizzaFactory
{
public:
    /*!
     *  Returns the client pizza.
     *
     *      @param [in] type.
     *
     *      @return The new pizza.
     */
    static Pizza* getMyPizza(int type);
};
#endif
