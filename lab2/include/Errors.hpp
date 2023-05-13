#pragma once

#include <exception>
#include <cstdio>
#include <source_location>

#define ERROR_MESSAGE_BUFFER_SIZE 512

class BaseError : public std::exception
{
public:
    BaseError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errortype = "Error") 
    {
        sprintf(msg,
            "\033[31m%s\033[37m in file %s(%d) in function \n\t%s \n %s",
            errortype, filename, line, funcname, time);
    }

    virtual const char *what() const noexcept override
    {
        return msg;
    }

private:
    static constexpr size_t size_buf = ERROR_MESSAGE_BUFFER_SIZE;
    char msg[size_buf]{};
};

class IteratorError : public BaseError
{
public:
    IteratorError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errortype = "Invalid object access error")
        : BaseError(filename, funcname, line, time, errortype)
    {
    }
};

class TreeError : public BaseError
{
public:
    TreeError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errortype = "Invalid object access error")
        : BaseError(filename, funcname, line, time, errortype)
    {
    }
};

class InvalidIteratorError : public IteratorError
{
public:
    InvalidIteratorError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errortype = "Invalid object access error")
        : IteratorError(filename, funcname, line, time, errortype)
    {
    }
};

class IteratorOutOfBoundsError : public IteratorError
{
public:
    IteratorOutOfBoundsError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errortype = "Out of bounds access error")
        : IteratorError(filename, funcname, line, time, errortype)
    {
    }
};

class TreeBadAlloc : public TreeError
{
public:
    TreeBadAlloc(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errortype = "Could not allocate tree element")
        : TreeError(filename, funcname, line, time, errortype)
    {
    }
};

class TreeCopyError : public TreeError
{
public:
    TreeCopyError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errortype = "Tree copy from invalid source error")
        : TreeError(filename, funcname, line, time, errortype)
    {
    }
};

class InvalidTreeError : public TreeError
{
public:
    InvalidTreeError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errortype = "Empty tree access error")
        : TreeError(filename, funcname, line, time, errortype)
    {
    }
};

