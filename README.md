# Portfolio

Добро пожаловать в мой портфолио! Здесь собраны некоторые из моих проектов, демонстрирующие мои навыки в программировании на C и C++.

## Библиотеки

В этом репозитории вы найдете три библиотеки, которые являются аналогами стандартных библиотек:

* **decimal_lib**: библиотека для работы с большими числами (в диапазоне -10^32 до 10^32), написанная на C.
* **string_lib**: библиотека для работы со строками (аналог `std::string`), написанная на C++.
* **container_lib**: библиотека для работы с контейнерами (аналог `std::vector`, `std::list`, `std::map` и др.), написанная на C++.

Эти библиотеки я писал в группах с другими людьми (по 3-4 человека), например в контейнерах я реализовывал структуры, основанные на AVL-дереве, то есть само дерево, словарь и множество.

## Тетрис

В этом репозитории также находятся две версии игры Тетрис:

* **BrickGame_v1.0**: консольная версия игры Тетрис, написанная на C.
* **BrickGame_v2.0**: версия игры Тетрис с консольным и десктопным отображением, написанная на C++ с использованием библиотеки QT.

Это два полностью личных проекта и фронт, и бэк, и тесты которого я писал сам. Во второй версии помимо тетриса, реализована змейка, у обоих версий есть сохранение максимального счёта и ускорение игры по мере прохождения. 

## Использование

Чтобы использовать эти проекты, просто клонируйте репозиторий и запустите команду `make` в папке src. Это создаст исполняемый файл (или файл библиотеки) для каждого проекта.

Все проекты сделаны с полным покрытием тестами (>95%)
