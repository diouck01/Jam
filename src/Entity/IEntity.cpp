/*
** EPITECH PROJECT, 2023
** IEntity
** File description:
** The file contains the exception methods of the class IEntity.
*/

#include "IEntity.hpp"

IEntity::LoadingError::LoadingError(const std::string &message) : _msg(message)
{
}

IEntity::LoadingError::~LoadingError()
{
}

const char *IEntity::LoadingError::what() const noexcept
{
    return (_msg.c_str());
}