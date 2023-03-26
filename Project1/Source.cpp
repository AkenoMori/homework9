#include <iostream>
class Electronic {
protected:
    std::string brand; // бренд
    std::string model; // модель
    double price; // цена

public:
    Electronic(const std::string& brand, const std::string& model, double price)
        : brand(brand), model(model), price(price) {}

    // методы доступа
    const std::string& getBrand() const { return brand; }
    const std::string& getModel() const { return model; }
    double getPrice() const { return price; }

    // метод вывода информации об устройстве
    virtual void printInfo() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};
class Laptop : public Electronic {
protected:
    std::string cpu; // процессор
    int ram; // оперативная память
    int storage; // внутренняя память

public:
    Laptop(const std::string& brand, const std::string& model, double price, const std::string& cpu, int ram, int storage)
        : Electronic(brand, model, price), cpu(cpu), ram(ram), storage(storage) {}

    // метод вывода информации о ноутбуке
    virtual void printInfo() const override {
        Electronic::printInfo(); // вызываем метод базового класса
        std::cout << "CPU: " << cpu << std::endl;
        std::cout << "RAM: " << ram << "GB" << std::endl;
        std::cout << "Storage: " << storage << "GB" << std::endl;
    }
};

class Smartphone : public Electronic {
protected:
    std::string os; // операционная система
    int camera; // разрешение камеры

public:
    Smartphone(const std::string& brand, const std::string& model, double price, const std::string& os, int camera)
        : Electronic(brand, model, price), os(os), camera(camera) {}

    // метод вывода информации о смартфоне
    virtual void printInfo() const override {
        Electronic::printInfo(); // вызываем метод базового класса
        std::cout << "OS: " << os << std::endl;
        std::cout << "Camera: " << camera << "MP" << std::endl;
    }
};

class Smartwatch : public Electronic {
protected:
    std::string os; // операционная система
    std::string color; // цвет

public:
    Smartwatch(const std::string& brand, const std::string& model, double price, const std::string& os, const std::string& color)
        : Electronic(brand, model, price), os(os), color(color) {}

    // метод вывода информации о смарт-часах
    virtual void printInfo() const override {
        Electronic::printInfo(); // вызываем метод базового класса
        std::cout << "OS: " << os << std::endl;
        std::cout << "Color: " << color << std::endl;
    }
};

class SmartphoneWithGPS : public Smartphone {
protected:
    bool gps; // наличие GPS

public:
    SmartphoneWithGPS(const std::string& brand, const std::string& model, double price, const std::string& os, int camera, bool gps)
        : Smartphone(brand, model, price, os, camera), gps(gps) {}

    // метод вывода информации о смартфоне с GPS
    virtual void printInfo() const override {
        Smartphone::printInfo(); // вызываем метод базового класса
        std::cout << "GPS: " << (gps ? "Yes" : "No") << std::endl;
    }
};
int main() {
    // Создание объектов
    Laptop laptop("Apple", "Macbook Pro", 1999.99, "Intel Core i9", 16, 512);
    Smartphone smartphone("Samsung", "Galaxy S21", 799.99, "Android", 108);
    Smartwatch smartwatch("Apple", "Watch Series 6", 399.99, "watchOS", "Silver");
    SmartphoneWithGPS smartphoneWithGPS("Apple", "iPhone 12", 799.99, "iOS", 12, true);

    // Вызов методов для вывода информации
    std::cout << "Laptop info:" << std::endl;
    laptop.printInfo();
    std::cout << std::endl;

    std::cout << "Smartphone info:" << std::endl;
    smartphone.printInfo();
    std::cout << std::endl;

    std::cout << "Smartwatch info:" << std::endl;
    smartwatch.printInfo();
    std::cout << std::endl;

    std::cout << "Smartphone with GPS info:" << std::endl;
    smartphoneWithGPS.printInfo();
    std::cout << std::endl;

    return 0;
}