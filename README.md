# MorseCodeBlink
**Вводная:** Имеется отладочная плата на микроконтроллере STM32F407 (пример). К контакту PD4 подключен транзистор, управляющий светодиодом («1» на выходе – светодиод вкл., «0»-выкл.) По адресу 0х20001234 в памяти микроконтроллера хранится текстовая строка «HELLO WORLD», состоящая только из заглавных символов латинского алфавита. 

**Задача:**  Проинициализировать выход микроконтроллера и воспроизвести строку с помощью светодиода и [азбуки Морзе](https://ru.wikipedia.org/wiki/%D0%90%D0%B7%D0%B1%D1%83%D0%BA%D0%B0_%D0%9C%D0%BE%D1%80%D0%B7%D0%B5).

**Прочие условия и комментарии:** Задача должна быть решена с использованием языка C. Допустимо изменить производителя/модель микроконтроллера в задаче. Для уменьшения трудоемкости в коде реализации не обязательно указывать константы для всех букв, только необходимые. Для инициализации «ног» возможно использование стандартных библиотек или прямой доступ к регистрам микроконтроллера. Для возможности тестирования и отладки рекомендуется самостоятельно записать строку «HELLO WORLD» в область памяти.


