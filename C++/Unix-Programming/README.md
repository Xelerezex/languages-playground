# Conspectus


## Файлы:

Существует несколько типов файло в *UNIX*-системах:

-   Обычные файлы.
-   Каталоги.
-   Символические связи.
-   Специальные файлы.
-   Именованные каналы.
-   Сокеты.

#### Обычные файлы:

(Regular file) - Содержит байты данныхб которые организуются в одномерный непрерывный массив.
Любой байт или последовательность байтов можно **прочитать** или **записать**.
Чтение и запись начинаются с байта, определяемого **смещением в файле** (file offset), значение оффсета может быть
любой байт, даже за пределами файла.

Нельзя вставить байты в середину, только в конец. Удаление и вставка происходят только в конце, так можно изменить
размер файла до любого значения.

Файл могу читать сразу несколько процессов, что б не было коллизий - используются семафоры.

У файлов нет имен - лишь индексы (номера).

Индекс относится к массиву **индексных узлов**, хранящихся перед каждой областью файловой системы.
Каждый индекс содержит следующую информацию:

-   Тип файла.
-   Число связей.
-   Пользовательский идентификатор владельца.
-   Груповой идентификатор владельца.
-   Значения прав доступа к файлу у владельца.
-   Значения прав доступа к файлу у группы.
-   Значения прав доступа к файлу у других пользователей.
-   Размер файла в байтах.
-   Время последнего обращения.
-   Время последнего изменения.
-   Время последнего изменения индексного узла файла.
-   Указатель на блок диска, где хранится файл.

#### Каталог:

Католог создан для удобства, т.к. обращаться к файлу каждый раз через индексные дескрипторы неудобно.
Каталог эе позваляет обращение по **имени** файла

Концептуально каталог - это таблица, с двумя столбцами ```{имя, индекс}```. Пара ```{имя, индекс}``` называется
**связью** (link).

Обращения к файлу происходят следующим образом:

```commandline
    имя файла   ->  индекс   ->  индексный узел   ->  получение информации о файле, либо сами данные.
```

Каталог очень похож на обычный файл: он тоже имеет индексный узел и содержит данные. Это значит, что в каталоге
может хранится индексный узел другого каталога, а значит выйдет организовать иерархию файлов.

Для работы с каталогами предусмотрены специальные системные вызовы, вручную изенять их нельзя. Это сделанно потому,
что каталоги используются ядром, и одна неверная запись может порушить всю систему.

#### Символическая связь:

Специальный файл в файловой системе, в котором вместо пользовательских данных содержится путь к файлу,
открываемому при обращении к данной ссылке (файлу).

Целью ссылки может быть любой объект: например другая ссылка, файл, каталог или даже несуществующий файл
(в последнем случае при попытке открыть его должно выдаваться сообщение об отсутствии файла). Ссылка,
указывающая на несуществующий файл, называется висячей или битой.

Символические ссылки используются для более удобной организации структуры файлов на компьютере, так как:

-    позволяют для одного файла или каталога иметь несколько имён и различных атрибутов.
-    свободны от некоторых ограничений, присущих жёстким ссылкам (последние действуют только в пределах
     одной файловой системы (одного раздела) и не могут ссылаться на каталоги).

#### Специальные файлы:

Обычно это како-то устройство типа CD-ROM или канала связи.

Специальные файлы устрйоств делятся на два основных типа:
-   **Блочные специальные файлы** - соответсвуют конкретной модели, устройство содержит массив блоков фиксированного
    размера.
-   **Символьные специальные файлы** - не определяются никакими правилами.

Специальный файл имеет индексный узел, но он не указывает ни на какие данные на диске. Вместо этого индексный узел
содержит **номер устройства** - индекс в таблице, которую ядро использует для нахождения набора функций, называемого
**драйвером устройства**.

