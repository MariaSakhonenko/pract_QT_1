#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
/*
1. Запустите приложение.
2. Выберите фигуру из выпадающего списка "Shape".
3. Введите значения длины, ширины и высоты в соответствующие текстовые поля.
4. Нажмите кнопку "Calculate", чтобы вычислить площадь фигуры.
5. Результат будет отображен под кнопкой "Calculate" в виде текста "Square: [значение площади]".
6. Если вы хотите сохранить результат в файл, установите флажок "Save to file".
7. Для обработки других фигур повторите шаги 2-6, выбрав соответствующую фигуру из выпадающего списка.
8. Если введены некорректные значения (например, отрицательные числа), будет выведено сообщение об ошибке.
9. Если произойдет деление на ноль при вычислении площади, также будет выведено сообщение об ошибке.
*/
