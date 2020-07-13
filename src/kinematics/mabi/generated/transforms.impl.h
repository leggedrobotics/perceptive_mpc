
// Constructors
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::MotionTransforms
    ()
     :
    fr_arm_mount_X_fr_SHOULDER(),
    fr_arm_mount_X_fr_WRIST_2(),
    fr_WR_ROT_X_fr_WRIST_2(),
    fr_SHOULDER_X_fr_world(),
    fr_world_X_fr_SHOULDER(),
    fr_ARM_X_fr_SHOULDER(),
    fr_SHOULDER_X_fr_ARM(),
    fr_ELBOW_X_fr_ARM(),
    fr_ARM_X_fr_ELBOW(),
    fr_FOREARM_X_fr_ELBOW(),
    fr_ELBOW_X_fr_FOREARM(),
    fr_WRIST_1_X_fr_FOREARM(),
    fr_FOREARM_X_fr_WRIST_1(),
    fr_WRIST_2_X_fr_WRIST_1(),
    fr_WRIST_1_X_fr_WRIST_2()
{
    updateParameters();
}
template <typename TRAIT>
void iit::mabi::tpl::MotionTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::ForceTransforms
    ()
     :
    fr_arm_mount_X_fr_SHOULDER(),
    fr_arm_mount_X_fr_WRIST_2(),
    fr_WR_ROT_X_fr_WRIST_2(),
    fr_SHOULDER_X_fr_world(),
    fr_world_X_fr_SHOULDER(),
    fr_ARM_X_fr_SHOULDER(),
    fr_SHOULDER_X_fr_ARM(),
    fr_ELBOW_X_fr_ARM(),
    fr_ARM_X_fr_ELBOW(),
    fr_FOREARM_X_fr_ELBOW(),
    fr_ELBOW_X_fr_FOREARM(),
    fr_WRIST_1_X_fr_FOREARM(),
    fr_FOREARM_X_fr_WRIST_1(),
    fr_WRIST_2_X_fr_WRIST_1(),
    fr_WRIST_1_X_fr_WRIST_2()
{
    updateParameters();
}
template <typename TRAIT>
void iit::mabi::tpl::ForceTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::HomogeneousTransforms
    ()
     :
    fr_arm_mount_X_fr_SHOULDER(),
    fr_arm_mount_X_fr_WRIST_2(),
    fr_WR_ROT_X_fr_WRIST_2(),
    fr_SHOULDER_X_fr_world(),
    fr_world_X_fr_SHOULDER(),
    fr_ARM_X_fr_SHOULDER(),
    fr_SHOULDER_X_fr_ARM(),
    fr_ELBOW_X_fr_ARM(),
    fr_ARM_X_fr_ELBOW(),
    fr_FOREARM_X_fr_ELBOW(),
    fr_ELBOW_X_fr_FOREARM(),
    fr_WRIST_1_X_fr_FOREARM(),
    fr_FOREARM_X_fr_WRIST_1(),
    fr_WRIST_2_X_fr_WRIST_1(),
    fr_WRIST_1_X_fr_WRIST_2()
{
    updateParameters();
}
template <typename TRAIT>
void iit::mabi::tpl::HomogeneousTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER::Type_fr_arm_mount_X_fr_SHOULDER()
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
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) = - s_q_SH_ROT_;
    (*this)(1,0) =  s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    (*this)(3,0) = (- 0.189 *  s_q_SH_ROT_);
    (*this)(3,1) = (- 0.189 *  c_q_SH_ROT_);
    (*this)(3,3) =  c_q_SH_ROT_;
    (*this)(3,4) = - s_q_SH_ROT_;
    (*this)(4,0) = ( 0.189 *  c_q_SH_ROT_);
    (*this)(4,1) = (- 0.189 *  s_q_SH_ROT_);
    (*this)(4,3) =  s_q_SH_ROT_;
    (*this)(4,4) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2::Type_fr_arm_mount_X_fr_WRIST_2()
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
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar s_q_EL_ROT_;
    Scalar s_q_SH_FLE_;
    Scalar s_q_SH_ROT_;
    Scalar s_q_WR_ROT_;
    Scalar s_q_WR_FLE_;
    Scalar c_q_EL_FLE_;
    Scalar c_q_SH_FLE_;
    Scalar c_q_EL_ROT_;
    Scalar c_q_SH_ROT_;
    Scalar c_q_WR_FLE_;
    Scalar c_q_WR_ROT_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(0,1) = ((((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(0,2) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(1,0) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(1,1) = ((((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((( s_q_EL_ROT_ *  s_q_SH_ROT_) + (((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(1,2) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(2,0) = ((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + ((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(2,1) = ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(2,2) = ((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_));
    (*this)(3,0) = ((((((((((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (( 0.1 *  s_q_EL_ROT_) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  c_q_EL_ROT_)) *  s_q_SH_ROT_)) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (((((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) + ( 0.7 *  s_q_EL_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((((((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  s_q_EL_ROT_)) *  s_q_SH_ROT_) + ((((((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + (((- 0.7 *  c_q_EL_FLE_) -  0.55) *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + ((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_)) - (( 0.1 *  c_q_EL_ROT_) *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(3,1) = (((((((((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (((((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) - ( 0.7 *  s_q_EL_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + ((((((((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_EL_ROT_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  s_q_EL_ROT_)) *  s_q_SH_ROT_) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_)) + (( 0.1 *  c_q_EL_ROT_) *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (( 0.1 *  s_q_EL_ROT_) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  c_q_EL_ROT_)) *  s_q_SH_ROT_)) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(3,2) = ((((((((((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  s_q_EL_ROT_)) *  s_q_SH_ROT_) + ((((((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + (((- 0.7 *  c_q_EL_FLE_) -  0.55) *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + ((((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (((((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) - ( 0.7 *  s_q_EL_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_));
    (*this)(3,3) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(3,4) = ((((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(3,5) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(4,0) = ((((((((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + (((( 0.1 *  s_q_EL_ROT_) *  s_q_SH_ROT_) + (((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  s_q_EL_ROT_)) *  s_q_SH_ROT_)) + (((((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((((((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) + ( 0.7 *  s_q_EL_FLE_)) *  s_q_SH_ROT_) + ((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + ((((((((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + (((- 0.7 *  c_q_EL_FLE_) -  0.55) *  c_q_EL_ROT_)) *  s_q_SH_ROT_) + ((((((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_EL_ROT_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) - (( 0.1 *  c_q_EL_ROT_) *  s_q_SH_ROT_)) + (((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(4,1) = ((((((((((((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) - ( 0.7 *  s_q_EL_FLE_)) *  s_q_SH_ROT_) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  c_q_EL_ROT_)) *  s_q_SH_ROT_) + (((((((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (( 0.1 *  c_q_EL_ROT_) *  s_q_SH_ROT_)) + ((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + (((( 0.1 *  s_q_EL_ROT_) *  s_q_SH_ROT_) + (((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  s_q_EL_ROT_)) *  s_q_SH_ROT_)) + (((((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(4,2) = (((((((((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + (((- 0.7 *  c_q_EL_FLE_) -  0.55) *  c_q_EL_ROT_)) *  s_q_SH_ROT_) + ((((((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_EL_ROT_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) - ( 0.7 *  s_q_EL_FLE_)) *  s_q_SH_ROT_) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_));
    (*this)(4,3) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(4,4) = ((((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((( s_q_EL_ROT_ *  s_q_SH_ROT_) + (((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(4,5) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(5,0) = ((((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_EL_ROT_)) *  s_q_SH_FLE_)) + ((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + ((((((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + ((((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_)) + (((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(5,1) = (((((((((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_EL_ROT_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_)) + ((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + (((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_EL_ROT_)) *  s_q_SH_FLE_)) + ((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(5,2) = (((((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + ((((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_));
    (*this)(5,3) = ((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + ((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(5,4) = ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(5,5) = ((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_));
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2::Type_fr_WR_ROT_X_fr_WRIST_2()
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
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,1) = - s_q_WR_ROT_;
    (*this)(1,0) =  s_q_WR_ROT_;
    (*this)(1,1) =  c_q_WR_ROT_;
    (*this)(3,3) =  c_q_WR_ROT_;
    (*this)(3,4) = - s_q_WR_ROT_;
    (*this)(4,3) =  s_q_WR_ROT_;
    (*this)(4,4) =  c_q_WR_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world::Type_fr_SHOULDER_X_fr_world()
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
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) =  s_q_SH_ROT_;
    (*this)(1,0) = - s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    (*this)(3,0) = (- 1.28 *  s_q_SH_ROT_);
    (*this)(3,1) = ( 1.28 *  c_q_SH_ROT_);
    (*this)(3,3) =  c_q_SH_ROT_;
    (*this)(3,4) =  s_q_SH_ROT_;
    (*this)(4,0) = (- 1.28 *  c_q_SH_ROT_);
    (*this)(4,1) = (- 1.28 *  s_q_SH_ROT_);
    (*this)(4,3) = - s_q_SH_ROT_;
    (*this)(4,4) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER::Type_fr_world_X_fr_SHOULDER()
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
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) = - s_q_SH_ROT_;
    (*this)(1,0) =  s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    (*this)(3,0) = (- 1.28 *  s_q_SH_ROT_);
    (*this)(3,1) = (- 1.28 *  c_q_SH_ROT_);
    (*this)(3,3) =  c_q_SH_ROT_;
    (*this)(3,4) = - s_q_SH_ROT_;
    (*this)(4,0) = ( 1.28 *  c_q_SH_ROT_);
    (*this)(4,1) = (- 1.28 *  s_q_SH_ROT_);
    (*this)(4,3) =  s_q_SH_ROT_;
    (*this)(4,4) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER::Type_fr_ARM_X_fr_SHOULDER()
{
    (*this)(0,0) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = - 1;
    (*this)(2,1) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = - 1;
    (*this)(5,4) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_FLE_;
    Scalar c_q_SH_FLE_;
    
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    
    (*this)(0,1) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(0,2) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(1,1) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(1,2) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    (*this)(3,4) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(3,5) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(4,4) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(4,5) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM::Type_fr_SHOULDER_X_fr_ARM()
{
    (*this)(0,0) = 0;
    (*this)(0,1) = 0;
    (*this)(0,2) = - 1;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 0;
    (*this)(3,4) = 0;
    (*this)(3,5) = - 1;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM::update(const JState& q) {
    Scalar s_q_SH_FLE_;
    Scalar c_q_SH_FLE_;
    
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    
    (*this)(1,0) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(1,1) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(2,0) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(2,1) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    (*this)(4,3) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(4,4) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(5,3) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(5,4) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM::Type_fr_ELBOW_X_fr_ARM()
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
    (*this)(5,0) = 0;
    (*this)(5,1) = - 0.7;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar c_q_EL_FLE_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    
    (*this)(0,0) =  c_q_EL_FLE_;
    (*this)(0,1) =  s_q_EL_FLE_;
    (*this)(1,0) = - s_q_EL_FLE_;
    (*this)(1,1) =  c_q_EL_FLE_;
    (*this)(3,0) = (- 0.04 *  s_q_EL_FLE_);
    (*this)(3,1) = ( 0.04 *  c_q_EL_FLE_);
    (*this)(3,2) = ( 0.7 *  s_q_EL_FLE_);
    (*this)(3,3) =  c_q_EL_FLE_;
    (*this)(3,4) =  s_q_EL_FLE_;
    (*this)(4,0) = (- 0.04 *  c_q_EL_FLE_);
    (*this)(4,1) = (- 0.04 *  s_q_EL_FLE_);
    (*this)(4,2) = ( 0.7 *  c_q_EL_FLE_);
    (*this)(4,3) = - s_q_EL_FLE_;
    (*this)(4,4) =  c_q_EL_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW::Type_fr_ARM_X_fr_ELBOW()
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
    (*this)(4,2) = - 0.7;
    (*this)(4,5) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar c_q_EL_FLE_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    
    (*this)(0,0) =  c_q_EL_FLE_;
    (*this)(0,1) = - s_q_EL_FLE_;
    (*this)(1,0) =  s_q_EL_FLE_;
    (*this)(1,1) =  c_q_EL_FLE_;
    (*this)(3,0) = (- 0.04 *  s_q_EL_FLE_);
    (*this)(3,1) = (- 0.04 *  c_q_EL_FLE_);
    (*this)(3,3) =  c_q_EL_FLE_;
    (*this)(3,4) = - s_q_EL_FLE_;
    (*this)(4,0) = ( 0.04 *  c_q_EL_FLE_);
    (*this)(4,1) = (- 0.04 *  s_q_EL_FLE_);
    (*this)(4,3) =  s_q_EL_FLE_;
    (*this)(4,4) =  c_q_EL_FLE_;
    (*this)(5,0) = ( 0.7 *  s_q_EL_FLE_);
    (*this)(5,1) = ( 0.7 *  c_q_EL_FLE_);
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW::Type_fr_FOREARM_X_fr_ELBOW()
{
    (*this)(0,0) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 1;
    (*this)(2,1) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 1;
    (*this)(5,4) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW::update(const JState& q) {
    Scalar s_q_EL_ROT_;
    Scalar c_q_EL_ROT_;
    
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    
    (*this)(0,1) =  c_q_EL_ROT_;
    (*this)(0,2) =  s_q_EL_ROT_;
    (*this)(1,1) = - s_q_EL_ROT_;
    (*this)(1,2) =  c_q_EL_ROT_;
    (*this)(3,4) =  c_q_EL_ROT_;
    (*this)(3,5) =  s_q_EL_ROT_;
    (*this)(4,4) = - s_q_EL_ROT_;
    (*this)(4,5) =  c_q_EL_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM::Type_fr_ELBOW_X_fr_FOREARM()
{
    (*this)(0,0) = 0;
    (*this)(0,1) = 0;
    (*this)(0,2) = 1;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 0;
    (*this)(3,4) = 0;
    (*this)(3,5) = 1;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM::update(const JState& q) {
    Scalar s_q_EL_ROT_;
    Scalar c_q_EL_ROT_;
    
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    
    (*this)(1,0) =  c_q_EL_ROT_;
    (*this)(1,1) = - s_q_EL_ROT_;
    (*this)(2,0) =  s_q_EL_ROT_;
    (*this)(2,1) =  c_q_EL_ROT_;
    (*this)(4,3) =  c_q_EL_ROT_;
    (*this)(4,4) = - s_q_EL_ROT_;
    (*this)(5,3) =  s_q_EL_ROT_;
    (*this)(5,4) =  c_q_EL_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM::Type_fr_WRIST_1_X_fr_FOREARM()
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
    (*this)(5,0) = - 0.55;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM::update(const JState& q) {
    Scalar s_q_WR_FLE_;
    Scalar c_q_WR_FLE_;
    
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    
    (*this)(0,0) =  c_q_WR_FLE_;
    (*this)(0,2) = - s_q_WR_FLE_;
    (*this)(1,0) = - s_q_WR_FLE_;
    (*this)(1,2) = - c_q_WR_FLE_;
    (*this)(3,1) = ( 0.55 *  c_q_WR_FLE_);
    (*this)(3,3) =  c_q_WR_FLE_;
    (*this)(3,5) = - s_q_WR_FLE_;
    (*this)(4,1) = (- 0.55 *  s_q_WR_FLE_);
    (*this)(4,3) = - s_q_WR_FLE_;
    (*this)(4,5) = - c_q_WR_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1::Type_fr_FOREARM_X_fr_WRIST_1()
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
    (*this)(3,2) = - 0.55;
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
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1::update(const JState& q) {
    Scalar s_q_WR_FLE_;
    Scalar c_q_WR_FLE_;
    
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    
    (*this)(0,0) =  c_q_WR_FLE_;
    (*this)(0,1) = - s_q_WR_FLE_;
    (*this)(2,0) = - s_q_WR_FLE_;
    (*this)(2,1) = - c_q_WR_FLE_;
    (*this)(3,3) =  c_q_WR_FLE_;
    (*this)(3,4) = - s_q_WR_FLE_;
    (*this)(4,0) = ( 0.55 *  c_q_WR_FLE_);
    (*this)(4,1) = (- 0.55 *  s_q_WR_FLE_);
    (*this)(5,3) = - s_q_WR_FLE_;
    (*this)(5,4) = - c_q_WR_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1::Type_fr_WRIST_2_X_fr_WRIST_1()
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
    (*this)(2,1) = - 1;
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
    (*this)(5,4) = - 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,2) =  s_q_WR_ROT_;
    (*this)(1,0) = - s_q_WR_ROT_;
    (*this)(1,2) =  c_q_WR_ROT_;
    (*this)(3,0) = (- 0.1 *  s_q_WR_ROT_);
    (*this)(3,2) = ( 0.1 *  c_q_WR_ROT_);
    (*this)(3,3) =  c_q_WR_ROT_;
    (*this)(3,5) =  s_q_WR_ROT_;
    (*this)(4,0) = (- 0.1 *  c_q_WR_ROT_);
    (*this)(4,2) = (- 0.1 *  s_q_WR_ROT_);
    (*this)(4,3) = - s_q_WR_ROT_;
    (*this)(4,5) =  c_q_WR_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2::Type_fr_WRIST_1_X_fr_WRIST_2()
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
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = - 1;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2& iit::mabi::tpl::MotionTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,1) = - s_q_WR_ROT_;
    (*this)(2,0) =  s_q_WR_ROT_;
    (*this)(2,1) =  c_q_WR_ROT_;
    (*this)(3,0) = (- 0.1 *  s_q_WR_ROT_);
    (*this)(3,1) = (- 0.1 *  c_q_WR_ROT_);
    (*this)(3,3) =  c_q_WR_ROT_;
    (*this)(3,4) = - s_q_WR_ROT_;
    (*this)(5,0) = ( 0.1 *  c_q_WR_ROT_);
    (*this)(5,1) = (- 0.1 *  s_q_WR_ROT_);
    (*this)(5,3) =  s_q_WR_ROT_;
    (*this)(5,4) =  c_q_WR_ROT_;
    return *this;
}

template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER::Type_fr_arm_mount_X_fr_SHOULDER()
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) = - s_q_SH_ROT_;
    (*this)(0,3) = (- 0.189 *  s_q_SH_ROT_);
    (*this)(0,4) = (- 0.189 *  c_q_SH_ROT_);
    (*this)(1,0) =  s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    (*this)(1,3) = ( 0.189 *  c_q_SH_ROT_);
    (*this)(1,4) = (- 0.189 *  s_q_SH_ROT_);
    (*this)(3,3) =  c_q_SH_ROT_;
    (*this)(3,4) = - s_q_SH_ROT_;
    (*this)(4,3) =  s_q_SH_ROT_;
    (*this)(4,4) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2::Type_fr_arm_mount_X_fr_WRIST_2()
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar s_q_EL_ROT_;
    Scalar s_q_SH_FLE_;
    Scalar s_q_SH_ROT_;
    Scalar s_q_WR_ROT_;
    Scalar s_q_WR_FLE_;
    Scalar c_q_EL_FLE_;
    Scalar c_q_SH_FLE_;
    Scalar c_q_EL_ROT_;
    Scalar c_q_SH_ROT_;
    Scalar c_q_WR_FLE_;
    Scalar c_q_WR_ROT_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(0,1) = ((((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(0,2) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(0,3) = ((((((((((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (( 0.1 *  s_q_EL_ROT_) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  c_q_EL_ROT_)) *  s_q_SH_ROT_)) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (((((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) + ( 0.7 *  s_q_EL_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((((((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  s_q_EL_ROT_)) *  s_q_SH_ROT_) + ((((((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + (((- 0.7 *  c_q_EL_FLE_) -  0.55) *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + ((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_)) - (( 0.1 *  c_q_EL_ROT_) *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(0,4) = (((((((((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (((((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) - ( 0.7 *  s_q_EL_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + ((((((((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_EL_ROT_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  s_q_EL_ROT_)) *  s_q_SH_ROT_) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_)) + (( 0.1 *  c_q_EL_ROT_) *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (( 0.1 *  s_q_EL_ROT_) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  c_q_EL_ROT_)) *  s_q_SH_ROT_)) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(0,5) = ((((((((((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  s_q_EL_ROT_)) *  s_q_SH_ROT_) + ((((((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + (((- 0.7 *  c_q_EL_FLE_) -  0.55) *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + ((((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + (((((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) - ( 0.7 *  s_q_EL_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_));
    (*this)(1,0) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(1,1) = ((((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((( s_q_EL_ROT_ *  s_q_SH_ROT_) + (((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(1,2) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(1,3) = ((((((((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + (((( 0.1 *  s_q_EL_ROT_) *  s_q_SH_ROT_) + (((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  s_q_EL_ROT_)) *  s_q_SH_ROT_)) + (((((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((((((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) + ( 0.7 *  s_q_EL_FLE_)) *  s_q_SH_ROT_) + ((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + ((((((((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + (((- 0.7 *  c_q_EL_FLE_) -  0.55) *  c_q_EL_ROT_)) *  s_q_SH_ROT_) + ((((((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_EL_ROT_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) - (( 0.1 *  c_q_EL_ROT_) *  s_q_SH_ROT_)) + (((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(1,4) = ((((((((((((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) - ( 0.7 *  s_q_EL_FLE_)) *  s_q_SH_ROT_) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  c_q_EL_ROT_)) *  s_q_SH_ROT_) + (((((((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) + ( 0.189 *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (( 0.1 *  c_q_EL_ROT_) *  s_q_SH_ROT_)) + ((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + (((( 0.1 *  s_q_EL_ROT_) *  s_q_SH_ROT_) + (((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) + (((((((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.92707E-7 *  c_q_EL_FLE_) - ( 0.188999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) + ((( 0.7 *  c_q_EL_FLE_) +  0.55) *  s_q_EL_ROT_)) *  s_q_SH_ROT_)) + (((((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  c_q_EL_ROT_)) *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(1,5) = (((((((((( 1.92707E-7 *  s_q_EL_FLE_) + ( 0.188999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) + (((- 0.7 *  c_q_EL_FLE_) -  0.55) *  c_q_EL_ROT_)) *  s_q_SH_ROT_) + ((((((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_EL_ROT_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) - ( 0.189 *  s_q_EL_ROT_)) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((((( 0.188999 *  s_q_EL_FLE_) - ( 1.92707E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.92707E-7 *  s_q_EL_FLE_) - ( 0.188999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) - ( 0.7 *  s_q_EL_FLE_)) *  s_q_SH_ROT_) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_));
    (*this)(2,0) = ((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + ((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(2,1) = ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(2,2) = ((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_));
    (*this)(2,3) = ((((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_EL_ROT_)) *  s_q_SH_FLE_)) + ((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + ((((((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + ((((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_)) + (((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(2,4) = (((((((((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_EL_ROT_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + ((((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_)) + ((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + (((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + (((((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_EL_ROT_)) *  s_q_SH_FLE_)) + ((((( 4.07846E-8 *  c_q_EL_FLE_) - ( 0.0399999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(2,5) = (((((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_EL_ROT_) + ((( 4.07846E-8 *  s_q_EL_FLE_) + ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  s_q_SH_FLE_) + (((((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  s_q_EL_ROT_) + ((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  c_q_EL_ROT_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + ((((( 0.0399999 *  s_q_EL_FLE_) - ( 4.07846E-8 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 4.07846E-8 *  s_q_EL_FLE_) - ( 0.0399999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_));
    (*this)(3,3) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(3,4) = ((((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(3,5) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(4,3) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(4,4) = ((((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((( s_q_EL_ROT_ *  s_q_SH_ROT_) + (((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(4,5) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(5,3) = ((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + ((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(5,4) = ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(5,5) = ((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_));
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2::Type_fr_WR_ROT_X_fr_WRIST_2()
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,1) = - s_q_WR_ROT_;
    (*this)(1,0) =  s_q_WR_ROT_;
    (*this)(1,1) =  c_q_WR_ROT_;
    (*this)(3,3) =  c_q_WR_ROT_;
    (*this)(3,4) = - s_q_WR_ROT_;
    (*this)(4,3) =  s_q_WR_ROT_;
    (*this)(4,4) =  c_q_WR_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world::Type_fr_SHOULDER_X_fr_world()
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) =  s_q_SH_ROT_;
    (*this)(0,3) = (- 1.28 *  s_q_SH_ROT_);
    (*this)(0,4) = ( 1.28 *  c_q_SH_ROT_);
    (*this)(1,0) = - s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    (*this)(1,3) = (- 1.28 *  c_q_SH_ROT_);
    (*this)(1,4) = (- 1.28 *  s_q_SH_ROT_);
    (*this)(3,3) =  c_q_SH_ROT_;
    (*this)(3,4) =  s_q_SH_ROT_;
    (*this)(4,3) = - s_q_SH_ROT_;
    (*this)(4,4) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER::Type_fr_world_X_fr_SHOULDER()
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) = - s_q_SH_ROT_;
    (*this)(0,3) = (- 1.28 *  s_q_SH_ROT_);
    (*this)(0,4) = (- 1.28 *  c_q_SH_ROT_);
    (*this)(1,0) =  s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    (*this)(1,3) = ( 1.28 *  c_q_SH_ROT_);
    (*this)(1,4) = (- 1.28 *  s_q_SH_ROT_);
    (*this)(3,3) =  c_q_SH_ROT_;
    (*this)(3,4) = - s_q_SH_ROT_;
    (*this)(4,3) =  s_q_SH_ROT_;
    (*this)(4,4) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER::Type_fr_ARM_X_fr_SHOULDER()
{
    (*this)(0,0) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = - 1;
    (*this)(2,1) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = - 1;
    (*this)(5,4) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_FLE_;
    Scalar c_q_SH_FLE_;
    
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    
    (*this)(0,1) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(0,2) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(1,1) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(1,2) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    (*this)(3,4) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(3,5) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(4,4) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(4,5) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM::Type_fr_SHOULDER_X_fr_ARM()
{
    (*this)(0,0) = 0;
    (*this)(0,1) = 0;
    (*this)(0,2) = - 1;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 0;
    (*this)(3,4) = 0;
    (*this)(3,5) = - 1;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM::update(const JState& q) {
    Scalar s_q_SH_FLE_;
    Scalar c_q_SH_FLE_;
    
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    
    (*this)(1,0) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(1,1) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(2,0) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(2,1) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    (*this)(4,3) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(4,4) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(5,3) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(5,4) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM::Type_fr_ELBOW_X_fr_ARM()
{
    (*this)(0,2) = 0;
    (*this)(1,2) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0;
    (*this)(2,4) = - 0.7;
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar c_q_EL_FLE_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    
    (*this)(0,0) =  c_q_EL_FLE_;
    (*this)(0,1) =  s_q_EL_FLE_;
    (*this)(0,3) = (- 0.04 *  s_q_EL_FLE_);
    (*this)(0,4) = ( 0.04 *  c_q_EL_FLE_);
    (*this)(0,5) = ( 0.7 *  s_q_EL_FLE_);
    (*this)(1,0) = - s_q_EL_FLE_;
    (*this)(1,1) =  c_q_EL_FLE_;
    (*this)(1,3) = (- 0.04 *  c_q_EL_FLE_);
    (*this)(1,4) = (- 0.04 *  s_q_EL_FLE_);
    (*this)(1,5) = ( 0.7 *  c_q_EL_FLE_);
    (*this)(3,3) =  c_q_EL_FLE_;
    (*this)(3,4) =  s_q_EL_FLE_;
    (*this)(4,3) = - s_q_EL_FLE_;
    (*this)(4,4) =  c_q_EL_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW::Type_fr_ARM_X_fr_ELBOW()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,5) = - 0.7;
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar c_q_EL_FLE_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    
    (*this)(0,0) =  c_q_EL_FLE_;
    (*this)(0,1) = - s_q_EL_FLE_;
    (*this)(0,3) = (- 0.04 *  s_q_EL_FLE_);
    (*this)(0,4) = (- 0.04 *  c_q_EL_FLE_);
    (*this)(1,0) =  s_q_EL_FLE_;
    (*this)(1,1) =  c_q_EL_FLE_;
    (*this)(1,3) = ( 0.04 *  c_q_EL_FLE_);
    (*this)(1,4) = (- 0.04 *  s_q_EL_FLE_);
    (*this)(2,3) = ( 0.7 *  s_q_EL_FLE_);
    (*this)(2,4) = ( 0.7 *  c_q_EL_FLE_);
    (*this)(3,3) =  c_q_EL_FLE_;
    (*this)(3,4) = - s_q_EL_FLE_;
    (*this)(4,3) =  s_q_EL_FLE_;
    (*this)(4,4) =  c_q_EL_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW::Type_fr_FOREARM_X_fr_ELBOW()
{
    (*this)(0,0) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 1;
    (*this)(2,1) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 1;
    (*this)(5,4) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW::update(const JState& q) {
    Scalar s_q_EL_ROT_;
    Scalar c_q_EL_ROT_;
    
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    
    (*this)(0,1) =  c_q_EL_ROT_;
    (*this)(0,2) =  s_q_EL_ROT_;
    (*this)(1,1) = - s_q_EL_ROT_;
    (*this)(1,2) =  c_q_EL_ROT_;
    (*this)(3,4) =  c_q_EL_ROT_;
    (*this)(3,5) =  s_q_EL_ROT_;
    (*this)(4,4) = - s_q_EL_ROT_;
    (*this)(4,5) =  c_q_EL_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM::Type_fr_ELBOW_X_fr_FOREARM()
{
    (*this)(0,0) = 0;
    (*this)(0,1) = 0;
    (*this)(0,2) = 1;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 0;
    (*this)(3,4) = 0;
    (*this)(3,5) = 1;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM::update(const JState& q) {
    Scalar s_q_EL_ROT_;
    Scalar c_q_EL_ROT_;
    
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    
    (*this)(1,0) =  c_q_EL_ROT_;
    (*this)(1,1) = - s_q_EL_ROT_;
    (*this)(2,0) =  s_q_EL_ROT_;
    (*this)(2,1) =  c_q_EL_ROT_;
    (*this)(4,3) =  c_q_EL_ROT_;
    (*this)(4,4) = - s_q_EL_ROT_;
    (*this)(5,3) =  s_q_EL_ROT_;
    (*this)(5,4) =  c_q_EL_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM::Type_fr_WRIST_1_X_fr_FOREARM()
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
    (*this)(2,3) = - 0.55;
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM::update(const JState& q) {
    Scalar s_q_WR_FLE_;
    Scalar c_q_WR_FLE_;
    
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    
    (*this)(0,0) =  c_q_WR_FLE_;
    (*this)(0,2) = - s_q_WR_FLE_;
    (*this)(0,4) = ( 0.55 *  c_q_WR_FLE_);
    (*this)(1,0) = - s_q_WR_FLE_;
    (*this)(1,2) = - c_q_WR_FLE_;
    (*this)(1,4) = (- 0.55 *  s_q_WR_FLE_);
    (*this)(3,3) =  c_q_WR_FLE_;
    (*this)(3,5) = - s_q_WR_FLE_;
    (*this)(4,3) = - s_q_WR_FLE_;
    (*this)(4,5) = - c_q_WR_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1::Type_fr_FOREARM_X_fr_WRIST_1()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = - 0.55;
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
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1::update(const JState& q) {
    Scalar s_q_WR_FLE_;
    Scalar c_q_WR_FLE_;
    
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    
    (*this)(0,0) =  c_q_WR_FLE_;
    (*this)(0,1) = - s_q_WR_FLE_;
    (*this)(1,3) = ( 0.55 *  c_q_WR_FLE_);
    (*this)(1,4) = (- 0.55 *  s_q_WR_FLE_);
    (*this)(2,0) = - s_q_WR_FLE_;
    (*this)(2,1) = - c_q_WR_FLE_;
    (*this)(3,3) =  c_q_WR_FLE_;
    (*this)(3,4) = - s_q_WR_FLE_;
    (*this)(5,3) = - s_q_WR_FLE_;
    (*this)(5,4) = - c_q_WR_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1::Type_fr_WRIST_2_X_fr_WRIST_1()
{
    (*this)(0,1) = 0;
    (*this)(0,4) = 0;
    (*this)(1,1) = 0;
    (*this)(1,4) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
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
    (*this)(5,4) = - 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,2) =  s_q_WR_ROT_;
    (*this)(0,3) = (- 0.1 *  s_q_WR_ROT_);
    (*this)(0,5) = ( 0.1 *  c_q_WR_ROT_);
    (*this)(1,0) = - s_q_WR_ROT_;
    (*this)(1,2) =  c_q_WR_ROT_;
    (*this)(1,3) = (- 0.1 *  c_q_WR_ROT_);
    (*this)(1,5) = (- 0.1 *  s_q_WR_ROT_);
    (*this)(3,3) =  c_q_WR_ROT_;
    (*this)(3,5) =  s_q_WR_ROT_;
    (*this)(4,3) = - s_q_WR_ROT_;
    (*this)(4,5) =  c_q_WR_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2::Type_fr_WRIST_1_X_fr_WRIST_2()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1;
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
    (*this)(4,5) = - 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2& iit::mabi::tpl::ForceTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,1) = - s_q_WR_ROT_;
    (*this)(0,3) = (- 0.1 *  s_q_WR_ROT_);
    (*this)(0,4) = (- 0.1 *  c_q_WR_ROT_);
    (*this)(2,0) =  s_q_WR_ROT_;
    (*this)(2,1) =  c_q_WR_ROT_;
    (*this)(2,3) = ( 0.1 *  c_q_WR_ROT_);
    (*this)(2,4) = (- 0.1 *  s_q_WR_ROT_);
    (*this)(3,3) =  c_q_WR_ROT_;
    (*this)(3,4) = - s_q_WR_ROT_;
    (*this)(5,3) =  s_q_WR_ROT_;
    (*this)(5,4) =  c_q_WR_ROT_;
    return *this;
}

template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER::Type_fr_arm_mount_X_fr_SHOULDER()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.189;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_arm_mount_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) = - s_q_SH_ROT_;
    (*this)(1,0) =  s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2::Type_fr_arm_mount_X_fr_WRIST_2()
{
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_arm_mount_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar s_q_EL_ROT_;
    Scalar s_q_SH_FLE_;
    Scalar s_q_SH_ROT_;
    Scalar s_q_WR_ROT_;
    Scalar s_q_WR_FLE_;
    Scalar c_q_EL_FLE_;
    Scalar c_q_SH_FLE_;
    Scalar c_q_EL_ROT_;
    Scalar c_q_SH_ROT_;
    Scalar c_q_WR_FLE_;
    Scalar c_q_WR_ROT_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(0,1) = ((((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) + ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( c_q_EL_ROT_ *  c_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(0,2) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - ( s_q_EL_ROT_ *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(0,3) = ((((((((((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) - (( 0.1 *  s_q_EL_ROT_) *  c_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_SH_ROT_) *  c_q_WR_FLE_)) + (((((( 0.549999 *  s_q_EL_FLE_) - ( 5.60788E-7 *  c_q_EL_FLE_)) -  7.1373E-7) *  s_q_SH_FLE_) + ((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  c_q_SH_FLE_)) *  s_q_SH_ROT_)) - ( 0.04 *  c_q_SH_ROT_));
    (*this)(1,0) = ((((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_ROT_) + (((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + (((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(1,1) = ((((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  s_q_WR_FLE_) + ((( s_q_EL_ROT_ *  s_q_SH_ROT_) + (((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( c_q_EL_ROT_ *  s_q_SH_ROT_)) *  c_q_WR_ROT_));
    (*this)(1,2) = (((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - ( s_q_EL_ROT_ *  s_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  c_q_WR_FLE_));
    (*this)(1,3) = (((((((((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) - (( 0.1 *  s_q_EL_ROT_) *  s_q_SH_ROT_)) *  s_q_WR_FLE_) + (((((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  s_q_EL_FLE_) + ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_SH_ROT_) *  c_q_WR_FLE_)) - ( 0.04 *  s_q_SH_ROT_)) + ((((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  s_q_SH_FLE_) + (((( 5.60788E-7 *  s_q_EL_FLE_) + ( 0.549999 *  c_q_EL_FLE_)) +  0.699999) *  c_q_SH_FLE_)) *  c_q_SH_ROT_));
    (*this)(2,0) = ((((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_ROT_) + ((((((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  c_q_WR_ROT_));
    (*this)(2,1) = ((((((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) *  s_q_WR_ROT_) + (((((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  s_q_EL_ROT_) *  s_q_SH_FLE_) + (((( 1.01961E-6 *  s_q_EL_FLE_) + ( 0.999999 *  c_q_EL_FLE_)) *  s_q_EL_ROT_) *  c_q_SH_FLE_)) *  c_q_WR_ROT_));
    (*this)(2,2) = ((((((( 0.999999 *  s_q_EL_FLE_) - ( 1.01961E-6 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((- 1.01961E-6 *  s_q_EL_FLE_) - ( 0.999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-6 *  c_q_EL_FLE_) - ( 0.999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_));
    (*this)(2,3) = (((((((((( 0.0999999 *  s_q_EL_FLE_) - ( 1.01961E-7 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  s_q_SH_FLE_) + ((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  c_q_EL_ROT_) *  c_q_SH_FLE_)) *  s_q_WR_FLE_) + (((((- 1.01961E-7 *  s_q_EL_FLE_) - ( 0.0999999 *  c_q_EL_FLE_)) *  s_q_SH_FLE_) + ((( 1.01961E-7 *  c_q_EL_FLE_) - ( 0.0999999 *  s_q_EL_FLE_)) *  c_q_SH_FLE_)) *  c_q_WR_FLE_)) + ((((- 5.60788E-7 *  s_q_EL_FLE_) - ( 0.549999 *  c_q_EL_FLE_)) -  0.699999) *  s_q_SH_FLE_)) + ((((- 0.549999 *  s_q_EL_FLE_) + ( 5.60788E-7 *  c_q_EL_FLE_)) +  7.1373E-7) *  c_q_SH_FLE_)) +  0.189);
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2::Type_fr_WR_ROT_X_fr_WRIST_2()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
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
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WR_ROT_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,1) = - s_q_WR_ROT_;
    (*this)(1,0) =  s_q_WR_ROT_;
    (*this)(1,1) =  c_q_WR_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world::Type_fr_SHOULDER_X_fr_world()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = - 1.28;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_world::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) =  s_q_SH_ROT_;
    (*this)(1,0) = - s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER::Type_fr_world_X_fr_SHOULDER()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 1.28;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_world_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_ROT_;
    Scalar c_q_SH_ROT_;
    
    s_q_SH_ROT_ = TRAIT::sin( q(SH_ROT));
    c_q_SH_ROT_ = TRAIT::cos( q(SH_ROT));
    
    (*this)(0,0) =  c_q_SH_ROT_;
    (*this)(0,1) = - s_q_SH_ROT_;
    (*this)(1,0) =  s_q_SH_ROT_;
    (*this)(1,1) =  c_q_SH_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER::Type_fr_ARM_X_fr_SHOULDER()
{
    (*this)(0,0) = 0;
    (*this)(0,3) = 0;
    (*this)(1,0) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = - 1;
    (*this)(2,1) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ARM_X_fr_SHOULDER::update(const JState& q) {
    Scalar s_q_SH_FLE_;
    Scalar c_q_SH_FLE_;
    
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    
    (*this)(0,1) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(0,2) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(1,1) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(1,2) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM::Type_fr_SHOULDER_X_fr_ARM()
{
    (*this)(0,0) = 0;
    (*this)(0,1) = 0;
    (*this)(0,2) = - 1;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_SHOULDER_X_fr_ARM::update(const JState& q) {
    Scalar s_q_SH_FLE_;
    Scalar c_q_SH_FLE_;
    
    s_q_SH_FLE_ = TRAIT::sin( q(SH_FLE));
    c_q_SH_FLE_ = TRAIT::cos( q(SH_FLE));
    
    (*this)(1,0) = (( 1.01961E-6 *  s_q_SH_FLE_) + ( 0.999999 *  c_q_SH_FLE_));
    (*this)(1,1) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(2,0) = (( 1.01961E-6 *  c_q_SH_FLE_) - ( 0.999999 *  s_q_SH_FLE_));
    (*this)(2,1) = ((- 1.01961E-6 *  s_q_SH_FLE_) - ( 0.999999 *  c_q_SH_FLE_));
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM::Type_fr_ELBOW_X_fr_ARM()
{
    (*this)(0,2) = 0;
    (*this)(1,2) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = - 0.04;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ELBOW_X_fr_ARM::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar c_q_EL_FLE_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    
    (*this)(0,0) =  c_q_EL_FLE_;
    (*this)(0,1) =  s_q_EL_FLE_;
    (*this)(0,3) = (- 0.7 *  c_q_EL_FLE_);
    (*this)(1,0) = - s_q_EL_FLE_;
    (*this)(1,1) =  c_q_EL_FLE_;
    (*this)(1,3) = ( 0.7 *  s_q_EL_FLE_);
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW::Type_fr_ARM_X_fr_ELBOW()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0.7;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0.04;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ARM_X_fr_ELBOW::update(const JState& q) {
    Scalar s_q_EL_FLE_;
    Scalar c_q_EL_FLE_;
    
    s_q_EL_FLE_ = TRAIT::sin( q(EL_FLE));
    c_q_EL_FLE_ = TRAIT::cos( q(EL_FLE));
    
    (*this)(0,0) =  c_q_EL_FLE_;
    (*this)(0,1) = - s_q_EL_FLE_;
    (*this)(1,0) =  s_q_EL_FLE_;
    (*this)(1,1) =  c_q_EL_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW::Type_fr_FOREARM_X_fr_ELBOW()
{
    (*this)(0,0) = 0;
    (*this)(0,3) = 0;
    (*this)(1,0) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 1;
    (*this)(2,1) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FOREARM_X_fr_ELBOW::update(const JState& q) {
    Scalar s_q_EL_ROT_;
    Scalar c_q_EL_ROT_;
    
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    
    (*this)(0,1) =  c_q_EL_ROT_;
    (*this)(0,2) =  s_q_EL_ROT_;
    (*this)(1,1) = - s_q_EL_ROT_;
    (*this)(1,2) =  c_q_EL_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM::Type_fr_ELBOW_X_fr_FOREARM()
{
    (*this)(0,0) = 0;
    (*this)(0,1) = 0;
    (*this)(0,2) = 1;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_ELBOW_X_fr_FOREARM::update(const JState& q) {
    Scalar s_q_EL_ROT_;
    Scalar c_q_EL_ROT_;
    
    s_q_EL_ROT_ = TRAIT::sin( q(EL_ROT));
    c_q_EL_ROT_ = TRAIT::cos( q(EL_ROT));
    
    (*this)(1,0) =  c_q_EL_ROT_;
    (*this)(1,1) = - s_q_EL_ROT_;
    (*this)(2,0) =  s_q_EL_ROT_;
    (*this)(2,1) =  c_q_EL_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM::Type_fr_WRIST_1_X_fr_FOREARM()
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
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_FOREARM::update(const JState& q) {
    Scalar s_q_WR_FLE_;
    Scalar c_q_WR_FLE_;
    
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    
    (*this)(0,0) =  c_q_WR_FLE_;
    (*this)(0,2) = - s_q_WR_FLE_;
    (*this)(0,3) = ( 0.55 *  s_q_WR_FLE_);
    (*this)(1,0) = - s_q_WR_FLE_;
    (*this)(1,2) = - c_q_WR_FLE_;
    (*this)(1,3) = ( 0.55 *  c_q_WR_FLE_);
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1::Type_fr_FOREARM_X_fr_WRIST_1()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,3) = 0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0.55;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FOREARM_X_fr_WRIST_1::update(const JState& q) {
    Scalar s_q_WR_FLE_;
    Scalar c_q_WR_FLE_;
    
    s_q_WR_FLE_ = TRAIT::sin( q(WR_FLE));
    c_q_WR_FLE_ = TRAIT::cos( q(WR_FLE));
    
    (*this)(0,0) =  c_q_WR_FLE_;
    (*this)(0,1) = - s_q_WR_FLE_;
    (*this)(2,0) = - s_q_WR_FLE_;
    (*this)(2,1) = - c_q_WR_FLE_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1::Type_fr_WRIST_2_X_fr_WRIST_1()
{
    (*this)(0,1) = 0;
    (*this)(0,3) = 0;
    (*this)(1,1) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = - 0.1;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_2_X_fr_WRIST_1::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,2) =  s_q_WR_ROT_;
    (*this)(1,0) = - s_q_WR_ROT_;
    (*this)(1,2) =  c_q_WR_ROT_;
    return *this;
}
template <typename TRAIT>
iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2::Type_fr_WRIST_1_X_fr_WRIST_2()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1.0;
    (*this)(1,3) = - 0.1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2& iit::mabi::tpl::HomogeneousTransforms<TRAIT>::Type_fr_WRIST_1_X_fr_WRIST_2::update(const JState& q) {
    Scalar s_q_WR_ROT_;
    Scalar c_q_WR_ROT_;
    
    s_q_WR_ROT_ = TRAIT::sin( q(WR_ROT));
    c_q_WR_ROT_ = TRAIT::cos( q(WR_ROT));
    
    (*this)(0,0) =  c_q_WR_ROT_;
    (*this)(0,1) = - s_q_WR_ROT_;
    (*this)(2,0) =  s_q_WR_ROT_;
    (*this)(2,1) =  c_q_WR_ROT_;
    return *this;
}

