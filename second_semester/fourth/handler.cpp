#include <iostream>

using namespace std;

class Handler {
	public:
	virtual void preProcess() {
	}

	virtual void postProcess() {
	}

	virtual bool accessAllowed(string username) {
		return true;
	}
	
	virtual void run() = 0;

	virtual ~Handler() = default;
};

// Должен не работать, так как не предоставляет run
class BadHandler : public Handler {
};

// Должен технически корректно работать
class DummyHandler : public Handler {
public:
    void run() {
        cout << "DummyHandler runs" << endl;
    }
};

// Должен технически корректно работать 
// и использовать собственные реализации всех методов
class SmartHandler : public Handler {
public:
    void preProcess() {
        cout << "SmartHandler preprocess" << endl;
    }
    
    void postProcess() {
        cout << "SmartHandler postprocess" << endl;
    }
    
    bool accessAllowed(string username) {
        return "admin" == username;
    }
    
    void run() {
        cout << "SmartHandler runs" << endl;
    }
};

// Должен технически корректно работать
// и очистить память за собой
class HeavyHandler : public Handler {
protected:
    int* data;
public:
    HeavyHandler() {
        data = new int[1000];
    }
    ~HeavyHandler() {
        delete[] data;
    }

    void run() {
        cout << "HeavyHandler runs" << endl;
    }
};

int main()
{
    // Приём запроса. Извлечение данных пользователя.
    // ... происходит какая-то работа, возникает имя пользователя ...
    string username = "some_user_name";

    // Выполнение какой-то логики для выбора нужного обработчика.
    // Допустим, нужен обработчик SomeHandler. Создаём его.
    Handler* h = new DummyHandler();

    // Далее идёт блок, единый для всех типов обработчиков,
    // ради него и задуман общий интерфейс и базовый класс.

    // Выполнить предварительные действия
    h->preProcess();
    // Проверить, разрешён ли доступ данному пользователю
    if(h->accessAllowed(username)) {
        // Если доступ разрешён, выполнить обработку запроса
        h->run();
    }
    // Выполнить завершающие действия
    h->postProcess();

    // Удалить экземпляр обработчика
    delete h;

    return 0;
};
