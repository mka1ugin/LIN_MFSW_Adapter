# LIN_MFSW_Adapter

Проект адаптера для установки новых MQB мультирулей на автомобили платформы PQ.

Аппаратно адаптер выполнен на микроконтроллере STM32F103C8T6, схема и печатная плата разработаны в среде KiCad. Печатная плата односторонняя, габаритные размеры 43 x 26 мм.
В микроконтроллере задействованы 2 UART-порта, сконфигурированные в режиме LIN. UART1 работает в режиме Master и отправляет запросы на блок кнопок, UART2 в режиме Slave
обрабатывает запросы от подрулевого блока.
Прошивка написана в среде Keil 5 с использованием STM32Cube MX. Все действия выполняются в callback-функциях по окончании приёма/передачи по UART. 

Устройство испытано на VW Passat B6 с подрулевым блоком 5K0953569T (SW 0180) и мультирулём 5E3419093CVKH. Его кнопки максимально имитируют работу кнопок старого 12-кнопочного
руля. Кнопки вызова ассистентов, управления обогревом руля и включения круиза пока не задействованы.
Сам адаптер установлен прямо в мультируль, под него вырезано место (на версиях мультируля с датчиками KLR здесь установлен контроллер KLR).
![skoda_mqb_steering_on_pq46](https://user-images.githubusercontent.com/62425725/210203639-a533e3e3-a7ce-4d8a-91e1-b8231dde0e3e.jpg)
![device](https://user-images.githubusercontent.com/62425725/210203677-e6caa57b-e54c-4008-92ee-f6c950cfd3ae.jpg)
