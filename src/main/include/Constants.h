// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <units/length.h>
#include <units/velocity.h>

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */





// ------------
//All "Ports" are CAN ID's
//----------

namespace OperatorConstants 
{

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants


namespace DriveConstants
{
    //motor controler ports

    inline constexpr int kLeftMotorAPort = 5;
    inline constexpr int kLeftMotorBPort = 4;
    inline constexpr int kRightMotorAPort = 3;
    inline constexpr int kRightMotorBPort = 2;

    //Track width
    //  inline constexpr int kTrackWidth = 0;
    inline constexpr units::foot_t kTrackWidth = 1.92_ft;

    inline constexpr units::feet_per_second_t kSpeed = 1.0_fps;
}

namespace ShootConstants
{
    //Shooter motor ports

    inline constexpr int kShooterPortA = 9;
    inline constexpr int kShooterPortB = 10;
    inline constexpr int kShooterSpeed = 0.6; // 1 = 100%, 0 = 0%. Not actually inputing motor speed itslef just its percent
}

namespace LoadConstants
{
 inline constexpr int kLowerInnerMotorPort = 6; //same as "middle load"
 inline constexpr int kHigherInnerMotorPort = 8;
 inline constexpr int kIntakeMotorPort = 7;
 inline constexpr int kLoadSpeed = 0.8; // 1 = 100%, 0 = 0%. Not actually inputing motor speed itslef just its percent
   

}



namespace DemoModeConstants
{
    inline constexpr int kDemoSwitchPort = 8; 
    inline constexpr int kDemoShootScale = 0.5; 
    inline constexpr int kDemoDriveScale = 0.5; 
}