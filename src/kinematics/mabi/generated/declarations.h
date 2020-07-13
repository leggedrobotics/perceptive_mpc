#ifndef IIT_ROBOT_MABI_DECLARATIONS_H_
#define IIT_ROBOT_MABI_DECLARATIONS_H_

#include <iit/rbd/rbd.h>

namespace iit {
namespace mabi {

static const int JointSpaceDimension = 6;
static const int jointsCount = 6;
/** The total number of rigid bodies of this robot, including the base */
static const int linksCount  = 7;

namespace tpl {
template <typename SCALAR>
using Column6d = iit::rbd::PlainMatrix<SCALAR, 6, 1>;

template <typename SCALAR>
using JointState = Column6d<SCALAR>;
}

using Column6d = tpl::Column6d<double>;
typedef Column6d JointState;

enum JointIdentifiers {
    SH_ROT = 0
    , SH_FLE
    , EL_FLE
    , EL_ROT
    , WR_FLE
    , WR_ROT
};

enum LinkIdentifiers {
    WORLD = 0
    , SHOULDER
    , ARM
    , ELBOW
    , FOREARM
    , WRIST_1
    , WRIST_2
};

static const JointIdentifiers orderedJointIDs[jointsCount] =
    {SH_ROT,SH_FLE,EL_FLE,EL_ROT,WR_FLE,WR_ROT};

static const LinkIdentifiers orderedLinkIDs[linksCount] =
    {WORLD,SHOULDER,ARM,ELBOW,FOREARM,WRIST_1,WRIST_2};

}
}
#endif
