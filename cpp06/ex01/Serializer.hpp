#pragma once

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Data;

class Serializer {
	private:
	public:
		Serializer();
		Serializer(const Serializer &c);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		Serializer & operator=(const Serializer &c);
		~Serializer();
};
