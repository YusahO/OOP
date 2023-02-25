#ifndef __ERROR_PROCESSOR_H__
#define __ERROR_PROCESSOR_H__

// #include <QString>
// #include <QMessageBox>

enum error_code_t
{
    SUCCESS,
    ERR_ALLOC,
    ERR_INVALID_PTR_PASSED,
    ERR_MESH_NOT_LOADED,
    ERR_OPENING_FILE,
    ERR_LOADING_MESH,
    ERR_INCORRECT_USER_INPUT,
    ERR_INCORRECT_VERTEX_DATA,
    ERR_INSUFFICIENT_VERTEX_DATA,
    ERR_INCORRECT_LINKAGE_DATA,
    ERR_INSUFFICIENT_LINKAGE_DATA
};

void process_error(const error_code_t &ec);

#endif // __ERROR_PROCESSOR_H__