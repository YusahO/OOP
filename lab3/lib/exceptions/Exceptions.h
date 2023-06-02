#pragma once

#include <exception>
#include <cstdio>
#include <source_location>

#define ERROR_MESSAGE_BUFFER_SIZE 512

class BaseException : public std::exception
{
public:
    BaseException(
        const char *filename,
        const char *funcname,
        const int line,
        const char *errortype = "Error") noexcept
    {
        snprintf(msg, size_buf,
            "\033[31m%s\033[37m in file %s(%d) in function \n\t%s\n",
            errortype, filename, line, funcname);
    }

    virtual const char *what() const noexcept override
    {
        return msg;
    }

private:
    static constexpr size_t size_buf = ERROR_MESSAGE_BUFFER_SIZE;
    char msg[size_buf] {};
};


class CameraException : public BaseException
{
public:
    explicit CameraException(
        const char *filename,
        const char *funcname,
        const int line,
        const char *errortype = "Camera error") noexcept
        : BaseException(filename, funcname, line, errortype)
    {
    }
};


class SourceException : public BaseException
{
public:
    explicit SourceException(
        const char *filename,
        const char *funcname,
        const int line,
        const char *errortype = "Load error") noexcept
        : BaseException(filename, funcname, line, errortype)
    {
    }
};


class ModelException : public BaseException
{
public:
    explicit ModelException(
        const char *filename,
        const char *funcname,
        const int line,
        const char *errortype = "Model build") noexcept
        : BaseException(filename, funcname, line, errortype)
    {
    }
};
