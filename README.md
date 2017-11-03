# ForceSetScrResolution
(Windows 10) Force set screen resolution command.
=============================================================

## Overview
ForceSetScrResolution.exe command force set windows screen resolution.

Windows 10 clone mode of Hi-resolution Display  and  Low-resolution Display, It down Low-resolution.
This command force set Hi-resolution setting.

## Quick Start
Prerequisites:
- Windows 10, 10 IoT Enterprise
- Visual Studio 2015 Runtime

Run x64bin/ForceSetScrResolution.exe

## Build
Visual Studio 2015 open Project .sln.

## Examples
1. reset display. (Windows Display set Extend mode. (TEST prepair) )
```
DisplaySwitch.exe  /extend
```
2. two display clone. 
```
DisplaySwitch.exe  /clone
```
-->(oops! Hi-resolution Display down Low-resolution. (720p, VGA, ...))

3. force set Hi-resolution (1080p). 
```
ForceSetScrResolution.exe  1080
```


## License
Code licensed under the [MIT License](LICENSE).

## Author
[Naohisa Fukuoka](https://github.com/fknaopen)

