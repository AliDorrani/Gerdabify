#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <exception>
using namespace std;

class InvalidArguments : public exception {};
class InvalidCredentials : public exception {};
class AlreadyExists : public exception {};
class MusicContainerDoesNotExists : public exception {};
class NotAuthorized : public exception {};
class MethodNotAvailable : public exception {};

#endif