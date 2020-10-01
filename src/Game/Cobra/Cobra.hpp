#pragma once
// Global
#include <vector>
//Local
#include "./Corpo/Cabeca/Cabeca.hpp"
#include "./Corpo/Cauda/Cauda.hpp"
namespace Cobra {

class Cobra {
   private:
    std::vector<Cauda> cauda;
    Cabeca cabeca;
    size_t qtd_comida;

   public:
    Cobra();
    void update();
    std::vector<Cauda> get_cauda();
    Cabeca get_cabeca();
    void set_direction(Direction direction);
    void comer(size_t qtd);
    ~Cobra();
};

}  // namespace Cobra
