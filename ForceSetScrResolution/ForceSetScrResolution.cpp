/*
MIT License

Copyright (c) 2017 Naohisa Fukuoka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
    ForceSetScrResolution

    Usage: command [resolution-id]
	Note: dafault-resolution=1920x1080
*/

#include <windows.h>

long SetResolution(int width, int height, int moniter)
{
	// get device
	DISPLAY_DEVICE disp;
	EnumDisplayDevices(NULL, moniter, &disp, NULL);

	// set resolution
	DEVMODE mode = { 0 };
	mode.dmSize = sizeof(mode);
	mode.dmPelsWidth = width;
	mode.dmPelsHeight = height;
	mode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

	return(ChangeDisplaySettingsEx(disp.DeviceName, &mode, NULL, 0, NULL));
}

int main(int argc, char *argv[], char *envp[])
{
	int w = 1920; int h = 1080;

	if (argc == 2) {
		switch (atoi(argv[1]) /* resolution-id */)
		{
		case 768:
			w = 1024; h = 768;
			break;
		case 720:
			w = 1280; h = 720;
			break;
		default:
			break;
		}
	}
	return(SetResolution(w, h, 0));
}