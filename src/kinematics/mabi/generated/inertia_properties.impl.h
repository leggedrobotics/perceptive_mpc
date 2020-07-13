template <typename TRAIT>
iit::mabi::dyn::tpl::InertiaProperties<TRAIT>::InertiaProperties()
{
    com_SHOULDER = iit::rbd::Vector3d(-0.04792482,0.0,-0.002274739).cast<Scalar>();
    tensor_SHOULDER.fill(
        Scalar(7.6494994),
        com_SHOULDER,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.03003958),
                Scalar(0.0773548),
                Scalar(0.07406564),
                Scalar(-3.2869E-5),
                Scalar(1.1196529E-4),
                Scalar(-1.0358E-5)) );

    com_ARM = iit::rbd::Vector3d(0.29409721,0.0,0.19270521).cast<Scalar>();
    tensor_ARM.fill(
        Scalar(13.640494),
        com_ARM,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.56744206),
                Scalar(2.8621187),
                Scalar(2.3521094),
                Scalar(1.3513623E-4),
                Scalar(0.78613657),
                Scalar(2.6102602E-5)) );

    com_ELBOW = iit::rbd::Vector3d(-0.0045213597,-1.046407E-4,0.035705905).cast<Scalar>();
    tensor_ELBOW.fill(
        Scalar(4.6480036),
        com_ELBOW,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.027474921),
                Scalar(0.029336002),
                Scalar(0.011686607),
                Scalar(2.80449E-5),
                Scalar(-1.2148451E-4),
                Scalar(1.4539959E-5)) );

    com_FOREARM = iit::rbd::Vector3d(-5.1024003E-4,0.04744292,0.27441633).cast<Scalar>();
    tensor_FOREARM.fill(
        Scalar(5.727165),
        com_FOREARM,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.6914857),
                Scalar(0.66195536),
                Scalar(0.042477604),
                Scalar(1.6938051E-5),
                Scalar(-4.3756753E-4),
                Scalar(0.13129324)) );

    com_WRIST_1 = iit::rbd::Vector3d(0.0,0.0,0.0).cast<Scalar>();
    tensor_WRIST_1.fill(
        Scalar(1.9710281),
        com_WRIST_1,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.0066945674),
                Scalar(0.005564212),
                Scalar(0.0038716148),
                Scalar(-4.5275E-6),
                Scalar(7.5009E-6),
                Scalar(-3.509941E-4)) );

    com_WRIST_2 = iit::rbd::Vector3d(-2.453794E-4,-0.0012360854,0.00778653).cast<Scalar>();
    tensor_WRIST_2.fill(
        Scalar(2.6557686),
        com_WRIST_2,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.014252975),
                Scalar(0.01525163),
                Scalar(0.0036114499),
                Scalar(1.4206211E-6),
                Scalar(4.4650424E-5),
                Scalar(5.0032435E-5)) );

}

