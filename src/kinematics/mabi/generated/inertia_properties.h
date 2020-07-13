#ifndef IIT_ROBOT_MABI_INERTIA_PROPERTIES_H_
#define IIT_ROBOT_MABI_INERTIA_PROPERTIES_H_

#include <iit/rbd/rbd.h>
#include <iit/rbd/InertiaMatrix.h>
#include <iit/rbd/utils.h>
#include <iit/rbd/traits/DoubleTrait.h>

#include "declarations.h"

namespace iit {
namespace mabi {
/**
 * This namespace encloses classes and functions related to the Dynamics
 * of the robot mabi.
 */
namespace dyn {

using InertiaMatrix = iit::rbd::InertiaMatrixDense;

namespace tpl {

template <typename TRAIT>
class InertiaProperties {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        typedef typename TRAIT::Scalar Scalar;
        typedef iit::rbd::Core<Scalar> CoreS;
        typedef iit::rbd::tpl::InertiaMatrixDense<Scalar> IMatrix;
        typedef typename CoreS::Vector3 Vec3d;

        InertiaProperties();
        ~InertiaProperties();
        const IMatrix& getTensor_SHOULDER() const;
        const IMatrix& getTensor_ARM() const;
        const IMatrix& getTensor_ELBOW() const;
        const IMatrix& getTensor_FOREARM() const;
        const IMatrix& getTensor_WRIST_1() const;
        const IMatrix& getTensor_WRIST_2() const;
        Scalar getMass_SHOULDER() const;
        Scalar getMass_ARM() const;
        Scalar getMass_ELBOW() const;
        Scalar getMass_FOREARM() const;
        Scalar getMass_WRIST_1() const;
        Scalar getMass_WRIST_2() const;
        const Vec3d& getCOM_SHOULDER() const;
        const Vec3d& getCOM_ARM() const;
        const Vec3d& getCOM_ELBOW() const;
        const Vec3d& getCOM_FOREARM() const;
        const Vec3d& getCOM_WRIST_1() const;
        const Vec3d& getCOM_WRIST_2() const;
        Scalar getTotalMass() const;

    private:

        IMatrix tensor_SHOULDER;
        IMatrix tensor_ARM;
        IMatrix tensor_ELBOW;
        IMatrix tensor_FOREARM;
        IMatrix tensor_WRIST_1;
        IMatrix tensor_WRIST_2;
        Vec3d com_SHOULDER;
        Vec3d com_ARM;
        Vec3d com_ELBOW;
        Vec3d com_FOREARM;
        Vec3d com_WRIST_1;
        Vec3d com_WRIST_2;
};

template <typename TRAIT>
inline InertiaProperties<TRAIT>::~InertiaProperties() {}

template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::IMatrix& InertiaProperties<TRAIT>::getTensor_SHOULDER() const {
    return this->tensor_SHOULDER;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::IMatrix& InertiaProperties<TRAIT>::getTensor_ARM() const {
    return this->tensor_ARM;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::IMatrix& InertiaProperties<TRAIT>::getTensor_ELBOW() const {
    return this->tensor_ELBOW;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::IMatrix& InertiaProperties<TRAIT>::getTensor_FOREARM() const {
    return this->tensor_FOREARM;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::IMatrix& InertiaProperties<TRAIT>::getTensor_WRIST_1() const {
    return this->tensor_WRIST_1;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::IMatrix& InertiaProperties<TRAIT>::getTensor_WRIST_2() const {
    return this->tensor_WRIST_2;
}
template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getMass_SHOULDER() const {
    return this->tensor_SHOULDER.getMass();
}
template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getMass_ARM() const {
    return this->tensor_ARM.getMass();
}
template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getMass_ELBOW() const {
    return this->tensor_ELBOW.getMass();
}
template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getMass_FOREARM() const {
    return this->tensor_FOREARM.getMass();
}
template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getMass_WRIST_1() const {
    return this->tensor_WRIST_1.getMass();
}
template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getMass_WRIST_2() const {
    return this->tensor_WRIST_2.getMass();
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::Vec3d& InertiaProperties<TRAIT>::getCOM_SHOULDER() const {
    return this->com_SHOULDER;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::Vec3d& InertiaProperties<TRAIT>::getCOM_ARM() const {
    return this->com_ARM;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::Vec3d& InertiaProperties<TRAIT>::getCOM_ELBOW() const {
    return this->com_ELBOW;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::Vec3d& InertiaProperties<TRAIT>::getCOM_FOREARM() const {
    return this->com_FOREARM;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::Vec3d& InertiaProperties<TRAIT>::getCOM_WRIST_1() const {
    return this->com_WRIST_1;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::Vec3d& InertiaProperties<TRAIT>::getCOM_WRIST_2() const {
    return this->com_WRIST_2;
}

template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getTotalMass() const {
    return 7.6494994 + 13.640494 + 4.6480036 + 5.727165 + 1.9710281 + 2.6557686;
}

}

using InertiaProperties = tpl::InertiaProperties<rbd::DoubleTrait>;

}
}
}

#include "inertia_properties.impl.h"

#endif
