#include <vector>

class SpacePort
{
public:
    // Создать космодром, в котором size штук доков.
    // Доки нумеруются от 0 до size-1.
    // В момент создания все доки свободны.
    SpacePort(unsigned int size): docks(size, true) {
    }

    // Запросить посадку в док с номером dockNumber.
    // Если такого дока нет - вернуть false (запрет посадки).
    // Если док есть, но занят - вернуть false (запрет посадки).
    // Если док есть и свободен - вернуть true (разрешение посадки) и док становится занят.
    bool requestLanding(unsigned int dockNumber) {
	    if (dockNumber < size && docks[dockNumber]) {
		    docks[dockNumber] = false;
		    return true;
	    }
	    return false;
    }

    // Запросить взлёт из дока с номером dockNumber.
    // Если такого дока нет - вернуть false (запрет взлёта).
    // Если док есть, но там пусто - вернуть false (запрет взлёта).
    // Если док есть и в нём кто-то стоит - вернуть true (разрешение взлёта) и док становится свободен.
    bool requestTakeoff(unsigned int dockNumber) {
	    if (dockNumber < size && docks[dockNumber]) {
		    return false;
	    }
	    docks[dockNumber] = true;
	    return true;
    }

private:
	    std::vector<bool> docks;
};
