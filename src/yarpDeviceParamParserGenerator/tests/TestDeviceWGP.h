/*
 * SPDX-FileCopyrightText: 2024-2024 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/dev/DeviceDriver.h>
#include "TestDeviceWGP_ParamsParser.h"

#include <string>

/**
* @ingroup dev_impl_media
*
* \brief `TestDeviceWGP` : A test device driver, for Continuous Integration purposes.
*
* Parameters required by this device are shown in class: TestDeviceWGP_ParamsParser
*/

class TestDeviceWGP :
        public yarp::dev::DeviceDriver,
        public TestDeviceWGP_ParamsParser
{
public:
    TestDeviceWGP();
    TestDeviceWGP(const TestDeviceWGP&) = delete;
    TestDeviceWGP(TestDeviceWGP&&) = delete;
    TestDeviceWGP& operator=(const TestDeviceWGP&) = delete;
    TestDeviceWGP& operator=(TestDeviceWGP&&) = delete;
    ~TestDeviceWGP() override;

    // Device Driver interface
    bool open(yarp::os::Searchable &config) override;
    bool close() override;
};
