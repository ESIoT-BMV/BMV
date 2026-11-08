# Setup

This project targets the **MSP432P401R** and needs the **SimpleLink MSP432 SDK** (driverlib).
The SDK is not installed by the project, so you must tell your IDE where it is.

## Code Composer Studio (CCS)

1. Import the project: *Project → Import CCS Projects...*
2. Open *Project → Properties → Resource → Linked Resources → Path Variables*.
3. Edit the variable `SIMPLELINK_SDK` and set it to the folder where you put the SDK, for example:
   - Windows: `C:/ti/simplelink_msp432p4_sdk_3_40_01_02`
   - Linux: `/home/<user>/ti/simplelink_msp432p4_sdk_3_40_01_02`
4. Run *Project → Clean*, then *Build*.

The SDK can live anywhere. Only this variable needs to point to it.

## Visual Studio Code

1. Install the **C/C++** extension (Microsoft).
2. Create `.vscode/c_cpp_properties.json` and paste the block for your OS.
3. Replace the SDK and CCS paths with the ones on your machine.

This configuration only enables IntelliSense (autocomplete and error highlighting). To build and flash, you still need CCS or the TI compiler on the command line.

### Windows

```jsonc
{
    "configurations": [
        {
            "name": "Windows",
            "includePath": [
                "${workspaceFolder}/**",
                // Path to the SimpleLink SDK (change this):
                "C:/ti/ccs1281/ccs/ccs_base/arm/include/**",
                "C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include/"
            ],
            "defines": [
                "__MSP432P401R__",
                "__TI_ARM__",
            ],
            "cStandard": "gnu89",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

### Linux

```jsonc
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                // Path to the SimpleLink SDK (change this):
                "${userHome}/ti/ccs1281/ccs/ccs_base/arm/include/**",
                "${userHome}/ti/ccs1281/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include/"
            ],
            "defines": [
                "__MSP432P401R__",
                "__TI_ARM__",
            ],
            "cStandard": "gnu89",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

> Adjust the paths if your CCS version (`ccs1281`), compiler version, or SDK version differ.