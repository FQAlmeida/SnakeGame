#pragma once
// Global
#include <vector>
//Local
#include "./Corpo/Cabeca/Cabeca.hpp"
#include "./Corpo/Cauda/Cauda.hpp"
namespace Cobra {

class Cobra {
   private:
    std::vector<Corpo::Cauda::Cauda> cauda;
    Corpo::Cabeca::Cabeca cabeca;
    size_t qtd_comida;

   public:
    Cobra();
    void update();
    std::vector<Corpo::Cauda::Cauda> get_cauda();
    Corpo::Cabeca::Cabeca get_cabeca();
    void set_direction(Structure::Direction::Direction direction);
    void comer(size_t qtd);
    ~Cobra();
};

}  // namespace Cobra
