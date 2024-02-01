#ifndef _DSEXCEPTIONS_H_
#define _DSEXCEPTIONS_H_

#include <iostream>


class Underflow : public std::runtime_error
{
public:
    Underflow(std::string const& error)
        : std::runtime_error(error) {}

    Underflow()
        :std::runtime_error("Underflow Exception") {}
};

class Overflow : public std::runtime_error
{

public:
    Overflow(std::string const& error)
        : std::runtime_error(error) {}

    Overflow()
        :std::runtime_error("Overflow Exception") {}
};

class InvalidOperator : public std::runtime_error
{

public:
    InvalidOperator(std::string const& error)
        : std::runtime_error(error) {}

    InvalidOperator()
        :std::runtime_error("Invalid Exception") {}
};



class OutOfMemory : public std::runtime_error
{

public:
    OutOfMemory(std::string const& error)
        : std::runtime_error(error) {}

    OutOfMemory()
        :std::runtime_error("Out Of Memory Exception") {}
};

class BadIterator : public std::runtime_error
{

public:
    BadIterator(std::string const& error)
        : std::runtime_error(error) {}

    BadIterator()
        :std::runtime_error("Bad Iterator Exception") {}
};

class DataError : public std::runtime_error
{

public:
    DataError(std::string const& error)
        : std::runtime_error(error) {}

    DataError()
        :std::runtime_error("Data Error Exception") {}
};

class DivisionByZero : public std::runtime_error
{

public:
    DivisionByZero(std::string const& error)
        : std::runtime_error(error) {}

    DivisionByZero()
        :std::runtime_error("Division By Zero Exception") {}
};

class UnderflowException : public std::runtime_error
{

public:
    UnderflowException(std::string const& error)
        : std::runtime_error(error) {}

    UnderflowException()
        :std::runtime_error("UnderflowException") {}
};

#endif