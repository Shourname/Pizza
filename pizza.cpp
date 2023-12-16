#include <iostream>
#include <string>
using namespace std;

class Pizza
{
    protected:
        string name;
        string description;
        int size;
        int salt;
        float cost;
        int cheese;

    public:
        Pizza(string NAME, string DESCRIPTION, int SIZE, float COST)
        {
            name = NAME;
            description = DESCRIPTION;
            size = SIZE;
            cost = COST;
        }

        virtual float Price()
        {
            float price = cost;

            if (size == 25 or size == 30 or size == 35 or size == 40) { price *= size / 10; } else { cout << "Неверный размер пиццы." << endl; return 1; }

            price += salt * 1.5;
            price += cheese * 1.8;

            return price;
        }

        virtual void PrintDescription()
        {
            cout << "- Пицца - " << name << endl;
            cout << "- Описание - " << description << endl;
            cout << "- Размер - " << size << endl;
            cout << "- Кол-во соли - " << salt << endl;
            cout << "- Кол-вo сыра - " << cheese << endl;
            cout << "- Итоговоя стоимость - " << Price() << "руб." << endl;
        }

        void SetSalt(int s) { salt = s; }
        void SetCheese(int c) { cheese = c; }
};

class PizzaSiciliana : public Pizza
{
    public:
        PizzaSiciliana(int ss) : Pizza("Сицилийская пицца", "Пицца, имеющая прямоугольную форму, а таже с томатной пастой и кольцами томата и чеснока", ss, 500) {}
};

class PizzaRomana : public Pizza
{
    public:
        PizzaRomana(int ss) : Pizza("Римская пицца", "Пицца на римском тесте и с сыром Буратта", ss, 300) {}
};

class Calzone : public Pizza
{
    public:
        Calzone(int ss) : Pizza("Кальцоне", "Закрытая форма пиццы в виде полумесяца", ss, 700) {}
};

class OrderPizza
{
    public:
        int totalPrice = 0;
        void AddPizza(float plusCost)
        {
            totalPrice += plusCost;
        }

        void PrintTotalPrice()
        {
            cout << "Итоговая стоимость всего заказа: " << totalPrice << "руб." << endl;
        }
    ;
};

int main()
{
    OrderPizza* order;
    char answer = 'y';
    int ansName, ansSize, Salt, Cheese;

    while (answer == 'y')
    {
        cout << "Выберите пиццу: (1) Сицилийская пицца, (2) Романская пицца, (3) Кальцоне" << endl;
        cin >> ansName;
        cout << "Выберите размер пиццы: 25, 30, 35, 40 " << endl;
        cin >> ansSize;

        Pizza* NowPizza = nullptr;

        switch (ansName) {
        case 1:
            NowPizza = new PizzaSiciliana(ansSize);
            break;
        case 2:
            NowPizza = new PizzaRomana(ansSize);
            break;
        case 3:
            NowPizza = new Calzone(ansSize);
            break;
        default:
            cout << "Неверный выбор" << endl;
            continue;
        }

        cout << "Введите кол-во. соли (0 - не солить) : "; cin >> Salt;
        cout << "Введите кол-во. сыра (0 - не сырить) : "; cin >> Cheese;

        NowPizza->SetSalt(Salt);
        NowPizza->SetCheese(Cheese);

        NowPizza->PrintDescription();

        float pr = NowPizza->Price();
        order->AddPizza(pr);
        delete NowPizza;

        cout << "Желаете добавить пиццу? (y - да, n - нет)" << endl; 
        cin >> answer;
    }

    order->PrintTotalPrice();

    return 0;
}
