#include <iostream>
#include "Serializer.hpp"

int main()
{
    try
    {
        Data data{42, "Hive"};

        uintptr_t serialized = Serializer::serialize(&data);

        if (serialized == 0)
            throw std::runtime_error("Serialized value is zero (null pointer).");

        std::cout << "Serialized address: " << std::hex << serialized << std::dec << std::endl;

        Data* deserialized = Serializer::deserialize(serialized);

        if (deserialized == nullptr)
            throw std::runtime_error("Deserialized pointer is null.");

        if (deserialized == &data)
        {
            std::cout << "Deserialization successful!" << std::endl;
            std::cout << "Data: num = " << deserialized->num << ", str = " << deserialized->str << std::endl;
        }
        else
        {
            std::cout << "Deserialization failed." << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
