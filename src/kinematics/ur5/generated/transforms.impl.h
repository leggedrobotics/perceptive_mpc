
// Constructors
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::MotionTransforms
    ()
     :
    fr_base_X_fr_shoulder_link(),
    fr_base_X_fr_wrist_3_link(),
    fr_shoulder_link_X_fr_world(),
    fr_world_X_fr_shoulder_link(),
    fr_upper_arm_link_X_fr_shoulder_link(),
    fr_shoulder_link_X_fr_upper_arm_link(),
    fr_forearm_link_X_fr_upper_arm_link(),
    fr_upper_arm_link_X_fr_forearm_link(),
    fr_wrist_1_link_X_fr_forearm_link(),
    fr_forearm_link_X_fr_wrist_1_link(),
    fr_wrist_2_link_X_fr_wrist_1_link(),
    fr_wrist_1_link_X_fr_wrist_2_link(),
    fr_wrist_3_link_X_fr_wrist_2_link(),
    fr_wrist_2_link_X_fr_wrist_3_link()
{
    updateParameters();
}
template <typename TRAIT>
void iit::ur5::tpl::MotionTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::ForceTransforms
    ()
     :
    fr_base_X_fr_shoulder_link(),
    fr_base_X_fr_wrist_3_link(),
    fr_shoulder_link_X_fr_world(),
    fr_world_X_fr_shoulder_link(),
    fr_upper_arm_link_X_fr_shoulder_link(),
    fr_shoulder_link_X_fr_upper_arm_link(),
    fr_forearm_link_X_fr_upper_arm_link(),
    fr_upper_arm_link_X_fr_forearm_link(),
    fr_wrist_1_link_X_fr_forearm_link(),
    fr_forearm_link_X_fr_wrist_1_link(),
    fr_wrist_2_link_X_fr_wrist_1_link(),
    fr_wrist_1_link_X_fr_wrist_2_link(),
    fr_wrist_3_link_X_fr_wrist_2_link(),
    fr_wrist_2_link_X_fr_wrist_3_link()
{
    updateParameters();
}
template <typename TRAIT>
void iit::ur5::tpl::ForceTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::HomogeneousTransforms
    ()
     :
    fr_base_X_fr_shoulder_link(),
    fr_base_X_fr_wrist_3_link(),
    fr_shoulder_link_X_fr_world(),
    fr_world_X_fr_shoulder_link(),
    fr_upper_arm_link_X_fr_shoulder_link(),
    fr_shoulder_link_X_fr_upper_arm_link(),
    fr_forearm_link_X_fr_upper_arm_link(),
    fr_upper_arm_link_X_fr_forearm_link(),
    fr_wrist_1_link_X_fr_forearm_link(),
    fr_forearm_link_X_fr_wrist_1_link(),
    fr_wrist_2_link_X_fr_wrist_1_link(),
    fr_wrist_1_link_X_fr_wrist_2_link(),
    fr_wrist_3_link_X_fr_wrist_2_link(),
    fr_wrist_2_link_X_fr_wrist_3_link()
{
    updateParameters();
}
template <typename TRAIT>
void iit::ur5::tpl::HomogeneousTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link::Type_fr_base_X_fr_shoulder_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) = - c_q_shoulder_pan_joint_;
    (*this)(0,1) =  s_q_shoulder_pan_joint_;
    (*this)(1,0) = - s_q_shoulder_pan_joint_;
    (*this)(1,1) = - c_q_shoulder_pan_joint_;
    (*this)(3,0) = ( 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(3,1) = ( 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(3,3) = - c_q_shoulder_pan_joint_;
    (*this)(3,4) =  s_q_shoulder_pan_joint_;
    (*this)(4,0) = (- 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(4,1) = ( 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(4,3) = - s_q_shoulder_pan_joint_;
    (*this)(4,4) = - c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link::Type_fr_base_X_fr_wrist_3_link()
{
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar s_q_shoulder_lift_joint_;
    Scalar s_q_wrist_1_joint_;
    Scalar s_q_wrist_3_joint_;
    Scalar s_q_shoulder_pan_joint_;
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_elbow_joint_;
    Scalar c_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_pan_joint_;
    Scalar c_q_wrist_1_joint_;
    Scalar c_q_wrist_2_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(0,1) = ((((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(0,2) = ((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) + ( s_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(1,0) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(1,1) = (((( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + (((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(1,2) = ((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(2,0) = ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  c_q_wrist_3_joint_));
    (*this)(2,1) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  s_q_wrist_3_joint_) + (((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(2,2) = ((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_);
    (*this)(3,0) = ((((((((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ((((((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + ((((((((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + ((((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + ((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) + ( 0.09465 *  s_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(3,1) = (((((((((((- 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + (((((( 0.39225 *  c_q_elbow_joint_) +  0.425) *  s_q_shoulder_lift_joint_) + (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) -  0.08916) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + (((((((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) - ( 0.09465 *  s_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(3,2) = ((((((((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) - ( 0.09465 *  s_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + (((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ((((((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_));
    (*this)(3,3) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(3,4) = ((((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(3,5) = (((((((( 1.0 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 1.0 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) + ( s_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(4,0) = ((((((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ((((((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916) *  s_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + ((((((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + ((((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + (((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) - ( 0.09465 *  c_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(4,1) = (((((((((((- 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + (((((( 0.39225 *  c_q_elbow_joint_) +  0.425) *  s_q_shoulder_lift_joint_) + (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) -  0.08916) *  s_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + ((((((((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + (((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) + ( 0.09465 *  c_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(4,2) = (((((((((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + (((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) + ( 0.09465 *  c_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + (((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ((((((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916) *  s_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_));
    (*this)(4,3) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(4,4) = (((( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + (((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(4,5) = (((((((( 1.0 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 1.0 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(5,0) = ((((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((((- 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) - (( 0.39225 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) + ((( 0.39225 *  c_q_elbow_joint_) +  0.425) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_2_joint_) + ((((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(5,1) = ((((((((((( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) + (( 0.39225 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) + (((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_2_joint_) + (((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(5,2) = ((((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) + (((((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((((- 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) - (( 0.39225 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) + ((( 0.39225 *  c_q_elbow_joint_) +  0.425) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_2_joint_));
    (*this)(5,3) = ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  c_q_wrist_3_joint_));
    (*this)(5,4) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  s_q_wrist_3_joint_) + (((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(5,5) = (((((( 1.0 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world::Type_fr_shoulder_link_X_fr_world()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) =  c_q_shoulder_pan_joint_;
    (*this)(0,1) =  s_q_shoulder_pan_joint_;
    (*this)(1,0) = - s_q_shoulder_pan_joint_;
    (*this)(1,1) =  c_q_shoulder_pan_joint_;
    (*this)(3,0) = (- 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(3,1) = ( 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(3,3) =  c_q_shoulder_pan_joint_;
    (*this)(3,4) =  s_q_shoulder_pan_joint_;
    (*this)(4,0) = (- 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(4,1) = (- 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(4,3) = - s_q_shoulder_pan_joint_;
    (*this)(4,4) =  c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link::Type_fr_world_X_fr_shoulder_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) =  c_q_shoulder_pan_joint_;
    (*this)(0,1) = - s_q_shoulder_pan_joint_;
    (*this)(1,0) =  s_q_shoulder_pan_joint_;
    (*this)(1,1) =  c_q_shoulder_pan_joint_;
    (*this)(3,0) = (- 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(3,1) = (- 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(3,3) =  c_q_shoulder_pan_joint_;
    (*this)(3,4) = - s_q_shoulder_pan_joint_;
    (*this)(4,0) = ( 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(4,1) = (- 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(4,3) =  s_q_shoulder_pan_joint_;
    (*this)(4,4) =  c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link::Type_fr_upper_arm_link_X_fr_shoulder_link()
{
    (*this)(0,1) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,1) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,1) = 0;
    (*this)(3,4) = 0;
    (*this)(4,1) = 0;
    (*this)(4,4) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_lift_joint_;
    
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    
    (*this)(0,0) = - s_q_shoulder_lift_joint_;
    (*this)(0,2) = - c_q_shoulder_lift_joint_;
    (*this)(1,0) = - c_q_shoulder_lift_joint_;
    (*this)(1,2) =  s_q_shoulder_lift_joint_;
    (*this)(3,0) = (- 0.13585 *  c_q_shoulder_lift_joint_);
    (*this)(3,2) = ( 0.13585 *  s_q_shoulder_lift_joint_);
    (*this)(3,3) = - s_q_shoulder_lift_joint_;
    (*this)(3,5) = - c_q_shoulder_lift_joint_;
    (*this)(4,0) = ( 0.13585 *  s_q_shoulder_lift_joint_);
    (*this)(4,2) = ( 0.13585 *  c_q_shoulder_lift_joint_);
    (*this)(4,3) = - c_q_shoulder_lift_joint_;
    (*this)(4,5) =  s_q_shoulder_lift_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link::Type_fr_shoulder_link_X_fr_upper_arm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = 1;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link::update(const JState& q) {
    Scalar s_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_lift_joint_;
    
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    
    (*this)(0,0) = - s_q_shoulder_lift_joint_;
    (*this)(0,1) = - c_q_shoulder_lift_joint_;
    (*this)(2,0) = - c_q_shoulder_lift_joint_;
    (*this)(2,1) =  s_q_shoulder_lift_joint_;
    (*this)(3,0) = (- 0.13585 *  c_q_shoulder_lift_joint_);
    (*this)(3,1) = ( 0.13585 *  s_q_shoulder_lift_joint_);
    (*this)(3,3) = - s_q_shoulder_lift_joint_;
    (*this)(3,4) = - c_q_shoulder_lift_joint_;
    (*this)(5,0) = ( 0.13585 *  s_q_shoulder_lift_joint_);
    (*this)(5,1) = ( 0.13585 *  c_q_shoulder_lift_joint_);
    (*this)(5,3) = - c_q_shoulder_lift_joint_;
    (*this)(5,4) =  s_q_shoulder_lift_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link::Type_fr_forearm_link_X_fr_upper_arm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,5) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = - 0.425;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar c_q_elbow_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    
    (*this)(0,0) =  c_q_elbow_joint_;
    (*this)(0,1) =  s_q_elbow_joint_;
    (*this)(1,0) = - s_q_elbow_joint_;
    (*this)(1,1) =  c_q_elbow_joint_;
    (*this)(3,0) = ( 0.1197 *  s_q_elbow_joint_);
    (*this)(3,1) = (- 0.1197 *  c_q_elbow_joint_);
    (*this)(3,2) = ( 0.425 *  c_q_elbow_joint_);
    (*this)(3,3) =  c_q_elbow_joint_;
    (*this)(3,4) =  s_q_elbow_joint_;
    (*this)(4,0) = ( 0.1197 *  c_q_elbow_joint_);
    (*this)(4,1) = ( 0.1197 *  s_q_elbow_joint_);
    (*this)(4,2) = (- 0.425 *  s_q_elbow_joint_);
    (*this)(4,3) = - s_q_elbow_joint_;
    (*this)(4,4) =  c_q_elbow_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link::Type_fr_upper_arm_link_X_fr_forearm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = - 0.425;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar c_q_elbow_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    
    (*this)(0,0) =  c_q_elbow_joint_;
    (*this)(0,1) = - s_q_elbow_joint_;
    (*this)(1,0) =  s_q_elbow_joint_;
    (*this)(1,1) =  c_q_elbow_joint_;
    (*this)(3,0) = ( 0.1197 *  s_q_elbow_joint_);
    (*this)(3,1) = ( 0.1197 *  c_q_elbow_joint_);
    (*this)(3,3) =  c_q_elbow_joint_;
    (*this)(3,4) = - s_q_elbow_joint_;
    (*this)(4,0) = (- 0.1197 *  c_q_elbow_joint_);
    (*this)(4,1) = ( 0.1197 *  s_q_elbow_joint_);
    (*this)(4,3) =  s_q_elbow_joint_;
    (*this)(4,4) =  c_q_elbow_joint_;
    (*this)(5,0) = ( 0.425 *  c_q_elbow_joint_);
    (*this)(5,1) = (- 0.425 *  s_q_elbow_joint_);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link::Type_fr_wrist_1_link_X_fr_forearm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = - 0.39225;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link::update(const JState& q) {
    Scalar s_q_wrist_1_joint_;
    Scalar c_q_wrist_1_joint_;
    
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    
    (*this)(0,0) = - s_q_wrist_1_joint_;
    (*this)(0,1) =  c_q_wrist_1_joint_;
    (*this)(1,0) = - c_q_wrist_1_joint_;
    (*this)(1,1) = - s_q_wrist_1_joint_;
    (*this)(3,2) = (- 0.39225 *  s_q_wrist_1_joint_);
    (*this)(3,3) = - s_q_wrist_1_joint_;
    (*this)(3,4) =  c_q_wrist_1_joint_;
    (*this)(4,2) = (- 0.39225 *  c_q_wrist_1_joint_);
    (*this)(4,3) = - c_q_wrist_1_joint_;
    (*this)(4,4) = - s_q_wrist_1_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link::Type_fr_forearm_link_X_fr_wrist_1_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = - 0.39225;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link::update(const JState& q) {
    Scalar s_q_wrist_1_joint_;
    Scalar c_q_wrist_1_joint_;
    
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    
    (*this)(0,0) = - s_q_wrist_1_joint_;
    (*this)(0,1) = - c_q_wrist_1_joint_;
    (*this)(1,0) =  c_q_wrist_1_joint_;
    (*this)(1,1) = - s_q_wrist_1_joint_;
    (*this)(3,3) = - s_q_wrist_1_joint_;
    (*this)(3,4) = - c_q_wrist_1_joint_;
    (*this)(4,3) =  c_q_wrist_1_joint_;
    (*this)(4,4) = - s_q_wrist_1_joint_;
    (*this)(5,0) = (- 0.39225 *  s_q_wrist_1_joint_);
    (*this)(5,1) = (- 0.39225 *  c_q_wrist_1_joint_);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link::Type_fr_wrist_2_link_X_fr_wrist_1_link()
{
    (*this)(0,1) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,1) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1.0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,2) = 0;
    (*this)(3,4) = 0;
    (*this)(4,0) = 0;
    (*this)(4,2) = 0;
    (*this)(4,4) = 0;
    (*this)(5,0) = 0.093;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = - 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link::update(const JState& q) {
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_wrist_2_joint_;
    
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    
    (*this)(0,0) =  c_q_wrist_2_joint_;
    (*this)(0,2) =  s_q_wrist_2_joint_;
    (*this)(1,0) = - s_q_wrist_2_joint_;
    (*this)(1,2) =  c_q_wrist_2_joint_;
    (*this)(3,1) = ( 0.093 *  c_q_wrist_2_joint_);
    (*this)(3,3) =  c_q_wrist_2_joint_;
    (*this)(3,5) =  s_q_wrist_2_joint_;
    (*this)(4,1) = (- 0.093 *  s_q_wrist_2_joint_);
    (*this)(4,3) = - s_q_wrist_2_joint_;
    (*this)(4,5) =  c_q_wrist_2_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link::Type_fr_wrist_1_link_X_fr_wrist_2_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0.093;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = - 1.0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link::update(const JState& q) {
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_wrist_2_joint_;
    
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    
    (*this)(0,0) =  c_q_wrist_2_joint_;
    (*this)(0,1) = - s_q_wrist_2_joint_;
    (*this)(2,0) =  s_q_wrist_2_joint_;
    (*this)(2,1) =  c_q_wrist_2_joint_;
    (*this)(3,3) =  c_q_wrist_2_joint_;
    (*this)(3,4) = - s_q_wrist_2_joint_;
    (*this)(4,0) = ( 0.093 *  c_q_wrist_2_joint_);
    (*this)(4,1) = (- 0.093 *  s_q_wrist_2_joint_);
    (*this)(5,3) =  s_q_wrist_2_joint_;
    (*this)(5,4) =  c_q_wrist_2_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link::Type_fr_wrist_3_link_X_fr_wrist_2_link()
{
    (*this)(0,1) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,1) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1.0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,2) = 0;
    (*this)(3,4) = 0;
    (*this)(4,0) = 0;
    (*this)(4,2) = 0;
    (*this)(4,4) = 0;
    (*this)(5,0) = - 0.09465;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link::update(const JState& q) {
    Scalar s_q_wrist_3_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) =  c_q_wrist_3_joint_;
    (*this)(0,2) = - s_q_wrist_3_joint_;
    (*this)(1,0) = - s_q_wrist_3_joint_;
    (*this)(1,2) = - c_q_wrist_3_joint_;
    (*this)(3,1) = ( 0.09465 *  c_q_wrist_3_joint_);
    (*this)(3,3) =  c_q_wrist_3_joint_;
    (*this)(3,5) = - s_q_wrist_3_joint_;
    (*this)(4,1) = (- 0.09465 *  s_q_wrist_3_joint_);
    (*this)(4,3) = - s_q_wrist_3_joint_;
    (*this)(4,5) = - c_q_wrist_3_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link::Type_fr_wrist_2_link_X_fr_wrist_3_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = - 0.09465;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = 1.0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link& iit::ur5::tpl::MotionTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link::update(const JState& q) {
    Scalar s_q_wrist_3_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) =  c_q_wrist_3_joint_;
    (*this)(0,1) = - s_q_wrist_3_joint_;
    (*this)(2,0) = - s_q_wrist_3_joint_;
    (*this)(2,1) = - c_q_wrist_3_joint_;
    (*this)(3,3) =  c_q_wrist_3_joint_;
    (*this)(3,4) = - s_q_wrist_3_joint_;
    (*this)(4,0) = ( 0.09465 *  c_q_wrist_3_joint_);
    (*this)(4,1) = (- 0.09465 *  s_q_wrist_3_joint_);
    (*this)(5,3) = - s_q_wrist_3_joint_;
    (*this)(5,4) = - c_q_wrist_3_joint_;
    return *this;
}

template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link::Type_fr_base_X_fr_shoulder_link()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) = - c_q_shoulder_pan_joint_;
    (*this)(0,1) =  s_q_shoulder_pan_joint_;
    (*this)(0,3) = ( 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(0,4) = ( 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(1,0) = - s_q_shoulder_pan_joint_;
    (*this)(1,1) = - c_q_shoulder_pan_joint_;
    (*this)(1,3) = (- 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(1,4) = ( 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(3,3) = - c_q_shoulder_pan_joint_;
    (*this)(3,4) =  s_q_shoulder_pan_joint_;
    (*this)(4,3) = - s_q_shoulder_pan_joint_;
    (*this)(4,4) = - c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link::Type_fr_base_X_fr_wrist_3_link()
{
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar s_q_shoulder_lift_joint_;
    Scalar s_q_wrist_1_joint_;
    Scalar s_q_wrist_3_joint_;
    Scalar s_q_shoulder_pan_joint_;
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_elbow_joint_;
    Scalar c_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_pan_joint_;
    Scalar c_q_wrist_1_joint_;
    Scalar c_q_wrist_2_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(0,1) = ((((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(0,2) = (((((((( 1.0 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 1.0 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) + ( s_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(0,3) = ((((((((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ((((((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + ((((((((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + ((((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + ((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) + ( 0.09465 *  s_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(0,4) = (((((((((((- 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + (((((( 0.39225 *  c_q_elbow_joint_) +  0.425) *  s_q_shoulder_lift_joint_) + (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) -  0.08916) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + (((((((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) - ( 0.09465 *  s_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(0,5) = ((((((((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  s_q_shoulder_pan_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) - ( 0.09465 *  s_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + (((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ((((((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_));
    (*this)(1,0) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(1,1) = (((( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + (((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(1,2) = (((((((( 1.0 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 1.0 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(1,3) = ((((((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ((((((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916) *  s_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + ((((((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + ((((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + (((((- 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) - ( 0.09465 *  c_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(1,4) = (((((((((((- 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + (((((( 0.39225 *  c_q_elbow_joint_) +  0.425) *  s_q_shoulder_lift_joint_) + (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) -  0.08916) *  s_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + ((((((((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + (((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) + ( 0.09465 *  c_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((((- 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) + ( 0.425 *  c_q_elbow_joint_)) +  0.39225) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(1,5) = (((((((((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + (((((( 0.08916 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.08916 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  c_q_elbow_joint_)) -  0.39225) *  c_q_shoulder_pan_joint_)) *  s_q_wrist_1_joint_) + (((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) + ((((( 0.08916 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.08916 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) - ( 0.425 *  s_q_elbow_joint_)) *  c_q_shoulder_pan_joint_)) *  c_q_wrist_1_joint_)) + ( 0.09465 *  c_q_shoulder_pan_joint_)) *  s_q_wrist_2_joint_) + (((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ((((((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916) *  s_q_shoulder_pan_joint_)) *  c_q_wrist_2_joint_));
    (*this)(2,0) = ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  c_q_wrist_3_joint_));
    (*this)(2,1) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  s_q_wrist_3_joint_) + (((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(2,2) = (((((( 1.0 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_);
    (*this)(2,3) = ((((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((((- 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) - (( 0.39225 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) + ((( 0.39225 *  c_q_elbow_joint_) +  0.425) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_2_joint_) + ((((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(2,4) = ((((((((((( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) + (( 0.39225 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) + (((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_2_joint_) + (((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((((- 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(2,5) = ((((((( 0.10915 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.10915 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.10915 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.10915 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) + (((((((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((((- 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) - (( 0.39225 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) + ((( 0.39225 *  c_q_elbow_joint_) +  0.425) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_2_joint_));
    (*this)(3,3) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(3,4) = ((((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(3,5) = ((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) + ( s_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(4,3) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(4,4) = (((( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + (((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(4,5) = ((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(5,3) = ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  c_q_wrist_3_joint_));
    (*this)(5,4) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  s_q_wrist_3_joint_) + (((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(5,5) = ((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world::Type_fr_shoulder_link_X_fr_world()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) =  c_q_shoulder_pan_joint_;
    (*this)(0,1) =  s_q_shoulder_pan_joint_;
    (*this)(0,3) = (- 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(0,4) = ( 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(1,0) = - s_q_shoulder_pan_joint_;
    (*this)(1,1) =  c_q_shoulder_pan_joint_;
    (*this)(1,3) = (- 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(1,4) = (- 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(3,3) =  c_q_shoulder_pan_joint_;
    (*this)(3,4) =  s_q_shoulder_pan_joint_;
    (*this)(4,3) = - s_q_shoulder_pan_joint_;
    (*this)(4,4) =  c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link::Type_fr_world_X_fr_shoulder_link()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) =  c_q_shoulder_pan_joint_;
    (*this)(0,1) = - s_q_shoulder_pan_joint_;
    (*this)(0,3) = (- 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(0,4) = (- 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(1,0) =  s_q_shoulder_pan_joint_;
    (*this)(1,1) =  c_q_shoulder_pan_joint_;
    (*this)(1,3) = ( 0.08916 *  c_q_shoulder_pan_joint_);
    (*this)(1,4) = (- 0.08916 *  s_q_shoulder_pan_joint_);
    (*this)(3,3) =  c_q_shoulder_pan_joint_;
    (*this)(3,4) = - s_q_shoulder_pan_joint_;
    (*this)(4,3) =  s_q_shoulder_pan_joint_;
    (*this)(4,4) =  c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link::Type_fr_upper_arm_link_X_fr_shoulder_link()
{
    (*this)(0,1) = 0;
    (*this)(0,4) = 0;
    (*this)(1,1) = 0;
    (*this)(1,4) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,4) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,4) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_lift_joint_;
    
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    
    (*this)(0,0) = - s_q_shoulder_lift_joint_;
    (*this)(0,2) = - c_q_shoulder_lift_joint_;
    (*this)(0,3) = (- 0.13585 *  c_q_shoulder_lift_joint_);
    (*this)(0,5) = ( 0.13585 *  s_q_shoulder_lift_joint_);
    (*this)(1,0) = - c_q_shoulder_lift_joint_;
    (*this)(1,2) =  s_q_shoulder_lift_joint_;
    (*this)(1,3) = ( 0.13585 *  s_q_shoulder_lift_joint_);
    (*this)(1,5) = ( 0.13585 *  c_q_shoulder_lift_joint_);
    (*this)(3,3) = - s_q_shoulder_lift_joint_;
    (*this)(3,5) = - c_q_shoulder_lift_joint_;
    (*this)(4,3) = - c_q_shoulder_lift_joint_;
    (*this)(4,5) =  s_q_shoulder_lift_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link::Type_fr_shoulder_link_X_fr_upper_arm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link::update(const JState& q) {
    Scalar s_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_lift_joint_;
    
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    
    (*this)(0,0) = - s_q_shoulder_lift_joint_;
    (*this)(0,1) = - c_q_shoulder_lift_joint_;
    (*this)(0,3) = (- 0.13585 *  c_q_shoulder_lift_joint_);
    (*this)(0,4) = ( 0.13585 *  s_q_shoulder_lift_joint_);
    (*this)(2,0) = - c_q_shoulder_lift_joint_;
    (*this)(2,1) =  s_q_shoulder_lift_joint_;
    (*this)(2,3) = ( 0.13585 *  s_q_shoulder_lift_joint_);
    (*this)(2,4) = ( 0.13585 *  c_q_shoulder_lift_joint_);
    (*this)(3,3) = - s_q_shoulder_lift_joint_;
    (*this)(3,4) = - c_q_shoulder_lift_joint_;
    (*this)(5,3) = - c_q_shoulder_lift_joint_;
    (*this)(5,4) =  s_q_shoulder_lift_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link::Type_fr_forearm_link_X_fr_upper_arm_link()
{
    (*this)(0,2) = 0;
    (*this)(1,2) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = - 0.425;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar c_q_elbow_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    
    (*this)(0,0) =  c_q_elbow_joint_;
    (*this)(0,1) =  s_q_elbow_joint_;
    (*this)(0,3) = ( 0.1197 *  s_q_elbow_joint_);
    (*this)(0,4) = (- 0.1197 *  c_q_elbow_joint_);
    (*this)(0,5) = ( 0.425 *  c_q_elbow_joint_);
    (*this)(1,0) = - s_q_elbow_joint_;
    (*this)(1,1) =  c_q_elbow_joint_;
    (*this)(1,3) = ( 0.1197 *  c_q_elbow_joint_);
    (*this)(1,4) = ( 0.1197 *  s_q_elbow_joint_);
    (*this)(1,5) = (- 0.425 *  s_q_elbow_joint_);
    (*this)(3,3) =  c_q_elbow_joint_;
    (*this)(3,4) =  s_q_elbow_joint_;
    (*this)(4,3) = - s_q_elbow_joint_;
    (*this)(4,4) =  c_q_elbow_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link::Type_fr_upper_arm_link_X_fr_forearm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = - 0.425;
    (*this)(1,2) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar c_q_elbow_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    
    (*this)(0,0) =  c_q_elbow_joint_;
    (*this)(0,1) = - s_q_elbow_joint_;
    (*this)(0,3) = ( 0.1197 *  s_q_elbow_joint_);
    (*this)(0,4) = ( 0.1197 *  c_q_elbow_joint_);
    (*this)(1,0) =  s_q_elbow_joint_;
    (*this)(1,1) =  c_q_elbow_joint_;
    (*this)(1,3) = (- 0.1197 *  c_q_elbow_joint_);
    (*this)(1,4) = ( 0.1197 *  s_q_elbow_joint_);
    (*this)(2,3) = ( 0.425 *  c_q_elbow_joint_);
    (*this)(2,4) = (- 0.425 *  s_q_elbow_joint_);
    (*this)(3,3) =  c_q_elbow_joint_;
    (*this)(3,4) = - s_q_elbow_joint_;
    (*this)(4,3) =  s_q_elbow_joint_;
    (*this)(4,4) =  c_q_elbow_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link::Type_fr_wrist_1_link_X_fr_forearm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = - 0.39225;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link::update(const JState& q) {
    Scalar s_q_wrist_1_joint_;
    Scalar c_q_wrist_1_joint_;
    
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    
    (*this)(0,0) = - s_q_wrist_1_joint_;
    (*this)(0,1) =  c_q_wrist_1_joint_;
    (*this)(0,5) = (- 0.39225 *  s_q_wrist_1_joint_);
    (*this)(1,0) = - c_q_wrist_1_joint_;
    (*this)(1,1) = - s_q_wrist_1_joint_;
    (*this)(1,5) = (- 0.39225 *  c_q_wrist_1_joint_);
    (*this)(3,3) = - s_q_wrist_1_joint_;
    (*this)(3,4) =  c_q_wrist_1_joint_;
    (*this)(4,3) = - c_q_wrist_1_joint_;
    (*this)(4,4) = - s_q_wrist_1_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link::Type_fr_forearm_link_X_fr_wrist_1_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = - 0.39225;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link::update(const JState& q) {
    Scalar s_q_wrist_1_joint_;
    Scalar c_q_wrist_1_joint_;
    
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    
    (*this)(0,0) = - s_q_wrist_1_joint_;
    (*this)(0,1) = - c_q_wrist_1_joint_;
    (*this)(1,0) =  c_q_wrist_1_joint_;
    (*this)(1,1) = - s_q_wrist_1_joint_;
    (*this)(2,3) = (- 0.39225 *  s_q_wrist_1_joint_);
    (*this)(2,4) = (- 0.39225 *  c_q_wrist_1_joint_);
    (*this)(3,3) = - s_q_wrist_1_joint_;
    (*this)(3,4) = - c_q_wrist_1_joint_;
    (*this)(4,3) =  c_q_wrist_1_joint_;
    (*this)(4,4) = - s_q_wrist_1_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link::Type_fr_wrist_2_link_X_fr_wrist_1_link()
{
    (*this)(0,1) = 0;
    (*this)(0,3) = 0;
    (*this)(0,5) = 0;
    (*this)(1,1) = 0;
    (*this)(1,3) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0.093;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,4) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,4) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = - 1.0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link::update(const JState& q) {
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_wrist_2_joint_;
    
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    
    (*this)(0,0) =  c_q_wrist_2_joint_;
    (*this)(0,2) =  s_q_wrist_2_joint_;
    (*this)(0,4) = ( 0.093 *  c_q_wrist_2_joint_);
    (*this)(1,0) = - s_q_wrist_2_joint_;
    (*this)(1,2) =  c_q_wrist_2_joint_;
    (*this)(1,4) = (- 0.093 *  s_q_wrist_2_joint_);
    (*this)(3,3) =  c_q_wrist_2_joint_;
    (*this)(3,5) =  s_q_wrist_2_joint_;
    (*this)(4,3) = - s_q_wrist_2_joint_;
    (*this)(4,5) =  c_q_wrist_2_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link::Type_fr_wrist_1_link_X_fr_wrist_2_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0.093;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1.0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = - 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link::update(const JState& q) {
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_wrist_2_joint_;
    
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    
    (*this)(0,0) =  c_q_wrist_2_joint_;
    (*this)(0,1) = - s_q_wrist_2_joint_;
    (*this)(1,3) = ( 0.093 *  c_q_wrist_2_joint_);
    (*this)(1,4) = (- 0.093 *  s_q_wrist_2_joint_);
    (*this)(2,0) =  s_q_wrist_2_joint_;
    (*this)(2,1) =  c_q_wrist_2_joint_;
    (*this)(3,3) =  c_q_wrist_2_joint_;
    (*this)(3,4) = - s_q_wrist_2_joint_;
    (*this)(5,3) =  s_q_wrist_2_joint_;
    (*this)(5,4) =  c_q_wrist_2_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link::Type_fr_wrist_3_link_X_fr_wrist_2_link()
{
    (*this)(0,1) = 0;
    (*this)(0,3) = 0;
    (*this)(0,5) = 0;
    (*this)(1,1) = 0;
    (*this)(1,3) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = - 0.09465;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,4) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,4) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1.0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link::update(const JState& q) {
    Scalar s_q_wrist_3_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) =  c_q_wrist_3_joint_;
    (*this)(0,2) = - s_q_wrist_3_joint_;
    (*this)(0,4) = ( 0.09465 *  c_q_wrist_3_joint_);
    (*this)(1,0) = - s_q_wrist_3_joint_;
    (*this)(1,2) = - c_q_wrist_3_joint_;
    (*this)(1,4) = (- 0.09465 *  s_q_wrist_3_joint_);
    (*this)(3,3) =  c_q_wrist_3_joint_;
    (*this)(3,5) = - s_q_wrist_3_joint_;
    (*this)(4,3) = - s_q_wrist_3_joint_;
    (*this)(4,5) = - c_q_wrist_3_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link::Type_fr_wrist_2_link_X_fr_wrist_3_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = - 0.09465;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1.0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link& iit::ur5::tpl::ForceTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link::update(const JState& q) {
    Scalar s_q_wrist_3_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) =  c_q_wrist_3_joint_;
    (*this)(0,1) = - s_q_wrist_3_joint_;
    (*this)(1,3) = ( 0.09465 *  c_q_wrist_3_joint_);
    (*this)(1,4) = (- 0.09465 *  s_q_wrist_3_joint_);
    (*this)(2,0) = - s_q_wrist_3_joint_;
    (*this)(2,1) = - c_q_wrist_3_joint_;
    (*this)(3,3) =  c_q_wrist_3_joint_;
    (*this)(3,4) = - s_q_wrist_3_joint_;
    (*this)(5,3) = - s_q_wrist_3_joint_;
    (*this)(5,4) = - c_q_wrist_3_joint_;
    return *this;
}

template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link::Type_fr_base_X_fr_shoulder_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.08916;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_base_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) = - c_q_shoulder_pan_joint_;
    (*this)(0,1) =  s_q_shoulder_pan_joint_;
    (*this)(1,0) = - s_q_shoulder_pan_joint_;
    (*this)(1,1) = - c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link::Type_fr_base_X_fr_wrist_3_link()
{
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_base_X_fr_wrist_3_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar s_q_shoulder_lift_joint_;
    Scalar s_q_wrist_1_joint_;
    Scalar s_q_wrist_3_joint_;
    Scalar s_q_shoulder_pan_joint_;
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_elbow_joint_;
    Scalar c_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_pan_joint_;
    Scalar c_q_wrist_1_joint_;
    Scalar c_q_wrist_2_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(0,1) = ((((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( s_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(0,2) = ((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) + ( s_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(0,3) = (((((((( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + ( 0.10915 *  s_q_shoulder_pan_joint_)) + (((( 0.39225 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  c_q_shoulder_lift_joint_)) *  c_q_shoulder_pan_joint_));
    (*this)(1,0) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + ((((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_)) *  c_q_wrist_3_joint_));
    (*this)(1,1) = (((( c_q_shoulder_pan_joint_ *  s_q_wrist_2_joint_) + (((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_)) *  s_q_wrist_3_joint_) + (((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(1,2) = ((((((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + (((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_) - ( c_q_shoulder_pan_joint_ *  c_q_wrist_2_joint_));
    (*this)(1,3) = (((((((( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_) - (( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  s_q_wrist_1_joint_) + ((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_) *  c_q_wrist_1_joint_)) + (((( 0.39225 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  c_q_shoulder_lift_joint_)) *  s_q_shoulder_pan_joint_)) - ( 0.10915 *  c_q_shoulder_pan_joint_));
    (*this)(2,0) = ((((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_3_joint_) + (((((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) + ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  c_q_wrist_3_joint_));
    (*this)(2,1) = ((((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_2_joint_) *  s_q_wrist_3_joint_) + (((((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + ((( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  c_q_wrist_3_joint_));
    (*this)(2,2) = ((((( s_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( c_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((- c_q_elbow_joint_ *  s_q_shoulder_lift_joint_) - ( s_q_elbow_joint_ *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) *  s_q_wrist_2_joint_);
    (*this)(2,3) = (((((((( 0.09465 *  c_q_elbow_joint_) *  s_q_shoulder_lift_joint_) + (( 0.09465 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  s_q_wrist_1_joint_) + (((( 0.09465 *  s_q_elbow_joint_) *  s_q_shoulder_lift_joint_) - (( 0.09465 *  c_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) *  c_q_wrist_1_joint_)) + (((- 0.39225 *  c_q_elbow_joint_) -  0.425) *  s_q_shoulder_lift_joint_)) - (( 0.39225 *  s_q_elbow_joint_) *  c_q_shoulder_lift_joint_)) +  0.08916);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world::Type_fr_shoulder_link_X_fr_world()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = - 0.08916;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_world::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) =  c_q_shoulder_pan_joint_;
    (*this)(0,1) =  s_q_shoulder_pan_joint_;
    (*this)(1,0) = - s_q_shoulder_pan_joint_;
    (*this)(1,1) =  c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link::Type_fr_world_X_fr_shoulder_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.08916;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_world_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_pan_joint_;
    Scalar c_q_shoulder_pan_joint_;
    
    s_q_shoulder_pan_joint_ = TRAIT::sin( q(SHOULDER_PAN_JOINT));
    c_q_shoulder_pan_joint_ = TRAIT::cos( q(SHOULDER_PAN_JOINT));
    
    (*this)(0,0) =  c_q_shoulder_pan_joint_;
    (*this)(0,1) = - s_q_shoulder_pan_joint_;
    (*this)(1,0) =  s_q_shoulder_pan_joint_;
    (*this)(1,1) =  c_q_shoulder_pan_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link::Type_fr_upper_arm_link_X_fr_shoulder_link()
{
    (*this)(0,1) = 0;
    (*this)(0,3) = 0;
    (*this)(1,1) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = - 0.13585;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_shoulder_link::update(const JState& q) {
    Scalar s_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_lift_joint_;
    
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    
    (*this)(0,0) = - s_q_shoulder_lift_joint_;
    (*this)(0,2) = - c_q_shoulder_lift_joint_;
    (*this)(1,0) = - c_q_shoulder_lift_joint_;
    (*this)(1,2) =  s_q_shoulder_lift_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link::Type_fr_shoulder_link_X_fr_upper_arm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1.0;
    (*this)(1,3) = 0.13585;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_shoulder_link_X_fr_upper_arm_link::update(const JState& q) {
    Scalar s_q_shoulder_lift_joint_;
    Scalar c_q_shoulder_lift_joint_;
    
    s_q_shoulder_lift_joint_ = TRAIT::sin( q(SHOULDER_LIFT_JOINT));
    c_q_shoulder_lift_joint_ = TRAIT::cos( q(SHOULDER_LIFT_JOINT));
    
    (*this)(0,0) = - s_q_shoulder_lift_joint_;
    (*this)(0,1) = - c_q_shoulder_lift_joint_;
    (*this)(2,0) = - c_q_shoulder_lift_joint_;
    (*this)(2,1) =  s_q_shoulder_lift_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link::Type_fr_forearm_link_X_fr_upper_arm_link()
{
    (*this)(0,2) = 0;
    (*this)(1,2) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.1197;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_forearm_link_X_fr_upper_arm_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar c_q_elbow_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    
    (*this)(0,0) =  c_q_elbow_joint_;
    (*this)(0,1) =  s_q_elbow_joint_;
    (*this)(0,3) = ( 0.425 *  s_q_elbow_joint_);
    (*this)(1,0) = - s_q_elbow_joint_;
    (*this)(1,1) =  c_q_elbow_joint_;
    (*this)(1,3) = ( 0.425 *  c_q_elbow_joint_);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link::Type_fr_upper_arm_link_X_fr_forearm_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = - 0.425;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = - 0.1197;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_upper_arm_link_X_fr_forearm_link::update(const JState& q) {
    Scalar s_q_elbow_joint_;
    Scalar c_q_elbow_joint_;
    
    s_q_elbow_joint_ = TRAIT::sin( q(ELBOW_JOINT));
    c_q_elbow_joint_ = TRAIT::cos( q(ELBOW_JOINT));
    
    (*this)(0,0) =  c_q_elbow_joint_;
    (*this)(0,1) = - s_q_elbow_joint_;
    (*this)(1,0) =  s_q_elbow_joint_;
    (*this)(1,1) =  c_q_elbow_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link::Type_fr_wrist_1_link_X_fr_forearm_link()
{
    (*this)(0,2) = 0;
    (*this)(1,2) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_forearm_link::update(const JState& q) {
    Scalar s_q_wrist_1_joint_;
    Scalar c_q_wrist_1_joint_;
    
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    
    (*this)(0,0) = - s_q_wrist_1_joint_;
    (*this)(0,1) =  c_q_wrist_1_joint_;
    (*this)(0,3) = ( 0.39225 *  c_q_wrist_1_joint_);
    (*this)(1,0) = - c_q_wrist_1_joint_;
    (*this)(1,1) = - s_q_wrist_1_joint_;
    (*this)(1,3) = (- 0.39225 *  s_q_wrist_1_joint_);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link::Type_fr_forearm_link_X_fr_wrist_1_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = - 0.39225;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_forearm_link_X_fr_wrist_1_link::update(const JState& q) {
    Scalar s_q_wrist_1_joint_;
    Scalar c_q_wrist_1_joint_;
    
    s_q_wrist_1_joint_ = TRAIT::sin( q(WRIST_1_JOINT));
    c_q_wrist_1_joint_ = TRAIT::cos( q(WRIST_1_JOINT));
    
    (*this)(0,0) = - s_q_wrist_1_joint_;
    (*this)(0,1) = - c_q_wrist_1_joint_;
    (*this)(1,0) =  c_q_wrist_1_joint_;
    (*this)(1,1) = - s_q_wrist_1_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link::Type_fr_wrist_2_link_X_fr_wrist_1_link()
{
    (*this)(0,1) = 0;
    (*this)(1,1) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_1_link::update(const JState& q) {
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_wrist_2_joint_;
    
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    
    (*this)(0,0) =  c_q_wrist_2_joint_;
    (*this)(0,2) =  s_q_wrist_2_joint_;
    (*this)(0,3) = (- 0.093 *  s_q_wrist_2_joint_);
    (*this)(1,0) = - s_q_wrist_2_joint_;
    (*this)(1,2) =  c_q_wrist_2_joint_;
    (*this)(1,3) = (- 0.093 *  c_q_wrist_2_joint_);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link::Type_fr_wrist_1_link_X_fr_wrist_2_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1;
    (*this)(1,3) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0.093;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_1_link_X_fr_wrist_2_link::update(const JState& q) {
    Scalar s_q_wrist_2_joint_;
    Scalar c_q_wrist_2_joint_;
    
    s_q_wrist_2_joint_ = TRAIT::sin( q(WRIST_2_JOINT));
    c_q_wrist_2_joint_ = TRAIT::cos( q(WRIST_2_JOINT));
    
    (*this)(0,0) =  c_q_wrist_2_joint_;
    (*this)(0,1) = - s_q_wrist_2_joint_;
    (*this)(2,0) =  s_q_wrist_2_joint_;
    (*this)(2,1) =  c_q_wrist_2_joint_;
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link::Type_fr_wrist_3_link_X_fr_wrist_2_link()
{
    (*this)(0,1) = 0;
    (*this)(1,1) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_3_link_X_fr_wrist_2_link::update(const JState& q) {
    Scalar s_q_wrist_3_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) =  c_q_wrist_3_joint_;
    (*this)(0,2) = - s_q_wrist_3_joint_;
    (*this)(0,3) = ( 0.09465 *  s_q_wrist_3_joint_);
    (*this)(1,0) = - s_q_wrist_3_joint_;
    (*this)(1,2) = - c_q_wrist_3_joint_;
    (*this)(1,3) = ( 0.09465 *  c_q_wrist_3_joint_);
    return *this;
}
template <typename TRAIT>
iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link::Type_fr_wrist_2_link_X_fr_wrist_3_link()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,3) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0.09465;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link& iit::ur5::tpl::HomogeneousTransforms<TRAIT>::Type_fr_wrist_2_link_X_fr_wrist_3_link::update(const JState& q) {
    Scalar s_q_wrist_3_joint_;
    Scalar c_q_wrist_3_joint_;
    
    s_q_wrist_3_joint_ = TRAIT::sin( q(WRIST_3_JOINT));
    c_q_wrist_3_joint_ = TRAIT::cos( q(WRIST_3_JOINT));
    
    (*this)(0,0) =  c_q_wrist_3_joint_;
    (*this)(0,1) = - s_q_wrist_3_joint_;
    (*this)(2,0) = - s_q_wrist_3_joint_;
    (*this)(2,1) = - c_q_wrist_3_joint_;
    return *this;
}

