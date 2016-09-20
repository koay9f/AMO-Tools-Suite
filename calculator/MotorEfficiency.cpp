//
// Created by Accawi, Gina K. on 6/17/16.
//

#include "MotorEfficiency.h"

double MotorEfficiency::calculate() {
    /*
     * Define the coefficients for various partial loads
     */
    double eeLt125hp[6][5][5] = {
            {
                    {94.4693298, 95.1883316, 95.0271149, 94.9202652},
                    {-6.7603207, -4.4313388, -4.8838,    -5.922698},
                    {0.0052155, 0.0106831, 0.0214738, 0.0237195},
                    {-7.9877062,  -6.093112,   -5.9321046, -6.543364},
                    {0.1217007, 0.1334047, 0.2192181, 0.2797724}
            },
            {
                    {94.0760422, 95.0031586, 95.7414398, 95.8239212},
                    {-4.0479503, -3.8880327, -3.7168772, -4.457212},
                    {0.0074405, 0.0227826, 0.0176223, 0.0161946},
                    {-11.6170053, -7.0314751,  -6.7421432, -7.133626},
                    {0.0996109, 0.1561793, 0.1534494, 0.1677254}
            },
            {
                    {93.8141632, 94.3727875, 94.9153595, 95.6721725},
                    {-4.6062179, -6.1103659, -5.8322458, -3.0945094},
                    {0.0087636, 0.0456474, 0.041177,  0.0117143},
                    {-13.4103832, -16.6809139, -89.012764, -5.0211687},
                    {0.1305176, 0.4906062, 0.9124035, 0.0657746}
            },
            {
                    {94.2564316, 93.7924881, 94.4580078, 94.3365479},
                    {-8.466527,  -5.9279881, -5.4461684, -6.5838289},
                    {0.0127797, 0.025979,  0.0235942, 0.0240012},
                    {-13.6514874, -6.3681383,  -5.3772583, -5.7107716},
                    {0.1311112, 0.1638303, 0.1798776, 0.2732519}
            },
            {
                    {94.2680664, 95.0007401, 95.0822067, 94.0307465},
                    {-8.5491753, -5.2248688, -4.7491908, -6.5328078},
                    {0.0113539, 0.0097385, 0.011445,  0.023122},
                    {-13.7128668, -7.4668455,  -5.7718344, -5.5414934},
                    {0.1269029, 0.101055,  0.1043508, 0.2589573}
            },
            {
                    {93.3125305, 92.8547821, 93.512825,  93.3929825},
                    {-8.3825922, -5.8717227, -5.3947954, -6.5176635},
                    {0.0127878, 0.025987,  0.0236169, 0.0240058},
                    {-13.511425,  -6.3085694,  -5.3237853, -5.6540089},
                    {0.1311268, 0.1641091, 0.1801914, 0.2732107}

            }
    };

    double eeGt125hp[6][5][4] = {
            {
                    {94.3096085, 95.4968796, 96.139473,  97.0688095},
                    {-3.727977,  -1.600693,  -2.7417369, -1.4560699},
                    {0.007403,  0.0054024, 0.0053153, 0.0003762},
                    {-4.7637739,  -1.67193,   -4.6803808, -4.551105},
                    {0.0075521, 0.0054322, 0.0338892, 0.0115459},
            },
            {
                    {94.603508,  95.8442917, 96.4988785, 96.6830826},
                    {-0.7509496, -1.588917,  -0.9214408, -1.137637},
                    {0.0039577, 0.0029285, 0.0012706, 0.0008665},
                    {-2.8904891,  -1.502286,  -3.5917449, -4.7013001},
                    {0.004297,  0.025422,  0.0182224, 0.0192254}
            },
            {
                    {94.3688278, 95.694931,  96.1228485, 96.1271667},
                    {-2.125608,  -0.8348691, -0.9790492, -1.061084},
                    {0.0023973, 0.0015253, 0.0020161, 0.0017854},
                    {-7.5474558,  -0.7378651, -0.5181185, -5.6413188},
                    {0.0224034, 0.0013705, 0.0023116, 0.0233735}
            },
            {
                    {94.3297577, 95.5607681, 95.9862671, 95.8755875},
                    {-2.284539,  -1.387513,  -1.408622,  -2.771245},
                    {0.0021414, 0.002526,  0.0029882, 0.0034777},
                    {-23.8047905, -1.4607199, -1.4225709, -2.233391},
                    {0.0410458, 0.0025111, 0.0031864, 0.0246192}
            },
            {
                    {93.2923508, 94.5161896, 95.2470474, 95.3985214},
                    {-5.9736061, -2.7443399, -1.210045,  -0.3572588},
                    {0.0204008, 0.0173088, 0.012607,  0.0017577},
                    {-6.5185871,  -4.5606341, -4.2518239, -3.84008},
                    {0.0212322, 0.0175787, 0.0122263, 0.0079938}
            },
            {
                    {93.1023407, 94.3389664, 95.0703964, 95.0254974},
                    {-2.0127361, -1.240494,  -1.461535,  -1.71726},
                    {0.0025637, 0.0028372, 0.0033915, 0.0043212},
                    {-29.8683701, -1.335932,  -1.5587929, -1.78483},
                    {0.0430958, 0.002916,  0.0034837, 0.0043405}
            }
    };

    double seLt125hp[6][5][4] = {
            {
                    {97.4548645, 97.4707947, 94.015892,  92.4391479},
                    {-18.0711155, -10.1910353, -5.8480735,  -7.1247296},
                    {0.0028282, 0.0032727, 0.0083719, 0.0205557},
                    {-59.4316139,  -21.0729675, -12.9961395, -9.6740131},
                    {0.2845082, 0.1622825, 0.1389329, 0.1904846}
            },
            {
                    {89.3273544, 92.7246628, 93.4581299, 93.5225067},
                    {-8.8647995,  -6.3382502,  -6.3839912,  -7.8095098},
                    {0.0148274, 0.0197547, 0.0229227, 0.025956},
                    {-15.5345573,  -12.6434078, -11.7203112, -5.9152899},
                    {0.1425448, 0.1994676, 0.2518388, 0.2156732}
            },
            {
                    {99.2363434, 92.6848145, 93.7202225, 94.2445374},
                    {-17.0507069, -6.9303293,  -6.3185277,  -6.2978926},
                    {0.0039364, 0.0240113, 0.020703,  0.0159671},
                    {-18.6118832,  -49.6246109, -28.4840584, -10.4567404},
                    {0.1920894, 0.4071523, 0.331402,  0.1448536}
            },
            {
                    {92.3568573, 92.8039093, 93.4443588, 93.5711594},
                    {-21.5697231, -11.6206055, -10.7237835, -10.364789},
                    {0.0227553, 0.0275493, 0.0284822, 0.0234638},
                    {-332.2605591, -50.9596672, -86.1763382, -14.2348366},
                    {0.7202584, 0.5368639, 0.7059667, 0.391852}
            },
            {
                    {93,         94.0712967, 93.2845001, 92.3863754},
                    {-21.9251518, -12.3048677, -10.7361937, -10.1686945},
                    {0.0201186, 0.0195313, 0.0269523, 0.0293788},
                    {-263.0942993, -37.1354179, -68.3101425, -22.9536724},
                    {0.6665215, 0.4436121, 0.6529689, 0.5341633}
            },
            {
                    {92.3629227, 93.0339813, 92.712265,  91.6989059},
                    {-22.2433224, -12.3250246, -10.801403,  -10.2091818},
                    {0.0213771, 0.0225923, 0.0276071, 0.0310663},
                    {-297.3449402, -47.1449051, -80.57061,   -33.0391464},
                    {0.7008656, 0.5131685, 0.6985243, 0.627565}

            }
    };

    double seGt125hp[6][5][4] = {
            {
                    {94.5,       95.4700012, 95.8499985, 95.7781372},
                    {-2.2533519, -3.368489,  -2.2158239, -1.6455671},
                    {0.0008045, 0.0012732, 0.0011157, 0.0009219},
                    {-16.8750191, -7.2525139,  -6.6073551, -6.4217591},
                    {0.0061182, 0.0114441, 0.0106369, 0.0082956}
            },
            {
                    {93.9530334, 95.1749573, 95.5904312, 95.6738815},
                    {-4.5862999, -2.143106,  -0.9812574, -0.8146866},
                    {0.0048627, 0.0023812, 0.0016211, 0.0006364},
                    {-6.3994851,  -2.808579,   -3.6719639, -4.0802579},
                    {0.0049118, 0.0054079, 0.0062618, 0.0068752}
            },
            {
                    {94.1330795, 95.261467,  95.6270599, 95.4791107},
                    {-1.5423239, -3.0588069, -1.670272,  -1.309896},
                    {0.0011977, 0.0023687, 0.0014245, 0.0009319},
                    {-17.3768005, -4.225328,   -4.677979,  -4.8598661},
                    {0.0120962, 0.0146774, 0.0116709, 0.0121007}
            },
            {
                    {94.1878967, 95,         95.1999969, 95.491127},
                    {-2.1457081, -1.815267,  -1.4718159, -2.554836},
                    {0.0013492, 0.0024264, 0.0027722, 0.001149},
                    {-2.2014821,  -1.823415,   -1.645975,  -5.08461},
                    {0.003867,  0.0023876, 0.0029125, 0.0220845}
            },
            {
                    {93,         94.1999969, 94.656868,  93.9838028},
                    {-2.1450679, -2.2449639, -1.422925,  -1.466002},
                    {0.0048143, 0.0051079, 0.0038267, 0.0038691},
                    {-10.8882599, -12.0848799, -1.590228,  -1.5229239},
                    {0.0331321, 0.0348395, 0.0039306, 0.0038869}
            },
            {
                    {93.1586075, 94.3856277, 94.193428,  93.2530594},
                    {-0.9520077, -0.9646612, -1.089741,  -1.189248},
                    {0.0014575, 0.0014577, 0.0024626, 0.0030805},
                    {-1.173719,   -1.1895,     -1.388774,  -1.441321},
                    {0.0015139, 0.0015143, 0.0024572, 0.00279}
            }
    };

    /*
     * Find the poles
     */
    int polechooser = 0;

    /*
     * Calculating Motor Efficiency
     * On the EE and SE tabs are all the coefficient arrays. At the bottom of the sheets are calculated tables of efficiency vs load for each speed class.
     * The 25%,50%,75%, and 100% load efficiencies are calculated using the above double-exponential calculation
     * At 0% load, the motor efficiency is, by definition, 0%
     */
    //double eeMotorEfficiency_[5] = {};
    //double seMotorEfficiency_[5] = {};
    double motorEfficiency_[5] = {};
    if (efficiencyClass_ == Motor::EfficiencyClass::ENERGY_EFFICIENT) {
        for (int i = 0; i < 4; ++i) { //cols
            if (motorRatedPower_ <= 125) {
                motorEfficiency_[i] = (eeLt125hp[polechooser][0][i] + (eeLt125hp[polechooser][1][i] *
                                                                       exp(-1 * eeLt125hp[polechooser][2][i] *
                                                                           motorRatedPower_)) +
                                       (eeLt125hp[polechooser][3][i] *
                                        exp(-1 * eeLt125hp[polechooser][4][i] * motorRatedPower_))) / 100;
            } else {
                motorEfficiency_[i] = (eeGt125hp[polechooser][0][i] + (eeGt125hp[polechooser][1][i] *
                                                                       exp(-1 * eeGt125hp[polechooser][2][i] *
                                                                           motorRatedPower_)) +
                                       (eeGt125hp[polechooser][3][i] *
                                        exp(-1 * eeGt125hp[polechooser][4][i] * motorRatedPower_))) / 100;
            }
        }
    } else if (efficiencyClass_ == Motor::EfficiencyClass::STANDARD) {
        for (int i = 0; i < 4; ++i) { //cols
            if (motorRatedPower_ <= 125) {
                motorEfficiency_[i] = (seLt125hp[polechooser][0][i] + (seLt125hp[polechooser][1][i] *
                                                                       exp(-1 * seLt125hp[polechooser][2][i] *
                                                                           motorRatedPower_)) +
                                       (seLt125hp[polechooser][3][i] *
                                        exp(-1 * seLt125hp[polechooser][4][i] * motorRatedPower_))) / 100;
            } else {
                motorEfficiency_[i] = (seGt125hp[polechooser][0][i] + (seGt125hp[polechooser][1][i] *
                                                                       exp(-1 * seGt125hp[polechooser][2][i] *
                                                                           motorRatedPower_)) +
                                       (seGt125hp[polechooser][3][i] *
                                        exp(-1 * seGt125hp[polechooser][4][i] * motorRatedPower_))) / 100;
            }
        }
    }
    /*
     * PSAT assumes that the efficiency at 125% load is 99% of the full load efficiency.
     */
    motorEfficiency_[4] = 0.99 * motorEfficiency_[3];

    /*
     * Corrections if the efficiency is specified
     */


    double motorEff_ = 0.0;
    /*
     * Calculating the 1% interval values based on the load factor
     * 0 - 25
     * 1. Using the 0% and 25% kW loss values, develop a linear table of loss by 1% load
     * Equation: kWloss (X) = kWloss (0) + X * (kWloss(25) - kWloss(0))/25      where X = 0,1,2,3…..25
     * 2. Assemble an array of shaft power from 0 to 25
     * Equation: kW shaft (X) = rated hp *0.746 * (X / 100)
     * Assemble an array of kWe (input electric power
     * Equation: kWe(X) = kWloss(x) + kWshaft(X)
     * Calculate efficiency
     * Equation: Eff(X) = kW shaft (X) / kWe (X)
     */

    /*
     * Setting up kWloss0 and kWloss25
     * Make sure motoEfficiency is in decimal rather %.
     * E.g.: 0.92 is correct, 92 is wrong.
     */
    double kWloss25 = ((1 / motorEfficiency_[0]) - 1) * motorRatedPower_ * 0.746 * 0.25;
    double kWloss0 = 0.8 * kWloss25;

    /*
     * Note: Above is for EE or SE. More calculations are required for Specified Efficiency
     */


    if (loadFactor_ <= 0.25) {
        double kWloss_ = kWloss0 + loadFactor_ * (kWloss25 - kWloss0) / 25;
        double kWshaft_ = motorRatedPower_ * 0.746 * (loadFactor_); // Make sure motorRatedPower is in hp
        double kWe_ = kWloss_ + kWshaft_; // Input electric power
        motorEff_ = kWshaft_ / kWe_; //Final efficiency calculation
    }
        /*
         * 26 - 125
         * Fitting tabular, 25% interval, motor efficiency data to assemble an overall curve with 1% interval data from 26 to 150%
         * 25% load interval efficiency values come from "Adjusting 25 percent arrays for specified efficiency"
         * Pick the 25,50,75,100,and 125% motor efficiency values and do a 4th order polynomial fit.
         * Use the fit coefficients to popluate, in 1% load intervals, from 26 to 125% load
         */

    else if (loadFactor_ <= 1.25 && loadFactor_ > 0.25) {
        double xCoord_[5] = {.25, .50, .75, 1.00, 1.25};
        double yCoord_[5] = {motorEfficiency_[0], motorEfficiency_[1], motorEfficiency_[2], motorEfficiency_[3],
                             motorEfficiency_[4]};
        CurveFitVal cfv(5, xCoord_, motorEfficiency_, 4, loadFactor_);
        motorEff_ = cfv.calculate();
    }
        /*
         * 126 - 150
         * Pick the 75, 100, and 125% motor efficiency values and do a 2nd order polynomial fit
         * Use the fit coefficients to populate, in 1% load intervals, the current range from 126 to 150% load
         */
    else if (loadFactor_ <= 1.50 && loadFactor_ > 1.25) {
        double xCoord_[3] = {.75, 1.00, 1.25};
        double yCoord_[3] = {motorEfficiency_[2], motorEfficiency_[3], motorEfficiency_[4]};
        CurveFitVal cfv(3, xCoord_, yCoord_, 2, loadFactor_);
        motorEff_ = cfv.calculate();
    }
    /*
     * When ready uncomment the below.
     */
    return motorEff_;
    //return 94.36;
}
