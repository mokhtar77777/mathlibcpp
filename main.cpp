#include "vectors.hpp"

int main(void)
{
    StdVector<float> v(12);
    v.append(5.2);
    v.append(7.1);
    v.print();
}
