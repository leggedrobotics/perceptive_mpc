#ifndef UR10_TRANSFORMS_H_
#define UR10_TRANSFORMS_H_

#include <Eigen/Dense>
#include <iit/rbd/TransformsBase.h>
#include "declarations.h"
#include <iit/rbd/traits/DoubleTrait.h>
#include "kinematics_parameters.h"

namespace iit {
namespace ur10 {

template<typename SCALAR, class M>
class TransformMotion : public iit::rbd::SpatialTransformBase<tpl::JointState<SCALAR>, M> {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

template<typename SCALAR, class M>
class TransformForce : public iit::rbd::SpatialTransformBase<tpl::JointState<SCALAR>, M> {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

template<typename SCALAR, class M>
class TransformHomogeneous : public iit::rbd::HomogeneousTransformBase<tpl::JointState<SCALAR>, M> {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

namespace tpl {


/**
 * The class for the 6-by-6 coordinates transformation matrices for
 * spatial motion vectors.
 */
template <typename TRAIT>
class MotionTransforms {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    typedef typename TRAIT::Scalar Scalar;

    typedef JointState<Scalar> JState;
    class Dummy {};
    typedef typename TransformMotion<Scalar, Dummy>::MatrixType MatrixType;
public:
    class Type_fr_base_X_fr_shoulder_link : public TransformMotion<Scalar, Type_fr_base_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_base_X_fr_shoulder_link();
        const Type_fr_base_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_base_X_fr_wrist_3_link : public TransformMotion<Scalar, Type_fr_base_X_fr_wrist_3_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_base_X_fr_wrist_3_link();
        const Type_fr_base_X_fr_wrist_3_link& update(const JState&);
    protected:
    };
    
    class Type_fr_shoulder_link_X_fr_world : public TransformMotion<Scalar, Type_fr_shoulder_link_X_fr_world>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_shoulder_link_X_fr_world();
        const Type_fr_shoulder_link_X_fr_world& update(const JState&);
    protected:
    };
    
    class Type_fr_world_X_fr_shoulder_link : public TransformMotion<Scalar, Type_fr_world_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_world_X_fr_shoulder_link();
        const Type_fr_world_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_upper_arm_link_X_fr_shoulder_link : public TransformMotion<Scalar, Type_fr_upper_arm_link_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_upper_arm_link_X_fr_shoulder_link();
        const Type_fr_upper_arm_link_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_shoulder_link_X_fr_upper_arm_link : public TransformMotion<Scalar, Type_fr_shoulder_link_X_fr_upper_arm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_shoulder_link_X_fr_upper_arm_link();
        const Type_fr_shoulder_link_X_fr_upper_arm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_forearm_link_X_fr_upper_arm_link : public TransformMotion<Scalar, Type_fr_forearm_link_X_fr_upper_arm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_forearm_link_X_fr_upper_arm_link();
        const Type_fr_forearm_link_X_fr_upper_arm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_upper_arm_link_X_fr_forearm_link : public TransformMotion<Scalar, Type_fr_upper_arm_link_X_fr_forearm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_upper_arm_link_X_fr_forearm_link();
        const Type_fr_upper_arm_link_X_fr_forearm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_1_link_X_fr_forearm_link : public TransformMotion<Scalar, Type_fr_wrist_1_link_X_fr_forearm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_1_link_X_fr_forearm_link();
        const Type_fr_wrist_1_link_X_fr_forearm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_forearm_link_X_fr_wrist_1_link : public TransformMotion<Scalar, Type_fr_forearm_link_X_fr_wrist_1_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_forearm_link_X_fr_wrist_1_link();
        const Type_fr_forearm_link_X_fr_wrist_1_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_2_link_X_fr_wrist_1_link : public TransformMotion<Scalar, Type_fr_wrist_2_link_X_fr_wrist_1_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_2_link_X_fr_wrist_1_link();
        const Type_fr_wrist_2_link_X_fr_wrist_1_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_1_link_X_fr_wrist_2_link : public TransformMotion<Scalar, Type_fr_wrist_1_link_X_fr_wrist_2_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_1_link_X_fr_wrist_2_link();
        const Type_fr_wrist_1_link_X_fr_wrist_2_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_3_link_X_fr_wrist_2_link : public TransformMotion<Scalar, Type_fr_wrist_3_link_X_fr_wrist_2_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_3_link_X_fr_wrist_2_link();
        const Type_fr_wrist_3_link_X_fr_wrist_2_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_2_link_X_fr_wrist_3_link : public TransformMotion<Scalar, Type_fr_wrist_2_link_X_fr_wrist_3_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_2_link_X_fr_wrist_3_link();
        const Type_fr_wrist_2_link_X_fr_wrist_3_link& update(const JState&);
    protected:
    };
    
public:
    MotionTransforms();
    void updateParameters();
    Type_fr_base_X_fr_shoulder_link fr_base_X_fr_shoulder_link;
    Type_fr_base_X_fr_wrist_3_link fr_base_X_fr_wrist_3_link;
    Type_fr_shoulder_link_X_fr_world fr_shoulder_link_X_fr_world;
    Type_fr_world_X_fr_shoulder_link fr_world_X_fr_shoulder_link;
    Type_fr_upper_arm_link_X_fr_shoulder_link fr_upper_arm_link_X_fr_shoulder_link;
    Type_fr_shoulder_link_X_fr_upper_arm_link fr_shoulder_link_X_fr_upper_arm_link;
    Type_fr_forearm_link_X_fr_upper_arm_link fr_forearm_link_X_fr_upper_arm_link;
    Type_fr_upper_arm_link_X_fr_forearm_link fr_upper_arm_link_X_fr_forearm_link;
    Type_fr_wrist_1_link_X_fr_forearm_link fr_wrist_1_link_X_fr_forearm_link;
    Type_fr_forearm_link_X_fr_wrist_1_link fr_forearm_link_X_fr_wrist_1_link;
    Type_fr_wrist_2_link_X_fr_wrist_1_link fr_wrist_2_link_X_fr_wrist_1_link;
    Type_fr_wrist_1_link_X_fr_wrist_2_link fr_wrist_1_link_X_fr_wrist_2_link;
    Type_fr_wrist_3_link_X_fr_wrist_2_link fr_wrist_3_link_X_fr_wrist_2_link;
    Type_fr_wrist_2_link_X_fr_wrist_3_link fr_wrist_2_link_X_fr_wrist_3_link;

protected:

}; //class 'MotionTransforms'

/**
 * The class for the 6-by-6 coordinates transformation matrices for
 * spatial force vectors.
 */
template <typename TRAIT>
class ForceTransforms {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    typedef typename TRAIT::Scalar Scalar;

    typedef JointState<Scalar> JState;
    class Dummy {};
    typedef typename TransformForce<Scalar, Dummy>::MatrixType MatrixType;
public:
    class Type_fr_base_X_fr_shoulder_link : public TransformForce<Scalar, Type_fr_base_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_base_X_fr_shoulder_link();
        const Type_fr_base_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_base_X_fr_wrist_3_link : public TransformForce<Scalar, Type_fr_base_X_fr_wrist_3_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_base_X_fr_wrist_3_link();
        const Type_fr_base_X_fr_wrist_3_link& update(const JState&);
    protected:
    };
    
    class Type_fr_shoulder_link_X_fr_world : public TransformForce<Scalar, Type_fr_shoulder_link_X_fr_world>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_shoulder_link_X_fr_world();
        const Type_fr_shoulder_link_X_fr_world& update(const JState&);
    protected:
    };
    
    class Type_fr_world_X_fr_shoulder_link : public TransformForce<Scalar, Type_fr_world_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_world_X_fr_shoulder_link();
        const Type_fr_world_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_upper_arm_link_X_fr_shoulder_link : public TransformForce<Scalar, Type_fr_upper_arm_link_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_upper_arm_link_X_fr_shoulder_link();
        const Type_fr_upper_arm_link_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_shoulder_link_X_fr_upper_arm_link : public TransformForce<Scalar, Type_fr_shoulder_link_X_fr_upper_arm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_shoulder_link_X_fr_upper_arm_link();
        const Type_fr_shoulder_link_X_fr_upper_arm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_forearm_link_X_fr_upper_arm_link : public TransformForce<Scalar, Type_fr_forearm_link_X_fr_upper_arm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_forearm_link_X_fr_upper_arm_link();
        const Type_fr_forearm_link_X_fr_upper_arm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_upper_arm_link_X_fr_forearm_link : public TransformForce<Scalar, Type_fr_upper_arm_link_X_fr_forearm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_upper_arm_link_X_fr_forearm_link();
        const Type_fr_upper_arm_link_X_fr_forearm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_1_link_X_fr_forearm_link : public TransformForce<Scalar, Type_fr_wrist_1_link_X_fr_forearm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_1_link_X_fr_forearm_link();
        const Type_fr_wrist_1_link_X_fr_forearm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_forearm_link_X_fr_wrist_1_link : public TransformForce<Scalar, Type_fr_forearm_link_X_fr_wrist_1_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_forearm_link_X_fr_wrist_1_link();
        const Type_fr_forearm_link_X_fr_wrist_1_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_2_link_X_fr_wrist_1_link : public TransformForce<Scalar, Type_fr_wrist_2_link_X_fr_wrist_1_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_2_link_X_fr_wrist_1_link();
        const Type_fr_wrist_2_link_X_fr_wrist_1_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_1_link_X_fr_wrist_2_link : public TransformForce<Scalar, Type_fr_wrist_1_link_X_fr_wrist_2_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_1_link_X_fr_wrist_2_link();
        const Type_fr_wrist_1_link_X_fr_wrist_2_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_3_link_X_fr_wrist_2_link : public TransformForce<Scalar, Type_fr_wrist_3_link_X_fr_wrist_2_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_3_link_X_fr_wrist_2_link();
        const Type_fr_wrist_3_link_X_fr_wrist_2_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_2_link_X_fr_wrist_3_link : public TransformForce<Scalar, Type_fr_wrist_2_link_X_fr_wrist_3_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_2_link_X_fr_wrist_3_link();
        const Type_fr_wrist_2_link_X_fr_wrist_3_link& update(const JState&);
    protected:
    };
    
public:
    ForceTransforms();
    void updateParameters();
    Type_fr_base_X_fr_shoulder_link fr_base_X_fr_shoulder_link;
    Type_fr_base_X_fr_wrist_3_link fr_base_X_fr_wrist_3_link;
    Type_fr_shoulder_link_X_fr_world fr_shoulder_link_X_fr_world;
    Type_fr_world_X_fr_shoulder_link fr_world_X_fr_shoulder_link;
    Type_fr_upper_arm_link_X_fr_shoulder_link fr_upper_arm_link_X_fr_shoulder_link;
    Type_fr_shoulder_link_X_fr_upper_arm_link fr_shoulder_link_X_fr_upper_arm_link;
    Type_fr_forearm_link_X_fr_upper_arm_link fr_forearm_link_X_fr_upper_arm_link;
    Type_fr_upper_arm_link_X_fr_forearm_link fr_upper_arm_link_X_fr_forearm_link;
    Type_fr_wrist_1_link_X_fr_forearm_link fr_wrist_1_link_X_fr_forearm_link;
    Type_fr_forearm_link_X_fr_wrist_1_link fr_forearm_link_X_fr_wrist_1_link;
    Type_fr_wrist_2_link_X_fr_wrist_1_link fr_wrist_2_link_X_fr_wrist_1_link;
    Type_fr_wrist_1_link_X_fr_wrist_2_link fr_wrist_1_link_X_fr_wrist_2_link;
    Type_fr_wrist_3_link_X_fr_wrist_2_link fr_wrist_3_link_X_fr_wrist_2_link;
    Type_fr_wrist_2_link_X_fr_wrist_3_link fr_wrist_2_link_X_fr_wrist_3_link;

protected:

}; //class 'ForceTransforms'

/**
 * The class with the homogeneous (4x4) coordinates transformation
 * matrices.
 */
template <typename TRAIT>
class HomogeneousTransforms {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    typedef typename TRAIT::Scalar Scalar;

    typedef JointState<Scalar> JState;
    class Dummy {};
    typedef typename TransformHomogeneous<Scalar, Dummy>::MatrixType MatrixType;
public:
    class Type_fr_base_X_fr_shoulder_link : public TransformHomogeneous<Scalar, Type_fr_base_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_base_X_fr_shoulder_link();
        const Type_fr_base_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_base_X_fr_wrist_3_link : public TransformHomogeneous<Scalar, Type_fr_base_X_fr_wrist_3_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_base_X_fr_wrist_3_link();
        const Type_fr_base_X_fr_wrist_3_link& update(const JState&);
    protected:
    };
    
    class Type_fr_shoulder_link_X_fr_world : public TransformHomogeneous<Scalar, Type_fr_shoulder_link_X_fr_world>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_shoulder_link_X_fr_world();
        const Type_fr_shoulder_link_X_fr_world& update(const JState&);
    protected:
    };
    
    class Type_fr_world_X_fr_shoulder_link : public TransformHomogeneous<Scalar, Type_fr_world_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_world_X_fr_shoulder_link();
        const Type_fr_world_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_upper_arm_link_X_fr_shoulder_link : public TransformHomogeneous<Scalar, Type_fr_upper_arm_link_X_fr_shoulder_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_upper_arm_link_X_fr_shoulder_link();
        const Type_fr_upper_arm_link_X_fr_shoulder_link& update(const JState&);
    protected:
    };
    
    class Type_fr_shoulder_link_X_fr_upper_arm_link : public TransformHomogeneous<Scalar, Type_fr_shoulder_link_X_fr_upper_arm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_shoulder_link_X_fr_upper_arm_link();
        const Type_fr_shoulder_link_X_fr_upper_arm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_forearm_link_X_fr_upper_arm_link : public TransformHomogeneous<Scalar, Type_fr_forearm_link_X_fr_upper_arm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_forearm_link_X_fr_upper_arm_link();
        const Type_fr_forearm_link_X_fr_upper_arm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_upper_arm_link_X_fr_forearm_link : public TransformHomogeneous<Scalar, Type_fr_upper_arm_link_X_fr_forearm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_upper_arm_link_X_fr_forearm_link();
        const Type_fr_upper_arm_link_X_fr_forearm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_1_link_X_fr_forearm_link : public TransformHomogeneous<Scalar, Type_fr_wrist_1_link_X_fr_forearm_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_1_link_X_fr_forearm_link();
        const Type_fr_wrist_1_link_X_fr_forearm_link& update(const JState&);
    protected:
    };
    
    class Type_fr_forearm_link_X_fr_wrist_1_link : public TransformHomogeneous<Scalar, Type_fr_forearm_link_X_fr_wrist_1_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_forearm_link_X_fr_wrist_1_link();
        const Type_fr_forearm_link_X_fr_wrist_1_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_2_link_X_fr_wrist_1_link : public TransformHomogeneous<Scalar, Type_fr_wrist_2_link_X_fr_wrist_1_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_2_link_X_fr_wrist_1_link();
        const Type_fr_wrist_2_link_X_fr_wrist_1_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_1_link_X_fr_wrist_2_link : public TransformHomogeneous<Scalar, Type_fr_wrist_1_link_X_fr_wrist_2_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_1_link_X_fr_wrist_2_link();
        const Type_fr_wrist_1_link_X_fr_wrist_2_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_3_link_X_fr_wrist_2_link : public TransformHomogeneous<Scalar, Type_fr_wrist_3_link_X_fr_wrist_2_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_3_link_X_fr_wrist_2_link();
        const Type_fr_wrist_3_link_X_fr_wrist_2_link& update(const JState&);
    protected:
    };
    
    class Type_fr_wrist_2_link_X_fr_wrist_3_link : public TransformHomogeneous<Scalar, Type_fr_wrist_2_link_X_fr_wrist_3_link>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_wrist_2_link_X_fr_wrist_3_link();
        const Type_fr_wrist_2_link_X_fr_wrist_3_link& update(const JState&);
    protected:
    };
    
public:
    HomogeneousTransforms();
    void updateParameters();
    Type_fr_base_X_fr_shoulder_link fr_base_X_fr_shoulder_link;
    Type_fr_base_X_fr_wrist_3_link fr_base_X_fr_wrist_3_link;
    Type_fr_shoulder_link_X_fr_world fr_shoulder_link_X_fr_world;
    Type_fr_world_X_fr_shoulder_link fr_world_X_fr_shoulder_link;
    Type_fr_upper_arm_link_X_fr_shoulder_link fr_upper_arm_link_X_fr_shoulder_link;
    Type_fr_shoulder_link_X_fr_upper_arm_link fr_shoulder_link_X_fr_upper_arm_link;
    Type_fr_forearm_link_X_fr_upper_arm_link fr_forearm_link_X_fr_upper_arm_link;
    Type_fr_upper_arm_link_X_fr_forearm_link fr_upper_arm_link_X_fr_forearm_link;
    Type_fr_wrist_1_link_X_fr_forearm_link fr_wrist_1_link_X_fr_forearm_link;
    Type_fr_forearm_link_X_fr_wrist_1_link fr_forearm_link_X_fr_wrist_1_link;
    Type_fr_wrist_2_link_X_fr_wrist_1_link fr_wrist_2_link_X_fr_wrist_1_link;
    Type_fr_wrist_1_link_X_fr_wrist_2_link fr_wrist_1_link_X_fr_wrist_2_link;
    Type_fr_wrist_3_link_X_fr_wrist_2_link fr_wrist_3_link_X_fr_wrist_2_link;
    Type_fr_wrist_2_link_X_fr_wrist_3_link fr_wrist_2_link_X_fr_wrist_3_link;

protected:

}; //class 'HomogeneousTransforms'

}

using MotionTransforms = tpl::MotionTransforms<rbd::DoubleTrait>;
using ForceTransforms = tpl::ForceTransforms<rbd::DoubleTrait>;
using HomogeneousTransforms = tpl::HomogeneousTransforms<rbd::DoubleTrait>;

}
}

#include "transforms.impl.h"

#endif
