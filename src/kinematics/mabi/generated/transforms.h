#ifndef MABI_TRANSFORMS_H_
#define MABI_TRANSFORMS_H_

#include <Eigen/Dense>
#include <iit/rbd/TransformsBase.h>
#include "declarations.h"
#include <iit/rbd/traits/DoubleTrait.h>
#include "kinematics_parameters.h"

namespace iit {
namespace mabi {

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
    class Type_fr_arm_mount_X_fr_SHOULDER : public TransformMotion<Scalar, Type_fr_arm_mount_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_arm_mount_X_fr_SHOULDER();
        const Type_fr_arm_mount_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_arm_mount_X_fr_WRIST_2 : public TransformMotion<Scalar, Type_fr_arm_mount_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_arm_mount_X_fr_WRIST_2();
        const Type_fr_arm_mount_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
    class Type_fr_WR_ROT_X_fr_WRIST_2 : public TransformMotion<Scalar, Type_fr_WR_ROT_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WR_ROT_X_fr_WRIST_2();
        const Type_fr_WR_ROT_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
    class Type_fr_SHOULDER_X_fr_world : public TransformMotion<Scalar, Type_fr_SHOULDER_X_fr_world>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_SHOULDER_X_fr_world();
        const Type_fr_SHOULDER_X_fr_world& update(const JState&);
    protected:
    };
    
    class Type_fr_world_X_fr_SHOULDER : public TransformMotion<Scalar, Type_fr_world_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_world_X_fr_SHOULDER();
        const Type_fr_world_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_ARM_X_fr_SHOULDER : public TransformMotion<Scalar, Type_fr_ARM_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ARM_X_fr_SHOULDER();
        const Type_fr_ARM_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_SHOULDER_X_fr_ARM : public TransformMotion<Scalar, Type_fr_SHOULDER_X_fr_ARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_SHOULDER_X_fr_ARM();
        const Type_fr_SHOULDER_X_fr_ARM& update(const JState&);
    protected:
    };
    
    class Type_fr_ELBOW_X_fr_ARM : public TransformMotion<Scalar, Type_fr_ELBOW_X_fr_ARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ELBOW_X_fr_ARM();
        const Type_fr_ELBOW_X_fr_ARM& update(const JState&);
    protected:
    };
    
    class Type_fr_ARM_X_fr_ELBOW : public TransformMotion<Scalar, Type_fr_ARM_X_fr_ELBOW>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ARM_X_fr_ELBOW();
        const Type_fr_ARM_X_fr_ELBOW& update(const JState&);
    protected:
    };
    
    class Type_fr_FOREARM_X_fr_ELBOW : public TransformMotion<Scalar, Type_fr_FOREARM_X_fr_ELBOW>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FOREARM_X_fr_ELBOW();
        const Type_fr_FOREARM_X_fr_ELBOW& update(const JState&);
    protected:
    };
    
    class Type_fr_ELBOW_X_fr_FOREARM : public TransformMotion<Scalar, Type_fr_ELBOW_X_fr_FOREARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ELBOW_X_fr_FOREARM();
        const Type_fr_ELBOW_X_fr_FOREARM& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_1_X_fr_FOREARM : public TransformMotion<Scalar, Type_fr_WRIST_1_X_fr_FOREARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_1_X_fr_FOREARM();
        const Type_fr_WRIST_1_X_fr_FOREARM& update(const JState&);
    protected:
    };
    
    class Type_fr_FOREARM_X_fr_WRIST_1 : public TransformMotion<Scalar, Type_fr_FOREARM_X_fr_WRIST_1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FOREARM_X_fr_WRIST_1();
        const Type_fr_FOREARM_X_fr_WRIST_1& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_2_X_fr_WRIST_1 : public TransformMotion<Scalar, Type_fr_WRIST_2_X_fr_WRIST_1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_2_X_fr_WRIST_1();
        const Type_fr_WRIST_2_X_fr_WRIST_1& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_1_X_fr_WRIST_2 : public TransformMotion<Scalar, Type_fr_WRIST_1_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_1_X_fr_WRIST_2();
        const Type_fr_WRIST_1_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
public:
    MotionTransforms();
    void updateParameters();
    Type_fr_arm_mount_X_fr_SHOULDER fr_arm_mount_X_fr_SHOULDER;
    Type_fr_arm_mount_X_fr_WRIST_2 fr_arm_mount_X_fr_WRIST_2;
    Type_fr_WR_ROT_X_fr_WRIST_2 fr_WR_ROT_X_fr_WRIST_2;
    Type_fr_SHOULDER_X_fr_world fr_SHOULDER_X_fr_world;
    Type_fr_world_X_fr_SHOULDER fr_world_X_fr_SHOULDER;
    Type_fr_ARM_X_fr_SHOULDER fr_ARM_X_fr_SHOULDER;
    Type_fr_SHOULDER_X_fr_ARM fr_SHOULDER_X_fr_ARM;
    Type_fr_ELBOW_X_fr_ARM fr_ELBOW_X_fr_ARM;
    Type_fr_ARM_X_fr_ELBOW fr_ARM_X_fr_ELBOW;
    Type_fr_FOREARM_X_fr_ELBOW fr_FOREARM_X_fr_ELBOW;
    Type_fr_ELBOW_X_fr_FOREARM fr_ELBOW_X_fr_FOREARM;
    Type_fr_WRIST_1_X_fr_FOREARM fr_WRIST_1_X_fr_FOREARM;
    Type_fr_FOREARM_X_fr_WRIST_1 fr_FOREARM_X_fr_WRIST_1;
    Type_fr_WRIST_2_X_fr_WRIST_1 fr_WRIST_2_X_fr_WRIST_1;
    Type_fr_WRIST_1_X_fr_WRIST_2 fr_WRIST_1_X_fr_WRIST_2;

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
    class Type_fr_arm_mount_X_fr_SHOULDER : public TransformForce<Scalar, Type_fr_arm_mount_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_arm_mount_X_fr_SHOULDER();
        const Type_fr_arm_mount_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_arm_mount_X_fr_WRIST_2 : public TransformForce<Scalar, Type_fr_arm_mount_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_arm_mount_X_fr_WRIST_2();
        const Type_fr_arm_mount_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
    class Type_fr_WR_ROT_X_fr_WRIST_2 : public TransformForce<Scalar, Type_fr_WR_ROT_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WR_ROT_X_fr_WRIST_2();
        const Type_fr_WR_ROT_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
    class Type_fr_SHOULDER_X_fr_world : public TransformForce<Scalar, Type_fr_SHOULDER_X_fr_world>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_SHOULDER_X_fr_world();
        const Type_fr_SHOULDER_X_fr_world& update(const JState&);
    protected:
    };
    
    class Type_fr_world_X_fr_SHOULDER : public TransformForce<Scalar, Type_fr_world_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_world_X_fr_SHOULDER();
        const Type_fr_world_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_ARM_X_fr_SHOULDER : public TransformForce<Scalar, Type_fr_ARM_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ARM_X_fr_SHOULDER();
        const Type_fr_ARM_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_SHOULDER_X_fr_ARM : public TransformForce<Scalar, Type_fr_SHOULDER_X_fr_ARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_SHOULDER_X_fr_ARM();
        const Type_fr_SHOULDER_X_fr_ARM& update(const JState&);
    protected:
    };
    
    class Type_fr_ELBOW_X_fr_ARM : public TransformForce<Scalar, Type_fr_ELBOW_X_fr_ARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ELBOW_X_fr_ARM();
        const Type_fr_ELBOW_X_fr_ARM& update(const JState&);
    protected:
    };
    
    class Type_fr_ARM_X_fr_ELBOW : public TransformForce<Scalar, Type_fr_ARM_X_fr_ELBOW>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ARM_X_fr_ELBOW();
        const Type_fr_ARM_X_fr_ELBOW& update(const JState&);
    protected:
    };
    
    class Type_fr_FOREARM_X_fr_ELBOW : public TransformForce<Scalar, Type_fr_FOREARM_X_fr_ELBOW>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FOREARM_X_fr_ELBOW();
        const Type_fr_FOREARM_X_fr_ELBOW& update(const JState&);
    protected:
    };
    
    class Type_fr_ELBOW_X_fr_FOREARM : public TransformForce<Scalar, Type_fr_ELBOW_X_fr_FOREARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ELBOW_X_fr_FOREARM();
        const Type_fr_ELBOW_X_fr_FOREARM& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_1_X_fr_FOREARM : public TransformForce<Scalar, Type_fr_WRIST_1_X_fr_FOREARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_1_X_fr_FOREARM();
        const Type_fr_WRIST_1_X_fr_FOREARM& update(const JState&);
    protected:
    };
    
    class Type_fr_FOREARM_X_fr_WRIST_1 : public TransformForce<Scalar, Type_fr_FOREARM_X_fr_WRIST_1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FOREARM_X_fr_WRIST_1();
        const Type_fr_FOREARM_X_fr_WRIST_1& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_2_X_fr_WRIST_1 : public TransformForce<Scalar, Type_fr_WRIST_2_X_fr_WRIST_1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_2_X_fr_WRIST_1();
        const Type_fr_WRIST_2_X_fr_WRIST_1& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_1_X_fr_WRIST_2 : public TransformForce<Scalar, Type_fr_WRIST_1_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_1_X_fr_WRIST_2();
        const Type_fr_WRIST_1_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
public:
    ForceTransforms();
    void updateParameters();
    Type_fr_arm_mount_X_fr_SHOULDER fr_arm_mount_X_fr_SHOULDER;
    Type_fr_arm_mount_X_fr_WRIST_2 fr_arm_mount_X_fr_WRIST_2;
    Type_fr_WR_ROT_X_fr_WRIST_2 fr_WR_ROT_X_fr_WRIST_2;
    Type_fr_SHOULDER_X_fr_world fr_SHOULDER_X_fr_world;
    Type_fr_world_X_fr_SHOULDER fr_world_X_fr_SHOULDER;
    Type_fr_ARM_X_fr_SHOULDER fr_ARM_X_fr_SHOULDER;
    Type_fr_SHOULDER_X_fr_ARM fr_SHOULDER_X_fr_ARM;
    Type_fr_ELBOW_X_fr_ARM fr_ELBOW_X_fr_ARM;
    Type_fr_ARM_X_fr_ELBOW fr_ARM_X_fr_ELBOW;
    Type_fr_FOREARM_X_fr_ELBOW fr_FOREARM_X_fr_ELBOW;
    Type_fr_ELBOW_X_fr_FOREARM fr_ELBOW_X_fr_FOREARM;
    Type_fr_WRIST_1_X_fr_FOREARM fr_WRIST_1_X_fr_FOREARM;
    Type_fr_FOREARM_X_fr_WRIST_1 fr_FOREARM_X_fr_WRIST_1;
    Type_fr_WRIST_2_X_fr_WRIST_1 fr_WRIST_2_X_fr_WRIST_1;
    Type_fr_WRIST_1_X_fr_WRIST_2 fr_WRIST_1_X_fr_WRIST_2;

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
    class Type_fr_arm_mount_X_fr_SHOULDER : public TransformHomogeneous<Scalar, Type_fr_arm_mount_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_arm_mount_X_fr_SHOULDER();
        const Type_fr_arm_mount_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_arm_mount_X_fr_WRIST_2 : public TransformHomogeneous<Scalar, Type_fr_arm_mount_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_arm_mount_X_fr_WRIST_2();
        const Type_fr_arm_mount_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
    class Type_fr_WR_ROT_X_fr_WRIST_2 : public TransformHomogeneous<Scalar, Type_fr_WR_ROT_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WR_ROT_X_fr_WRIST_2();
        const Type_fr_WR_ROT_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
    class Type_fr_SHOULDER_X_fr_world : public TransformHomogeneous<Scalar, Type_fr_SHOULDER_X_fr_world>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_SHOULDER_X_fr_world();
        const Type_fr_SHOULDER_X_fr_world& update(const JState&);
    protected:
    };
    
    class Type_fr_world_X_fr_SHOULDER : public TransformHomogeneous<Scalar, Type_fr_world_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_world_X_fr_SHOULDER();
        const Type_fr_world_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_ARM_X_fr_SHOULDER : public TransformHomogeneous<Scalar, Type_fr_ARM_X_fr_SHOULDER>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ARM_X_fr_SHOULDER();
        const Type_fr_ARM_X_fr_SHOULDER& update(const JState&);
    protected:
    };
    
    class Type_fr_SHOULDER_X_fr_ARM : public TransformHomogeneous<Scalar, Type_fr_SHOULDER_X_fr_ARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_SHOULDER_X_fr_ARM();
        const Type_fr_SHOULDER_X_fr_ARM& update(const JState&);
    protected:
    };
    
    class Type_fr_ELBOW_X_fr_ARM : public TransformHomogeneous<Scalar, Type_fr_ELBOW_X_fr_ARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ELBOW_X_fr_ARM();
        const Type_fr_ELBOW_X_fr_ARM& update(const JState&);
    protected:
    };
    
    class Type_fr_ARM_X_fr_ELBOW : public TransformHomogeneous<Scalar, Type_fr_ARM_X_fr_ELBOW>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ARM_X_fr_ELBOW();
        const Type_fr_ARM_X_fr_ELBOW& update(const JState&);
    protected:
    };
    
    class Type_fr_FOREARM_X_fr_ELBOW : public TransformHomogeneous<Scalar, Type_fr_FOREARM_X_fr_ELBOW>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FOREARM_X_fr_ELBOW();
        const Type_fr_FOREARM_X_fr_ELBOW& update(const JState&);
    protected:
    };
    
    class Type_fr_ELBOW_X_fr_FOREARM : public TransformHomogeneous<Scalar, Type_fr_ELBOW_X_fr_FOREARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_ELBOW_X_fr_FOREARM();
        const Type_fr_ELBOW_X_fr_FOREARM& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_1_X_fr_FOREARM : public TransformHomogeneous<Scalar, Type_fr_WRIST_1_X_fr_FOREARM>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_1_X_fr_FOREARM();
        const Type_fr_WRIST_1_X_fr_FOREARM& update(const JState&);
    protected:
    };
    
    class Type_fr_FOREARM_X_fr_WRIST_1 : public TransformHomogeneous<Scalar, Type_fr_FOREARM_X_fr_WRIST_1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FOREARM_X_fr_WRIST_1();
        const Type_fr_FOREARM_X_fr_WRIST_1& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_2_X_fr_WRIST_1 : public TransformHomogeneous<Scalar, Type_fr_WRIST_2_X_fr_WRIST_1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_2_X_fr_WRIST_1();
        const Type_fr_WRIST_2_X_fr_WRIST_1& update(const JState&);
    protected:
    };
    
    class Type_fr_WRIST_1_X_fr_WRIST_2 : public TransformHomogeneous<Scalar, Type_fr_WRIST_1_X_fr_WRIST_2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_WRIST_1_X_fr_WRIST_2();
        const Type_fr_WRIST_1_X_fr_WRIST_2& update(const JState&);
    protected:
    };
    
public:
    HomogeneousTransforms();
    void updateParameters();
    Type_fr_arm_mount_X_fr_SHOULDER fr_arm_mount_X_fr_SHOULDER;
    Type_fr_arm_mount_X_fr_WRIST_2 fr_arm_mount_X_fr_WRIST_2;
    Type_fr_WR_ROT_X_fr_WRIST_2 fr_WR_ROT_X_fr_WRIST_2;
    Type_fr_SHOULDER_X_fr_world fr_SHOULDER_X_fr_world;
    Type_fr_world_X_fr_SHOULDER fr_world_X_fr_SHOULDER;
    Type_fr_ARM_X_fr_SHOULDER fr_ARM_X_fr_SHOULDER;
    Type_fr_SHOULDER_X_fr_ARM fr_SHOULDER_X_fr_ARM;
    Type_fr_ELBOW_X_fr_ARM fr_ELBOW_X_fr_ARM;
    Type_fr_ARM_X_fr_ELBOW fr_ARM_X_fr_ELBOW;
    Type_fr_FOREARM_X_fr_ELBOW fr_FOREARM_X_fr_ELBOW;
    Type_fr_ELBOW_X_fr_FOREARM fr_ELBOW_X_fr_FOREARM;
    Type_fr_WRIST_1_X_fr_FOREARM fr_WRIST_1_X_fr_FOREARM;
    Type_fr_FOREARM_X_fr_WRIST_1 fr_FOREARM_X_fr_WRIST_1;
    Type_fr_WRIST_2_X_fr_WRIST_1 fr_WRIST_2_X_fr_WRIST_1;
    Type_fr_WRIST_1_X_fr_WRIST_2 fr_WRIST_1_X_fr_WRIST_2;

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
