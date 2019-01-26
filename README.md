[![Build Status](https://travis-ci.com/farafonov-alexey/node-atol-wrapper.svg?branch=master)](https://travis-ci.com/farafonov-alexey/node-atol-wrapper)

Название
=========
Node.js обертка для драйвера торгового оборудования (ДТО) версии 10 от компании [АТОЛ](https://www.atol.ru/)

[Документация по интеграции](http://integration.atol.ru/)

Функции
========
Реализованы следующие методы работы с драйвером
* create() -  Инициализация драйвера 
* destroy() - Деинициализация драйвера
* getSettings() - Выгрузка настроек

Возвращает json-объект настроек, который затем можно передать в функцию setSettings
```js
{ AccessPassword: '',
  AutoDisableBluetooth: false,
  AutoEnableBluetooth: true,
  BaudRate: 115200,
  Bits: 8,
  ComFile: '1',
  IPAddress: '192.168.1.10',
  IPPort: 5555,
  LibraryPath: '',
  MACAddress: 'FF:FF:FF:FF:FF:FF',
  Model: 500,
  OfdChannel: 0,
  Parity: 0,
  Port: 0,
  StopBits: 0,
  UsbDevicePath: 'auto',
  UserPassword: '' }
```
* setSettings(settings) - Настройка драйвера

Принимает _settings_ json-объект настроек полученных на предыдущем шаге и модифицированых по необходимости.
* open() - Соединение с ККТ
* close() - Завершение соединения с ККТ
* processJson(task) - Выполнение JSON-задания

Здесь _task_ - json-объект описание задания для ККТ. Например, задание для открытия смены:
```js
{
    type: 'openShift',
    operator: {
       name: 'Иванов',
       vatin: '123654789507'
    }
}
```
Более подробную информацию по видам json-задании можно получить из документации к [ДТО 10](http://fs.atol.ru/SitePages/%D0%A6%D0%B5%D0%BD%D1%82%D1%80%20%D0%B7%D0%B0%D0%B3%D1%80%D1%83%D0%B7%D0%BA%D0%B8.aspx?raz1=%D0%9F%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%BD%D0%BE%D0%B5+%D0%BE%D0%B1%D0%B5%D1%81%D0%BF%D0%B5%D1%87%D0%B5%D0%BD%D0%B8%D0%B5&raz2=%D0%94%D0%A2%D0%9E&raz3=10.x).
#### Обработка ошибок
При возникновении ошибки во время выполнения функций ДТО, она обрабытвается и выбрасывается Error c текстом ошибки, 
например, Error: Ошибка - 4 [ Порт недоступен ].

### Поддерживаемые платформы:
* Widows, Linux

Пример использования
========
Пример использования обертки можно посмотерть в файле index.js
