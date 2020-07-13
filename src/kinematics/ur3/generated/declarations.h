#ifndef IIT_ROBOT_UR3_DECLARATIONS_H_
#define IIT_ROBOT_UR3_DECLARATIONS_H_

#include <iit/rbd/rbd.h>

namespace iit {
namespace ur3 {

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
    SHOULDER_PAN_JOINT = 0
    , SHOULDER_LIFT_JOINT
    , ELBOW_JOINT
    , WRIST_1_JOINT
    , WRIST_2_JOINT
    , WRIST_3_JOINT
};

enum LinkIdentifiers {
    WORLD = 0
    , SHOULDER_LINK
    , UPPER_ARM_LINK
    , FOREARM_LINK
    , WRIST_1_LINK
    , WRIST_2_LINK
    , WRIST_3_LINK
};

static const JointIdentifiers orderedJointIDs[jointsCount] =
    {SHOULDER_PAN_JOINT,SHOULDER_LIFT_JOINT,ELBOW_JOINT,WRIST_1_JOINT,WRIST_2_JOINT,WRIST_3_JOINT};

static const LinkIdentifiers orderedLinkIDs[linksCount] =
    {WORLD,SHOULDER_LINK,UPPER_ARM_LINK,FOREARM_LINK,WRIST_1_LINK,WRIST_2_LINK,WRIST_3_LINK};

}
}
#endif
