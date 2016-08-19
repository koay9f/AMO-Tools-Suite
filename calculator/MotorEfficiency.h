//
// Created by Accawi, Gina K. on 6/17/16.
//

#ifndef AMO_LIBRARY_MOTOREFFICIENCY_H
#define AMO_LIBRARY_MOTOREFFICIENCY_H

#include "../Motor.h"
#include "../FieldData.h"

class MotorEfficiency {
public:

    MotorEfficiency(double lineFrequency, double motorRpm, Motor::EfficiencyClass efficiencyClass, double hp,
                    FieldData::LoadEstimationMethod loadEstimationMethod, double motorKwh, double motorAmps,
                    double voltage) : lineFrequency_(lineFrequency), motorRpm_(motorRpm),
                                      efficiencyClass_(efficiencyClass), hp_(hp),
                                      loadEstimationMethod_(loadEstimationMethod), motorKwh_(motorKwh),
                                      motorAmps_(motorAmps), voltage_(voltage) {}

    double calculate();

    double getLineFrequency() const {
        return lineFrequency_;
    }

    void setLineFrequency(double lineFrequency) {
        lineFrequency_ = lineFrequency;
    }

    double getMotorRpm() const {
        return motorRpm_;
    }

    void setMotorRpm(double motorRpm) {
        motorRpm_ = motorRpm;
    }

    Motor::EfficiencyClass getEfficiencyClass() const {
        return efficiencyClass_;
    }

    void setEfficiencyClass(Motor::EfficiencyClass efficiencyClass) {
        efficiencyClass_ = efficiencyClass;
    }

    double getHp() const {
        return hp_;
    }

    void setHp(double hp) {
        hp_ = hp;
    }

    FieldData::LoadEstimationMethod getLoadEstimationMethod() const {
        return loadEstimationMethod_;
    }

    void setLoadEstimationMethod(FieldData::LoadEstimationMethod loadEstimationMethod) {
        loadEstimationMethod_ = loadEstimationMethod;
    }

    double getMotorKwh() const {
        return motorKwh_;
    }

    void setMotorKwh(double motorKwh) {
        motorKwh_ = motorKwh;
    }

    double getMotorAmps() const {
        return motorAmps_;
    }

    void setMotorAmps(double motorAmps) {
        motorAmps_ = motorAmps;
    }

    double getVoltage() const {
        return voltage_;
    }

    void setVoltage(double voltage) {
        voltage_ = voltage;
    }

private:
    double lineFrequency_;
    double motorRpm_;
    Motor::EfficiencyClass efficiencyClass_;
    double hp_;
    FieldData::LoadEstimationMethod loadEstimationMethod_;
    double motorKwh_;
    double motorAmps_;
    double voltage_;
};


#endif //AMO_LIBRARY_MOTOREFFICIENCY_H
