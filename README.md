# Anilibria desktop client

В данный момент приложение находиться в глубокой стадии разработки поэтому воспринимать его как готовое к полноценному использованию не стоит, потому что приложение может не стабильно работать либо не работать вообще, также в нем может не быть очевидного для Вас функционала. Но если все же Вас это не останавливает не забывайте отписываться о проблемах в этом репозитории, заранее спасибо.

## Системные требования:

**Windows** - Windows 7+  
**macOS** - macOS 10.13+  
**Linux** - дистрибутивы поддерживающие AppImage, сборка из исходников для остальных

## Дополнительные компоненты необходимые для установки:

**Windows** - для полноценной работы видеоплеера необходимо установить [LAV filters](https://github.com/Nevcairiel/LAVFilters/releases).

## Сборка из исходников:

### Для сборки необходимо:
- Минимальная поддерживаемая версия Qt 5.12.3
- Поддержка C++11 (минимальные версии компиляторов MSVC15, GCC 4.8 или CLANG 3.3)
- Для сборки проекта используется qmake

### Linux

OpenSSL для Qt 5.12.3-5.12.5 **1.0.2**, Qt 5.12.5+ **1.1.1**  
GStreamer 1.0

```bash
cd src
qmake
make
make install
```
