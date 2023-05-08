#pragma once

#include <exception>
#include <string>

class BaseError : public std::exception
{
public:
    BaseError(const std::string &filename,
              const std::string &classname,
              int line,
              const std::string &errType = "Error")
    {
        m_errorInfo = "\n" + errType +
                      " in file " + filename +
                      "(" + std::to_string(line) + ")\n" +
                      "Class: " + classname + "\n";
    }

    virtual const char *what() const noexcept override
    {
        return m_errorInfo.c_str();
    }

    virtual ~BaseError() = default;

protected:
    std::string m_errorInfo;
};

class MemoryError : public BaseError
{
public:
    MemoryError(const std::string &filename,
                const std::string &classname,
                int line,
                const std::string &errType = "Memory allocation error")
        : BaseError(filename, classname, line, errType)
    {
    }
};

class DeletedObjectError : public BaseError
{
public:
    DeletedObjectError(const std::string &filename,
                       const std::string &classname,
                       int line,
                       const std::string &errType = "Deleted object access error")
        : BaseError(filename, classname, line, errType)
    {
    }
};

class InvalidIteratorError : public BaseError
{
public:
    InvalidIteratorError(const std::string &filename,
                         const std::string &classname,
                         int line,
                         const std::string &errType = "Invalid iterator access error")
        : BaseError(filename, classname, line, errType)
    {
    }
};

class InvalidPointerError : public BaseError
{
public:
    InvalidPointerError(const std::string &filename,
                        const std::string &classname,
                        int line,
                        const std::string &errType = "Invalid pointer access error")
        : BaseError(filename, classname, line, errType)
    {
    }
};

class EmptyTreeError : public BaseError
{
public:
    EmptyTreeError(const std::string &filename,
                   const std::string &classname,
                   int line,
                   const std::string &errType = "Empty tree error")
        : BaseError(filename, classname, line, errType)
    {
    }
};

class TreeOutOfBoundsError : public BaseError
{
public:
    TreeOutOfBoundsError(const std::string &filename,
                         const std::string &classname,
                         int line,
                         const std::string &errType = "Out of bounds access error")
        : BaseError(filename, classname, line, errType)
    {
    }
};

class TreeCopyError : public BaseError
{
public:
    TreeCopyError(const std::string &filename,
                  const std::string &classname,
                  int line,
                  std::string errType = "Tree copy from non-existent source error\n")
        : BaseError(filename, classname, line, errType)
    {
    }
};

class TreeValueError : public BaseError
{
public:
    TreeValueError(const std::string &filename,
                   const std::string &classname,
                   int line,
                   std::string errType = "insertion of existent value error\n")
        : BaseError(filename, classname, line, errType)
    {
    }
};
