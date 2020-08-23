#include <NN/Functions.hpp>

namespace NN {

    namespace Activation {

        float (*None) (float, int, float) = nullptr;

    }

    namespace Loss {

        const void* (*None) (const MX::Matrixf&, const MX::Matrixf&, int, float) = nullptr;

        const void* MSE (const MX::Matrixf& A, const MX::Matrixf& Y, int mode, float hp) {
            MX::Matrixf* loss = new MX::Matrixf;
            switch (mode) {
                case 0:
                    *loss = MX::Sum((A - Y) * (A - Y), 0);
                    *loss /= A.rows();
                    break;
                case 1: 
                    *loss =  2 * (A - Y) / A.rows();
                    break;
                default: abort();
            }
            return loss;
        }

    }

}