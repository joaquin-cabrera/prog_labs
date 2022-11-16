#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>

class Comentario{
    private:
        std::string comentario;
    public:
        Comentario(std::string comentario);
        ~Comentario();
};

#endif