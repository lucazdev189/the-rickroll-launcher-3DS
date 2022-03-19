/*
	This is the work of lucazdev189. Credit to original author Aurelio Mannara.
    In this program, I am going to show you how to do a simple rickroll using
	only printf.
*/

#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	
	gfxInitDefault();

	
	PrintConsole topScreen, bottomScreen;

	
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);

	
	consoleSelect(&topScreen);
	printf("\x1b[6;20HNever Gonna\n");
	
	consoleSelect(&bottomScreen);
	printf("\x1b[6;15HGive you up\n");

	consoleSelect(&topScreen);
	printf("\x1b[27;10HPress Start to exit this rickroll.");

	consoleSelect(&topScreen);
	printf("\x1b[30;20Hlucazdev189.");

	// Main loop
	while (aptMainLoop())
	{
		
		hidScanInput();

		
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; 

		
		gfxFlushBuffers();
		gfxSwapBuffers();

		
		gspWaitForVBlank();
	}

	
	gfxExit();

	return 0;
}

// Made with devkitpro. Just experimenting around the examples. First project done!

// lucazdev189
