#include "shapes.hpp"
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[]){
    // Random seed gen
    srand(static_cast <unsigned> (time(0)));

    auto shapes = std::make_shared<Shapes>();
    shapes->run();

    return 0;
}