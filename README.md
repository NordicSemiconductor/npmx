# npmx
## Overview
npmx is a set of drivers for peripherals present in Nordic Semiconductor's Power Management ICs (PMICs).

For the user's convenience, the drivers come with the ADK package. This package contains definitions of register structures and bitfields for PMICs.

A comprehensive set of [Zephyr samples](https://github.com/NordicSemiconductor/npmx-zephyr) using this library are also available.

## Supported devices

* nPM1300 revision 2.2
* nPM1304 revision 1.1

## Directories
```
 .
 ├── adk             # nPM ADK files
 ├── backends        # npmx backend files
 ├── doc             # Project documentation files
 ├── drivers         # npmx driver files
 │   ├── include     # npmx driver headers
 │   └── src         # npmx driver sources
 ├── templates       # Templates of npmx integration files
 └── zephyr          # Zephyr integration files
```

## Porting to other platforms
See the [Porting guide](PORTING.md) for guidance on porting npmx to other platforms.
