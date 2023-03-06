#include "error_processor.h"
#include <QString>
#include <QMessageBox>

#define MBOX_WIDTH 500
#define MBOX_HEIGHT 300

void process_error(const error_code_t &ec)
{
    QMessageBox messagebox;
    messagebox.setFixedSize(MBOX_WIDTH, MBOX_HEIGHT);

    switch (ec)
    {
    case SUCCESS:
        return;
    case ERR_ALLOC:
        messagebox.critical(nullptr, "Ошибка", "Не удалось выделить память");
        break;
    case ERR_OPENING_FILE:
        messagebox.critical(nullptr, "Ошибка", "Не удалось открыть файл");
        break;
    case ERR_MESH_NOT_LOADED:
        messagebox.warning(nullptr, "Предупреждение", "Пожалуйста, загрузите модель");
        break;
    case ERR_INCORRECT_VERTEX_DATA:
        messagebox.critical(nullptr, "Ошибка", "Данные о вершинах некорректны");
        break;
    case ERR_INSUFFICIENT_VERTEX_DATA:
        messagebox.critical(nullptr, "Ошибка", "Данных о вершинах недостаточно");
        break;
    case ERR_INCORRECT_LINKAGE_DATA:
        messagebox.critical(nullptr, "Ошибка", "Данные о связях вершин некорректны");
        break;
    case ERR_INSUFFICIENT_LINKAGE_DATA:
        messagebox.critical(nullptr, "Ошибка", "Данных о связях вершин недостаточно");
        break;
    case ERR_INCORRECT_USER_INPUT:
        messagebox.critical(nullptr, "Ошибка", "Невозможно обработать введенные данные");
        break;
    case ERR_INVALID_PTR_PASSED:
        messagebox.critical(nullptr, "Ошибка", "Невозможно обработать данные");
        break;
    case ERR_UNKNOWN_ACTION:
        messagebox.critical(nullptr, "Ошибка", "Неизвестное действие");
        break;
    default:
        messagebox.critical(nullptr, "Ошибка", "Произошла неизвестная ошибка");
        break;
    }
}
